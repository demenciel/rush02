#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include "ft_atoi.c"
int check_pos(int nb)
{
    int i; 
    i = 0; 

    while (nb != 0)
    {
        nb = nb / 10;
        i++;
    }
    return(i);
}


int check_tens(int nb)
{
    int i; 
    i = 0; 

    while (nb != 0)
    {
        nb = nb / 10;
        i++;
    }
    return(i % 3 + i / 3);
}

void print_hundreds()
{
    int file; 
    int i;
    i = 0;
    char *c;
    c = (char*)malloc(1024);
    file = open("Header/numbers.dict", O_RDWR | O_CREAT);
    size_t rd = read(file, c, 1024);
    while (c[i] != '\0')
    {
        if(c[i] == 49 && c[i + 1] == 48 && c[i + 2] == 48)
        {
            while (c[i] != '\n')
            {
                if ((c[i] >= 65 && c[i] <= 90) || (c[i] >= 97 && c[i] <= 122))
                    printf("%c", c[i]);
                i++;
            }
        }
        i++;
    }
    
    close(file);
}

void print(char *ch, int pos)
{       
    int file; 
    int i;
    i = 0;
    char *c;
    c = (char*)malloc(1024);
    file = open("Header/numbers.dict", O_RDWR | O_CREAT);
    size_t rd = read(file, c, 1024); 
    if (pos == 2)
    {
        while (c[i] != ch[0])
            i++;
        while (ch[i] == 32 || ch[i] == 58)
            i++;
        while (c[i] != '\n')
        {
            if ((c[i] >= 65 && c[i] <= 90) || (c[i] >= 97 && c[i] <= 122))
                printf("%c", c[i]);
            i++;
        }
        print_hundreds();

    }
  
    close(file);
}

int main(int argc, char *argv[])
{ 
    int pos;
    pos = 2;
    int nb = ft_atoi(argv[1]);
    int times = check_tens(nb);

    while (pos >= 0)
    {
        print(&argv[1][pos], pos);
        pos--;
    }
    
    //printf("%s", c);
}   