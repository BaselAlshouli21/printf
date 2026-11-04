*This project has been created as part of the 42 curriculum by balshoul.*

time spent: **14 days**

# ft_printf

## Description

**ft_printf** is a re-implementation of the C standard library function `printf`. The goal of the project is to learn how variadic functions work (`stdarg.h`), how a format string is parsed, and how to structure a medium-sized C program in a clean, modular way under the 42 Norm.

The function has the following prototype:

```c
int ft_printf(const char *format, ...);
```

It writes the formatted output to the standard output and returns the number of bytes written.

### Supported features

| Category | Supported |
|---|---|
| Conversions | `c` `s` `p` `d` `i` `u` `x` `X` `%` |
| Flags | `-` `0` `#` `+` (space) |
| Width | yes |
| Precision | yes (`.` followed by digits) |

Flag interactions follow the behaviour of the real `printf`. For example `-` overrides `0`, `+` overrides space, `0` is ignored when a precision is given for an integer conversion, and `#` only has an effect on non-zero `x` / `X` values.

Not handled: length modifiers (`l`, `h`, ...), the `*` width/precision, and the other conversions of the C standard library.

### Overview of the design

The code is split into a *parser* and a *renderer*, which communicate through a single `t_format` struct.

1. `ft_printf` walks through the string and copies normal characters to the output.
2. On a `%`, the **parser** (`ft_parser.c`) reads the flags, width, precision and specifier into a `t_format`, then `fix_flags` disables the flags that make no sense for that specifier.
3. The **renderer** (`ft_renderer.c`, `ft_render_specifiers.c`) fetches the next argument with `va_arg` and prints it.
4. Numbers are rendered by computing the total length of the output once (`digits + precision zeros + sign/prefix`), so that padding can be printed before or after in a single, consistent step.

| File | Role |
|---|---|
| `ft_printf.c` | Entry point and main loop |
| `ft_parser.c`, `ft_parser_utils.c` | Parsing of flags, width, precision and specifier |
| `ft_renderer.c` | Dispatch by specifier, pointer rendering |
| `ft_render_specifiers.c` | Rendering of `c`, `s`, `d`/`i`/`u`, `x`/`X` |
| `ft_render_flags.c` | Sign/prefix, precision zeros and padding |
| `ft_renderer_utils.c` | Number helpers (size, base conversion, argument fetching) |
| `ft_printf_utils.c` | Low-level output (`write_buff`) and `fix_flags` |
| `ft_printf.h` | Types, constants and prototypes |

## Instructions

### Requirements

- A C compiler (`cc`, `gcc` or `clang`)
- `make`
- The project's `libft` directory (it provides functions such as `ft_strlen`, `ft_memset` and `ft_isdigit`) located at `./libft`, since the header includes `libft/libft.h`

### Compilation

Adapt this section to your Makefile if its rules or targets are named differently.

```bash
make          # builds the library (libftprintf.a)
make clean    # removes object files
make fclean   # removes object files and the library
make re       # full rebuild
```

All files are compiled with:

```bash
cc -Wall -Wextra -Werror
```

### Usage

Include the header in your code and link against the library:

```c
#include "ft_printf.h"

int main(void)
{
    ft_printf("Hello %s, you are number %05d!\n", "world", 42);
    return (0);
}
```

```bash
cc -Wall -Wextra -Werror main.c libftprintf.a -o test
./test
```

## Design Justification

This section explains the main design choices and why they were made.

### A parser and a renderer, linked by one struct

Parsing the format string and printing the output are two different jobs, so they are two separate stages. `parse_format` fills a `t_format` and the renderers only read from it.

- **Why a struct:** every flag, the width, the precision, the specifier and the base are needed together by the renderer. Passing them as separate arguments would break the Norm's 4-parameter limit almost immediately.
- **Why `memset` + `precision_value = -1`:** `0` is a valid precision (`%.0d`, `%.s`), so it can't mean "no precision". Starting the precision at `-1` lets `precision_value >= 0` mean "a precision was given", and `memset` guarantees that no flag leaks from one conversion into the next.
- **Why `ssize_t` for the precision and `size_t` for the width:** the precision needs a sign to carry the `-1` marker, while the width is never negative. Comparisons between the two and `size_t` lengths use explicit casts (see `get_zeros` and `render_precision`) to avoid silent signed/unsigned conversions.
### Cleaning the flags once, in `fix_flags`

Real `printf` silently ignores flags that don't make sense (`%#d`, `%+u`, `%.3c`, `%-05d`). Instead of checking this in every renderer, `fix_flags` turns those flags off once, right after parsing:

| Rule | Reason |
|---|---|
| `#` kept only for `x` / `X` | it has no effect elsewhere |
| `+` and *`space`* kept only for `d` / `i` | they only apply to signed conversions |
| `+` overrides *`space`* | C standard |
| precision kept only for `d i u x X s` | undefined for the others |
| `-` or a precision cancels `0` | C standard |

After this, `render_sign`, `sign_size` and the renderers can trust the flags and don't need special cases. The only rule that depends on the argument itself is the one for `#` with a value of 0 (`%#x` with `0` prints `0`, not `0x0`), so it is handled in `render_hex`, where the value is known.

### Computing the length once

The first version of the integer renderer changed the width and the length in several places, which means **printing** *and* modifying the **length** and each place had its own idea of what "length" meant. The current design separates counting from printing:

```
total   = digits + precision zeros + sign/prefix
padding = width - total
```

- `num_size`, `get_zeros` and `sign_size` only **count**.
- `render_sign`, `render_precision`, `itoa_base` and `render_pad` only **print**.
- `render_decimal` and `render_hex` compute `total` once and never change it.
The order in which things are printed is the only thing that differs between the three branches, and it matches what the C standard describes:

| Case | Order |
|---|---|
| left-justified | sign, zeros + digits, spaces |
| right-justified with `0` | sign, zero padding, zeros + digits |
| right-justified otherwise | spaces, sign, zeros + digits |

`render_pad` works on a **local copy** of the width. Because the width is a `size_t`, decrementing the stored value could wrap around to `SIZE_MAX` and print billions of characters, which was the original `%-10.5d` bug. The same thinking applies to `render_right`, which computes `total` itself instead of receiving it as a fifth parameter, to not go over the Norm's limit of 4 parameters.

### Sharing code between conversions

`d`, `i`, `u`, `x` and `X` all go through the same chain (`num_size`, `get_zeros`, `sign_size`, `render_sign`, `render_digits`, `render_right`). The only differences are the digit set and the base, which are passed as a `const char *` (`NUMS_10`, `LOWER_16`, `UPPER_16`). `itoa_base` derives the numeric base from the length of that string, so there is a single recursive conversion routine for all of them. The recursion is bounded by the number of digits (at most 20 for a 64-bit value), so the stack use is small, and it avoids allocating a buffer and having to handle `malloc` failures.

`%p` reuses the same helpers and prints `(nil)` for a null pointer by calling `render_string`, which gives it the same padding and justification logic as a string for free.

### Handling the limits of the integer types

- **`INT_MIN`:** in `get_number`, a negative `int` is converted with `-(long long)val` instead of `-val`. Negating `INT_MIN` as an `int` overflows, while the `long long` cast makes it safe. The sign is stored in `is_neg` and the magnitude is stored as an `unsigned long`, so the digit routines only ever deal with non-negative values.
- **`%u` and `%x`:** read as `unsigned int`, as the C standard requires, so passing a negative number prints its two's complement representation, like the real function.
- **`%p`:** read as a pointer and printed as an unsigned 64-bit hexadecimal number.
- **`%.0d` and `%.0x` with `0`:** `render_decimal` and `render_hex` set the digit count to 0, so nothing is printed for the number, while the padding and sign are still handled normally.
### Output through `write_buff`

All output goes through `write_buff`, which calls `write` with the exact length it is given, and adds the number of bytes actually written to `bytes_written`.

- **Why exact lengths and not "until `\0`":** a first version stopped at the string's terminator, which made `%c` with `0` and `%.1s` with an empty string impossible to handle correctly. The caller always knows how many bytes it wants, so the function should not look at the content.
- **Why unbuffered:** printing directly keeps the return value always correct and means that no flush is needed on any exit path, including when parsing fails. The trade-off is performance, since each character is its own system call. A buffer would be faster, but would need to be flushed on every exit path and handled with care for `write` errors. Since this implementation is not performance-critical, simplicity was chosen *(and mainly because the subject forced a write and not a buffer approach)*.
### Known limitations

- Length modifiers (`l`, `h`, `ll`) and `*` for width/precision are not handled.
- An unknown conversion makes `ft_printf` stop and return `PARSE_ERROR`.
- Very large widths or precisions are not specially guarded and are limited by the range of `size_t`.


## Resources

### References

- `man 3 printf` – the reference for the behaviour of every conversion, flag, width and precision
- [a video on variadic functions](https://www.youtube.com/watch?v=7Sph8JlRo0g)
- [a video about the naive approach](https://www.youtube.com/watch?v=byRw36Y3Hjs)
- [a video on how to parse the flags](https://www.youtube.com/watch?v=kM-DOhKR080&t=2644s)

### Use of AI

- **Debugging the integer renderer** (`d`, `i`, `u`): finding the reasons behind wrong padding, wrong sign handling.
- **Reviewing edge cases**: understanding how edge cases how work with each flag.
- **Drafting this README.**

The AI-suggested code was reviewed, adapted and tested by me against the real `printf`. No part of the project was accepted without being understood first.