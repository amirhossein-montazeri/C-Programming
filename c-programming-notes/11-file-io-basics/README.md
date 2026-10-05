# 💾 11 · File I/O basics

> Reading and writing integers, strings and characters with the standard file functions.

| | |
|---|---|
| 📄 **Source** | [`file_io_basics.c`](file_io_basics.c) |
| 📝 **From the original note** | `2.fileIO.txt` |
| 🏷️ **Topic** | File I/O |

## 📖 What it does

Five operations as functions — write a number (`"w"`), append a string (`"a"`), read an integer, a string and a character — executed in sequence on `file.txt` (`2` → `2EEE`).

## 🧠 Key concepts

- Writing: `fprintf(fptr, "%s", string)`, `fputs(string, fptr)`, `putc(c, fptr)`
- Reading: `fscanf(fptr, "%d", &n)`, `fgets(string, size, fptr)`, `getc(fptr)`
- Modes: `"r"` read · `"w"` write (truncates) · `"a"` append
- Always check `fopen` for `NULL`; `fclose` each file exactly once

## ⚙️ Build & run

```bash
gcc -std=c11 -Wall -Wextra -o file_io_basics file_io_basics.c
./file_io_basics
```

## 🧪 Example

```bash
$ ./file_io_basics
$ cat file.txt
```
```text
integer read: 2
string read: 2EEE
character read: 2
2EEE
```

## 🛠️ Fixes applied to the original notes

Changes compared with the original text note:

- `fclose(fw)` was called on a variable that did not exist in snippets 1 and 2, and files were closed twice in snippets 1-3.
- Hard-coded Windows paths (`C:\Users\...\Desktop\file.txt`) → relative `file.txt`, so the code runs on any machine.
- `getc` result stored in an `int` so `EOF` can be detected.

## 📌 Notes

The program creates `file.txt` in the current directory (it is git-ignored).

---
[⬅️ Back to the index](../README.md)
