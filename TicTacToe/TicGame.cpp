/* Angelina Kennedy
   TicGame.cpp
   Purpose: This program creates a game Tic-Tac-Toe for two players.
   Input: In this game, one player places the X pieces and the other player places the O pieces.
   Processing: The program creates a class definition with appropriate member functions for the game.
   Output: The game ends as soon as a player has filled one row or one column or one full diagonal.
   Example: [ ] [ ] [ ]
            [ ] [ ] [ ]
            [ ] [ ] [ ]
            Player X
            Enter your row:1
            Enter your column:1
            [X] [ ] [ ]
            [ ] [ ] [ ]
            [ ] [ ] [ ]
*/

#include "TicTacToe.h"
#include <iostream>

using namespace std;

int main(int argc, char *argv[])
{
  TicTacToe game;
  game.gamestarts();

  return 0;
}
