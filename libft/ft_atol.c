#include "libft.h"

long ft_atol(const char *str){
    int i;
    long sign;
    long result;

    i = 0;

    if(str[i] == '+' || str[i] == '-'){
        if(str[i] == '-'){
            sign = -1;
        }
        i++;
    }
    while(str[i]){
        result = result * 10 + (str[i] - '0');
        i++;
    }
    result *= sign;
    return (result);
}