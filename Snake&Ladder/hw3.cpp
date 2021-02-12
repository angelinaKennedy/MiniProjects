/* Angelina Kennedy
   hw3.cpp
   Purpose: It is an C++ program for a board game
            called “Chutes & Ladders”.
   Input: The program allows two players to play
          the game and ask the users for their names.
   Processing: This C++ program uses functions and loops.
   Output: The program "spins" and the players is
           told the result of their spin.
   Example: Enter player1's name: Tom                                                                                                                 
            Enter player2's name: Helen
   Results: Tom: Its your turn
            You rolled 2
            Your new location is: 2
            Helen: Its your turn.
            You rolled 5
            Your new location is: 5         
*/  

#include <iostream>
#include <string>
#include <cstdlib>

using namespace std;

//function prototype 
void welcomeMessage();
int play(string, int, string);
void turnMessage(string);
int spinnerValue();
int calculatePosition(int, int);
bool isLimitExceeded(int);
int ladders(int);
int chutes(int);
bool checkWinner(int);
void goodbyeMessage();

int main()

{   //variable declaration and initialization  
    const string PLAYER1 = "Player 1 ";
    const string PLAYER2 = "Player 2 ";
    string player1, player2;
    char userWish;
    int player1Position, player2Position;

    //function invocation 
    welcomeMessage();
    
    /*do-while gets the player's name and asks the players if they to play
    again.
    It invokes play() and checkWinner().
    */
    do
    {
        player1Position = 0;
        player2Position=0;
        
        cout << "\nEnter player1's name: ";
        getline(cin,player1);
        cout << "Enter player2's name: ";
        getline(cin,player2);
        cout << endl;
        
        while(true)
        {
           player1Position = play(player1, player1Position, PLAYER1);
           if(checkWinner(player1Position))
           {
               cout << PLAYER1 << player1 << " Won" << endl;
               break;
           }
           cout << endl;
           
           player2Position = play(player2, player2Position, PLAYER2);
           if(checkWinner(player2Position))
           {
               cout << PLAYER2 << player2 << " Won" << endl;
               break;
           }
           cout << endl;

        }
        
        cout << endl;
        cout << "Do you want to continue(y/n)?: ";
        cin >> userWish;
        cin.ignore();
        
    }while(userWish=='y');
    
    goodbyeMessage();
    return 0;
}

//the welcome function outputs a welcome message.
//it doesn't have any parameters and it doesn't return anything to the main()
void welcomeMessage()
{
  cout << endl << endl;    
  cout << "                 WELCOME TO CHUTES & LADDERS" << endl;
  cout << "                 ***************************" << endl;
  cout << "The players take turns at spinning a spinner ,and each moves his \n";
  cout << "or her counter forward the number of squares corresponding to the \n";
  cout << "number on the spinner. The first person to reach square 100 is the winner.";
  cout << endl <<endl;
}

/* The play function invokes spinnervalue & calculatePosition function.
It outputs the value of what we spinned and tells the player their
current position.
The parameters contains the player's name, their position and their title
(i.e whether they are player1 or player2)
It returns the player's position to the main().
*/
int play(string playerName, int playerPosition, string playerTitle)
{
    
   turnMessage(playerName);
   int spinner = spinnerValue();
   cout << "You rolled "<< spinner << endl;
   playerPosition = calculatePosition(playerPosition, spinner);
   cout << "Your new location is: " << playerPosition << endl;
   return playerPosition;
}

/* The turnMessage function informs the player when it is their chance.
The parameter consist of the player's name.
it doesn't return anything.
*/
void turnMessage(string playerName)
{
  cout <<  playerName << " :Its your turn." <<endl;
}

/* The spinnerValue funtion calculates the spin value.
it doesn't have any parameters and it return the spin value to
the play function */
int spinnerValue()
{
  return rand()%(6)+1;
}

/* The calculatePosition functon invokes isLimitExceeded, ladders and chutes
functons.
It checks if the players moves up in the ladder or
move down in the ladder and also checks if the player exceeds 100th 
position.
The parameter consist of the player position and the spin value.
It return the new player's position to the play().
*/
int calculatePosition(int playerPosition, int spinner)
{
    int ladderResult , chuteResult;
    int newPlayerPosition = playerPosition + spinner;
    
    if(isLimitExceeded(newPlayerPosition))
    {
        return playerPosition;
    }
    
    ladderResult = ladders(newPlayerPosition);
    chuteResult = chutes(newPlayerPosition);
    
    if((!isLimitExceeded(newPlayerPosition)) && (ladderResult != newPlayerPosition))
    {
        cout << "You landed on ladders, and get to move up the board!" << endl;
        return ladderResult;
    }
    
    if((!isLimitExceeded(newPlayerPosition)) && (chuteResult != newPlayerPosition))
    {
        cout << "You landed on chutes, and have to move down!" << endl;
        return chuteResult;
    }

    return newPlayerPosition;
}

/* The isLimitExceeded function checks if the players position is less than 100.
The parameter consist of the player's position.
It return a bool value to the calculatePosition().
*/
bool isLimitExceeded(int playerPosition)
{
    if(playerPosition > 100)
    {
        cout << "The spin is ignored because the result will past 100" << endl;
        return true;
    }
    
    return false;
}

/* The ladders function checks if the player is going up in the ladder.
It consist of the player's new position which is found after adding the spin
value.
It return the result to the calculatePosition().
*/
int ladders(int ladderNumber)
{
   if(ladderNumber==1)
     ladderNumber+=37;
   else if (ladderNumber==4)   
     ladderNumber+=10;
   else if (ladderNumber==9) 
     ladderNumber+=12;
   else if (ladderNumber==23)
     ladderNumber+=21;
   else if (ladderNumber==28)
     ladderNumber+=56;
   else if (ladderNumber==36) 
     ladderNumber+=8;
   else if (ladderNumber==51) 
     ladderNumber+=15;
   else if (ladderNumber==71)
     ladderNumber+=19;
   else if (ladderNumber==80)  
     ladderNumber+=20;
     
    return ladderNumber; 
     
}

/* The chutes function checks if the player is going down in the chute.
It consist of the player's new position which is found after adding the spin
value.
It return the result to the calculatePosition().
*/
int chutes(int chuteNumber)
{
  if(chuteNumber==98)
     chuteNumber-=20;
   else if (chuteNumber==95)   
     chuteNumber-=20;
   else if (chuteNumber==93) 
     chuteNumber-=20;
   else if (chuteNumber==87)
     chuteNumber-=63;
   else if (chuteNumber==64)
     chuteNumber-=4;
   else if (chuteNumber==62) 
     chuteNumber-=43;
   else if (chuteNumber==56) 
     chuteNumber-=3;
   else if (chuteNumber==49)
     chuteNumber-=38;
   else if (chuteNumber==48)  
     chuteNumber-=22;
   else if (chuteNumber==16) 
     chuteNumber-=10;
     
    return chuteNumber;   
}

/* the checkWinner function checks if the player won or not.
The parameter consist of the player's position.
It return the result to the main().
*/
bool checkWinner(int playerPosition)
{
    if(playerPosition == 100)
        return true;
    return false;
}

//the goodbye() outputs an goodbye message
//it doesn't have any parameters and it doesn't return anything to the main()
void goodbyeMessage()
{
    cout << endl << endl;
    cout << "              GOODBYE" << endl;
    cout << "              *******" << endl;
    cout << "See you soon with another interesting game";
}




