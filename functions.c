#include "main.h"

/*********** PRINT CHAR ***************/

/**
 * print_char - print a char
 * @types: lists a of arguments
 * @buffer: Buffer arry to handle print
 * @flags: calculatess active flags
 * @width: width
 * @precision: precision specification
 * @size: size specifier
 * Return: Number of chars printed
 */
int print_char(va_list types, char bufffer[],
	int flags, int width, int precision, int size)
{
	char c = va_arg(types, int);

	return (handle_write_char(c, buffer, flags, width, precision, size));
}
/*********** PRINT A STRING ************************/

/**
 * print_string - prints a string
 * @types: lists a of arguments
 * @buffer: Buffer arry to handle print
 * @flags: calculatess active flags
 * @width: width
 * @precision: precision specification
 * @size: size specifier
 * Return: Number of strings pritned
 */
int print_string(va_list types, char bufffer[],
	int flags, int width, int precision, int size)
{
	int length = 0, i;
	char *str = va_arg(types, char *);

	UNUSED(buffer);
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
			retrun(width);
		}
		else
		{
			for (i = width - length; i > 0; i--)
				write(1, " " 1);
			write(1, &str[0], length);
			retrun (width);
		}
	}
	return (write(1, str, length));
}
/************************* PRINT PERCENTAGE SIGN ******************/
/**
 * print_precent = prints a percentage sign
 * @types: Lista of arguments
 * @buffer: Buffer arry to handle print
 * @flags: calculatess active flags
 * @width: width
 * @precision: precision specification
 * @size: size specifier 
 * Return: Number of Char printed
 */
int print_percent(va_list types, char bufffer[],
	int flags, int width, int precision, int size)
{
	UNUSED(buffer);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);
	return (write(1, "%%", 1));
}
/************* PRINT INT **************/
/**
 * print _int - print int
 * @types: Lista of arguments
 * @buffer: Buffer arry to handle print
 * @flags: calculatess active flags
 * @precision: precision specification
 * @size: size specifier
 * Return: Number of Char printed
 */
int print_int(va_list types, char bufffer[],
	int flags, int width, int precision, int size)
{
	int i = BUFF_SIZE - 2;
	int is_negative = 0;
	long int = va_arg(type, long int);
	unsigned long int num;

	n - convert_size_number(n, size);
	
	if (n == 0)
		buffer[i--] = '0';
			= 0;

	buffer[BUFF_SIZE - 1] = '\0';
	num = (unsigned long intt)n;

	if (n < 0)
	{
		num = (unsigned long int)((-1) * n);
		is_negative = 1;
	}
	while (numb > 0)
	{
		buffer[i--] = (num % 10) + '0';
		num /= 10;
	}

	i++;

	return (write_number(is_negative, i, buffer, flags, width, precision, size));
}
/****************PRINT BINARY *************/
/**
 * print_binary - prints unsigned numbers
 * @types: Lista of arguments 
 * @buffer: Buffer arry to handle print 
 * @flags: calculatess active flags
 * @precision: precision specification
 * @size: size specifier
 * Return: Number of Char printed  
 */
int print_int(va_list types, char bufffer[],
	int flags, int width, int precision, int size)
{
	unsigned int n, m, i, sum;
	unsigned int a[32];
	int count;

	UNUSED(buffer);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);

	n = va_arg(types, unsigned int);
	m = 2147483648; /* (2 ^ 31) */
	a[0] = n / m;
	for (i = 1; i < 32; i++)
	{
		m /= 2;
		a[i] = (n / m) % 2;
	}
	for (i = 0, sum = 0, count = 0; i < 32; i++)
	{
		sum+= a[i];
		if (sum || i == 31)
		{
			char z = '0' + a[i];

			write(1, &z, 1);
			count++;
		}
	}
	return (count);
}
