#include "main.h"


char *buffer;
int buff_indx = 0;

int write_to_buffer(char c){
    if (buff_indx >= 1024) {
        write(1, buffer, buff_indx);
        buff_indx = 0;
    }
    buffer[buff_indx++] = c;
    return 1;
}

int	print_char(int c)
{
	//return write(1, &c, 1);
	return write_to_buffer((char)c);
}


int	print_digit(long n, int base)
{
	int		count;
	char	*symbols;

	symbols = "0123456789abcdef";
	if (n < 0)
	{
		//write(1, "-", 1);
		write_to_buffer('-');
		return print_digit(-n, base) + 1;
	}
	else if (n < base)
		return print_char(symbols[n]);
	else
	{
		count = print_digit(n / base, base);
		return count + print_digit(n % base, base);
	}
}

int	print_digit_X(long n, int base)
{
	int		count;
	char	*symbols;

	symbols = "0123456789ABCDEF";
	if (n < 0)
	{
		//write(1, "-", 1);
		write_to_buffer('-');
		return print_digit_X(-n, base) + 1;
	}
	else if (n < base)
		return print_char(symbols[n]);
	else
	{
		count = print_digit_X(n / base, base);
		return count + print_digit_X(n % base, base);
	}
}

int	print_str(char *s)
{
	int	count;

	count = 0;
	while (*s)
		//count += write(1, s++, 1);
		count += write_to_buffer(*s++);
	return count;
}

int	print_format(char specifier, va_list ap)
{
	int	count;

	count = 0;
	if (specifier == 'c')
		count = print_char(va_arg(ap, int));
	else if (specifier == 's')
		count = print_str(va_arg(ap, char *));
	else if (specifier == 'd' || specifier == 'i')
        //Note that d and i are the same but the only difference when using scanf -- When I looked up information online, I found that it said this.
		count = print_digit((long)va_arg(ap, int), 10);
    else if (specifier == 'b')
        count = print_digit((long)va_arg(ap,unsigned int),2);
    else if (specifier == 'u')
        count = print_digit((long)va_arg(ap,unsigned int),10);
    else if (specifier == 'o')
        count = print_digit((long)va_arg(ap,unsigned int),8);
    else if (specifier == 'x')
        count = print_digit((long)va_arg(ap,unsigned int),16);
    else if (specifier == 'X')
        count = print_digit_X((long)va_arg(ap,unsigned int),16);
	else
		//count += write(1, &specifier, 1);
		count += write_to_buffer(specifier);
	return count;
}


int	_printf(const char *format, ...)
{
	va_list	ap;
	int	count;
    buffer = (char *)malloc (1024 * sizeof(char));


	va_start(ap, format);
	count = 0;
	while (*format)
	{
		if (*format == '%')
			count += print_format(*++format, ap);
		else
			//count += write(STDOUT_FILENO, format, 1);
			count += write_to_buffer(*format);
		++format;
	}

	va_end(ap);

    if (buff_indx >= 0) {
        write(1, buffer, buff_indx);
        buff_indx = 0;
    }

	return count;
}
