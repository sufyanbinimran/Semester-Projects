#include <iostream>
#include <cstdlib>
#include <ctime>
#include <pthread.h>
#include <unistd.h>
#include <sys/ipc.h>
#include <sys/shm.h>

using namespace std;

// Constants
const int BOARD_ROWS = 4;
const int BOARD_COLS = 5;
const int NUM_PLAYERS = 2;
const int PLAYER_COLS = 5;

// Shared Memory IDs
int shmid_gameBoard;
int shmid_playerBoard[NUM_PLAYERS];
int shmid_playerScores;

// Mutexes
pthread_mutex_t mutex_gameBoard = PTHREAD_MUTEX_INITIALIZER;
pthread_mutex_t mutex_playerBoard[NUM_PLAYERS] = { PTHREAD_MUTEX_INITIALIZER, PTHREAD_MUTEX_INITIALIZER };

// Define the game state
enum GameState
{
    INITIALIZING,
    RUNNING,
    FINISHED
};
GameState gameStatus = INITIALIZING;

// Define the player colors
const char PLAYER_COLORS[NUM_PLAYERS] = { 'R', 'B' };

// Define the potion ingredients
const char RED = 'R';
const char YELLOW = 'Y';
const char BLUE = 'B';
const char BLACK = 'K';

// Define the game board structures
char* gameBoard;
char* playerBoard[NUM_PLAYERS];
int* playerScores;

// Forward declarations
void assessReaction(int player);
int getPlayerMove(int player);
void showGameBoard();
void displayPlayerInfo();
void executeMove(int move, int player);
bool hasGameFinished();
void announceChampion();
void* gameLoop(void* arg);

// Function to create shared memory for the game board
template <typename T>
T* createSharedMemory(int& shmid, int size)
{
    shmid = shmget(IPC_PRIVATE, sizeof(T) * size, IPC_CREAT | 0666);
    T* memory = (T*)shmat(shmid, NULL, 0);
    return memory;
}

// Function to initialize shared memory
void initializeSharedMemory()
{
    srand(time(NULL));

    gameBoard = createSharedMemory<char>(shmid_gameBoard, BOARD_ROWS * BOARD_COLS);

    for (int i = 0; i < NUM_PLAYERS; ++i)
    {
        playerBoard[i] = createSharedMemory<char>(shmid_playerBoard[i], PLAYER_COLS);
    }

    playerScores = createSharedMemory<int>(shmid_playerScores, NUM_PLAYERS);

    for (int i = 0; i < BOARD_ROWS * BOARD_COLS; ++i)
    {
        gameBoard[i] = rand() % 4 + 'A';
    }

    for (int i = 0; i < NUM_PLAYERS; ++i)
    {
        for (int j = 0; j < PLAYER_COLS; ++j)
        {
            playerBoard[i][j] = ' ';
        }
    }

    for (int i = 0; i < NUM_PLAYERS; ++i)
    {
        playerScores[i] = 0;
    }
}

// Function to display the game board
void showGameBoard()
{
    pthread_mutex_lock(&mutex_gameBoard);

    // Print top border
    cout << "+";
    for (int i = 0; i < BOARD_COLS * 5 - 1; ++i)
    {
        cout << "-";
    }
    cout << "+" << endl;

    for (int i = 0; i < BOARD_ROWS; i++)
    {
        cout << "| ";
        for (int j = 0; j < BOARD_COLS; j++)
        {
            char ingredient = gameBoard[i * BOARD_COLS + j];
            switch (ingredient)
            {
            case 'A':
                cout << "\033[1;31m" << ingredient << "\033[0m | "; // Red
                break;
            case 'B':
                cout << "\033[1;34m" << ingredient << "\033[0m | "; // Blue
                break;
            case 'C':
                cout << "\033[1;33m" << ingredient << "\033[0m | "; // Yellow
                break;
            case 'D':
                cout << "\033[1;30m" << ingredient << "\033[0m | "; // Black
                break;
            default:
                cout << ingredient << " | ";
            }
        }
        cout << endl;
        cout << "+";
        for (int i = 0; i < BOARD_COLS * 5 - 1; ++i)
        {
            cout << "-";
        }
        cout << "+" << endl;
    }

    pthread_mutex_unlock(&mutex_gameBoard);
}

// Function to display player boards and scores
void displayPlayerInfo()
{
    for (int player = 0; player < NUM_PLAYERS; player++)
    {
        pthread_mutex_lock(&mutex_playerBoard[player]);

        // Print top border
        cout << "+";
        for (int i = 0; i < PLAYER_COLS * 5 - 1; ++i)
        {
            cout << "-";
        }
        cout << "+" << endl;

        cout << "| ";
        for (int j = 0; j < PLAYER_COLS; j++)
        {
            char ingredient = playerBoard[player][j];
            switch (ingredient)
            {
            case 'A':
                cout << "\033[1;31m" << ingredient << "\033[0m | "; // Red
                break;
            case 'B':
                cout << "\033[1;34m" << ingredient << "\033[0m | "; // Blue
                break;
            case 'C':
                cout << "\033[1;33m" << ingredient << "\033[0m | "; // Yellow
                break;
            case 'D':
                cout << "\033[1;30m" << ingredient << "\033[0m | "; // Black
                break;
            default:
                cout << ingredient << " | ";
            }
        }
        cout << "  Score: " << playerScores[player] << " ";
        cout << endl;
        cout << "+";
        for (int i = 0; i < PLAYER_COLS * 5 - 1; ++i)
        {
            cout << "-";
        }
        cout << "+" << endl;

        pthread_mutex_unlock(&mutex_playerBoard[player]);
    }
}

// Function to get the player's move
int getPlayerMove(int player)
{
    int move;
    while (true)
    {
        cout << "Player " << (player + 1) << ", Take Your Turn : ";
        cin >> move;
        if (move >= 1 && move <= PLAYER_COLS)
        {
            return move;
        }
        else
        {
            cout << "Please enter a number between 1 and 5." << endl;
        }
    }
}

// Function to process the player's move
void executeMove(int move, int player)
{
    int col = move - 1;

    if (gameBoard[col] != ' ')
    {
        char ingredient = gameBoard[col];

        for (int i = 0; i < BOARD_ROWS - 1; i++)
        {
            gameBoard[i * BOARD_COLS + col] = gameBoard[(i + 1) * BOARD_COLS + col];
        }
        gameBoard[(BOARD_ROWS - 1) * BOARD_COLS + col] = ' ';

        for (int i = 0; i < PLAYER_COLS; i++)
        {
            if (playerBoard[player][i] == ' ')
            {
                playerBoard[player][i] = ingredient;
                break;
            }
        }

        assessReaction(player);
    }
    else
    {
        cout << "Invalid move. Please choose a column with marbles." << endl;
    }
}

// Function to check if a move caused a reaction
void assessReaction(int player)
{
    int count = 0;
    char lastIngredient = ' ';

    for (int i = 0; i < PLAYER_COLS; i++)
    {
        if (playerBoard[player][i] == ' ')
        {
            break;
        }

        if (playerBoard[player][i] == lastIngredient)
        {
            count++;
        }
        else
        {
            count = 1;
            lastIngredient = playerBoard[player][i];
        }

        if (count >= 3)
        {
            for (int j = i; j <= i + 2; j++)
            {
                playerBoard[player][j] = ' ';
            }

            char ingredient = playerBoard[player][i];

            // Update the player's score
            if (ingredient == RED)
            {
                playerScores[player] += 2;
            }
            else if (ingredient == YELLOW)
            {
                playerScores[player] += 3;
            }
            else if (ingredient == BLUE)
            {
                playerScores[player] += 4;
            }
            else
            {
                playerScores[player] += 5;
            }

            assessReaction(player);
            break; // Exit the loop after finding and processing one reaction
        }
    }
}

// Function to check if the game is over
bool hasGameFinished()
{
    for (int j = 0; j < BOARD_COLS; j++)
    {
        if (gameBoard[j] != ' ')
        {
            return false;
        }
    }

    return true;
}

// Function to declare the winner and display scores
void announceChampion()
{
    displayPlayerInfo();

    if (playerScores[0] > playerScores[1])
    {
        cout << "Player 1 WON" << endl;
    }
    else if (playerScores[1] > playerScores[0])
    {
        cout << "Player 2 WON" << endl;
    }
    else
    {
        cout << " TIE " << endl;
    }
}

// Function for the game loop in a separate thread
void* gameLoop(void* arg)
{
    while (!hasGameFinished())
    {
        showGameBoard();
        displayPlayerInfo();

        int move1 = getPlayerMove(0);
        executeMove(move1, 0);

        showGameBoard();
        displayPlayerInfo();

        if (hasGameFinished())
        {
            break;
        }

        int move2 = getPlayerMove(1);
        executeMove(move2, 1);
    }

    announceChampion();

    shmdt(gameBoard);
    for (int i = 0; i < NUM_PLAYERS; ++i)
    {
        shmdt(playerBoard[i]);
    }
    shmdt(playerScores);

    shmctl(shmid_gameBoard, IPC_RMID, NULL);
    for (int i = 0; i < NUM_PLAYERS; ++i)
    {
        shmctl(shmid_playerBoard[i], IPC_RMID, NULL);
    }
    shmctl(shmid_playerScores, IPC_RMID, NULL);

    pthread_exit(NULL);
}

int main()
{
    initializeSharedMemory();

    pthread_t thread;
    pthread_create(&thread, NULL, gameLoop, NULL);

    pthread_join(thread, NULL);

    return 0;
}
