#include "ft_printf.h"

int ft_putptr(void *ptr)
{
    int count = 0;

    if(!ptr)
        return ft_putstr("(nil)");
    count += ft_putstr("0x");
    count += ft_putnbr_base((unsigned long)ptr, "0123456789abcdef");
    return count;
}