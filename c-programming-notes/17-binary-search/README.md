# 🎯 17 · Binary search

> Halve the search interval at every step on a sorted array.

| | |
|---|---|
| 📄 **Source** | [`binary_search.c`](binary_search.c) |
| 📝 **From the original note** | `2.binarySearch.txt` |
| 🏷️ **Topic** | Searching |

## 📖 What it does

Let `v[N]` be a **sorted** array of N distinct elements and `k` a key; returns the index of `k` or `-1`.

## 🧠 Key concepts

- Time **O(log N)**
- Requires a sorted array

## ⚙️ Build & run

```bash
gcc -std=c11 -Wall -Wextra -o binary_search binary_search.c
./binary_search
```

## 🧪 Example

```text
array: 0 6 8 9 15 21
BinarySearch(k=9)  = 3
BinarySearch(k=21) = 5
BinarySearch(k=4)  = -1  (not found)
```

## 🛠️ Fixes applied to the original notes

Changes compared with the original text note:

- `found` was uninitialised (undefined behaviour); `m` is now initialised too.
- The test array `{6, 8, 0, 9}` was not sorted, which breaks binary search → `{0, 6, 8, 9, 15, 21}`.

---
[⬅️ Back to the index](../README.md)
