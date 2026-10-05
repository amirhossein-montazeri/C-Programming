# 📊 12 · Read structs from a file, sort, write

> Reads `first last gpa` records from a file, sorts them by GPA and writes a second file.

| | |
|---|---|
| 📄 **Source** | [`struct_read_sort_write.c`](struct_read_sort_write.c) |
| 📝 **From the original note** | `9.structReadSortWrite.txt` |
| 🏷️ **Topic** | File I/O / structures / sorting |

## 📖 What it does

Reads up to 100 records of `struct Master { fname, lname, gpa }` from `file.txt`, sorts them with bubble sort (ascending GPA) and writes `file2.txt`. Optional arguments change the file names.

## 🧠 Key concepts

- `fscanf` returns the number of items read — compare with `== 3`
- Passing a counter by pointer (`int *count`)
- Structs can be copied/swapped by assignment

## ⚙️ Build & run

```bash
gcc -std=c11 -Wall -Wextra -o struct_read_sort_write struct_read_sort_write.c
./struct_read_sort_write [input_file] [output_file]
```

## 🧪 Example

```bash
$ ./struct_read_sort_write
$ cat file2.txt
```
```text
4 record(s) read from file.txt, sorted by GPA, written to file2.txt
Luca Verdi 2.85
Sara Neri 3.10
Mario Rossi 3.40
Giulia Bianchi 3.90
```

## 🛠️ Fixes applied to the original notes

Changes compared with the original text note:

- Hard-coded `C:\Users\...` paths → relative file names (command-line overridable).
- A failed `fopen` only printed an error and then kept using the `NULL` pointer (crash) → now returns an error.
- `!= EOF` could loop forever on malformed lines → `== 3`; records are capped at 100 (array size).
- Included a sample `file.txt`.

---
[⬅️ Back to the index](../README.md)
