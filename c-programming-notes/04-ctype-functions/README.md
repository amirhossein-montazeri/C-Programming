# 🔤 04 · Character classification with `<ctype.h>`

> `isdigit`, `isalpha`, `isalnum`, `isupper`, `islower` (+ `isspace`, `ispunct`) in action.

| | |
|---|---|
| 📄 **Source** | [`ctype_functions.c`](ctype_functions.c) |
| 📝 **From the original note** | `7.ctype.h.txt` |
| 🏷️ **Topic** | Characters / standard library |

## 📖 What it does

Tests single characters with the ctype functions, prints a full classification table for a few samples and then counts digits/letters in strings, character by character.

## 🧠 Key concepts

- Each ctype function takes **one character** (single quotes), never a whole string
- Cast to `(unsigned char)` before calling them
- ctype functions cannot be used as `switch` cases — they return a truth value, not a constant

## ⚙️ Build & run

```bash
gcc -std=c11 -Wall -Wextra -o ctype_functions ctype_functions.c
./ctype_functions
```

## 🧪 Example

```text
digit
alnum
upper
lower
alpha

Full classification:
'3' -> digit alnum
'A' -> alpha alnum upper
's' -> alpha alnum lower
'?' -> punct
' ' -> space

Strings, character by character:
"32.50": 4 digit(s), 0 letter(s), 1 other
"12reis": 2 digit(s), 4 letter(s), 0 other
```

## 🛠️ Fixes applied to the original notes

Changes compared with the original text note:

- `'32.50'` and `'12reis'` are *multi-character constants*, not valid `char` values; strings are now checked one character at a time.
- Added the `unsigned char` cast and a classification table.

---
[⬅️ Back to the index](../README.md)
