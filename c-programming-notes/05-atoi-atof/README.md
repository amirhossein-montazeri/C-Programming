# 🔢 05 · atoi & atof (string → number)

> Converting strings and single characters to numbers.

| | |
|---|---|
| 📄 **Source** | [`atoi_atof.c`](atoi_atof.c) |
| 📝 **From the original note** | `8.atoi.atof.txt` |
| 🏷️ **Topic** | Strings / conversions |

## 📖 What it does

Converts strings with `atoi` / `atof` and single digit characters with `'5' - '0'`.

## 🧠 Key concepts

- `atoi` : string → `int`, `atof` : string → floating point — both in `<stdlib.h>`
- `'5' - '0'` → `5` because the digit characters are consecutive in ASCII
- `atoi`/`atof` return `0` when nothing can be converted — they cannot report errors (`strtol` / `strtod` can)

## ⚙️ Build & run

```bash
gcc -std=c11 -Wall -Wextra -o atoi_atof atoi_atof.c
./atoi_atof
```

## 🧪 Example

```text
atoi("1234") = 1234
atof("54.12") = 54.120000
atoi("5")      = 5
atof("5.542")  = 5.542000
'5' - '0'        = 5
(float)('5'-'0') = 5.000000
atoi("abc")    = 0
```

## 🛠️ Fixes applied to the original notes

Changes compared with the original text note:

- Added the char → int / float conversions that were noted in `3.repeated.characters.txt` (with `printf` typos `pritf` and a `%d` used for a float fixed).
- `const char *` string pointers kept as in the original.

---
[⬅️ Back to the index](../README.md)
