# 🔁 01 · while vs do-while

> The two loop forms side by side, including the case where they behave differently.

| | |
|---|---|
| 📄 **Source** | [`while_do_while.c`](while_do_while.c) |
| 📝 **From the original note** | `1.whileDoWhile.txt` |
| 🏷️ **Topic** | Control flow / loops |

## 📖 What it does

Prints `0..4` with a `while` loop and `0..3` with a `do-while` loop, then shows what happens when the condition is false from the start.

## 🧠 Key concepts

- `while` tests the condition **before** each iteration (may run 0 times)
- `do-while` tests it **after** each iteration (always runs at least once)

## ⚙️ Build & run

```bash
gcc -std=c11 -Wall -Wextra -o while_do_while while_do_while.c
./while_do_while
```

## 🧪 Example

```text
while loop (i < 5):
0
1
2
3
4

do-while loop (i < 4):
0
1
2
3

while with a false condition (n < 5):
(body skipped)

do-while with a false condition (n < 5):
n = 10 (printed once)
```

## 🛠️ Fixes applied to the original notes

Changes compared with the original text note:

- The two original snippets each had their own `main`; they are merged into a single runnable program.
- Added the *false-condition* demo that makes the difference between the loops visible.

---
[⬅️ Back to the index](../README.md)
