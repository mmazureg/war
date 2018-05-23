#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "functions.h"
#define MAX_DECK_SIZE 52

int main()
{
  srand(time(0));
  int c;
  printf("HELLO\n Welcome to the War Card Game simulator. Do you want to simulate a game of War?\n");

  while (1)
  {
    printf("Press:\n (1) to simulate a game\n (2) to simulate n games\n (9) to exit the simulator\n");
    while (scanf("%d",&c)!=1)
    {
       printf("Invalid input: Press:\n(1) to simulate a game\n(2) to simulate 10 games\n(9) to exit the simulator\n");
    }
    double average=0;
    int n=0;
    switch(c)
    {
      case 1:
        Game(); break;
      case 2:
        do
        {
            printf("\nHow many games do you want to simulate?\n");
        }
        while(scanf("%d",&n)!=1 && n<0 && n>10000000);

        for(int i=0;i<n;i++)
        {
          average+=Game();
        }
        average=average/n;

        printf("\nAverage number of battles in a game: %lg\n",average);
        break;

      case 9:
        printf("\nThank you for your time!\n");
        return 0;
    }
  }
}




