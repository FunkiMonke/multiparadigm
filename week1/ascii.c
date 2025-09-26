#include <stdio.h>

int asciify(int usr)
{
    for (int i = usr-5; i < (usr + 5); i++)
    {
        printf("ha! number %d - %c\n", i, i);
    }
}

int main()
{
    int usr = 0;
    if(scanf("%d", &usr)==1 && usr>=5 && usr<=123)
    {
        asciify(usr);        
    }
    else
    {
        printf("stupid");
    }
}