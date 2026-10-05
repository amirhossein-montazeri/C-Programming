# 👉 07 · Pointers — basics

> A pointer is a variable that stores the memory address of another variable.

| | |
|---|---|
| 📄 **Source** | [`pointers_basics.c`](pointers_basics.c) |
| 📝 **From the original note** | `4.pointer.txt` |
| 🏷️ **Topic** | Pointers |

## 📖 What it does

Eight small examples in one program: address & dereference, pointer subtraction, pointer + integer, writing through a pointer, swapping with pointers, `scanf` with pointers, walking a 2D array with a single pointer, and `strlen`.

## 🧠 Key concepts

- `&x` = address of `x`, `*p` = value at address `p`
- Between two pointers only subtraction is valid (inside the same array) — not `+`, `*` or `/`
- `scanf` needs the **address** of a variable: `scanf("%d", p)` ≡ `scanf("%d", &*p)`
- `int *p = *arr;` for a 2D array → `arr[i][j] == *(p + i*col + j)`
- `strlen` counts characters before `'\0'`; `sizeof` gives the buffer size

## ⚙️ Build & run

```bash
gcc -std=c11 -Wall -Wextra -o pointers_basics pointers_basics.c
./pointers_basics
```

## 🧪 Example

```bash
$ printf '7 8 9 10\n' | ./pointers_basics
```
<sub>The input is piped, so the typed values do not appear in the output; in a terminal you see them as you type.</sub>

```text
--- 1. address and dereference ---
number: 20
pointer (address of a): 0x7ffd5e3c1a24
*b - 1 = 19

--- 2. pointer subtraction ---
last - first = 3 elements

--- 3a. pointer + integer ---
*d + 1     = 44
*(d + 1)   = 23

--- 3b. write through pointer ---
arr[1] after *c = 5: 5

--- 4. swap ---
before swap -> a: 10, b: 43
after  swap -> a: 43, b: 10

--- 5. scanf with a pointer ---
Enter 4 integers: You entered: 7 8 9 10

--- 6. 2D array with a pointer ---
4 5 2 6 
65 3 12 2 
90 65 89 22 

--- 7. strlen ---
strlen(answer) = 3, sizeof(answer) = 100
```

## 🛠️ Fixes applied to the original notes

Changes compared with the original text note:

- Printing a pointer with `%d` → `%p` (cast to `void *`).
- `x* = *y` (syntax error) → `*x = *y` in the swap function.
- Example 5 used undeclared `lenArray`/`array` and `scanf("%d", arr[i])` (passes a *value*); example 5 also lacked closing braces.
- `strlen` without `<string.h>`.
- All snippets (each with its own `main`) are now functions of one program.

## 📌 Notes

The pointer address printed by example 1 changes on every run.

---
[⬅️ Back to the index](../README.md)
