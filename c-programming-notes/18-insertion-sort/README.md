# 🃏 18 · Insertion sort

> Insert each element into the already sorted prefix.

| | |
|---|---|
| 📄 **Source** | [`insertion_sort.c`](insertion_sort.c) |
| 📝 **From the original note** | `6.Insertion.Sort.txt` |
| 🏷️ **Topic** | Sorting |

## 📖 What it does

For each `x = A[i]` the larger elements of the sorted part are shifted one position right and `x` is inserted.

## 🧠 Key concepts

- Worst case O(n²), best case (sorted input) O(n)
- Stable and in place

## ⚙️ Build & run

```bash
gcc -std=c11 -Wall -Wextra -o insertion_sort insertion_sort.c
./insertion_sort
```

## 🧪 Example

```text
before: 5 2 9 1 5 6 0
after:  0 1 2 5 5 6 9
```

## 🛠️ Fixes applied to the original notes

Changes compared with the original text note:

- The outer loop started at `i = l - 1`, reading `A[-1]` → starts at `l + 1`.
- Added `main` and a print helper (the original was only the function).

---
[⬅️ Back to the index](../README.md)
