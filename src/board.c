#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include "board.h"


int flag = 1;

void printboard(char place[][8])
{
    int i,j;
    for (i = 0; i<8; i++)
    {
        printf("%d ",i+1);
        for (j = 0; j < 8; j++)
        {
           printf("%c ", place[i][j]);
        }
        printf("\n");
    }
    printf("  A B C D E F G H\n");
}

void board(char place[][8])
{
    int i, j;
    place[0][0] = 'R';
    place[0][1] = 'N'; 
    place[0][2] = 'B';
    place[0][3] = 'Q'; 
    place[0][4] = 'K'; 
    place[0][5] = 'B';
    place[0][6] = 'N'; 
    place[0][7] = 'R';
    place[7][0] = 'r';
    place[7][1] = 'n'; 
    place[7][2] = 'b';
    place[7][3] = 'q'; 
    place[7][4] = 'k'; 
    place[7][5] = 'b';
    place[7][6] = 'n'; 
    place[7][7] = 'r';
    for (i = 0; i<8; i++)
       {
             place[1][i] = 'P';
             place[6][i] = 'p';
       }
    for (j = 2; j < 6; j++)
    {
        for (i = 0; i<8; i++)
        place[j][i] = ' ';
    }
}

int CheckInMove(char Move[], char place[][8])
{
     int c1 = (int)(Move[0]) - 65;
     int c2 = (int)(Move[3]) - 65;
     int n1 = (int)(Move[1]) - 49;
     int n2 = (int)(Move[4]) - 49;
     char figure = place[n1][c1];
     char EmptySpace = place[n2][c2];
     switch(figure)
     {
        case 'p': if (n1 == 6)
             { if ((((n1 - n2) < 3) && ((n1 - n2) > 0)) &&  flag == 0 && c1 == c2
             && CheckWay(Move, place) && EmptySpace == ' ') return 1;}
             if ((place[n2][c2]!=' ') && (((c1+1==c2) || (c1-1==c2))
             && (n1-1==n2)) &&  flag == 0 && CheckEnemy(Move,place)) return 1;
             if ((((n1 - n2) < 2) && ((n1 - n2) > 0)) &&  flag == 0 && c1 == c2
             && CheckWay(Move, place) && EmptySpace == ' ') return 1;
             else goto M;
        case 'P': if (n1 == 1)
             { if ((((n2 - n1) < 3) && ((n2 - n1) > 0)) && flag == 1 && c1 == c2
             && CheckWay(Move, place) && EmptySpace == ' ') return 1;}
             if ((place[n2][c2]!=' ') && (((c1+1==c2) || (c1-1==c2))
             && (n1+1==n2)) && flag == 1 && CheckEnemy(Move,place)) return 1;
             if ((((n2 - n1) < 2 )&& ((n2 - n1) > 0)) && flag == 1 && c1 == c2
             && CheckWay(Move, place) && EmptySpace == ' ') return 1;
             else goto M;
        case 'r': if (CheckWay(Move, place) && CheckEnemy(Move,place)
             && ((c1 == c2) || (n1 == n2)) &&  flag == 0) return 1;
             else goto M;
        case 'R': if (CheckWay(Move, place) && CheckEnemy(Move, place)
             && ((c1 == c2) || (n1 == n2)) &&  flag == 1) return 1;
             else goto M;
        case 'b': if (CheckWay(Move, place) && CheckEnemy(Move, place)
             && (abs(n1 - n2) == abs(c1 - c2)) &&  flag == 0) return 1;
             else goto M;
        case 'B': if (CheckWay(Move, place) && CheckEnemy(Move, place)
             && (abs(n1 - n2) == abs(c1 - c2)) &&  flag == 1) return 1;
             else goto M;
        case 'q': if (CheckWay(Move, place) && CheckEnemy(Move, place)
             && ((abs(n1 - n2) == abs(c1 - c2)) || (c2 == c1)
             || (n2 == n1)) &&  flag == 0) return 1;
             else goto M;
        case 'Q': if (CheckWay(Move, place) && CheckEnemy(Move, place)
             && ((abs(n1 - n2) == abs(c1 - c2)) || (c2 == c1)
             || (n2 == n1)) &&  flag == 1) return 1;
             else goto M;
        case 'n': if (CheckEnemy(Move,place) && flag == 0 
             && (abs(c1 - c2) + abs(n1 - n2) == 3) && (c1 != c2) && (n1 != n2))
             return 1;
             else goto M;
        case 'N': if (CheckEnemy(Move,place) && flag == 1 
             && (abs(c1 - c2) + abs(n1 - n2) == 3) && (c1 != c2) && (n1 != n2))
             return 1;
             else goto M;
        case 'k': if ((n1 == 7) && ((c2 - c1) == 2) && (place[n1][c1+3] == 'r') && CheckWay(Move, place) && EmptySpace == ' ')
             {

                   place[n1][c1+1] = 'r';
                   place[n1][c1+3] = ' ';
                   return 1;
             };
                  if ((n1 == 7) && ((c1 - c2) == 2) && (place[n1][c1-3] == 'r') && CheckWay(Move, place) && EmptySpace == ' ')
             {
                   place[n1][c1-1] = 'r';
                   place[n1][c1-3] = ' ';
                   return 1;
             };
             if (CheckEnemy(Move,place) && flag == 0 
             && (abs(c1 - c2)<2) && (abs(n1 - n2)<2)) return 1;
             else goto M;
        case 'K': if ((n1 == 0) && ((c2 - c1) == 2) && (place[n1][c1+3] == 'R') && CheckWay(Move, place) && EmptySpace == ' ')
             {
                   place[n1][c1+1] = 'R';
                   place[n1][c1+3] = ' ';
                   return 1;
             };
                  if ((n1 == 0) && ((c1 - c2) == 2) && (place[n1][c1-3] == 'R') && CheckWay(Move, place) && EmptySpace == ' ')
            {
                   place[n1][c1-1] = 'R';
                   place[n1][c1-3] = ' ';
                   return 1;
            };
             if (CheckEnemy(Move,place) && flag == 1 
             && (abs(c1 - c2)<2) && (abs(n1 - n2)<2)) return 1;
             else goto M;
             M:
        default: return 0;
     }
}

int CheckEnemy(char Move[], char place[][8])
{
   int n2 = (int)(Move[4]) - 49;
   int c2 = (int)(Move[3]) - 65;
   if (flag == 1)
   {
       if (place[n2][c2]=='p' || place[n2][c2]=='r' || place[n2][c2]=='n'
       || place[n2][c2]=='b' || place[n2][c2]=='q' || place[n2][c2]=='k'
       || place[n2][c2]==' ')
       return 1;
       else
       return 0;
   }
   else
   {
      if (place[n2][c2]=='P' || place[n2][c2]=='R' || place[n2][c2]=='N'
      || place[n2][c2]=='B' || place[n2][c2]=='Q' || place[n2][c2]=='K'
      || place[n2][c2]==' ')
      return 1;
      else
      return 0;
   }
}

int CheckKing(char place[][8])
{
   int i, j, KingW = 0, KingB = 0;
   for (i = 0; i < 8; i++)
   {
      for (j = 0; j < 8; j++)
      {
      if (place[i][j] == 'K') KingW = 1;
      if (place[i][j] == 'k') KingB = 1;
      }
   }
   if ((KingW == 1) && (KingB == 1))
   return 1;
   return 0;
}

int CheckWay(char Move[], char place[][8])
{
    int i;
    int c1 = (int)(Move[0]) - 65;
    int c2 = (int)(Move[3]) - 65;
    int n1 = (int)(Move[1]) - 49;
    int n2 = (int)(Move[4]) - 49;
    if ((c2 - c1) == (n2 - n1))
    {
       for(i = 1; i < (c2-c1); i++)
       {
          if (place[n1+i][c1+i]!=' ')
          return 0;
       }
    }
    if ((c1 - c2) == (n2 - n1))
    {
       for(i = 1; i < (n2-n1); i++)
       {
          if (place[n1+i][c1-i]!=' ')
          return 0;
       }
    }
    if ((c2 - c1) == (n1 - n2))
    {
       for(i = 1; i < (c2-c1); i++)
       {
          if (place[n1-i][c1+i]!=' ')
          return 0;
       }
    }
    if ((c1 - c2) == (n1 - n2))
    {
       for(i = 1; i < (c1-c2); i++)
       {
          if (place[n1-i][c1-i]!=' ')
          return 0;
       }
    }
    if (c1 == c2)
    {
       if (n1 < n2)
       {
          for(i = 1; i < (n2-n1); i++)
          {
             if (place[n1+i][c1]!=' ')
             return 0;
          }
       }
       else
       {
          for(i = 1; i < (n1-n2); i++)
          {
             if (place[n1-i][c1]!=' ')
             return 0;
          }
       }
    }
    if (n1 == n2)
    {
       if (c1 < c2)
       {
          for(i = 1; i < (c2-c1); i++)
          {
             if (place[n1][c1+i]!=' ')
             return 0;
          }
       }
       else
       {
          for(i = 1; i < (c1-c2); i++)
          {
             if (place[n1][c1-i]!=' ')
             return 0;
          }
       }
    }
    
    return 1;
}

void CheckInPawn(char place[][8])
{
  int i;
  for (i = 0; i < 8; i++)
  if ((place[7][i] == 'P') || (place[0][i] == 'p'))
   {
      char ChooseFigure;
      printf("Choose figure\n");
      K:
      scanf(" %c", &ChooseFigure);
      if ((flag == 1 && (ChooseFigure!='R' && ChooseFigure!='Q' 
      && ChooseFigure!='N' && ChooseFigure!='B')) || (flag == 0 && (ChooseFigure!='r' 
      && ChooseFigure!='q' && ChooseFigure!='n' && ChooseFigure!='b')))
      {printf("Wrong figure\n"); goto K;}
      else
      {
	 if (place[7][i] == 'P') place[7][i] = ChooseFigure;
	 if (place[0][i] == 'p') place[0][i] = ChooseFigure;
	 break;
      }
   }
}

void CheckIn(char Move[], char place[][8])
{
     if ((strlen(Move)==5) && (Move[2]=='-')
     && ((int)(Move[1])>48) && ((int)(Move[1])<57) 
     && ((int)(Move[4])>48) && ((int)(Move[4])<57)
     && ((int)(Move[0])<73) && ((int)(Move[0])>64) 
     && ((int)(Move[3])<73) && ((int)(Move[3])>64)) {
        int c1 = (int)(Move[0]) - 65;
        int c2 = (int)(Move[3]) - 65;
        int n1 = (int)(Move[1]) - 49;
        int n2 = (int)(Move[4]) - 49;
        if(CheckInMove(Move, place))
        {
           place[n2][c2] = place[n1][c1];
           place[n1][c1] = ' ';
	       CheckInPawn(place);
           flag = 1 - flag;
           printboard(place);
        }
        else
        printf("Incorrect move\n");
    }
    else puts("Incorrect input\n");
}
