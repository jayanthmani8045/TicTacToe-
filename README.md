# TicTacToe Console Game

A simple two-player TicTacToe game implemented in C++ that runs in the terminal. Players take turns choosing slots 1–9 to place their markers (‘x’ or ‘o’) until one wins or all slots are filled.

---

## Table of Contents

* [Features](#features)
* [Prerequisites](#prerequisites)
* [Compilation](#compilation)
* [Usage](#usage)
* [How It Works](#how-it-works)
* [Code Overview](#code-overview)
* [Contributing](#contributing)
* [License](#license)

---

## Features

* **Two-player** turn-based gameplay
* **Input validation** for slot selection
* **Win detection** across rows, columns, and diagonals
* **Simple ASCII board** display
* **Clean exit** when a winner is found

---

## Prerequisites

* A C++ compiler supporting C++11 or later (e.g., `g++`, `clang++`)
* A terminal or console window

---

## Compilation

1. Clone or download the repository.
2. Open a terminal in the project directory.
3. Run:

   ```bash
   g++ -std=c++11 -o tictactoe TicTacToe.cpp
   ```

   This produces an executable named `tictactoe`.

---

## Usage

In your terminal, run:

```bash
./tictactoe
```

* The board is displayed with slots numbered 1–9.
* Players alternate turns: ‘x’ goes first.
* Enter the slot number where you want to place your marker.
* The game ends when one player wins or all slots are filled.

---

## How It Works

1. **Board Representation**
   A 3×3 `char` array holds slot labels or markers.

2. **Drawing the Board**
   `drawboard()` prints the current board state with ASCII art.

3. **Placing Markers**
   `placemarker(int s)` converts the slot number to array indices and toggles the turn between ‘x’ and ‘o’.

4. **Win Detection**
   `winnerfn()` checks rows, columns, and diagonals for three identical markers.

5. **Game Loop**

   * Up to 9 turns (`for` loop).
   * Prompt user for input and validate (digit, range 1–9).
   * Place marker and check for a winner.
   * Exit early if a winner is found.

---

## Code Overview

```cpp
#include <iostream>
using namespace std;

// Global variables
char board[3][3] = {{'1','2','3'},{'4','5','6'},{'7','8','9'}};
char slot, turn = 'x', winner;

// Draws the current board
void drawboard();

// Places the current player's marker
void placemarker(int s);

// Checks for and returns the winner ('x' or 'o'), or ' ' if none
char winnerfn();

int main() {
    int s;
    for (int i = 0; i < 9; i++) {
        drawboard();
        cout << "Choose a slot for " << turn << ": ";
        cin >> slot;
        if (!isdigit(slot)) { --i; continue; }

        s = slot - '0';
        if (s < 1 || s > 9) {
            cout << "\nInvalid slot. Try again.\n";
            --i; continue;
        }

        placemarker(s);
        winner = winnerfn();
        if (winner != ' ') {
            cout << "Congrats: The winner is " << winner << "!\n";
            return 0;
        }
    }
    cout << "It's a draw!\n";
    return 0;
}
```

---
