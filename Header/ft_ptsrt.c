#include <unistd.h>
void ft_ptstr(char *ch)
{
    int i;

    i = 0;
    while (ch[i] != '\0-')
    {
        write(1, &ch[i], 1);
        i++;
    }   
}