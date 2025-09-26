#include <stdio.h>

int display(int l, float array[])
{
    float avg = 0;
    for (int i = 0; i < l; i++)
    {
        printf("\nEnter Competitor %d time: ", i);
        scanf("%f", &array[i]);
    }
    for (int i = 0; i < l; i++)
    {
        printf("\n%d - %.2f", i, array[i]);
    }

    for (int i = 0; i < l; i++)
    {
        avg += array[i];
    }
    avg = avg/l;
    printf("\navg - %.1f", avg);
}

int main()
{
    float time[5];
    int l = sizeof(time)/sizeof(time[0]);
    display(l, time);
    
    return 0;
}
