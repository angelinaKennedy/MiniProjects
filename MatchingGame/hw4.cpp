/* Angelina Kennedy
   hw4.cpp
   Purpose: This is a C++ program that play a popular card game. 
   Input: This program allow the user to choose a card and
          turns over that card. 
   Processing: This C++ program uses arrays and functions to create
               a memory game.
   Output: The game is won when all cards have been removed from the field.
   Example: pick a row and a col: 1 1
   Result: F * * *
           *  * * *
           *  * * *
*/     

#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>

using namespace std;

//function prototype
void welcome();
bool isValidRowColumn(char [][4], int, int, int = -1, int =-1);
void display(char [][4], char [][4], int, int, int=-1, int=-1, int = -1, int =-1 );
void checkMatchingCard(char [][4], char [][4], int, int, int, int);
void wait();
bool gameover(char [][4], int, int);
void goodbye();


int main()

{
    //variable declaration and initialization

    //variable to open a file and read from it.  
    ifstream inputFile;  
    string fileNames[] ={"p4data1.dat","p4data2.dat"}; 
    string fileName;

    //variables to store the string and to get the users choice to see if they
    //want to continue or not
    char letter, userWish;
    int randomNum, count =0;
    const int ROWSIZE = 3, COLSIZE =4;
    char card[ROWSIZE][COLSIZE], cardTurn[ROWSIZE][COLSIZE];

    //function invocation
    welcome();

    //this loop reads from a file and invokes display()
    do
    {
        count =0;
        randomNum = rand()% 2 + 1;
    
        switch (randomNum)
	    {
	      case 1:
	        fileName = fileNames[0];
	        break;
	      case 2:
	        fileName = fileNames[1];
	        break;
    	}
    	
    	inputFile.open(fileName);
	
    	if (inputFile)
	    {
	        for (int i=0; i < ROWSIZE; i++)
            {
    	      for (int j=0; j < COLSIZE; j++)
	          {
	              if(inputFile >> letter)
	              {
	                 card[i][j] = letter;
	              }
	              else
	              {
	                  break;
	              }
	            
	          }
            }
	      inputFile.close();
    	}
    	else
	    {
	        cout << "Error opening the file.\n";
	    }
        
        for (int i=0; i < ROWSIZE; i++)
    	{
    	    for (int j=0; j < COLSIZE; j++)
	        {
	          cardTurn[i][j] = '*';
	        }
    	}

    	display(card, cardTurn, ROWSIZE, COLSIZE);

        //this nested do-while loop asks the user for a row and column and invokes isValidRowColumn(),
        //display() and checkMatchingCard()
        do
        {
          int row1, column1, row2, column2; 
         
          cout << "Enter the Row and Column: ";
          cin >> row1 >> column1;
          cout << endl;
          row1-=1;
          column1-=1;
          while(row1<0 || row1>=ROWSIZE || column1<0 || column1>=COLSIZE || (!isValidRowColumn(cardTurn, row1, column1)))  
          {
            cout << "ReEnter the Row and Column: ";
            cin >> row1 >> column1;
            cout << endl;
            row1-=1;
            column1-=1;
          }
          display(card, cardTurn, ROWSIZE, COLSIZE, row1, column1);
          
          
          cout << "Enter the another Row and Column: ";
          cin >> row2 >> column2;
          cout << endl;
          row2-=1;
          column2-=1;
          while(row2<0 || row2>=ROWSIZE || column2<0 || column2>=COLSIZE || (!isValidRowColumn(cardTurn, row1, column1, row2, column2)))  
          {
              cout << "ReEnter the another Row and Column: ";
              cin >> row2 >> column2;
              row2-=1;
              column2-=1;
              cout << endl;
          }
          display(card, cardTurn, ROWSIZE, COLSIZE, row1, column1, row2, column2);

    	  
    	  checkMatchingCard(card, cardTurn, row1, column1, row2, column2);
    	  count++;
          display(card, cardTurn, ROWSIZE, COLSIZE);
        }while(!gameover(cardTurn, ROWSIZE, COLSIZE));
        
        cout << "You win! the score is " << count << endl; 
        
    	cout << "Do you want to continue(y/n)?: ";
    	cin >> userWish;
    }while(userWish=='y');
    
    goodbye();
    return 0;
    
}

//the welcome function outputs a welcome message.
//it doesn't have any parameters and it doesn't return anything to the main()
void welcome()
{
    cout << endl << endl;
    cout << "                                  WELCOME \n ";
    cout << "                                  ******* \n ";
    cout << "This is a popular card game where a scene of various cards are set face down. \n ";
    cout << "The fact is to locate the coordinating cards and eliminate the two cards from play. \n";
    cout << endl << endl;
}

//isValidRowColumn() checks if the card is already removed or not.
//its parameter consist of an array of char type and the user input of int type.
//it return a bool type to the main().
bool isValidRowColumn(char cardTurn[][4], int row1, int column1 , int row2, int column2)
{
    if(cardTurn[row1][column1] == '-')
    {
        cout << "The card is already removed, please choose again \n";
        return false;
    }
    else if(row2 != -1 && column2 != -1)
    {
        if(cardTurn[row2][column2] == '-')
        {
            cout << "The card is already removed, please choose again \n";
            return false;
        }
        else if((row1 == row2) && (column1 == column2))
        {
            return false;
        }
    }
    return true;
} 

//display() display the array to the user.
///its parameter consist of 2 arrays of char type, the user input of int type and the size of the arrays of type int
//it doesn't return anything to the main()
void display(char card[][4], char cardTurn[][4], int ROWSIZE, int COLSIZE, int row1, int column1, int row2, int column2)
{
    cout<<endl;
    for (int i=0; i < ROWSIZE; i++)
    {
       for (int j=0; j < COLSIZE; j++)
	   {
	       cout<<"  ";
	       if((i==row1 && j==column1) || (i==row2 && j==column2))
	       {
	           cout << card[i][j];
	       }
	       else
	       {
	           cout << cardTurn[i][j];
	       }
	   }
	   cout<<endl;
    }
}

//checkMatchingCard() checks if the two cards match. if it doesn't match, then it invokes the wait()
///its parameter consist of 2 arrays of char type and the user input of int type
//it doesn't return anything to the main()    
void checkMatchingCard(char card[][4], char cardTurn[][4], int row1, int column1, int row2, int column2)
{
    if(card[row1][column1] == card[row2][column2])
    {
        cardTurn[row1][column1] = '-';
        cardTurn[row2][column2] = '-';
        cout << "The two cards match and are removed \n";
    }
    else
    {
        cout << "Do not match \n";
        cout << "pausing for 5 seconds \n";
        wait();
    }
}

//wait() pauses the program 5 for seconds
//it doesn't have any parameters and it doesn't return anything to the main()  
void wait()
{
    clock_t endwait;
    endwait = clock() + 5 * CLOCKS_PER_SEC;
    while(clock() < endwait) 
    { 
    }
}

//gameover() checks if the user has won the game or not.
// its parameter consist of an array of char type and its size in int type
//it return a bool type to the main(). 
bool gameover(char cardTurn[][4], int ROWSIZE, int COLSIZE)
{
    for (int i=0; i < ROWSIZE; i++)
    {
       for (int j=0; j < COLSIZE; j++)
	   {
	       if(cardTurn[i][j] != '-')
	       return false;
	   }
    }
    return true;
}

//the goodbye() outputs an goodbye message
//it doesn't have any parameters and it doesn't return anything to the main()
void goodbye()
{
    cout << endl << endl; 
    cout << "              GOODBYE" << endl;
    cout << "              *******" << endl;  
    cout << "See you soon with another interesting game";
}



