#ifndef BOARD_H
#define BOARD_H

void board(char place[][8]);
void CheckIn(char Move[], char place[][8]);
void printboard(char place[][8]);
int CheckInMove(char Move[], char place[][8]);
int CheckWay(char Move[], char place[][8]);
int CheckKing(char place[][8]);
int CheckEnemy(char Move[], char place[][8]);

#endif
