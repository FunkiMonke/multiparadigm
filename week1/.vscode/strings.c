#include <stdio.h>
#include <string.h>

int main()
{
    char array[6][5];
    for (int i = 0; i < 5; i++)
    {
        printf("\nEnter colour %d: ", i);
        scanf("%s", array[i]);
        printf("%s", array[i]);
        printf("length is %d",strlen(array[i]));
        printf("\nstrcmp says %d", strcmp(array[i], "yellow"));
    }
}
