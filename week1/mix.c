#include <stdio.h>
int main()
{
    char name[10];
    int age;
    char type;
    printf("enter all details - name, age and bloodtype:\n");
    scanf("%s %d %c", &name, &age, &type);
    printf("%s - %d - %c", name, age, type);
}
