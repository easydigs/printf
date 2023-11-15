#include "main.h"

/**
 * get_flags - Calculates active flags
 * @format: Formatted string in which to print the arguments
 * @i: Pointer to the current position in the format string
 * Return: Flags
 */
int get_flags(const char *format, int *i)
{
    int j, curr_i;
    int flags = 0;
    const char FLAGS_CH[] = {'-', '+', '0', '#', ' ', '\0'};
    const int FLAGS_ARR[] = {F_MINUS, F_PLUS, F_ZERO, F_HASH, F_SPACE, 0};

    // Loop through the characters in the format string after the current position
    for (curr_i = *i + 1; format[curr_i] != '\0'; curr_i++)
    {
        // Check if the current character is one of the flag characters
        for (j = 0; FLAGS_CH[j] != '\0'; j++)
        {
            if (format[curr_i] == FLAGS_CH[j])
            {
                // Set the corresponding flag in the flags variable
                flags |= FLAGS_ARR[j];
                break;
            }
        }

        // If the character is not one of the flag characters, break out of the loop
        if (FLAGS_CH[j] == '\0')
            break;
    }

    // Update the current position in the format string
    *i = curr_i - 1;

    return flags;
}
