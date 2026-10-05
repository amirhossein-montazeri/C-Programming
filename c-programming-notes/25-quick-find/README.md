# 🔗 25 · Quick-Find (union-find)

> Dynamic connectivity: are `p` and `q` connected? If not, connect them.

| | |
|---|---|
| 📄 **Source** | [`quick_find.c`](quick_find.c) |
| 📝 **From the original note** | `3.Qick.Find.txt` |
| 🏷️ **Topic** | Union-Find / connectivity |

## 📖 What it does

Every element starts in its own component (`id[i] = i`). All elements of a component share the same `id[]` value, so *find* is one comparison and *union* relabels the whole array.

## 🧠 Key concepts

- find **O(1)**, union **O(N)**
- `while (scanf("%d %d", &p, &q))` is true when at least one integer is read (and even on `EOF`, which is `-1`)
- `while (scanf("%d %d", &p, &q) == 2)` checks that exactly two integers were read — safer and more precise
- Reading from the terminal: stop with `Ctrl+D` (`Ctrl+Z` + Enter on Windows)

## ⚙️ Build & run

```bash
gcc -std=c11 -Wall -Wextra -o quick_find quick_find.c
./quick_find
```

## 🧪 Example

```bash
$ printf '3 4\n4 9\n8 0\n2 3\n5 6\n2 9\n5 9\n7 3\n4 8\n5 6\n0 2\n6 1\n' | ./quick_find
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

- The original contained many syntax errors: `i++1`, `scanf("%d %d,&p,&q)` (unterminated string), `print` instead of `printf`, a `:` instead of `;`, missing arguments and unbalanced braces.
- `pair p q not yet connected` was printed inside the relabelling loop (once per element) → printed once.
- `main()` → `int main(void)`; input range check added.

## 📌 Notes

Same sample input as the classic *Algorithms in C* connectivity example.

---
[⬅️ Back to the index](../README.md)
