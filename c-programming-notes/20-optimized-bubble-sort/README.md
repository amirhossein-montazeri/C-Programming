# ⚡ 20 · Optimized bubble sort

> Bubble sort that stops as soon as a pass makes no swap.

| | |
|---|---|
| 📄 **Source** | [`optimized_bubble_sort.c`](optimized_bubble_sort.c) |
| 📝 **From the original note** | `8.OptBubbleSort.txt` |
| 🏷️ **Topic** | Sorting |

## 📖 What it does

A `flag` records whether a pass swapped anything; if not, the array is already sorted and the loop ends.

## 🧠 Key concepts

- Best case (already sorted) **O(n)**, worst case O(n²)

## ⚙️ Build & run

```bash
gcc -std=c11 -Wall -Wextra -o optimized_bubble_sort optimized_bubble_sort.c
./optimized_bubble_sort
```

## 🧪 Example

```text
before: 5 2 9 1 5 6 0
after:  0 1 2 5 5 6 9

sorted input: 1 2 3 4 5
after:        1 2 3 4 5
```

## 🛠️ Fixes applied to the original notes

Changes compared with the original text note:

- `flah` (declaration) vs `flag` (use) typo.
- `return;` was inside the outer loop, so the sort ended after the first pass → moved after the loops.
- Added `main` with a random and an already-sorted input.

---
[⬅️ Back to the index](../README.md)
