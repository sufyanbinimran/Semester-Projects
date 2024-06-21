import tkinter as tk
from tkinter import ttk, messagebox, simpledialog
import time

class SudokuCSP:
    def __init__(self, board):
        if not all(len(row) == 9 for row in board) or len(board) != 9:
            raise ValueError("Board must be a 9x9 grid.")
        self.board = [row[:] for row in board]
        self.variables = [(i, j) for i in range(9) for j in range(9)]  # All cells are variables
        self.domains = {(i, j): list(range(1, 10)) if board[i][j] == 0 else [board[i][j]]
                        for i in range(9) for j in range(9)}
        self.neighbors = {v: self.find_neighbors(v) for v in self.variables}

    def find_neighbors(self, var):
        r, c = var
        neighbors = [(r, cc) for cc in range(9) if cc != c] + \
                    [(rr, c) for rr in range(9) if rr != r] + \
                    [(rr, cc) for rr in range((r // 3) * 3, (r // 3) * 3 + 3) for cc in
                     range((c // 3) * 3, (c // 3) * 3 + 3)
                     if (rr, cc) != var]
        return set(neighbors)

    def solve_with_backtracking(self):
        start_time = time.time()
        if self.backtrack():
            end_time = time.time()
            self.time_complexity = end_time - start_time
            return True
        return False

    def backtrack(self):
        unassigned = self.find_unassigned_location()
        if not unassigned:
            return True  # Puzzle solved
        row, col = unassigned

        for num in range(1, 10):  # Try all possible numbers
            if self.is_valid_assignment(row, col, num):
                self.board[row][col] = num
                if self.backtrack():
                    return True
                self.board[row][col] = 0  # Undo assignment (backtrack)
        return False  # Trigger backtracking
    
    def solve_with_ac3(self):
        start_time = time.time()
        if self.ac3():
            # If AC-3 prunes the domains successfully, try to solve the puzzle with backtracking
            if self.solve_with_backtracking():
                end_time = time.time()
                self.time_complexity = end_time - start_time
                return True
        else:
            # If AC-3 fails to prune the domains, return False indicating no solution
            return False

    def ac3(self):
        queue = [(xi, xj) for xi in self.variables for xj in self.neighbors[xi]]
        while queue:
            xi, xj = queue.pop(0)
            if self.revise(xi, xj):
                if not self.domains[xi]:
                    return False
                for xk in self.neighbors[xi]:
                    if xk != xj:
                        queue.append((xk, xi))
        return True
        




    def revise(self, xi, xj):
        revised = False
        domain_xi = self.domains.get(xi, [])
        domain_xj = self.domains.get(xj, [])
        for x in domain_xi[:]:
            if all(x != y for y in domain_xj) and self.check_sudoku_constraints(xi, x):
                self.domains[xi].remove(x)
                revised = True
        return revised

    def check_sudoku_constraints(self, var, value):
        row, col = var
        if any(value == self.board[row][j] for j in range(9)):
            return False
        if any(value == self.board[i][col] for i in range(9)):
            return False
        start_row, start_col = 3 * (row // 3), 3 * (col // 3)
        if any(value == self.board[i][j] for i in range(start_row, start_row + 3)
                                         for j in range(start_col, start_col + 3)):
            return False
        return True

    def find_unassigned_location(self):
        for i in range(9):
            for j in range(9):
                if self.board[i][j] == 0:
                    return i, j
        return None

    def is_valid_assignment(self, row, col, num):
        for k in range(9):
            if self.board[row][k] == num or self.board[k][col] == num:
                return False
        box_start_row, box_start_col = 3 * (row // 3), 3 * (col // 3)
        for i in range(box_start_row, box_start_row + 3):
            for j in range(box_start_col, box_start_col + 3):
                if self.board[i][j] == num:
                    return False
        return True


class SudokuGUI:
    def __init__(self, master):
        self.master = master
        master.title("Sudoku Solver")
        self.cells = {}

        # Initialize entry cells for the Sudoku grid
        for row in range(9):
            for col in range(9):
                entry = tk.Entry(master, width=3, font=('Arial', 18), borderwidth=2, justify='center')
                entry.grid(row=row, column=col, sticky='nsew', padx=1, pady=1)
                self.cells[(row, col)] = entry

        # Initialize control frame and other components after all entries are created
        self.initialize_controls()

        self.puzzles = {
            'Easy': [
                # Puzzle #1
                [
                    [0, 7, 0, 3, 5, 0, 8, 0, 0],
                    [0, 3, 8, 7, 1, 4, 0, 6, 9],
                    [6, 4, 5, 0, 0, 0, 7, 1, 3],
                    [5, 8, 0, 1, 0, 0, 4, 0, 0],
                    [0, 0, 2, 0, 0, 9, 3, 0, 7],
                    [3, 9, 0, 4, 7, 8, 2, 5, 1],
                    [9, 5, 0, 2, 4, 1, 0, 0, 0],
                    [0, 6, 0, 8, 9, 5, 1, 0, 2],
                    [8, 2, 1, 6, 3, 7, 0, 0, 5]
                ],
                # Puzzle #2
                [
                    [0, 7, 1, 0, 8, 0, 0, 3, 0],
                    [3, 0, 9, 6, 5, 7, 0, 1, 0],
                    [0, 0, 2, 0, 1, 9, 6, 8, 0],
                    [0, 6, 0, 2, 3, 5, 8, 0, 1],
                    [0, 2, 3, 0, 9, 0, 7, 5, 0],
                    [1, 0, 8, 0, 0, 6, 3, 9, 2],
                    [8, 1, 6, 0, 0, 3, 0, 2, 5],
                    [7, 3, 5, 0, 0, 4, 9, 0, 0],
                    [2, 9, 4, 5, 0, 8, 1, 7, 3]
                ],
                # Puzzle #3
                [
                    [7, 6, 1, 9, 3, 4, 0, 0, 2],
                    [5, 0, 0, 8, 2, 1, 0, 6, 0],
                    [0, 0, 2, 6, 7, 0, 0, 1, 4],
                    [0, 1, 0, 3, 0, 6, 0, 0, 0],
                    [9, 3, 0, 0, 0, 7, 0, 8, 5],
                    [0, 5, 7, 2, 8, 9, 0, 3, 0],
                    [0, 2, 9, 5, 0, 8, 4, 0, 0],
                    [0, 0, 5, 7, 9, 3, 0, 2, 6],
                    [6, 7, 3, 4, 0, 2, 0, 9, 0]
                ],
                # Puzzle #4
                [
                    [2, 7, 3, 0, 0, 0, 0, 8, 5],
                    [0, 0, 1, 8, 0, 0, 0, 7, 0],
                    [5, 0, 0, 0, 0, 0, 0, 0, 1],
                    [0, 0, 0, 0, 8, 9, 0, 4, 0],
                    [0, 0, 8, 0, 6, 5, 0, 3, 7],
                    [4, 0, 7, 0, 0, 2, 8, 5, 0],
                    [3, 5, 0, 1, 7, 0, 0, 2, 4],
                    [0, 0, 0, 0, 0, 0, 7, 1, 0],
                    [7, 0, 0, 9, 0, 3, 0, 6, 8]
                ]
            ],
             # Medium Level Puzzles...
            'Medium': [
                      # Puzzle #1
                [
                    [1, 0, 0, 0, 0, 0, 3, 5, 6],
                    [9, 0, 0, 4, 3, 5, 1, 2, 0],
                    [0, 0, 0, 1, 2, 0, 0, 0, 4],
                    [8, 2, 7, 3, 6, 0, 0, 0, 1],
                    [0, 0, 1, 0, 5, 0, 0, 6, 0],
                    [0, 3, 6, 0, 1, 9, 8, 4, 0],
                    [0, 5, 4, 2, 9, 3, 6, 0, 8],
                    [0, 0, 9, 6, 8, 7, 4, 3, 0],
                    [6, 8, 3, 5, 4, 0, 2, 7, 9]
                ],
                      # Puzzle #2
                [
                    [3, 5, 6, 0, 8, 0, 9, 0, 1],
                    [2, 0, 0, 1, 0, 3, 7, 5, 6],
                    [9, 1, 7, 0, 0, 0, 0, 0, 8],
                    [4, 8, 0, 6, 0, 0, 3, 0, 0],
                    [0, 0, 0, 8, 3, 0, 1, 0, 0],
                    [0, 3, 0, 0, 0, 2, 6, 8, 5],
                    [5, 6, 4, 0, 0, 9, 8, 1, 0],
                    [0, 0, 0, 0, 1, 0, 0, 0, 0],
                    [0, 0, 0, 4, 0, 0, 0, 0, 7]
                ],
                      # Puzzle #3
                [
                    [9, 6, 2, 0, 4, 0, 0, 7, 0],
                    [7, 0, 0, 1, 0, 0, 0, 2, 0],
                    [3, 5, 1, 8, 0, 2, 9, 6, 4],
                    [0, 0, 3, 7, 8, 4, 0, 1, 0],
                    [8, 1, 0, 0, 0, 6, 0, 0, 7],
                    [0, 0, 7, 0, 0, 5, 0, 8, 2],
                    [0, 0, 0, 9, 0, 0, 0, 4, 0],
                    [4, 0, 0, 0, 0, 0, 0, 0, 5],
                    [0, 7, 5, 0, 0, 0, 0, 0, 0]
                ],      # Puzzle #4
                [
                    [5, 0, 0, 0, 0, 0, 7, 8, 0],
                    [0, 0, 0, 8, 0, 0, 0, 1, 0],
                    [0, 3, 7, 0, 1, 0, 9, 0, 0],
                    [0, 0, 0, 1, 0, 0, 6, 0, 8],
                    [9, 8, 0, 3, 2, 6, 0, 0, 0],
                    [0, 0, 3, 0, 0, 0, 0, 9, 0],
                    [3, 0, 0, 0, 6, 4, 0, 5, 9],
                    [0, 7, 9, 2, 5, 0, 3, 4, 0],
                    [6, 0, 4, 9, 3, 0, 0, 2, 0]
                ]
               
            ],
            'Hard': [
                      # Puzzle #1
                [
                    [7, 0, 0, 0, 0, 5, 0, 0, 0],
                    [0, 0, 0, 1, 0, 4, 6, 5, 0],
                    [0, 0, 0, 0, 6, 0, 3, 0, 1],
                    [3, 0, 6, 4, 0, 0, 0, 0, 0],
                    [0, 0, 4, 8, 0, 0, 1, 0, 9],
                    [9, 0, 0, 0, 7, 0, 4, 6, 0],
                    [0, 0, 0, 0, 0, 3, 0, 0, 2],
                    [5, 0, 0, 0, 0, 0, 9, 0, 0],
                    [1, 0, 8, 0, 4, 0, 5, 0, 0]
                ],
                      # Puzzle #2
                [
                    [0, 0, 9, 0, 0, 0, 3, 0, 0],
                    [0, 0, 1, 0, 0, 4, 9, 6, 0],
                    [0, 6, 0, 0, 8, 0, 0, 0, 4],
                    [8, 0, 6, 4, 5, 3, 0, 9, 0],
                    [0, 0, 0, 0, 0, 0, 0, 8, 0],
                    [5, 0, 0, 0, 6, 0, 0, 3, 0],
                    [6, 0, 2, 0, 4, 0, 0, 0, 0],
                    [0, 1, 3, 5, 0, 0, 0, 0, 0],
                    [0, 0, 0, 0, 2, 0, 1, 0, 0]
                ],
                      # Puzzle #3
                [
                    [8, 0, 0, 0, 0, 0, 0, 0, 3],
                    [0, 0, 3, 0, 0, 4, 7, 0, 0],
                    [0, 0, 2, 0, 0, 0, 0, 0, 0],
                    [0, 0, 1, 5, 8, 0, 9, 7, 0],
                    [3, 0, 0, 0, 0, 0, 8, 5, 1],
                    [0, 0, 5, 0, 0, 0, 0, 0, 4],
                    [9, 0, 0, 0, 0, 7, 0, 0, 0],
                    [0, 0, 0, 4, 0, 6, 2, 0, 0],
                    [0, 0, 0, 8, 0, 0, 6, 4, 9]
                ],
                      # Puzzle #4
                [
                    [5, 7, 9, 0, 0, 2, 8, 0, 0],
                    [2, 0, 0, 8, 0, 0, 7, 0, 9],
                    [0, 0, 8, 0, 0, 0, 2, 6, 0],
                    [0, 0, 7, 0, 0, 0, 0, 0, 6],
                    [0, 5, 4, 0, 9, 6, 0, 0, 0],
                    [0, 1, 0, 0, 7, 0, 0, 0, 0],
                    [0, 6, 0, 7, 2, 0, 4, 0, 0],
                    [0, 0, 3, 6, 0, 0, 0, 0, 7],
                    [0, 2, 0, 4, 0, 0, 6, 0, 0]
                ]
            ]
        }


        self.current_puzzle = 0  # Start with the first puzzle by default
        self.load_puzzle(self.current_puzzle)
        self.update_gui_from_board()

    def initialize_controls(self):
        # Set up controls frame and other GUI elements
        self.controls_frame = tk.Frame(self.master)
        self.controls_frame.grid(row=0, column=9, rowspan=9, sticky='ns')

        self.level_var = tk.StringVar(value='Easy')
        ttk.Label(self.controls_frame, text="Level").grid(row=0, column=0, padx=5, pady=5)
        self.level_menu = ttk.Combobox(self.controls_frame, textvariable=self.level_var, values=['Easy', 'Medium', 'Hard'])
        self.level_menu.grid(row=1, column=0, padx=5, pady=5)

        self.algorithm_var = tk.StringVar(value='Backtracking')
        ttk.Label(self.controls_frame, text="Algorithms").grid(row=2, column=0, padx=5, pady=5)
        ttk.Radiobutton(self.controls_frame, text='Arc Consistency-3', variable=self.algorithm_var, value='AC-3').grid(row=3, column=0, padx=5, pady=5)
        ttk.Radiobutton(self.controls_frame, text='Backtracking', variable=self.algorithm_var, value='Backtracking').grid(row=4, column=0, padx=5, pady=5)

        self.puzzle_var = tk.IntVar(value=1)
        ttk.Label(self.controls_frame, text="Choose Puzzle").grid(row=5, column=0, padx=5, pady=5)
        for i in range(4):  # Assuming there are 4 puzzles
            ttk.Radiobutton(self.controls_frame, text=f'Puzzle {i+1}', variable=self.puzzle_var, value=i, command=self.change_puzzle).grid(row=6+i, column=0, padx=5, pady=5)

        ttk.Button(self.controls_frame, text="Solve", command=self.solve).grid(row=10, column=0, padx=5, pady=5)
        ttk.Button(self.controls_frame, text="Reset", command=self.reset).grid(row=11, column=0, padx=5, pady=5)

        self.status = ttk.Label(self.master, text="Load a puzzle and select a solving method.", font=('Arial', 14))
        self.status.grid(row=10, column=0, columnspan=9)

    def change_puzzle(self):
        """ Change the currently loaded puzzle based on user selection """
        index = self.puzzle_var.get()
        self.current_puzzle = index
        self.load_puzzle(self.current_puzzle)
        self.update_gui_from_board()

    def load_puzzle(self, index):
        """Load a puzzle based on the selected level."""
        level = self.level_var.get()
        self.board = self.puzzles[level][index]
        self.csp = SudokuCSP(self.board)


    def solve(self):
        """Solve the currently loaded puzzle using the selected algorithm."""
        solution_found = False
        if self.algorithm_var.get() == 'AC-3':
            if self.csp.solve_with_ac3():
                self.status['text'] = f"Puzzle solved using AC-3! Time complexity: {self.csp.time_complexity:.6f} seconds."
                solution_found = True  # Set solution_found to True here
            else:
                self.status['text'] = "AC-3 could not completely solve the puzzle."

        elif self.algorithm_var.get() == 'Backtracking':
            if self.csp.solve_with_backtracking():
                self.status['text'] = f"Puzzle solved using Backtracking! Time complexity: {self.csp.time_complexity:.6f} seconds."
                solution_found = True
            else:
                self.status['text'] = "No solution exists using Backtracking."

        if solution_found:
            self.board = [row[:] for row in self.csp.board]  # Copy the solved board to the GUI
            self.update_gui_from_board()  # Update GUI only if a solution was found

            
    def reset(self):
        """Reset the board to the initial state of the current puzzle."""
        self.load_puzzle(self.current_puzzle)
        self.update_gui_from_board()
        self.status['text'] = "Puzzle reset to initial state."

    def update_gui_from_board(self):
        # Update the GUI to reflect the current state of the board.
        for row in range(9):
            for col in range(9):
                self.cells[(row, col)].delete(0, tk.END)
                if self.board[row][col] != 0:
                    self.cells[(row, col)].insert(0, str(self.board[row][col]))


def main():
    root = tk.Tk()
    gui = SudokuGUI(root)
    root.mainloop()


if __name__ == "__main__":
    main()
