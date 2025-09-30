#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct movie
{
    int runTime;
    char title[50];
    float rating;
} Movie;

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


int main()
{
    Movie m;
    printf("Enter Movie details - length, title and rating (out of 10): ");
    scanf("%d %s %f", &m.runTime, &m.title, &m.rating);
    display(&m);

    Movie* p = NULL;
    p = &m;
    printf("\naddress is %p", p);

    initialise(p);
    display(p);

    Movie movies[3];
    printf("Enter again lol\n");
    for (int i = 0; i < 3; i++)
    {
        scanf("%d %s %f", &movies[i].runTime, &movies[i].title, &movies[i].rating);
    }
    displayArr(movies, 3);
    
    Movie* r = NULL;
    r = (Movie*)malloc(sizeof(Movie));
    r->rating = 1;
    r->runTime = 20;
    strcpy(r->title, "lolfunny");
    display(r);
    free(r);

    Movie* arr = NULL;
    arr = (Movie*)malloc(sizeof(Movie)*3);
    for (int i = 0; i < 3; i++)
    {
        strcpy(arr[i].title, "movie");
        arr[i].rating = i;
        arr[i].runTime = i+10;
    }
    displayArr(arr, 3);
    free(arr);

    Movie g;
    initialise(&g);
    g.runTime = 25;
    g.rating = 25;
    printf("runTIME BAYYDEIAH - %d", getRunTime(&g));

    getSetRun(&g, 900);
    printf("runTIME BAYYDEIAH - %d", getRunTime(&g));

    Movie h;
    clone(&g,&h);
    display(&h);
}