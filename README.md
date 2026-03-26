# ft_printf — Custom printf Implementation

> **42KL Core — Module 1**

A complete re-implementation of the C standard library `printf` function, built without using `printf` itself. Handles the most common conversion specifiers and formatting flags, returning the total number of characters written.

---

## 📁 Project Structure

```
m1/ft_printf/
├── include/
│   └── ft_printf.h      # Function prototypes, t_flags struct
├── src/
│   ├── ft_printf.c      # Entry point — format string parser
│   ├── ft_flags.c       # Flag parsing and dispatcher
│   ├── ft_flags_cs.c    # Handlers for %c and %s
│   ├── ft_flags_di.c    # Handler for %d / %i
│   ├── ft_flags_u.c     # Handler for %u
│   ├── ft_flags_p.c     # Handler for %p
│   ├── ft_flags_x.c     # Handler for %x / %X
│   └── ft_bs_esc.c      # Backslash / escape character handler
├── libft/               # Bundled libft dependency
├── Makefile
└── main*.c              # Manual test files per specifier
```

---

## ✅ Supported Conversion Specifiers

| Specifier | Output |
|---|---|
| `%c` | Single character |
| `%s` | Null-terminated string (`(null)` for NULL) |
| `%d` / `%i` | Signed decimal integer |
| `%u` | Unsigned decimal integer |
| `%x` | Unsigned hexadecimal — lowercase (`a-f`) |
| `%X` | Unsigned hexadecimal — uppercase (`A-F`) |
| `%p` | Pointer address (prefixed with `0x`) |
| `%%` | Literal `%` character |

---

## 🚩 Supported Flags

| Flag | Effect |
|---|---|
| `-` | Left-align the output within the given width |
| `0` | Pad with zeros instead of spaces |
| `#` | Prefix `0x` / `0X` for hexadecimal conversions |
| `+` | Always prepend a sign (`+` or `-`) for numeric types |
| ` ` (space) | Prepend a space for positive numbers (overridden by `+`) |
| `[width]` | Minimum field width (decimal number or `*`) |
| `.[precision]` | Precision for strings (max chars) and numbers (min digits) |
| `*` | Width or precision taken from next `va_list` argument |

Flag combinations are parsed in any order before the conversion specifier.

---

## 🔧 Data Structures

```c
typedef struct s_flags {
    int   left_align;   // '-' flag
    int   zero_pad;     // '0' flag
    int   hash_hex;     // '#' flag
    int   show_sign;    // '+' flag
    int   space;        // ' ' flag
    int   width;        // minimum field width
    int   precision;    // precision value (-1 = unset)
    char  specifier;    // conversion character
    char *buffer;       // formatted output buffer
} t_flags;
```

---

## 🛠️ Build

```bash
# Build ft_printf as a static library (libftprintf.a)
make

# Clean object files
make clean

# Full clean
make fclean

# Rebuild
make re
```

---

## 🚀 Usage

```c
#include "ft_printf.h"

int main(void) {
    int n = ft_printf("%-10s | %+05d | %#010x\n", "hello", 42, 255);
    ft_printf("Characters written: %d\n", n);
    return 0;
}
```

**Output:**
```
hello      | +0042 | 0x000000ff
Characters written: 40
```

```bash
gcc -Wall -Wextra -Werror main.c -L. -lftprintf -o program
```

---

## 📋 Examples

```c
// Width and left-align
ft_printf("%-10s!\n", "hi");         // "hi        !"

// Zero padding with sign
ft_printf("%+010d\n", 42);           // "+000000042"

// Hexadecimal with prefix
ft_printf("%#x | %#X\n", 255, 255);  // "0xff | 0XFF"

// Pointer
ft_printf("%p\n", (void *)0x1234);   // "0x1234"

// Precision on string
ft_printf("%.3s\n", "hello");        // "hel"
```

---

## 📝 Notes

- `ft_printf` returns the total number of characters written to stdout, identical to `printf`.
- Passing `NULL` as a `%s` argument prints the string `(null)`.
- Precision on integers sets the minimum number of digits; it overrides the `0` zero-padding flag.
- The `*` width/precision modifier reads the value from the next variadic argument as an `int`.
