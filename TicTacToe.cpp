//____________________TicTacToe.cpp file
#include "TicTacToe.h"
#include <iostream>

using namespace std;

TicTacToe::TicTacToe()
{
  for(int i=0; i < 3; i++) {
    for(int j =0; j < 3; j++) {
      board[i][j] = 0;
    }
  }
  Xwins = 0;
  Owins = 0;
}

void TicTacToe::displayBoard()
{
  for(int i=0; i < 3; i++) {
    for(int j =0; j < 3; j++) {
      cout << "[" << board[i][j] << "]\t";
    }
    cout << endl;
  }  
}

void TicTacToe::gamestarts()
{
  while(!isFull()) {
    Xwins = play('X');

    if(isWon(Xwins)) {
        cout << "X wins!!\n";
        break;
    }
    
    if(isFull()) {
      break;
    }
    
    Owins = play('O');

    if(isWon(Owins)) {
        cout << "O wins!!\n";
        break;
    }
  }
}

int TicTacToe::play(char player)
{
  int enterRow, enterCol;
  int xOcount =0;
    
  displayBoard();
  cout << "Player " << player << endl;

  cout << "Enter your row: ";
  cin >> enterRow;

  cout << "Enter your column: ";
  cin >> enterCol;
  cout << endl;
  
  while(isValid(enterRow, enterCol)) {
    cout << "ReEnter your row: ";
    cin >> enterRow;

    cout << "ReEnter your column: ";
    cin >> enterCol;
    cout << endl;
  }

  updateBoard(enterRow, enterCol, player);
  xOcount = isMatch(player);

  return xOcount;
}

void TicTacToe::updateBoard(int enterRow, int enterCol, char player)
{
    board[enterRow - 1][enterCol - 1] = player;
}

bool TicTacToe::isValid(int enterRow,int enterCol) const
{
  if( enterRow <1 || enterRow >3 || enterCol <1 || enterCol >3 ) {
    return true;
  }
  if((board[enterRow - 1][enterCol - 1] == 'X')||(board[enterRow - 1][enterCol - 1] == 'O'))
    return true;
  return false;
}

int TicTacToe::isMatch(char player) const
{
  for(int i = 0; i < 3; i++) {
    if(player == board[i][0] && player ==  board[i][1] && player == board[i][2])
      return 1;
  }

  for (int j = 0; j < 3; j++) {
    if(player == board[0][j] && player == board[1][j] && player == board[2][j]) {
      return 1;
    }
  }

  if(player == board[0][0] && player == board[1][1] && player == board[2][2]) {
    return 1;
  }

  if(player == board[0][2] && player == board[1][1] && player == board[2][0]) {
    return 1;
  }

  return 0;
}

bool TicTacToe::isWon(int playerWinOrNot) 
{
  if(playerWinOrNot == 1) {
      displayBoard();
      cout << "\nWE HAVE A WINNER!!!\n";
      return true;
  }
  return false;
}

bool TicTacToe::isFull() 
{
  for(int i = 0; i < 3; i++) {
      for (int j = 0; j < 3; j++) {
        if(board[i][j] ==0) {
          return false;
        }
      }
  }
  displayBoard();
  cout << "The game ended in a tie.\n";
  return true;
}
