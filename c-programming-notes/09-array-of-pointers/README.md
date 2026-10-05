# 🧵 09 · Arrays of pointers

> Access selected characters of strings stored in arrays of pointers (1D and 2D).

| | |
|---|---|
| 📄 **Source** | [`array_of_pointers.c`](array_of_pointers.c) |
| 📝 **From the original note** | `5.arrayOfPointers.txt` |
| 🏷️ **Topic** | Pointers / strings |

## 📖 What it does

Four examples sharing a single user input `k`: the *k*-th character of each string in a 1D array, the same for a 2D array, an array of pointers to `int` arrays, and an array of month names.

## 🧠 Key concepts

- `char *name[3]` is an array of **pointers** to strings
- `*(values[i] + j)` ≡ `values[i][j]`
- `printf("%s", months)` is wrong — the strings are `months[i]`
- `int main()` returns an exit status; `void main(void)` is non-standard

## ⚙️ Build & run

```bash
gcc -std=c11 -Wall -Wextra -o array_of_pointers array_of_pointers.c
./array_of_pointers
```

## 🧪 Example

```bash
$ printf '2\n' | ./array_of_pointers
```
<sub>The input is piped, so the typed values do not appear in the output; in a terminal you see them as you type.</sub>

```text
Enter a number: 
1) 1D array of strings:
b
r
m

2) 2D array of strings:
b
r
m
z

3) array of int pointers:
5 3 
9 6 

4) months:
Month 0 : August
Month 1 : September
```

## 🛠️ Fixes applied to the original notes

Changes compared with the original text note:

- `void main(void)` → `int main(void)`; missing `#include <string.h>` for `strlen`.
- Typos: `sizedof`, `pritnf`, `"Ausust"` → `"August"`.
- `int mat2[3] = {9, 6}` plus loops over the wrong bound; both rows now have 2 elements and the column count is explicit.
- Input is read once and validated.

---
[⬅️ Back to the index](../README.md)
