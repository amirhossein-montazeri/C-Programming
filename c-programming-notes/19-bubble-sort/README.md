# 🫧 19 · Bubble sort

> Repeatedly swap adjacent elements that are out of order.

| | |
|---|---|
| 📄 **Source** | [`bubble_sort.c`](bubble_sort.c) |
| 📝 **From the original note** | `7.BubbleSort.txt` |
| 🏷️ **Topic** | Sorting |

## 📖 What it does

After pass `i`, the `i` largest elements are in their final positions.

## 🧠 Key concepts

- Always O(n²) comparisons
- Stable and in place

## ⚙️ Build & run

```bash
gcc -std=c11 -Wall -Wextra -o bubble_sort bubble_sort.c
./bubble_sort
```

## 🧪 Example

```text
before: 5 2 9 1 5 6 0
after:  0 1 2 5 5 6 9
```

## 🛠️ Fixes applied to the original notes

Changes compared with the original text note:

- The expression `r – i + l` used a typographic en-dash `–` (compile error) → `-`.
- Added `main` and a print helper.

---
[⬅️ Back to the index](../README.md)
