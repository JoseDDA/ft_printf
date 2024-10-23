# Ft Printf

A print function.

## 1. Description

The `ft_printf` function replicates the behavior pf the standard `printf` function, handling various types of input provided by the user.

It supports multiple format specifiers such as characters, strings, integers, unsigened integers, hexadecimal values and pointers, as well as the literal percentage sign `%`.

Supported Format Specifiers: You could add a list of supported format specifiers for completeness. For example:

- %c for characters
- %s for strings
- %d and %i for integers
- %u for unsigned integer
- %x and %X for hexadecimal (lowercase and uppercase)
- %p for pointers
- %% for the percent symbol

## 2. Usage

To use `ft_printf` function in your project, follow these steps:

1. **Include All Files**: Ensure you have `ft_printf.c`, `ft_printf_utils.c`, and `ft_printf.h` are included in your project.

2. **Compile**: Compile your program with the appropriate files. Make sure use the right type of format specified (`%d %s %x`) is used based on expected output.
   To compile it use the following syntax:
   `cc -Wall -Wextra -Werror main.c ft_printf.c ft_printf.h ft_printf_utils.c -o my_program`

3. **Call the function**: Create a [main](./main.c) program, which calls `ft_printf` function with the desired format string and arguments. (Above is link to an example)
   - The function returns `-1` if an invalid input is encountered.
   - It returns the total number of characters printed, excluding the null terminator.

## 3. Functions Overview:

In addition to `ft_printf` this project consist of several helper functions that handle different task. Below is a brief description of each:

- `int	ft_printf(char const *c, ...)`

  - The main function of the project. It's a [variadic function](), which means it can accept a variable number of arguments. The function processess the input string, counts every character passed through the parameters, and returms the total number of characters written. It prints strings, numbers, and handles various format specifiers like %c, %s, %p, %d, %u, %x, and %%.
  - It uses `<stdarg.h>` library to manage the variable arguments with:
    - `va_start` :arrow_right: Initializes the `va_list` object
    - `va_arg` :arrow_right: Accesses the next argument.
    - `va_end` :arrow_right: Cleans up the `va_list`object

- `int	ft_handle_case(char c, va_list ptr)`
  - This functions identifies the format specifier and directs the argument to the appropiate handler function
  - Returns the number of characters printed by the specific handler function
- `int	ft_handle_char_str(char c, va_list ptr)`
  - Handles the `%c` (char) and `%s`(string) format specifiers
  - If `%c`, it prints a single character
  - If `%s`, it prints a string
  - Returns the number of characters printed
- `int	ft_handle_int(char c, va_list ptr)`
  - Manages the %d, %i, and %u specifiers for signed and unsigned integers.
  - Converts the integer to a string and prints it.
  - Returns the number of characters printed.
- `int	ft_handle_hexa_pointer(char c, va_list)`

  - Handles the `%p`, `%x`, and `%X` format specifiers.
  - `%x` and `%X` print integers in hexadecimal (lowercase for `%x`, uppercase for `%X`).
  - `%p` prints a pointer address in hexadecimal, prefixed with `0x` or `(nil)` if the pointer is `NULL`.
    Returns the number of characters printed.

  ### a. Other Functions

  Other functions used in these project where an adaptation of [libft](../libft/).
  Therefore, a deeper explanation of function is not needed.

  - `int	ft_puthcar_fd(char c, int fd)`
    - It write the character and returns 1.
  - `int	ft_putstr_fd(char *s, int fd)`
    - It writes the string and returns the total amount of characters.
  - `int	ft_putnbr_fd(long n, int fd)`
    - In order to read all numbers in the range from `%d`and `%i` instead of using `int n`, `int long` was used.
    - Returns the total amount of characters
  - `int	ft_putnbr_base(unsigned long n, char *base)`
    - It uses the given base to output the hexadecimal number
    - Returns the total amount of characters

## 4. Limitations

- This function is limited by the format specifiers described in [Functions Overview](#3-functions-overview).
- Although this function replicates `printf` there are no width, precision handling, or flags like `-`, `+` or 0 padding for formatting
- There is No Buffer Management, the functions writes directly to the output.
- The handling of pointers is specific for GNU/Linux.
- Due to the simple nature of this function, it only handles one invalid format. Other errors were not handle, because it wasn't needed.
