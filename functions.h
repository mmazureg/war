#ifndef FUNCTIONS_H
#define ADD_H

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int getRandomNumber(int min, int max);
int getBottomIndex(int* deck);
int getTopCard(int* deck);
void printDeck(int*, int);
void distributeDeck(int *mainDeck,int* userDeck, int* botDeck);
int *fillAndShuffle(int* deck, int n);
void zeroDeck(int* deck, int n);
int Battle(int* userDeck, int* botDeck);
int Game();

#endif
