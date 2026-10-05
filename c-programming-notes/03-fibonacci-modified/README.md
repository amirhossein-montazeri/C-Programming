# 🌀 03 · Fibonacci & Modified Fibonacci

> Prints N terms of the Fibonacci sequence and of a multiplicative variant.

| | |
|---|---|
| 📄 **Source** | [`fibonacci_modified.c`](fibonacci_modified.c) |
| 📝 **From the original note** | `2.Fibonacci.Modified.txt` |
| 🏷️ **Topic** | Algorithms / loops |

## 📖 What it does

Two sliding-window sequences:

| Sequence | Rule | Start | Example (N = 4) |
|---|---|---|---|
| Fibonacci | `x2 = x1 + x0` | `0, 1` | `0 1 1 2` |
| Modified | `x2 = x1 * x0` | `1, 2` | `1 2 2 4` |

## 🧠 Key concepts

- Sliding window: `x0, x1, x2` → `x0 ← x1`, `x1 ← x2`
- `unsigned long long` + `%llu` for large values

## ⚙️ Build & run

```bash
gcc -std=c11 -Wall -Wextra -o fibonacci_modified fibonacci_modified.c
./fibonacci_modified
```

## 🧪 Example

```bash
$ printf '10\n' | ./fibonacci_modified
```
<sub>The input is piped, so the typed values do not appear in the output; in a terminal you see them as you type.</sub>

```text
Enter a number: The Fibonacci sequence (10 terms):
0 1 1 2 3 5 8 13 21 34 
The modified sequence (10 terms):
1 2 2 4 8 32 256 8192 2097152 17179869184 
```

## 🛠️ Fixes applied to the original notes

Changes compared with the original text note:

- The original loop ran `N-2` times and never printed the first two terms; now exactly **N** terms are printed, matching the comments (`0,1,1,2` and `1,2,2,4`).
- `%d` was used with `unsigned` values; now `%llu`.
- Output is limited (93 terms for Fibonacci, 11 for the modified sequence) to avoid silent 64-bit overflow — the modified sequence grows like 2^Fibonacci(n).
- Added labels and line breaks between the two sequences.

---
[⬅️ Back to the index](../README.md)
