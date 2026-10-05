# ➗ 02 · Greatest Common Divisor (Euclidean algorithm)

> Computes the GCD (GCF) of two non-negative integers with the Euclidean algorithm.

| | |
|---|---|
| 📄 **Source** | [`euclid_gcd.c`](euclid_gcd.c) |
| 📝 **From the original note** | `1.Euler.method.txt` |
| 🏷️ **Topic** | Algorithms / loops |

## 📖 What it does

Reads two integers, rejects invalid input, then repeats `(A, B) -> (B, A mod B)` until the remainder is `0`; the last non-zero value is the GCD.

## 🧠 Key concepts

- Euclidean algorithm — the original file was named *Euler method*, but this is Euclid's algorithm
- Exit codes: `return 0` = completed successfully, `return 1` = error / not completed
- Complexity: O(log(min(a, b)))

## ⚙️ Build & run

```bash
gcc -std=c11 -Wall -Wextra -o euclid_gcd euclid_gcd.c
./euclid_gcd
```

## 🧪 Example

```bash
$ printf '48\n18\n' | ./euclid_gcd
```
<sub>The input is piped, so the typed values do not appear in the output; in a terminal you see them as you type.</sub>

```text
Enter num1: Enter num2: The GCF of 48 and 18 is 6
```

## 🛠️ Fixes applied to the original notes

Changes compared with the original text note:

- Typo in the message (`GCF pf` → `GCF of`).
- `A % B` crashed with a division by zero when one input was `0`; now `gcd(0, n) = n` and `gcd(0, 0)` is reported as undefined.
- `scanf` return values are checked (non-numeric input no longer produces garbage).

---
[⬅️ Back to the index](../README.md)
