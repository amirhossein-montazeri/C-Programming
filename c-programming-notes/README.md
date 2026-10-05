# 📘 C Programming Notes

A collection of **28 small C programs** with explanations — pointers, structures, file I/O, searching, sorting, union-find and a tic-tac-toe game. Every folder contains one runnable `.c` source and a `README.md` describing the idea, how to build and run it, a real example of its output and the corrections made to the original course notes.

> ✅ All programs compile with `gcc -std=c11 -Wall -Wextra -pedantic` without warnings and were run with AddressSanitizer + UBSan.

## 🚀 Quick start

```bash
# build and run one program
cd 18-insertion-sort
gcc -std=c11 -Wall -Wextra -o insertion_sort insertion_sort.c
./insertion_sort

# build everything (binaries are named after the folder)
for d in */; do gcc -std=c11 -Wall -Wextra -o "${d%/}/prog" "${d%/}"/*.c || echo "FAILED: $d"; done
```

Requirements: any C compiler (GCC / Clang / MinGW). Some programs read input interactively or from files in their own folder, so run them **from inside their folder**.

## 📑 Index

### 🧱 Basics

| # | Program | Topic | Source |
|---|---|---|---|
| 01 | [🔁 while vs do-while](01-while-do-while/) | Control flow / loops | [`while_do_while.c`](01-while-do-while/while_do_while.c) |
| 02 | [➗ Greatest Common Divisor (Euclidean algorithm)](02-euclid-gcd/) | Algorithms / loops | [`euclid_gcd.c`](02-euclid-gcd/euclid_gcd.c) |
| 03 | [🌀 Fibonacci & Modified Fibonacci](03-fibonacci-modified/) | Algorithms / loops | [`fibonacci_modified.c`](03-fibonacci-modified/fibonacci_modified.c) |
| 04 | [🔤 Character classification with `<ctype.h>`](04-ctype-functions/) | Characters / standard library | [`ctype_functions.c`](04-ctype-functions/ctype_functions.c) |
| 05 | [🔢 atoi & atof (string → number)](05-atoi-atof/) | Strings / conversions | [`atoi_atof.c`](05-atoi-atof/atoi_atof.c) |
| 06 | [📎 Build a file name with strcat](06-filename-strcat/) | Strings | [`filename_strcat.c`](06-filename-strcat/filename_strcat.c) |

### 👉 Pointers & structures

| # | Program | Topic | Source |
|---|---|---|---|
| 07 | [👉 Pointers — basics](07-pointers-basics/) | Pointers | [`pointers_basics.c`](07-pointers-basics/pointers_basics.c) |
| 08 | [🧭 Pointers summary — arrays & arrays of pointers](08-pointers-summary/) | Pointers / arrays | [`pointers_summary.c`](08-pointers-summary/pointers_summary.c) |
| 09 | [🧵 Arrays of pointers](09-array-of-pointers/) | Pointers / strings | [`array_of_pointers.c`](09-array-of-pointers/array_of_pointers.c) |
| 10 | [🗂️ Array of structs](10-array-of-struct/) | Structures | [`array_of_struct.c`](10-array-of-struct/array_of_struct.c) |

### 💾 File I/O & command line

| # | Program | Topic | Source |
|---|---|---|---|
| 11 | [💾 File I/O basics](11-file-io-basics/) | File I/O | [`file_io_basics.c`](11-file-io-basics/file_io_basics.c) |
| 12 | [📊 Read structs from a file, sort, write](12-struct-read-sort-write/) | File I/O / structures / sorting | [`struct_read_sort_write.c`](12-struct-read-sort-write/struct_read_sort_write.c) |
| 13 | [🗜️ Run-length compression of repeated characters](13-rle-compress-decompress/) | File I/O / algorithms | [`rle_compress_decompress.c`](13-rle-compress-decompress/rle_compress_decompress.c) |
| 14 | [🔡 Count runs of identical adjacent characters](14-count-adjacent-characters/) | File I/O / strings | [`count_adjacent_characters.c`](14-count-adjacent-characters/count_adjacent_characters.c) |
| 15 | [⌨️ Command-line arguments — case converter](15-command-line-case-converter/) | Command line / file I/O | [`case_converter.c`](15-command-line-case-converter/case_converter.c) |

### 🔍 Searching

| # | Program | Topic | Source |
|---|---|---|---|
| 16 | [🔍 Linear search](16-linear-search/) | Searching | [`linear_search.c`](16-linear-search/linear_search.c) |
| 17 | [🎯 Binary search](17-binary-search/) | Searching | [`binary_search.c`](17-binary-search/binary_search.c) |

### 📈 Sorting

| # | Program | Topic | Source |
|---|---|---|---|
| 18 | [🃏 Insertion sort](18-insertion-sort/) | Sorting | [`insertion_sort.c`](18-insertion-sort/insertion_sort.c) |
| 19 | [🫧 Bubble sort](19-bubble-sort/) | Sorting | [`bubble_sort.c`](19-bubble-sort/bubble_sort.c) |
| 20 | [⚡ Optimized bubble sort](20-optimized-bubble-sort/) | Sorting | [`optimized_bubble_sort.c`](20-optimized-bubble-sort/optimized_bubble_sort.c) |
| 21 | [🏷️ Selection sort](21-selection-sort/) | Sorting | [`selection_sort.c`](21-selection-sort/selection_sort.c) |
| 22 | [🔀 2-way merge](22-two-way-merge/) | Sorting / merge | [`two_way_merge.c`](22-two-way-merge/two_way_merge.c) |
| 23 | [🏗️ Bottom-up merge sort](23-bottom-up-merge-sort/) | Sorting / merge | [`bottom_up_merge_sort.c`](23-bottom-up-merge-sort/bottom_up_merge_sort.c) |
| 24 | [🧮 Counting sort](24-counting-sort/) | Sorting | [`counting_sort.c`](24-counting-sort/counting_sort.c) |

### 🔗 Union-Find

| # | Program | Topic | Source |
|---|---|---|---|
| 25 | [🔗 Quick-Find (union-find)](25-quick-find/) | Union-Find / connectivity | [`quick_find.c`](25-quick-find/quick_find.c) |
| 26 | [🌳 Quick-Union (union-find)](26-quick-union/) | Union-Find / connectivity | [`quick_union.c`](26-quick-union/quick_union.c) |
| 27 | [⚖️ Weighted Quick-Union (union by size)](27-weighted-quick-union/) | Union-Find / connectivity | [`weighted_quick_union.c`](27-weighted-quick-union/weighted_quick_union.c) |

### 🎮 Game

| # | Program | Topic | Source |
|---|---|---|---|
| 28 | [🎮 O/X game (tic-tac-toe)](28-ox-game/) | Arrays 2D / game logic | [`ox_game.c`](28-ox-game/ox_game.c) |

## 🛠️ About the code

These programs started as plain-text course notes (`.txt`), many with typos and compile errors. While turning them into a repository:

- every program was **fixed so it compiles and behaves as the notes intended** (each README lists the fixes);
- snippets that had several `main` functions were merged into a single program per folder;
- files that were only a function got a small `main` with sample data;
- hard-coded Windows paths (`C:\Users\…`) were replaced with relative file names;
- the numbering of the original notes (which restarted per topic) was replaced by one sequence, `01`–`28`, grouped by theme.

## 📂 Repository layout

```
.
├── README.md
├── .gitignore
├── 01-while-do-while/
│   ├── while_do_while.c
│   └── README.md
├── 02-euclid-gcd/
│   ├── euclid_gcd.c
│   └── README.md
└── … (28 project folders)
```

Some folders also contain small sample input files (`file.txt`, `source.txt`, `input.txt`) so the programs can be tried immediately.

