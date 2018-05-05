#define CTEST_MAIN

#include "board.c"
#include "ctest.h"

char Board[8][8];

CTEST (CheckKing, CorrectKingCheck)
{
      int i, j;
      for(i = 0; i < 8; i++)
      {
         for(j = 0; j < 8; j++)
         Board[i][j] = ' ';
      }
      int n1 = rand()%8;
      int c1 = rand()%8;
      int n2 = rand()%8;
      int c2 = rand()%8;
      Board[n1][c1] = 'K';
      if (n1 == n2) 
      {
         if(n2 < 8) n2++;
         else
         n2--;
      }
      Board[n2][c2] = 'k';
      int result = CheckKing(Board);
      int expecting = 1;
      ASSERT_EQUAL(expecting,result); 
}

CTEST (CheckChooseFigure, CorrectChooseFigure)
{
      int i, j, result = 0;
      for(i = 0; i < 8; i++)
      {
         for(j = 0; j < 8; j++)
         Board[i][j] = ' ';
      }
      Board[7][7] = 'P';
      CheckInPawn(Board);
      if (Board[7][7] == 'Q' || Board[7][7] == 'R' || Board[7][7] == 'N' || Board[7][7] == 'B') result = 1;
      ASSERT_TRUE(result);
}

CTEST (CheckKing, CorrectKingCheckEndWhite)
{
      int i, j;
      for(i = 0; i < 8; i++)
      {
         for(j = 0; j < 8; j++)
         Board[i][j] = ' ';
      }
      int n1 = rand()%8;
      int c1 = rand()%8;
      Board[n1][c1] = 'K';
      int result = CheckKing(Board);
      int expecting = 0;
      ASSERT_EQUAL(expecting,result); 
}

CTEST (CheckKing, CorrectKingCheckEndBlack)
{
      int i, j;
      for(i = 0; i < 8; i++)
      {
         for(j = 0; j < 8; j++)
         Board[i][j] = ' ';
      }
      int n1 = rand()%8;
      int c1 = rand()%8;
      Board[n1][c1] = 'k';
      int result = CheckKing(Board);
      int expecting = 0;
      ASSERT_EQUAL(expecting,result); 
}

CTEST (CheckKing, CorrectKingCheckEndBoth)
{
      int i, j;
      for(i = 0; i < 8; i++)
      {
         for(j = 0; j < 8; j++)
         Board[i][j] = ' ';
      }
      int result = CheckKing(Board);
      int expecting = 0;
      ASSERT_EQUAL(expecting,result); 
}

CTEST (CheckMoveP, CorrectCheckMoveP)
{
      int i, j, k = 0, result;
      char Symbol[] = {'A','B','C','D','E','F','G','H'};
      char Number[] = {'1','2','3','4','5','6','7','8'};
      for(i = 0; i < 8; i++)
      {
         for(j = 0; j < 8; j++)
         Board[i][j] = ' ';
      }
      for(i = 2; i < 7; i++)
      {
         Board[i][2] = 'p';
         Board[i][6] = 'p';
	  }
	  for(i = 3; i < 6; i++)
      {
         Board[2][i] = 'p';
         Board[6][i] = 'p';
	  }
	  Board[1][4] = 'P';
	  Board[2][4] = ' ';
	  char Move[5] = {'E','2','-',' ',' '};
      int expecting[] ={ 0, 0, 0, 0, 0, 0, 0, 0,
	                     0, 0, 0, 0, 0, 0, 0, 0,
						 0, 0, 0, 1, 1, 1, 0, 0,
						 0, 0, 0, 0, 1, 0, 0, 0,
						 0, 0, 0, 0, 0, 0, 0, 0,
						 0, 0, 0, 0, 0, 0, 0, 0,
						 0, 0, 0, 0, 0, 0, 0, 0,
						 0, 0, 0, 0, 0, 0, 0, 0,
						};
	  for(i = 0; i < 8; i++)
	  {
	     Move[4] = Number[i];
	     for(j = 0; j < 8; j++)
	     {
	     	Move[3] = Symbol[j];
	     	result = CheckInMove(Move, Board);
	     	ASSERT_EQUAL(expecting[k],result); 
	     	k++;
		 }
	  }
	  result = CheckInMove(Move, Board);
	  ASSERT_EQUAL(expecting[8],result); 
	  
}

CTEST (CheckMoveB, CorrectCheckMoveB)
{
      int i, j, k = 0, result;
      char Symbol[] = {'A','B','C','D','E','F','G','H'};
      char Number[] = {'1','2','3','4','5','6','7','8'};
      for(i = 0; i < 8; i++)
      {
         for(j = 0; j < 8; j++)
         Board[i][j] = ' ';
      }
      for(i = 2; i < 7; i++)
      {
         Board[i][2] = 'p';
         Board[i][6] = 'p';
	  }
	  for(i = 3; i < 6; i++)
      {
         Board[2][i] = 'p';
         Board[6][i] = 'p';
	  }
	  Board[4][4] = 'B';
	  char Move[5] = {'E','5','-',' ',' '};
      int expecting[] ={ 0, 0, 0, 0, 0, 0, 0, 0,
	                     0, 0, 0, 0, 0, 0, 0, 0,
						 0, 0, 1, 0, 0, 0, 1, 0,
						 0, 0, 0, 1, 0, 1, 0, 0,
						 0, 0, 0, 0, 0, 0, 0, 0,
						 0, 0, 0, 1, 0, 1, 0, 0,
						 0, 0, 1, 0, 0, 0, 1, 0,
						 0, 0, 0, 0, 0, 0, 0, 0,
						};
	  for(i = 0; i < 8; i++)
	  {
	     Move[4] = Number[i];
	     for(j = 0; j < 8; j++)
	     {
	     	Move[3] = Symbol[j];
	     	result = CheckInMove(Move, Board);
	     	ASSERT_EQUAL(expecting[k],result); 
	     	k++;
		 }
	  }
	  result = CheckInMove(Move, Board);
	  ASSERT_EQUAL(expecting[8],result); 
	  
}

CTEST (CheckMoveQ, CorrectCheckMoveQ)
{
      int i, j, k = 0, result;
      char Symbol[] = {'A','B','C','D','E','F','G','H'};
      char Number[] = {'1','2','3','4','5','6','7','8'};
      for(i = 0; i < 8; i++)
      {
         for(j = 0; j < 8; j++)
         Board[i][j] = ' ';
      }
      for(i = 2; i < 7; i++)
      {
         Board[i][2] = 'p';
         Board[i][6] = 'p';
	  }
	  for(i = 3; i < 6; i++)
      {
         Board[2][i] = 'p';
         Board[6][i] = 'p';
	  }
	  Board[4][4] = 'Q';
	  char Move[5] = {'E','5','-',' ',' '};
      int expecting[] ={ 0, 0, 0, 0, 0, 0, 0, 0,
	                     0, 0, 0, 0, 0, 0, 0, 0,
						 0, 0, 1, 0, 1, 0, 1, 0,
						 0, 0, 0, 1, 1, 1, 0, 0,
						 0, 0, 1, 1, 0, 1, 1, 0,
						 0, 0, 0, 1, 1, 1, 0, 0,
						 0, 0, 1, 0, 1, 0, 1, 0,
						 0, 0, 0, 0, 0, 0, 0, 0,
						};
	  for(i = 0; i < 8; i++)
	  {
	     Move[4] = Number[i];
	     for(j = 0; j < 8; j++)
	     {
	     	Move[3] = Symbol[j];
	     	result = CheckInMove(Move, Board);
	     	ASSERT_EQUAL(expecting[k],result); 
	     	k++;
		 }
	  }
	  result = CheckInMove(Move, Board);
	  ASSERT_EQUAL(expecting[8],result); 
	  
}

CTEST (CheckMoveN, CorrectCheckMoveN)
{
      int i, j, k = 0, result;
      char Symbol[] = {'A','B','C','D','E','F','G','H'};
      char Number[] = {'1','2','3','4','5','6','7','8'};
      for(i = 0; i < 8; i++)
      {
         for(j = 0; j < 8; j++)
         Board[i][j] = ' ';
      }
      for(i = 2; i < 7; i++)
      {
         Board[i][2] = 'p';
         Board[i][6] = 'p';
	  }
	  for(i = 3; i < 6; i++)
      {
         Board[2][i] = 'p';
         Board[6][i] = 'p';
	  }
	  Board[4][4] = 'N';
	  char Move[5] = {'E','5','-',' ',' '};
      int expecting[] ={ 0, 0, 0, 0, 0, 0, 0, 0,
	                     0, 0, 0, 0, 0, 0, 0, 0,
						 0, 0, 0, 1, 0, 1, 0, 0,
						 0, 0, 1, 0, 0, 0, 1, 0,
						 0, 0, 0, 0, 0, 0, 0, 0,
						 0, 0, 1, 0, 0, 0, 1, 0,
						 0, 0, 0, 1, 0, 1, 0, 0,
						 0, 0, 0, 0, 0, 0, 0, 0,
						};
	  for(i = 0; i < 8; i++)
	  {
	     Move[4] = Number[i];
	     for(j = 0; j < 8; j++)
	     {
	     	Move[3] = Symbol[j];
	     	result = CheckInMove(Move, Board);
	     	ASSERT_EQUAL(expecting[k],result); 
	     	k++;
		 }
	  }
	  result = CheckInMove(Move, Board);
	  ASSERT_EQUAL(expecting[8],result); 
	  
}

CTEST (CheckMoveK1, CorrectCheckMoveK1)
{
      int i, j, k = 0, result;
      char Symbol[] = {'A','B','C','D','E','F','G','H'};
      char Number[] = {'1','2','3','4','5','6','7','8'};
      for(i = 0; i < 8; i++)
      {
         for(j = 0; j < 8; j++)
         Board[i][j] = ' ';
      }
      for(i = 2; i < 7; i++)
      {
         Board[i][2] = 'p';
         Board[i][6] = 'p';
	  }
	  for(i = 3; i < 6; i++)
      {
         Board[2][i] = 'p';
         Board[6][i] = 'p';
	  }
	  Board[4][4] = 'K';
	  char Move[5] = {'E','5','-',' ',' '};
      int expecting[] ={ 0, 0, 0, 0, 0, 0, 0, 0,
	                     0, 0, 0, 0, 0, 0, 0, 0,
						 0, 0, 0, 0, 0, 0, 0, 0,
						 0, 0, 0, 1, 1, 1, 0, 0,
						 0, 0, 0, 1, 0, 1, 0, 0,
						 0, 0, 0, 1, 1, 1, 0, 0,
						 0, 0, 0, 0, 0, 0, 0, 0,
						 0, 0, 0, 0, 0, 0, 0, 0,
						};
	  for(i = 0; i < 8; i++)
	  {
	     Move[4] = Number[i];
	     for(j = 0; j < 8; j++)
	     {
	     	Move[3] = Symbol[j];
	     	result = CheckInMove(Move, Board);
	     	ASSERT_EQUAL(expecting[k],result); 
	     	k++;
		 }
	  }
	  result = CheckInMove(Move, Board);
	  ASSERT_EQUAL(expecting[8],result); 
	  
}

CTEST (CheckMoveR, CorrectCheckMoveR)
{
      int i, j, k = 0, result;
      char Symbol[] = {'A','B','C','D','E','F','G','H'};
      char Number[] = {'1','2','3','4','5','6','7','8'};
      for(i = 0; i < 8; i++)
      {
         for(j = 0; j < 8; j++)
         Board[i][j] = ' ';
      }
      for(i = 2; i < 7; i++)
      {
         Board[i][2] = 'p';
         Board[i][6] = 'p';
	  }
	  for(i = 3; i < 6; i++)
      {
         Board[2][i] = 'p';
         Board[6][i] = 'p';
	  }
	  Board[4][4] = 'R';
	  char Move[5] = {'E','5','-',' ',' '};
      int expecting[] ={ 0, 0, 0, 0, 0, 0, 0, 0,
	                     0, 0, 0, 0, 0, 0, 0, 0,
						 0, 0, 0, 0, 1, 0, 0, 0,
						 0, 0, 0, 0, 1, 0, 0, 0,
						 0, 0, 1, 1, 0, 1, 1, 0,
						 0, 0, 0, 0, 1, 0, 0, 0,
						 0, 0, 0, 0, 1, 0, 0, 0,
						 0, 0, 0, 0, 0, 0, 0, 0,
						};
	  for(i = 0; i < 8; i++)
	  {
	     Move[4] = Number[i];
	     for(j = 0; j < 8; j++)
	     {
	     	Move[3] = Symbol[j];
	     	result = CheckInMove(Move, Board);
	     	ASSERT_EQUAL(expecting[k],result); 
	     	k++;
		 }
	  }
	  result = CheckInMove(Move, Board);
	  ASSERT_EQUAL(expecting[8],result); 
	  
}

CTEST (CheckMoveK2, CorrectCheckMoveK2)
{
      int i, j, k = 0, result;
      char Symbol[] = {'A','B','C','D','E','F','G','H'};
      char Number[] = {'1','2','3','4','5','6','7','8'};
      for(i = 0; i < 8; i++)
      {
         for(j = 0; j < 8; j++)
         Board[i][j] = ' ';
      }
      for(i = 2; i < 7; i++)
      {
         Board[i][2] = 'p';
         Board[i][6] = 'p';
	  }
	  for(i = 3; i < 6; i++)
      {
         Board[2][i] = 'p';
         Board[6][i] = 'p';
	  }
	  Board[0][4] = 'K';
	  Board[0][7] = 'R';
	  Board[0][0] = 'R';
	  char Move[5] = {'E','1','-',' ',' '};
      int expecting[] ={ 0, 0, 0, 1, 0, 1, 1, 0,
	                     0, 0, 0, 1, 1, 1, 0, 0,
						 0, 0, 0, 0, 0, 0, 0, 0,
						 0, 0, 0, 0, 0, 0, 0, 0,
						 0, 0, 0, 0, 0, 0, 0, 0,
						 0, 0, 0, 0, 0, 0, 0, 0,
						 0, 0, 0, 0, 0, 0, 0, 0,
						 0, 0, 0, 0, 0, 0, 0, 0,
						};
	  for(i = 0; i < 8; i++)
	  {
	     Move[4] = Number[i];
	     for(j = 0; j < 8; j++)
	     {
	     	Move[3] = Symbol[j];
	     	result = CheckInMove(Move, Board);
	     	ASSERT_EQUAL(expecting[k],result); 
	     	k++;
		 }
	  }
	  result = CheckInMove(Move, Board);
	  ASSERT_EQUAL(expecting[8],result); 
	  
}

int main(int argc, const char** argv) 
{
    int test_res = ctest_main(argc, argv);
    return test_res;
}
