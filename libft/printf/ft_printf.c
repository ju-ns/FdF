#include "ft_printf.h"

static int handle_format(char spec, va_list args)
{
    if(spec == 'c')
        return ft_putchar(va_arg(args, int));
    else if (spec == 's')
        return(ft_putstr(va_arg(args, char *)));
    else if(spec == 'd' || spec == 'i')
        return ft_putnbr(va_arg(args, int));
    else if (spec == 'u')
        return ft_putnbr_unsigned(va_arg(args, unsigned int));
    else if(spec == 'x')
        return ft_putnbr_base(va_arg(args, unsigned int), "0123456789abcdef");
    else if(spec == 'X')
        return ft_putnbr_base(va_arg(args, unsigned int), "0123456789ABCDEF");
    else if(spec == 'p')
        return ft_putptr(va_arg(args, void *));
    else if (spec == '%')
        return ft_putchar('%');
    return (0);
}

int ft_printf(const char *format, ...){
    va_list args;
    int i = 0;
    int count = 0;

    va_start(args, format);
    while(format[i])
    {
        if(format[i] == '%')
            count += handle_format(format[++i], args);
        else
            count += ft_putchar(format[i]);
        i++;
    }
    va_end(args);
    return count;
}