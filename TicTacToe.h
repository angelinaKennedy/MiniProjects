//_________________TicTacToe.h file
#ifndef TICTACTOE_H
#define TICTACTOE_H

class TicTacToe
{
  int Owins, Xwins; //variables to check whether a player won the game or not.
  char board[3][3]; //a 2d array for the game.
  
public:

  //preconditions: Object declaration
  //postconditions: Object creation
  TicTacToe();

  //preconditions: TicTacToe class object should be present to invoke this method                                                          
  //postconditions: It outputs the result of the game.                                                                                     
  void gamestarts();

private:
  
  //preconditions: A board is a grid of 9 spaces, in a 3 x 3 arrangement is required.
  //postconditions: The function just prints the board in a formatted way.
  void displayBoard();

  //preconditions: A player is required to place their respective pieces.
  //postconditions: The player place their piece in the board after checking if the position is valid or not.
  int play(char player);

  //preconditions: This function requires a board to be updated, valid number for row and column, a player charater to place on the board.
  //postconditions: The board is updated with the player's piece.
  void updateBoard(int enterRow, int enterCol, char player);

  //preconditions: This function requires a number for row and a number for column from the player.
  //postconditions: This function checks whether the numbers entered by player was valid and if the position was empty or not.
  bool isValid(int enterRow,int enterCol) const;

  //preconditions: The player's character is required.
  //postconditions: A player's pieces are checked[Row/Column/Diagonal Match)] to see if they won the game.
  int isMatch(char player) const;

  //preconditions: The player's score is needed.
  //postconditions: It checks whether the game is over or not.
  bool isWon(int playerWinOrNot);

  //preconditions: none.
  //postconditions: This function checks whether the game ended in a tie or not.
  bool isFull();
};
#endif
