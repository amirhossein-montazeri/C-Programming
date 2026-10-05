# 🏗️ 23 · Bottom-up merge sort

> Iterative merge sort: merge blocks of length 1, 2, 4, 8, … until the array is sorted.

| | |
|---|---|
| 📄 **Source** | [`bottom_up_merge_sort.c`](bottom_up_merge_sort.c) |
| 📝 **From the original note** | `10.bottom.up.merge.sort.txt` |
| 🏷️ **Topic** | Sorting / merge |

## 📖 What it does

For `m = 1, 2, 4, …` every pair of adjacent sorted blocks of length `m` is merged with `merge()` (included here, see [`22-two-way-merge`](../22-two-way-merge)).

## 🧠 Key concepts

- **O(n log n)** time, O(n) extra space
- No recursion

## ⚙️ Build & run

```bash
gcc -std=c11 -Wall -Wextra -o bottom_up_merge_sort bottom_up_merge_sort.c
./bottom_up_merge_sort
```

## 🧪 Example

```text
before: 38 27 43 3 9 82 10 5 1 64 7
after:  1 3 5 7 9 10 27 38 43 64 82
```

## 🛠️ Fixes applied to the original notes

Changes compared with the original text note:

- `merge(A, B, i, q, r)` merged up to the end of the whole array instead of the end of the current pair of blocks → `min(i + 2m − 1, r)`.
- The `merge` function is included so the file is self-contained; added `main`.

---
[⬅️ Back to the index](../README.md)
