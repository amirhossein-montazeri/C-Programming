# 🏷️ 21 · Selection sort

> Select the minimum of the unsorted part and swap it into place.

| | |
|---|---|
| 📄 **Source** | [`selection_sort.c`](selection_sort.c) |
| 📝 **From the original note** | `9.SelectionSort.txt` |
| 🏷️ **Topic** | Sorting |

## 📖 What it does

For every position `i`, find the index of the minimum in `A[i..r]` and swap it with `A[i]` when different.

## 🧠 Key concepts

- O(n²) comparisons, at most n − 1 swaps
- In place, not stable

## ⚙️ Build & run

```bash
gcc -std=c11 -Wall -Wextra -o selection_sort selection_sort.c
./selection_sort
```

## 🧪 Example

```text
before: 5 2 9 1 5 6 0
after:  0 1 2 5 5 6 9
```

## 🛠️ Fixes applied to the original notes

Changes compared with the original text note:

- The algorithm was correct; added `main`, a print helper and the includes so it compiles and runs standalone.

---
[⬅️ Back to the index](../README.md)
