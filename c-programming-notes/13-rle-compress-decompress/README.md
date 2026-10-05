# 🗜️ 13 · Run-length compression of repeated characters

> Compress and decompress a text file by replacing runs of repeated characters.

| | |
|---|---|
| 📄 **Source** | [`rle_compress_decompress.c`](rle_compress_decompress.c) |
| 📝 **From the original note** | `3.repeated.characters.txt` |
| 🏷️ **Topic** | File I/O / algorithms |

## 📖 What it does

A run of 3 or more identical characters becomes `c!N` where `N` is *repetitions − 1* (max 9 → runs of up to 10); shorter runs are copied unchanged.

`aaaaabbbcd` → `a!4b!2cd`

| Choice | Reads | Writes |
|---|---|---|
| `C` | `source.txt` | `compression.txt` |
| `D` | `compression.txt` | `decompression.txt` |

## 🧠 Key concepts

- Prototypes first, `main`, then function definitions: `int compress(FILE *fin, FILE *fout);`
- `compress`: `while` loop with `if … counter++` / `else … counter = 0` / `ch = ch1`
- `decompress`: `if (ch1 == '!') …` / `else …`
- Read characters into an `int` so that `EOF` is distinguishable from real data

## ⚙️ Build & run

```bash
gcc -std=c11 -Wall -Wextra -o rle_compress_decompress rle_compress_decompress.c
./rle_compress_decompress
```

## 🧪 Example

```bash
$ printf 'C\n' | ./rle_compress_decompress
$ cat compression.txt
$ printf 'D\n' | ./rle_compress_decompress
$ cat decompression.txt
```
<sub>The input is piped, so the typed values do not appear in the output; in a terminal you see them as you type.</sub>

```text
Compression(C) or Decompression(D): The number of characters written is: 20
a!4b!2cd!9dd
xxyz!2
Compression(C) or Decompression(D): The number of characters written is: 29
aaaaabbbcdddddddddddd
xxyzzz
```

## 🛠️ Fixes applied to the original notes

Changes compared with the original text note:

- `FILE *f_read, *f_com, f_dec;` — `f_dec` was not a pointer.
- `switch` fell through from `C` to `D` to `default` (missing `break`s); `decompress` was called with the wrong arguments.
- `compress` and `decompress` wrote to the **input** stream `fin` instead of `fout`.
- `&` instead of `&&`; `int` declared twice in one declaration; unterminated `"` in `fprintf`; missing closing brace in `decompress`.
- `char` replaced by `int` for `EOF` handling. Round trip verified: `decompression.txt` is identical to `source.txt`.

## 📌 Notes

**Limitation:** the source text must not contain `!`.

**Conversion notes from the original file** (also demonstrated in [`05-atoi-atof`](../05-atoi-atof)):

| Goal | Code | Result |
|---|---|---|
| `char[]` → `int` | `atoi("5")` | `5` |
| `char[]` → floating point | `atof("5.542")` | `5.542` |
| `char` → `int` | `'5' - '0'` | `5` |
| `char` → floating point | `(float)('5' - '0')` | `5.0` |

(`atoi`/`atof` need `<stdlib.h>`; the original `pritf` and `%d` for the float were typos.)

---
[⬅️ Back to the index](../README.md)
