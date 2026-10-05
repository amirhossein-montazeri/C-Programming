# ⚖️ 27 · Weighted Quick-Union (union by size)

> Quick-Union optimisation: always attach the smaller tree under the larger one.

| | |
|---|---|
| 📄 **Source** | [`weighted_quick_union.c`](weighted_quick_union.c) |
| 📝 **From the original note** | `5.Qick.Union.Uptimization.txt` |
| 🏷️ **Topic** | Union-Find / connectivity |

## 📖 What it does

`sz[i]` stores the number of elements of the tree rooted at `i`. Keeping the trees balanced bounds their depth by log₂ N.

## 🧠 Key concepts

- find/union **O(log N)**
- `sz[]` is updated when two trees are joined

## ⚙️ Build & run

```bash
gcc -std=c11 -Wall -Wextra -o weighted_quick_union weighted_quick_union.c
./weighted_quick_union
```

## 🧪 Example

```bash
$ printf '3 4\n4 9\n8 0\n2 3\n5 6\n2 9\n5 9\n7 3\n4 8\n5 6\n0 2\n6 1\n' | ./weighted_quick_union
```
<sub>The input is piped, so the typed values do not appear in the output; in a terminal you see them as you type.</sub>

```text
Input pair p q: pair 3 4 not yet connected
Input pair p q: pair 4 9 not yet connected
Input pair p q: pair 8 0 not yet connected
Input pair p q: pair 2 3 not yet connected
Input pair p q: pair 5 6 not yet connected
Input pair p q: pair 2 9 already connected
Input pair p q: pair 5 9 not yet connected
Input pair p q: pair 7 3 not yet connected
Input pair p q: pair 4 8 not yet connected
Input pair p q: pair 5 6 already connected
Input pair p q: pair 0 2 already connected
Input pair p q: pair 6 1 not yet connected
Input pair p q: 
```

## 🛠️ Fixes applied to the original notes

Changes compared with the original text note:

- The original was a fragment (`...`); it is now a complete, compilable program with the same logic.

---
[⬅️ Back to the index](../README.md)
