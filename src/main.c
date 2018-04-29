#include <stdio.h>

#include "board.h"
#include "board_print_plain.h"
int main()
{   
    char place[8][8];
    board(place); 
    printboard(place);
    board_print_plain(place);
    char Move[5];
    while(CheckKing(place))
    {
            scanf("%s", Move);
            CheckIn(Move, place);
            board_print_plain(place);
            board_print_plain_Move(Move);
    }
}


