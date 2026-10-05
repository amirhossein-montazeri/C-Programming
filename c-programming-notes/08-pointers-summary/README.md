# 🧭 08 · Pointers summary — arrays & arrays of pointers

> Side-by-side summary of pointers with simple arrays and with arrays of pointers.

| | |
|---|---|
| 📄 **Source** | [`pointers_summary.c`](pointers_summary.c) |
| 📝 **From the original note** | `6.pointerSummary.txt` |
| 🏷️ **Topic** | Pointers / arrays |

## 📖 What it does

**A) Simple arrays** — A1 read a 1D array with a pointer, A2 fill a 1D array through a pointer, A3 read a 2D array with a pointer.

**B) Arrays of pointers** — B1 pick the *j*-th character of each string, B2 an array of pointers to `int` arrays, B3 print whole strings.

## 🧠 Key concepts

- Simple array → `*(p + i)` or `*(p + i*col + j)`
- Array of pointers → `*(values[i] + j)` or `names[i]`
- `&j` is the pointer (address) of `j` — that is what `scanf` needs

## ⚙️ Build & run

```bash
gcc -std=c11 -Wall -Wextra -o pointers_summary pointers_summary.c
./pointers_summary
```

## 🧪 Example

```bash
$ printf '1 2 3\n2\n' | ./pointers_summary
```
<sub>The input is piped, so the typed values do not appear in the output; in a terminal you see them as you type.</sub>

```text
A1 - 1D array read with a pointer:
23 234 12 

A2 - 1D array filled with a pointer:
Enter 3 integers: 1 2 3 

A3 - 2D array read with a pointer:
2 4 
5 0 

B1 - 1D array of pointers (characters):
Enter an integer number: n
r

B2 - array of pointers to int arrays:
4 5 
9 2 

B3 - 1D array of pointers (strings):
0.name: mahasti
1.name: hayedeh
```

## 🛠️ Fixes applied to the original notes

Changes compared with the original text note:

- `void main(void)` → `int main(void)` (standard C).
- In B2 the column count `sizeof(values[0]) / sizeof(values[0][0])` evaluates to the *pointer* size, not the row length; the row length (2) is now explicit.
- Input validation on both `scanf` calls; the six snippets are functions of one program.

## 📌 Notes

Sample input: `1 2 3` for A2 and `2` for B1 (prints the 3rd letter of *lunedi* and *martedi*).

---
[⬅️ Back to the index](../README.md)
