# 🎮 28 · O/X game (tic-tac-toe)

> Play O against a computer that plays X on random free cells.

| | |
|---|---|
| 📄 **Source** | [`ox_game.c`](ox_game.c) |
| 📝 **From the original note** | `10.O.X.Game.txt` |
| 🏷️ **Topic** | Arrays 2D / game logic |

## 📖 What it does

You enter a row and a column (`1..3`); the computer answers with a random free cell. The game ends with a row, column or diagonal of the same symbol, or a draw when the board is full.

Optional `seed` argument makes the computer's moves repeatable: `./ox_game 42`.

## 🧠 Key concepts

- Program structure: **1.** libraries · **2.** `#define SIZE 3` · **3.** `printMatrix()`, `bool checkWinner()`, `int main()`
- 2D arrays: `char matrix[SIZE][SIZE]`, empty cell = `_`
- `srand(time(0))` + `rand() % SIZE` for the computer's move

## ⚙️ Build & run

```bash
gcc -std=c11 -Wall -Wextra -o ox_game ox_game.c
./ox_game [seed]
```

## 🧪 Example

```bash
$ printf '1 1\n1 2\n1 3\n' | ./ox_game 42
```
<sub>The input is piped, so the typed values do not appear in the output; in a terminal you see them as you type.</sub>

```text
_ _ _ 
_ _ _ 
_ _ _ 
Enter a number as row (1-3): Enter a number as column (1-3): O _ _ 
_ _ _ 
X _ _ 
Enter a number as row (1-3): Enter a number as column (1-3): O O _ 
_ X _ 
X _ _ 
Enter a number as row (1-3): Enter a number as column (1-3): O O O 
_ X _ 
X _ _ 
User wins the match after 3 hands
```

## 🛠️ Fixes applied to the original notes

Changes compared with the original text note:

- The original was an unfinished sketch: missing braces and parentheses, `0lj<SIZE`, `if checkWinner(...)` without parentheses, and `matrix[1][j]` using `j` outside its loop.
- Moves were read but **never placed on the board**, and the loop could never end → both moves are now stored, the winner is detected and a draw is handled.
- Input validation (range, occupied cells, end of input); `checkWinner` generalised to any `SIZE`.

## 📌 Notes

Winner codes: `'U'` = user (O), `'P'` = computer player (X), `'D'` = draw.

---
[⬅️ Back to the index](../README.md)
