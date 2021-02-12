/*
 Angelina Kennedy
 hw2.cpp
 Purpose: This program plays an integer guessing game with user.
 Input: The program asks the user to provide a range (i.e the minimum integer
        and the maximum integer)
 Processing: This program uses nested do-while loop and random function.
 Output: The program generates a random number that is in the range and
         ask the user to guess the number.
 Example: Enter the minimum and the maximum number: 1 10
          Enter the number you had guessed: 1
 Result: Your guess is too low
         Do you want to make another guess(y/n)? n
         Do you want to replay(y/n)? n
*/

#include <iostream>
#include <cstdlib>

using namespace std;

int main()
  
{
  //variable declaration

  //to store the values entered by the user
  int miniNumber, maxNumber, randomNumber, guessNumber;

  //to store the character entered by the user
  char userWish, rePlay;

  //welcome message
  cout << endl << endl << endl;
  cout << "                      WELCOME" << endl;
  cout << "                      *******" << endl;
  cout << "This program is an integer guessing game where it will" << endl;
  cout << "ask the user to provide a range from which a random" << endl;
  cout << "number is generated and then it asks the user to guess" << endl;
  cout << "the number.";
  cout << endl << endl;

  do

    {
      //input
      cout <<"Enter the minimum number and the maximum number: ";
      cin >> miniNumber >> maxNumber;

      //to generate the random number
      randomNumber = rand() % (maxNumber - miniNumber +1) + miniNumber;

      do

        {
          cout << "Enter the number that you had guessed: ";
          cin >> guessNumber;

          //to check whether their guess is too high, too low, or correct
          if((guessNumber < miniNumber)||(guessNumber > maxNumber))
            {
              cout << "Your guess is not in the range" << endl;
            }
          else if (guessNumber > randomNumber)
            {
              cout << "Your guess is too high" << endl;
            }
          else if (guessNumber < randomNumber)
            {
              cout << "You guess is too low" << endl;
            }
          else 
            {
              cout << "you guessed it correctly" << endl;
              break;
            }  

          cout << endl; 
          cout << "Do you want to make another guess(y/n)? ";
          cin >> userWish;
          cout << endl; 

        } while(userWish == 'y');
      cout << endl;
      cout << "Do you want to replay(y/n)? ";
      cin >> rePlay;
      cout << endl;
    } while(rePlay=='y');

  cout << endl << endl;
  cout << "                   GOODBYE" << endl;
  cout << "                   *******" << endl;
  cout << "See you soon with another interesting game";
  cout << endl << endl;
  return 0;
}
