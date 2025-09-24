#include <stdio.h>

int calcTable(int t, int l, int b)
{
    
    if(b>l)
    {
        return 0;
    }
    int y = b*t;
    printf("%d x %d = %d\n", t, b, y);
    b++;
    calcTable(t,l,b);
    return 0; 

}


int main()
{
    int table;
    int limit;
    printf("Enter times table: ");
    scanf("%d", &table);
    printf("enter limit: ");
    scanf("%d", &limit);
    calcTable(table, limit, 1);
}