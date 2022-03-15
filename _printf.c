/*
#include "main.h"
*/
#include <stdarg.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include "main.h"

/**
 * _printf - Clone of printf function
 * @format: string with directives for printing
 */
int _printf(const char *format, ...)
{
	/*
		The _printf has two different modes
		mode = 0 writes directly to the console
		mode = 1 takes the directive and write the placeholder value
	*/
	va_list list;
	va_start(list, format);
	int i, counter_print, num;
	int mode;
	char s_chr;

	/*Initialize variables*/
	i = 0;
	counter_print = 0;
	mode = 0;

	/*Review format is not null*/
	if (format==NULL)
	{
		return(-1);
	}

	while (*format) /* While format is not null */
	{
		if (mode == 0)
		{
			if (*format == '%')
			{
				mode = 1;
			} else {
				write(1, &*format, 1);
			}
		} else if (mode == 1)
		{
			switch(*format)
			{
				case 'c':
				{
					s_chr = va_arg(list, int);
					write(1, &s_chr, 1);
					break;
				}
				case 's':
				{

					const char *s_str = va_arg(list, const char *);
					while(*s_str)
					{
						write(1, &*s_str++, 1);
					}
					break;
				}
				case 'd':
				{
					char num_buff[32];
					num = va_arg(list, int); 
					num_converter(num, 10, num_buff);
					for(int j = 0; num_buff[j]; j++)
					{
						write(1, &num_buff[j], 1);
					}
					break;
				}
				case 'i':
				{
					char num_buff[32];
					num = va_arg(list, int);
					pos_num_converter(num, 10, num_buff);
					for(int j = 0; num_buff[j]; j++)
					{
						write(1, &num_buff[j], 1);
					}
					break;
				}
				case 'b':
				{
					char num_buff[32];
					num = va_arg(list, int);
					pos_num_converter(num, 2, num_buff);
					for(int j = 0; num_buff[j]; j++)
					{
						write(1, &num_buff[j], 1);
					}
					break;
				}
				case 'x':
				{
					char num_buff[32];
					num = va_arg(list, int);
					pos_num_converter(num, 16, num_buff);
					for(int j = 0; num_buff[j]; j++)
					{
						write(1, &num_buff[j], 1);
					}
					break;
				}
				case 'o':
				{
					char num_buff[32];
					num = va_arg(list, int);
					num_converter(num, 8, num_buff);
					for(int j = 0; num_buff[j]; j++)
					{
						write(1, &num_buff[j], 1);
					}
					break;
				}
			}
			mode = 0;
		}
	format++;
	counter_print++;
	}
	va_end(list);
	return(counter_print++);

}


int main()
{
	_printf("This prints a single char: %c and %c\n", 'H', 'U');
	_printf("This prints a string: %s and %s \n", "Hello World", "TEST");
	_printf("This prints a decimal: %d succes and other number: %i\n", 1054, 20);
	_printf("This is a normal string.\n");
	_printf("This prints a negative decimal: %d \n", -10);
	_printf("This prints a number converter to binary: %b \n", 7);
	_printf("This prints a number converter to hex: %x \n", 10);
}
