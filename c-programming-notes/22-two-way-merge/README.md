# 🔀 22 · 2-way merge

> Merge two sorted sub-arrays `A[l..q]` and `A[q+1..r]` using an auxiliary array `B`.

| | |
|---|---|
| 📄 **Source** | [`two_way_merge.c`](two_way_merge.c) |
| 📝 **From the original note** | `11.2.way.merge.sort.txt` |
| 🏷️ **Topic** | Sorting / merge |

## 📖 What it does

Core routine of every merge sort: repeatedly takes the smaller head element from the two halves, then copies the result back into `A`.

## 🧠 Key concepts

- O(r − l + 1) time, auxiliary array of the same size
- Using `<=` on equal elements keeps the merge stable

## ⚙️ Build & run

```bash
gcc -std=c11 -Wall -Wextra -o two_way_merge two_way_merge.c
./two_way_merge
```

## 🧪 Example

```text
before: 2 5 8 11 1 3 4 9 10
after:  1 2 3 4 5 8 9 10 11
```

## 🛠️ Fixes applied to the original notes

Changes compared with the original text note:

- The last `else` copied `A[i++]` instead of `A[j++]` (the right half was never consumed).
- The copy-back loop was *inside* the merge loop and used `for (l = l; …)` → moved after it.
- `else if (A[i] < A[j]) || (A[i] == A[j])` had unbalanced parentheses → `A[i] <= A[j]`; a closing brace was missing.
- Added `main` merging two sorted halves.

---
[⬅️ Back to the index](../README.md)
