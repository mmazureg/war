#define MAX_DECK_SIZE 52
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int Battle(int* userDeck, int* botDeck)
{
  int userCard = getTopCard(userDeck);
  int botCard = getTopCard(botDeck);

  if(userCard==botCard)
  {
    int unusedUserCard = getTopCard(userDeck);  //War
    int unusedBotCard = getTopCard(botDeck);

    if(Battle(userDeck,botDeck))
    {
      userDeck[getBottomIndex(userDeck)] = unusedUserCard;
      userDeck[getBottomIndex(userDeck)] = unusedBotCard;
      userDeck[getBottomIndex(userDeck)] = userCard;
      userDeck[getBottomIndex(userDeck)] = botCard;
    }

    else
    {
      botDeck[getBottomIndex(botDeck)] = unusedBotCard;
      botDeck[getBottomIndex(botDeck)] = unusedUserCard;
      botDeck[getBottomIndex(botDeck)] = botCard;
      botDeck[getBottomIndex(botDeck)] = userCard;
    }
  }

  if(userCard>botCard)
  {
    userDeck[getBottomIndex(userDeck)] = userCard;
    userDeck[getBottomIndex(userDeck)] = botCard;
    return 1;
  }

  if(userCard<botCard)
  {
    botDeck[getBottomIndex(botDeck)] = botCard;
    botDeck[getBottomIndex(botDeck)] = userCard;
    return 0;
  }

}

int getBottomIndex(int* deck)
{
    for(int i=0;i<MAX_DECK_SIZE;i++)
   {
     if(!deck[i])return i;
   }
   return -1;
}

int getTopCard(int* deck)
{  int k = deck[0];
   for(int i=0;i<(MAX_DECK_SIZE-1);i++)
   {
     deck[i]=deck[i+1];
   }
   deck[MAX_DECK_SIZE-1] = 0;

   return k;
}

void distributeDeck(int *mainDeck,int* userDeck, int* botDeck)
{
    for(int i=0; i<(MAX_DECK_SIZE/2); i++)
    {
        userDeck[i] = mainDeck[2*i];
        botDeck[i] = mainDeck[(2*i)+1];
    }
}
void zeroDeck(int* deck, int n)
{
    for(int i=0;i<n;i++)
    {
      deck[i]= 0;
    }
}
int *fillAndShuffle(int* deck, int n)
{
    int i,j,temp;

    for(int i=0;i<n;i++)
    {
      deck[i]= (int) 1+(i/4);
    }

    for(i=n-1;i>=0;i--)
    { temp=deck[i];
      j = getRandomNumber(0,n-1);
      deck[i] = deck [j];
      deck[j] = temp;
    }
    return deck;
}

void printDeck(int *deck, int n)
{
    printf("\n----------------------------------------------------------\n");
    for(int i=0;i<n;i++)
    {
      printf("%d ",deck[i]);
    }
    printf("\n----------------------------------------------------------\n");
}

int getRandomNumber(int min, int max)
{
    static const double fraction = 1.0 / (RAND_MAX + 1.0);
    return min + (int)((max - min + 1) * (rand() * fraction));
}

int Game()
{
  int tmpDeck[MAX_DECK_SIZE];
  int userDeck[MAX_DECK_SIZE], botDeck[MAX_DECK_SIZE];
  int numberOfBattles=0;

  fillAndShuffle(tmpDeck,MAX_DECK_SIZE);
  zeroDeck(userDeck,MAX_DECK_SIZE);
  zeroDeck(botDeck,MAX_DECK_SIZE);
  distributeDeck(tmpDeck,userDeck,botDeck);

  printDeck(userDeck,52);
  printDeck(botDeck,52);
  printf("\n*********GameStartsHere********\n");

  while(getBottomIndex(userDeck)!=-1 && getBottomIndex(botDeck)!=-1 && numberOfBattles<100000)
  {
     Battle(userDeck,botDeck);
     numberOfBattles++;
  }


  printf("\n*********Results********\n");
        printf("User has: %d cards", (getBottomIndex(userDeck)%52));
        printDeck(userDeck,52);
        printf("Bot has: %d cards", (getBottomIndex(botDeck)%52));
        printDeck(botDeck,52);
        printf("Number of battles: %d\n",numberOfBattles);
    return numberOfBattles;
}
