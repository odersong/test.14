#define row 3
#define col 3
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void c(char a[row][col], int q, int e);

void d(char a[row][col], int q, int e);

void playmove(char a[row][col], int q, int e);

void computermove(char a[row][col], int q, int e);

char iswin(char a[row][col], int q, int e);