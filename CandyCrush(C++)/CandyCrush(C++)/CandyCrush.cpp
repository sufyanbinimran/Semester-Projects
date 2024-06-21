#include<iostream>
#include<string>
#include<ctime>
#include<windows.h>
using namespace std;
int a, b;
void board(int aray1[8][8])
{
	int a;
	int x;
	int y;
	srand(time(0));
	for (int i = 1; i < 6; i++)
	{
		char c = 'H';
		x = (rand() % 7 + 1);
		y = (rand() % 7 + 1);
		aray1[x][y] = c;
	}
	for (int i = 0; i <= 7; i++)
	{
		srand(time(0));
		for (int j = 0; j <= 7; )
		{

			a = (rand() % 31 + 35);

			if (aray1[i][j] == 'H')
			{
				j++;
			}
			else if (a == '@' || a == '#' || a == '$' || a == '&')
			{
				int d = i * 8 + j;
				if ((aray1[i][j - 1] != a || aray1[i][j - 2] != a) && (aray1[0][d - 16] != a || aray1[0][d - 8] != a))
				{
					aray1[i][j] = char(a);
					j++;
				}
			}
		}
	}
}
void display(int aray1[8][8])
{
	for (int i = 0; i <= 7; i++)
	{
		for (int j = 0; j <= 7; j++)
		{
			cout << "|" << char(aray1[i][j]) << "|" << "     ";
		}
		cout << endl;
		cout << endl;
		cout << endl;
	}
}
void move(int a, int b, int aray1[8][8])
{
	if (aray1[0][b] == 'H')
	{
	}
	else
	{
		swap(aray1[0][a], aray1[0][b]);
	}
}

void input(int aray1[8][8])
{
	int row = 0, col = 0, row1 = 0, col1 = 0, c = 0, d = 0, e = 0, f = 0;
	cout << "Input the row you want to swap = ";
	cin >> row;
	cout << "Input the column you want to swap = ";
	cin >> col;
	cout << "Input the row you want to swap with = ";
	cin >> row1;
	cout << "Input the column you want to swap with = ";
	cin >> col1;
	c = (row) * 8 + col;//Want to swap 
	d = (row1) * 8 + col1;//Want to swap with desired index
	while (d != c + 1 && d != c - 1 && d != c - 8 && d != c + 8)
	{
		cout << "Invalid Move!" << endl;
		cout << "Input the row you want to swap with = ";
		cin >> row1;
		cout << "Input the column you want to swap with = ";
		cin >> col1;
		d = (row1) * 8 + col1;
	}
	a = c;
	b = d;
	if ((aray1[0][c] == aray1[0][d + 1] && aray1[0][c] == aray1[0][d + 2]) || (aray1[0][c] == aray1[0][d - 1] &&
		aray1[0][c] == aray1[0][d - 2]) || (aray1[0][c] == aray1[0][d + 1] && aray1[0][c] == aray1[0][d - 1]) &&
		(aray1[0][c] == aray1[0][d + 8] && aray1[0][c] == aray1[0][d + 16]) || (aray1[0][c] == aray1[0][d - 8] &&
			aray1[0][c] == aray1[0][d - 16]) || (aray1[0][c] == aray1[0][d + 8] && aray1[0][c] == aray1[0][d - 8])
		|| (aray1[0][c + 1] == aray1[0][d] && aray1[0][c + 2] == aray1[0][d]) || (aray1[0][c - 1] == aray1[0][d] &&
			aray1[0][c - 2] == aray1[0][d]) || (aray1[0][c + 1] == aray1[0][d] && aray1[0][c - 1] == aray1[0][d]) &&
		(aray1[0][c + 8] == aray1[0][d] && aray1[0][c + 16] == aray1[0][d]) || (aray1[0][c - 8] == aray1[0][d] &&
			aray1[0][c - 16] == aray1[0][d]) || (aray1[0][c + 8] == aray1[0][d] && aray1[0][c - 8] == aray1[0][d]))
	{
		move(c, d, aray1);
	}
}
void num_match_4hori(int aray1[8][8])
{
	int temp = 0, a = 'B';
	bool b = false;
	//4 horizontal check
	while (b == false)
	{
		for (int i = 0; i < 8; i++)
		{
			if (b == true)
			{
				b = false;
				break;
			}
			for (int j = 0; j < 7; j++)
			{
				if (aray1[i][j] == aray1[i][j + 1] && aray1[i][j] == aray1[i][j + 2])
				{
					temp++;
				}
				else
				{
					temp = 0;
				}
				if (temp == 2)
				{
					while (a != '@' && a != '#' && a != '$' && a != '&')
					{
						srand(time(0));
						a = (rand() % 2) + 35;
					}
					cout << a << ": hello world" << endl;
					aray1[i][j] = a;
					a = 'B';
					while (a != '@' && a != '#' && a != '$' && a != '&')
					{
						srand(time(0));
						a = (rand() % 31) + 35;
					}
					aray1[i][j - 1] = a;
					a = 'B';
					while (a != '@' && a != '#' && a != '$' && a != '&')
					{
						srand(time(0));
						a = (rand() % 31) + 35;
					}
					aray1[i][j - 2] = a;
					a = 'B';
					while (a != '@' && a != '#' && a != '$' && a != '&')
					{
						srand(time(0));
						a = (rand() % 28) + 38;
					}
					aray1[i][j + 1] = a;
					a = 'B';
					while (a != '@' && a != '#' && a != '$' && a != '&')
					{
						srand(time(0));
						a = (rand() % 28) + 38;
					}
					aray1[i][j + 2] = a;
					a = 'B';
					b = true;
					temp = 0;
					break;
				}
			}
			temp = 0;
		}
		b = true;
	}
}
void num_match_4verti(int aray1[8][8])
{
	int temp = 0, a = 'B';
	bool b = false;
	//4 vertical check
	while (b == false)
	{
		for (int i = 0; i < 8; i++)
		{
			if (b == true)
			{
				b = false;
				break;
			}
			for (int j = 0; j < 7; j++)
			{
				if (aray1[j][i] == aray1[j][i + 8] && aray1[j][i] == aray1[j][i + 16])
				{
					temp++;
				}
				else
				{
					temp = 0;
				}
				if (temp == 2)
				{
					while (a != '@' && a != '#' && a != '$' && a != '&')
					{
						srand(time(0));
						a = (rand() % 2) + 35;
					}
					cout << a << ": hello world" << endl;
					aray1[j][i] = a;
					a = 'B';
					while (a != '@' && a != '#' && a != '$' && a != '&')
					{
						srand(time(0));
						a = (rand() % 31) + 35;
					}
					aray1[j][i - 1] = a;
					a = 'B';
					while (a != '@' && a != '#' && a != '$' && a != '&')
					{
						srand(time(0));
						a = (rand() % 31) + 35;
					}
					aray1[j][i - 2] = a;
					a = 'B';
					while (a != '@' && a != '#' && a != '$' && a != '&')
					{
						srand(time(0));
						a = (rand() % 28) + 38;
					}
					aray1[j][i + 1] = a;
					a = 'B';
					while (a != '@' && a != '#' && a != '$' && a != '&')
					{
						srand(time(0));
						a = (rand() % 28) + 38;
					}
					aray1[j][i + 2] = a;
					a = 'B';
					b = true;
					temp = 0;
					break;
				}
			}
			temp = 0;
		}
		b = true;
	}
}
void num_match_3hori(int aray1[8][8])
{
	int temp = 0, a = 'B';
	bool b = false;
	//3 horizontal check
	while (b == false)
	{
		for (int i = 0; i < 8; i++)
		{
			if (b == true)
			{
				b = false;
				break;
			}
			for (int j = 0; j < 7; j++)
			{
				if (aray1[i][j] == aray1[i][j + 1])
				{
					temp++;
				}
				else
				{
					temp = 0;
				}
				if (temp == 2)
				{
					while (a != '@' && a != '#' && a != '$' && a != '&')
					{
						srand(time(0));
						a = (rand() % 2) + 35;
					}
					cout << a << ": hello world" << endl;
					aray1[i][j] = a;
					a = 'B';
					while (a != '@' && a != '#' && a != '$' && a != '&')
					{
						srand(time(0));
						a = (rand() % 31) + 35;
					}
					aray1[i][j - 1] = a;
					a = 'B';
					while (a != '@' && a != '#' && a != '$' && a != '&')
					{
						srand(time(0));
						a = (rand() % 28) + 38;
					}
					aray1[i][j + 1] = a;
					a = 'B';

					b = true;
					temp = 0;
					break;
				}
			}
			temp = 0;
		}
		b = true;
	}
}
void num_match_3verti(int aray1[8][8])
{
	int temp = 0, a = 'B';
	bool b = false;
	//3 vertical check
	while (b == false)
	{
		for (int i = 0; i < 8; i++)
		{
			if (b == true)
			{
				b = false;
				break;
			}
			for (int j = 0; j < 7; j++)
			{
				if (aray1[j][i] == aray1[j][i + 8])
				{
					temp++;
				}
				else
				{
					temp = 0;
				}
				if (temp == 2)
				{
					while (a != '@' && a != '#' && a != '$' && a != '&')
					{
						srand(time(0));
						a = (rand() % 2) + 35;
					}
					cout << a << ": hello world" << endl;
					aray1[j][i] = a;
					a = 'B';
					while (a != '@' && a != '#' && a != '$' && a != '&')
					{
						srand(time(0));
						a = (rand() % 31) + 35;
					}
					aray1[j][i - 1] = a;
					a = 'B';
					while (a != '@' && a != '#' && a != '$' && a != '&')
					{
						srand(time(0));
						a = (rand() % 28) + 38;
					}
					aray1[j][i + 1] = a;
					a = 'B';
					b = true;
					temp = 0;
					break;
				}
			}
			temp = 0;
		}
		b = true;
	}
}
string credits(string n1)
{
	n1 = "Ali hassan (n) Sufyan Malik";
	return n1;
}
string inst(string ins)
{
	ins = " ";
	return ins;
}
int main()
{
	int a, q = 1;
	cout << "1:Play game" << endl;
	cout << "2:Credits" << endl;
	cout << "3:Instructions and rules" << endl;
	cout << "4:Exit";
	while (q)
	{
		cout << endl;
		cin >> a;
		if (a == 1)
		{
			int z = 15;
			int arra[8][8] = { 0 };
			board(arra);
			while (z > 0)
			{
				system("cls");
				cout << "Moves = " << z << endl;
				display(arra);
				input(arra);
				num_match_4hori(arra);
				num_match_4verti(arra);
				num_match_3hori(arra);
				num_match_3verti(arra);
				z--;
			}
			q = 0;
		}
		else if (a == 2)
		{
			string a1;
			cout << credits(a1) << endl;
		}
		else if (a == 3)
		{

		}
		else if (a == 4)
		{
			break;
		}
	}
}
