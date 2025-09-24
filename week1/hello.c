#include <stdio.h>
#include <string.h>

float getCelsius(float iVal)
{
    return ((iVal-32)*5/9);
}

float getFarenheit(float iVal)
{
    return ((iVal+32)*9/5);
}

int main()
{
    float userval;
    int type;
    for (int i = 0; i==0;)
    {
        printf("C = 0, F = 1 - other to quit");
        if (!scanf("%d", &type)==1 || type>1 || type<0)
        {
            printf("shit");
            break;
        }

        printf("Enter value: ");
        if(!scanf("%f", &userval) == 1)
        {
            printf("invalid, enter a number");
            break;
        }
        if (type == 0)
        {
            printf("value is %.2f in Celsius\n", getCelsius(userval));
        }
        else
        {
            printf("value is %.2f in Farenheit\n", getFarenheit(userval));
        }
        
    }
    return 0;
}