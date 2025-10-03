#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "movies.h"

void display(const Movie* m)
{
    printf("\n%d - %s - %.1f", m->runTime, m->title, m->rating);
}

void displayArr(const Movie m[], int l)
{
    for (int i = 0; i < l; i++)
    {
        printf("\n%d - %s - %.1f", m[i].runTime, m[i].title, m[i].rating);
    }
}

void initialise(Movie* m)
{
    m->runTime = 12;
    strcpy(m->title, "POINTER BABYYY");
    m->rating = 0.1;
}

int getRunTime(Movie* p)
{
    return p->runTime;
}

int getSetRun(Movie* p, int n)
{
    return (p->runTime = n); 
}

void clone(Movie* m1, Movie* m2)
{
    m2->rating = m1->rating;
    m2->runTime = m1->runTime;
    strcpy(m2->title, m1->title);
}