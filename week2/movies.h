#ifndef __MOVIE_HEADER_
#define __MOVIE_HEADER_
typedef struct movie
{
    int runTime;
    char title[50];
    float rating;
} Movie;
#endif 

void display(const Movie* m);
void displayArr(const Movie m[], int l);
void initialise(Movie* m);
int getRunTime(Movie* p);
int getSetRun(Movie* p, int n);
void clone(Movie* m1, Movie* m2);

