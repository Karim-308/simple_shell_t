#include "main.h"

/**
 * _putchar - Writes a character to stdout.
 * @c: The character to write.
 * Return: On success 1, on error -1.
 */
int _putchar(char c) { return (write(STDOUT_FILENO, &c, 1)); }

/**
 * _perror - Custom puts function.
 * @n: Number of arguments.
 * Return: void.
 */
void _puts(int n, ...)
{
    va_list ap;
    int i, j, len = 0;
    char buffer[1024], *temp;

    va_start(ap, n);
    for (i = 0; i < n; i++)
    {
        temp = va_arg(ap, char *);
        j = 0;
        while (temp[j])
        {
            buffer[len + j] = temp[j];
            j++;
        }
        len += j;
    }
    /*buffer[++len] = '\0';*/
    write(STDOUT_FILENO, &buffer, len);
}
