# ⌨️ 15 · Command-line arguments — case converter

> Converts a text file to lower or upper case, driven by `argc` / `argv`.

| | |
|---|---|
| 📄 **Source** | [`case_converter.c`](case_converter.c) |
| 📝 **From the original note** | `12.command.line.txt` |
| 🏷️ **Topic** | Command line / file I/O |

## 📖 What it does

`./case_converter <L|U> <input_name> [output_file]`

- `L` → lower case, `U` → UPPER case
- `.txt` is appended to the input name when missing
- default output file: `output.txt`

## 🧠 Key concepts

- `argc` = number of arguments, `argv[0]` = program name, `argv[1]…` = the arguments
- `argv[1]` is a **string**: its first character is `argv[1][0]`
- Two functions, `ToLower` / `ToUpper`, return the number of characters processed
- Exit codes: `1` bad usage, `2` input error, `3` output error, `5` invalid mode

## ⚙️ Build & run

```bash
gcc -std=c11 -Wall -Wextra -o case_converter case_converter.c
./case_converter U input
```

## 🧪 Example

```bash
$ ./case_converter U input
$ cat output.txt
$ ./case_converter L input lower.txt
$ cat lower.txt
$ ./case_converter X input
$ ./case_converter
```
```text
Number of characters: 76
HELLO, WORLD! C PROGRAMMING 101
THE QUICK BROWN FOX JUMPS OVER THE LAZY DOG
Number of characters: 76
hello, world! c programming 101
the quick brown fox jumps over the lazy dog
Error: invalid character (use L or U).
Usage: ./case_converter <L|U> <input_name> [output_file]
```

## 🛠️ Fixes applied to the original notes

Changes compared with the original text note:

- `char choice = argv[1]` assigned a pointer to a `char` → `argv[1][0]`.
- Prototypes `(FILE*fp_in, *fp_out)` were missing the second `FILE`; bodies used undeclared `fin` / `fout`.
- `printf(...):` (colon) and `printf("number of charcaters:", n)` without `%d`.
- `filename[10]` overflowed for any real name → 256 bytes with a length check.
- The `L`/`U` mapping of the original was inverted and its argument order ambiguous (`L fileLower fileUpper`); it is now the simple, explicit form above.
- Included a sample `input.txt`.

## 📌 Notes

Run `./case_converter` with no arguments to print the usage line.

---
[⬅️ Back to the index](../README.md)
