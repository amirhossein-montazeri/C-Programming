# 📎 06 · Build a file name with strcat

> Reads a name and appends the `.txt` extension.

| | |
|---|---|
| 📄 **Source** | [`filename_strcat.c`](filename_strcat.c) |
| 📝 **From the original note** | `4. ASCII table.txt` |
| 🏷️ **Topic** | Strings |

## 📖 What it does

Reads a file name and concatenates `".txt"` with `strcat`.

## 🧠 Key concepts

- `strcat(dest, src)` appends `src` to `dest` — `dest` must have enough room
- `scanf("%45s", ...)` limits the input so the 50-byte buffer can still hold `.txt` + `'\0'`

## ⚙️ Build & run

```bash
gcc -std=c11 -Wall -Wextra -o filename_strcat filename_strcat.c
./filename_strcat
```

## 🧪 Example

```bash
$ printf 'report\n' | ./filename_strcat
```
<sub>The input is piped, so the typed values do not appear in the output; in a terminal you see them as you type.</sub>

```text
Enter the name of the file: report.txt
```

## 🛠️ Fixes applied to the original notes

Changes compared with the original text note:

- Variable declared as `fileName` but used as `filename` (compile error).
- Missing `#include <string.h>`.
- `scanf("%s")` had no length limit (buffer overflow) → `%45s`.
- Note: the original file was called *ASCII table* but its content is this file-name example, so the folder is named after the content.

---
[⬅️ Back to the index](../README.md)
