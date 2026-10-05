# 🧮 24 · Counting sort

> Sort integers in the range `[0, K−1]` by counting occurrences.

| | |
|---|---|
| 📄 **Source** | [`counting_sort.c`](counting_sort.c) |
| 📝 **From the original note** | `12.CountingSort.txt` |
| 🏷️ **Topic** | Sorting |

## 📖 What it does

`C[v]` counts the occurrences of `v`, then becomes a running total (the final position of the last `v`); elements are placed into `B` from right to left (stable) and copied back into `A`.

## 🧠 Key concepts

- **O(N + K)** time, O(N + K) extra space
- Only for integer keys in a small known range

## ⚙️ Build & run

```bash
gcc -std=c11 -Wall -Wextra -o counting_sort counting_sort.c
./counting_sort
```

## 🧪 Example

```text
before: 4 2 2 8 3 3 1
after:  1 2 2 3 3 4 8
```

## 🛠️ Fixes applied to the original notes

Changes compared with the original text note:

- `CoutingSort` typo.
- The parameters were `K`/`C` but the body used `k`/`c` (C is case-sensitive) → consistent names.
- Added `main` (values are in `0..8`, so `K = 9`).

## 📌 Notes

Every value of `A` must be in `0..K-1`; the function does not check this.

---
[⬅️ Back to the index](../README.md)
