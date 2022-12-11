#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include "print_functions.c"

int ft_atoi(char *str)
{
    int i;
    int result;

    i = 0;
    result = 0;

    while (str[i] >= 48 && str[i] <= 57)
    {
        result = result * 10 + str[i] - '0';
		i++;
    }
    return (result);
}

int check_pos(int len)
{
    int pos = 0;
    while (len > 1)
    {
        len--;
        pos++;
        if (pos == 3)
            pos = 0;    
        printf("Len: %d, Pos: %d \n", len, pos);
    }
    return(pos);
}


int check_tens(int len)
{
    int tens = 0;
    int i = 0;
    while (len > 1)
    {
        len--;
        i++;
        if (i == 3)
        {
            tens++;
            i = 0;
        }
    }
    return(tens);
}

int total_pos_check(int nb)
{
    int i; 
    i = 0; 

        if (nb == 0)
        return(1);

    while (nb != 0)
    {
        nb = nb / 10;
        i++;
    }
    return(i);
}


void print(char *ch, int pos)
{       
    if (pos == 0)
        print_units(&ch[0]);
    else if (pos == 1)
        print_tens(&ch[0]);
    else if (pos == 2)
        print_hundreds(&ch[0]);
}

int main(int argc, char *argv[])
{ 
    int pos;
    int i;
    pos = 2;
    char *value;

    value = argv[1];
    int nb = ft_atoi(value);

    int total_pos = total_pos_check(nb);
    pos = check_pos(total_pos);
    int tens = check_tens(total_pos);

    if (total_pos <= 3)
    {
        tens = 0;

    }

    i = 0;

    while (i < total_pos)
    {
        if (argv[1][i] == 49 && pos == 1)
        {
            print_tens_one(&argv[1][i], &argv[1][i+1]);
            i += 2;
            pos -=2;
        } 
        else if (argv[1][i] == 48 && total_pos != 1)
        {
            i++;
            pos--;
        }
        else
        {
            print(&argv[1][i], pos);
            i++;
            pos--;
        }


        if(pos < 0)
        {           
            if (tens >= 1)
            {
                if (total_pos > 6)
                {
                    if (!(argv[1][i - 2] == 48 && argv[1][i - 1] == 48 && argv[1][i] == 48))
                                    print_thousands(tens);
                } else { 
                        print_thousands(tens);

                }
             
                tens--;
            }

            pos = 2;
        }
    }
    //printfkd
} 