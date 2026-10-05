# 🗂️ 10 · Array of structs

> Declaring a struct, creating instances and iterating over an array of them.

| | |
|---|---|
| 📄 **Source** | [`array_of_struct.c`](array_of_struct.c) |
| 📝 **From the original note** | `3.arrayOfStruct.txt` |
| 🏷️ **Topic** | Structures |

## 📖 What it does

Defines `struct color { name, grade, gpa }`, builds three instances, collects them into an array and prints each one.

## 🧠 Key concepts

- `char c = 'x'` (single quotes → one character) vs `char s[20] = "..."` (double quotes → string)
- Number of elements: `sizeof(colors) / sizeof(colors[0])`

## ⚙️ Build & run

```bash
gcc -std=c11 -Wall -Wextra -o array_of_struct array_of_struct.c
./array_of_struct
```

## 🧪 Example

```text
Color name: blue, Grade: B, GPA: 2.23
Color name: green, Grade: G, GPA: 3.12
Color name: red, Grade: R, GPA: 2.90
```

## 🛠️ Fixes applied to the original notes

Changes compared with the original text note:

- The GPA was printed with the label `Grade`; now `GPA`.
- Float initialisers use the `f` suffix.

---
[⬅️ Back to the index](../README.md)
