# 🌳 26 · Quick-Union (union-find)

> Union-find with trees: `id[i]` is the parent of `i`, and roots satisfy `id[i] == i`.

| | |
|---|---|
| 📄 **Source** | [`quick_union.c`](quick_union.c) |
| 📝 **From the original note** | `4.Qiuck.Union.txt` |
| 🏷️ **Topic** | Union-Find / connectivity |

## 📖 What it does

*Find* walks up to the root, *union* hooks the root of `p` under the root of `q`.

## 🧠 Key concepts

- find/union cost O(depth) — worst case **O(N)** because trees can become tall
- Two elements are connected when they have the same root

## ⚙️ Build & run

```bash
gcc -std=c11 -Wall -Wextra -o quick_union quick_union.c
./quick_union
```

## 🧪 Example

```bash
$ printf '3 4\n4 9\n8 0\n2 3\n5 6\n2 9\n5 9\n7 3\n4 8\n5 6\n0 2\n6 1\n' | ./quick_union
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

- `main()` without a return type → `int main(void)`; input range check added.
- Folder name fixed from the original `Qiuck` typo.

---
[⬅️ Back to the index](../README.md)
