# Tic-Tac-Toe in C

This is a simple console-based Tic-Tac-Toe game written in C.  
It supports **two-player mode**, **best-of-3 tournament mode**, and **play vs AI**.

---

## Functions

- `Boardbox()` → Initializes and displays the empty board with cell numbers.  
- `showBoard()` → Shows the current board state with player marks.  
- `updateBoard(cells, playerSign)` → Updates the board at the given cell with the player's sign (`X` or `O`).  
- `checkWinner(sign)` → Checks if the given player has won the game.  
- `play_tictactoe()` → Handles a single match between two players. Returns the winner.  
- `rou()` → Runs a best-of-3 tournament, keeps points, and declares the tournament winner.  
- `emptyCells(cells)` → Checks if a specific cell is empty. Used by AI.  
- `aiMove(ai, player)` → Returns the AI's move using a simple strategy.  
- `play_withai()` → Plays a single match against the AI.  
- `Replay()` → Loops the game for another match in two-player mode.  
- `Replay_AI()` → Loops the game for another match against AI.  

---

## How to Play

- Compile using a C compiler (e.g., `gcc main.c -o tic-tac-toe`).  
- Run the program (`./tic-tac-toe`).  
- Follow the console instructions to place marks using numbers 1–9.

---

## Screenshots
<img width="737" height="919" alt="Screenshot 2026-01-06 191910" src="https://github.com/user-attachments/assets/cbc3e9f7-2992-4874-855a-bcbbe4de925b" />
<img width="547" height="546" alt="Screenshot 2026-01-06 192014" src="https://github.com/user-attachments/assets/4ab08873-c2fd-49bc-9fc3-b831e17484af" />

## Author
[DIP DAS](https://github.com/DIPDAS4u)
