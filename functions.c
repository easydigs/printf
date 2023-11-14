#include "custom_printf.h"

int print_char_format(va_list args, char output_buffer[], int flags, int width, int precision, int size)
{
	    char character = va_arg(args, int);

	        return (write_character(character, output_buffer, flags, width, precision, size));
}

int print_string_format(va_list args, char output_buffer[], int flags, int width, int precision, int size)
{
	    int length = 0, i;
	        char *str = va_arg(args, char *);

		    UNUSED(output_buffer);
		        UNUSED(flags);
			    UNUSED(width);
			        UNUSED(precision);
				    UNUSED(size);

				        if (str == NULL)
						    {
							            str = "(null)";
								            if (precision >= 6)
										                str = "      ";
									        }

					    while (str[length] != '\0')
						            length++;

					        if (precision >= 0 && precision < length)
							        length = precision;

						    if (width > length)
							        {
									        if (flags & F_MINUS)
											        {
													            write(1, &str[0], length);
														                for (i = width - length; i > 0; i--)
																	                write(1, " ", 1);
																            return (width);
																	            }
										        else
												        {
														            for (i = width - length; i > 0; i--)
																                    write(1, " ", 1);
															                write(1, &str[0], length);
																	            return (width);
																		            }
											    }

						        return (write(1, str, length));
}

int print_percent_format(va_list args, char output_buffer[], int flags, int width, int precision, int size)
{
	    UNUSED(args);
	        UNUSED(output_buffer);
		    UNUSED(flags);
		        UNUSED(width);
			    UNUSED(precision);
			        UNUSED(size);

				    return (write(1, "%%", 1));
}

int print_int_format(va_list args, char output_buffer[], int flags, int width, int precision, int size)
{
	    int i = BUFF_SIZE - 2;
	        int is_negative = 0;
		    long int n = va_arg(args, long int);
		        unsigned long int num;

			    n = convert_size_number(n, size);

			        if (n == 0)
					        output_buffer[i--] = '0';

				    output_buffer[BUFF_SIZE - 1] = '\0';
				        num = (unsigned long int)n;

					    if (n < 0)
						        {
								        num = (unsigned long int)((-1) * n);
									        is_negative = 1;
										    }

					        while (num > 0)
							    {
								            output_buffer[i--] = (num % 10) + '0';
									            num /= 10;
										        }

						    i++;

						        return (write_number(is_negative, i, output_buffer, flags, width, precision, size));
}

int print_binary_format(va_list args, char output_buffer[], int flags, int width, int precision, int size)
{
	    unsigned int n, m, i, sum;
	        unsigned int binary_array[32];
		    int count;

		        UNUSED(output_buffer);
			    UNUSED(flags);
			        UNUSED(width);
				    UNUSED(precision);
				        UNUSED(size);

					    n = va_arg(args, unsigned int);
					        m = 2147483648; // (2 ^ 31)
						    binary_array[0] = n / m;

						        for (i = 1; i < 32; i++)
								    {
									            m /= 2;
										            binary_array[i] = (n / m) % 2;
											        }

							    for (i = 0, sum = 0, count = 0; i < 32; i++)
								        {
										        sum += binary_array[i];
											        if (sum || i == 31)
													        {
															            char binary_digit = '0' + binary_array[i];
																                write(1, &binary_digit, 1);
																		            count++;
																			            }
												    }

							        return count;
}
