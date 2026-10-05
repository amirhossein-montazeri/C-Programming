# 🔍 16 · Linear search

> Scan the array from the first element, comparing every element with the key `k`.

| | |
|---|---|
| 📄 **Source** | [`linear_search.c`](linear_search.c) |
| 📝 **From the original note** | `1.linearSearch.txt` |
| 🏷️ **Topic** | Searching |

## 📖 What it does

Two implementations: **method 1** always performs N steps (returns the *last* occurrence), **method 2** stops at the first match (at most N steps, returns the *first* occurrence). Both return `-1` when the key is absent.

## 🧠 Key concepts

- T(n) grows linearly with n → **O(n)**
- Works on unsorted arrays

## ⚙️ Build & run

```bash
gcc -std=c11 -Wall -Wextra -o linear_search linear_search.c
./linear_search
```

## 🧪 Example

```text
array: 43 12 43 20
LinearSearch1(k=43) = 2  (last occurrence)
LinearSearch2(k=43) = 0  (first occurrence)
LinearSearch1(k=99) = -1  (not found)
LinearSearch2(k=99) = -1  (not found)
```

## 🛠️ Fixes applied to the original notes

Changes compared with the original text note:

- `LinearSeach1` typo; the two programs (two `main`s) are merged.
- A comment line wrapped without `//` (`step current element and key k`) was a syntax error.

---
[⬅️ Back to the index](../README.md)
