# 🔡 14 · Count runs of identical adjacent characters

> Reads `file.txt` and writes how long each run of identical adjacent characters is.

| | |
|---|---|
| 📄 **Source** | [`count_adjacent_characters.c`](count_adjacent_characters.c) |
| 📝 **From the original note** | `11.counting.same.adjacent.characters.txt` |
| 🏷️ **Topic** | File I/O / strings |

## 📖 What it does

`aaabccdddd` → `a:3  b:1  c:2  d:4` (one pair per line in `fileWritten.txt`). Control characters such as the newline are written as `\n`.

## 🧠 Key concepts

- Comparison `==` vs assignment `=` (the original `if (ch = ch1)` always assigned)
- The **last** run must be written after the loop ends
- Exit codes: `1` cannot open input, `3` cannot open output

## ⚙️ Build & run

```bash
gcc -std=c11 -Wall -Wextra -o count_adjacent_characters count_adjacent_characters.c
./count_adjacent_characters
```

## 🧪 Example

```bash
$ ./count_adjacent_characters
$ cat fileWritten.txt
```
```text
Characters read: 11 (runs written to fileWritten.txt)
a:3
b:1
c:2
d:4
\n:1
```

## 🛠️ Fixes applied to the original notes

Changes compared with the original text note:

- `if (ch = ch1)` (assignment) → `==`.
- `fprintf(fp_in, …)` wrote to the file being read → writes to `fp_write`.
- `"%c:%d\n"` was given only one argument (the character was missing).
- The last run was never written; `numberOfCharacters` was never used.
- Characters are read as `int` to detect `EOF`; sample `file.txt` included.

---
[⬅️ Back to the index](../README.md)
