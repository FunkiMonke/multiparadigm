#include <stdio.h>

int display(float array[])
{
    float avg = 0;
    for (int i = 0; i < 5; i++)
    {
        printf("\nEnter Competitor %d time: ", i);
        scanf("%f", &array[i]);
    }
    for (int i = 0; i < 5; i++)
    {
        printf("\n%d - %.2f", i, array[i]);
    }

    for (int i = 0; i < sizeof(array); i++)
    {
        avg += array[i];
    }
    avg = avg/sizeof(array);
    printf("%d", avg);
}

int main()
{
    float time[5];
    
    display(time);
    
    return 0;
}
