*This project has been created as part of the 42 curriculum by balshoul.*

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