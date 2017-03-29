/* Victor Espinoza
* CECS 282, Section 1
* Spring 2014
* Due Date: 1/30/14		
* Lab #1- The Price is Wrong
*/


#include <iostream>
#include <cstdlib>
#include <time.h>
#include <string>
#include <regex>
using namespace std; 

void printGoatDoor(int door);
int validateDoor();
int changeDoorOption(int userChoice, int changeOption);

int main(int argc, char* argv[]) {
   //constant declarations for door options and grand prize options
   const int DOOR_1 = 1, DOOR_2 = 2, DOOR_3 = 3;
   const int THREE = 3, FIVE = 5;
   const int GRAND_PRIZE_1 = 1, GRAND_PRIZE_2 = 2, GRAND_PRIZE_3 = 3, 
    GRAND_PRIZE_4 = 4, GRAND_PRIZE_5 = 5;

   //Seed the random number generator based on current time.
   srand(time(0));
   //Generate a number between 1 and 3 in order to pick which door has the 
   //winning prize behind it.
   int prizeDoor = (rand() % THREE) + 1;

   //Display Welcome Message:
   cout << "Welcome to another exciting episode of The Price is Wrong!" 
    << endl;


   //Display the three doors to add a visual aspect to the game.
   cout << "   ____________       ____________       ____________ " << endl;
   cout << "  |            |     |            |     |            | " << endl;
   cout << "  |            |     |            |     |            | " << endl;
   cout << "  |  DOOR #1   |     |  DOOR #2   |     |  DOOR #3   | " << endl;
   cout << "  |            |     |            |     |            | " << endl;
   cout << "  |            |     |            |     |            | " << endl;
   cout << "  | O          |     | O          |     | O          | " << endl;
   cout << "  |            |     |            |     |            | " << endl;
   cout << "  |            |     |            |     |            | " << endl;
   cout << "  |            |     |            |     |            | " << endl;
   cout << "  |            |     |            |     |            | " << endl;
   cout << "  |            |     |            |     |            | " << endl;
   cout << "  |____________|     |____________|     |____________| " << endl;

   //Inform the user of the grand prize and prompt them to choose a door.
   cout << "\nBehind only one door lies a great prize; the other two doors "
    << endl << "have a goat behind them." << endl;
   int playerChoice = validateDoor();

   //Show the player a door with a goat behind it that
   //is not the door the player chose and ask them if
   //they want to switch to the last remaining door.
   if (playerChoice == DOOR_1){
      if (prizeDoor != DOOR_2){
         //If the player chooses door 1 and door 2 doesn't
         //have the prize, then that means that door 2 has a 
         //goat behind it. Show them door 2 and ask if they
         //want to switch with door 3.
         printGoatDoor(DOOR_2);
         //see if user wants to change doors
         playerChoice = changeDoorOption(playerChoice, DOOR_3);
      }//end if
      else {
         //If the player chooses door 1 and door 2 has
         //the prize, then that means that door 3 has a 
         //goat behind it. Show them door 3 and ask if they
         //want to switch with door 2.
         printGoatDoor(DOOR_3);
         //see if user wants to change doors
         playerChoice = changeDoorOption(playerChoice, DOOR_2);
      }//end else
   }//end if
   else {
      if (playerChoice == DOOR_2){
         if (prizeDoor != DOOR_1){
            //If the player chooses door 2 and door 1 doesn't
            //have the prize, then that means that door 1 has a 
            //goat behind it. Show them door 1 and ask if they
            //want to switch with door 3.
            printGoatDoor(DOOR_1);
            //see if user wants to change doors
            playerChoice = changeDoorOption(playerChoice, DOOR_3);
         }//end if
         else {
            //If the player chooses door 2 and door 1 has
            //the prize, then that means that door 3 has a 
            //goat behind it. Show them door 3 and ask if they
            //want to switch with door 1.
            printGoatDoor(DOOR_3);
            //see if user wants to change doors
            playerChoice = changeDoorOption(playerChoice, DOOR_1);
         }//end else
      }//end if
      else {
         if (prizeDoor != DOOR_1){			
            //Otherwise, the player picked door 3. If door 1 doesn't
            //have the prize, then that means that door 1 has a 
            //goat behind it. Show them door 1 and ask if they
            //want to switch with door 2.
            printGoatDoor(DOOR_1);
            //see if user wants to change doors
            playerChoice = changeDoorOption(playerChoice, DOOR_2);
         }//end if
         else {
            //If door 1 has the prize, then that means that door 2 
            //has a goat behind it. Show them door 2 and ask if they
            //want to switch with door 1.
            printGoatDoor(DOOR_2);
            //see if user wants to change doors
            playerChoice = changeDoorOption(playerChoice, DOOR_1);
         }//end else
      }//end else
   }//end else

   //Display what is behind the door that the player ended up choosing
   //If the player chose the winning door, GRAND PRIZE! is displayed,
   //otherwize we display (GOAT)
   cout << "\nAlright, lets see what's behind DOOR #" << playerChoice << 
    "!" << "..." << endl;
   cout << "   ____________   " << endl;
   cout << "  |            |  " << endl;
   cout << "  |            |  " << endl;
   cout << "  |  DOOR #" << playerChoice <<"   |  " << endl;
   cout << "  |            |  " << endl;
   cout << "  |            |  " << endl;
   if (playerChoice == prizeDoor )
      cout << "  |GRAND PRIZE!|  " << endl;
   else
      cout << "  |   (GOAT)   |  " << endl;
   cout << "  |            |  " << endl;
   cout << "  |            |  " << endl;
   cout << "  |            |  " << endl;
   cout << "  |            |  " << endl;
   cout << "  |            |  " << endl;
   cout << "  |____________|  " << endl;

   //description of each possible grand prize.
   string prize1 = "A whole herd of goats! Now you'll be the envy of all\n"
    "your friends. Who else can say that they have a whole herd of\n"
    "goats; I certainly can't. Enjoy your fabulous prize and don't\n"
    "forget to feed your new companions!";

   string prize2 = "A brand new 2014 Ford Mustang! Man are you lucky; now\n"
    "you can ride anywhere in style with this brand new muscle car! It \n"
    "isn't even available to the public yet! Warning, may cause an\n "
    "excessive spike in popularity. Just don't forget to put gas in it...";

   string prize3 = "$5 million. Looks like you picked the right door!\n"
    "You've won the jackpot of jackpots! What are you going to do with so\n"
    "much money? Don't forget about all of us little people now that \n"
    "you've made it big time...";

   string prize4 = "An all expenses paid trip to Las Vegas for you and\n"
    "your family for a week! You even get some gambling money!Just try\n"
    "not to spend it all in one place! Enjoy your trip; you deserve it!";

   string prize5 = "A brand new home entertainment system! Now you have\n"
    "everything you need to entertain guests during a party or just\n"
    "enjoy a movie night with your loved ones. This entertainment system\n"
    "comes complete with a brand new television, wall mount, surround\n"
    "sound speaker system, and a 10 year warranty on each item. Enjoy!";

   //Generate a random number between 1 and 5 to choose the final prize.
   int finalPrize = (rand() % FIVE) + 1;

   if (playerChoice == prizeDoor){
      cout << "\nCONGRADULATIONS!!! You have won the grand prize of:\n "
       << endl;
      //Output the appropriate message depending on what prize number  
      //was randomly generated.

      switch (finalPrize) {
      case GRAND_PRIZE_1: cout << prize1 << endl;
         break;
      case GRAND_PRIZE_2: cout << prize2 << endl;
         break;
      case GRAND_PRIZE_3: cout << prize3 << endl;
         break;
      case GRAND_PRIZE_4: cout << prize4 << endl;
         break;
      case GRAND_PRIZE_5: cout << prize5 << endl;
         break;
      default: cout << "Default case reached!" << endl;
         break;
      } //end switch

      cout << "\nWell, that concludes this episode. See you next time on\n"
       "The Price is Wrong!\n" << endl;
   }//end if	
   else { 
      //Output a sad message informing the player that they have lost.
      cout << "\nOuch, looks like you ended up choosing the door with\n"
       "a goat behind it. What bad luck :(. You missed out on the\n prize "
       "of a lifetime. Better luck next time!\n\nThat concludes "
       "this episode. Stay tuned for another episode\n"
       "of The Price is Wrong, coming up next!\n" << endl;
   }//end else

}//close main


void printGoatDoor(int doorNum){
   cout << "\nLets make things interesting... Door #" << doorNum << 
    " has a goat behind it!" << endl;

   //print out a door that has a goat inside of it
   cout << "   ____________   " << endl;
   cout << "  |            |  " << endl;
   cout << "  |            |  " << endl;
   cout << "  |  DOOR #" << doorNum <<"   |  " << endl;
   cout << "  |            |  " << endl;
   cout << "  |            |  " << endl;
   cout << "  |   (GOAT)   |  " << endl;
   cout << "  |            |  " << endl;
   cout << "  |            |  " << endl;
   cout << "  |            |  " << endl;
   cout << "  |            |  " << endl;
   cout << "  |            |  " << endl;
   cout << "  |____________|  " << endl;
}//close printGoatDoor(...)


int validateDoor(){
   int doorChoice = 0;
   string input;
   do {
      //prompt user for input
      cout << "Please select a door number (1-3): ";

      //input whole line
      getline(cin, input);
      //make sure user input was only one character long
      if(!regex_match(input, regex("(\\+|-)?[[:digit:]]+")))
         cout << "You must enter a VALID door NUMBER (1-3)!\n" << endl;
      else	{
         doorChoice = stoi(input);
         if(doorChoice < 1 || doorChoice > 3)
            cout << "You must enter a number between 1-3!\n" << endl;
      }//end else

      //end while
   } while(doorChoice < 1 || doorChoice > 3);
   return doorChoice;
}//close validateDoor()


int changeDoorOption(int userChoice, int changeOption){
   //char used to store the user's response when prompted
   //whether they would like to switch doors or not.
   char switchDoors = 'A';
   string input;
   do {
      //prompt user for input
      cout << "\nWould you like to switch your door with Door #"
       << changeOption << "? (Y/N/y/n):"<< endl;
      //input whole line
      getline(cin, input);
      //make sure user input was only one character long
      if(input.length() != 1)	
         cout << "\nPlease only enter one character (Y/N/y/n)!";
      else
         switchDoors = input[0];	
      //end while
   } while(switchDoors != 'y' && switchDoors != 'Y'  && 
      switchDoors != 'n' && switchDoors != 'N'  );

   //return appropriate value
   if (switchDoors == 'y' || switchDoors == 'Y')
      return changeOption;
   else
      return userChoice;
}//close changeDoorOption(...)

/* Output:
* (a) a run where the user does not switch and wins:

Welcome to another exciting episode of The Price is Wrong!
____________       ____________       ____________
|            |     |            |     |            |
|            |     |            |     |            |
|  DOOR #1   |     |  DOOR #2   |     |  DOOR #3   |
|            |     |            |     |            |
|            |     |            |     |            |
| O          |     | O          |     | O          |
|            |     |            |     |            |
|            |     |            |     |            |
|            |     |            |     |            |
|            |     |            |     |            |
|            |     |            |     |            |
|____________|     |____________|     |____________|

Behind only one door lies a great prize; the other two doors
have a goat behind them.
Please select a door number (1-3): 12
Please select a door number (1-3): =5

You must enter a VALID door NUMBER (1-3)!
Please select a door (1-3): 25
Please select a door (1-3): 1

Lets make things interesting... Door #2 has a goat behind it!
____________
|            |
|            |
|  DOOR #2   |
|            |
|            |
|   (GOAT)   |
|            |
|            |
|            |
|            |
|            |
|____________|

Would you like to switch your door with Door #3? (Y/N/y/n):
Young

Please only enter one character (Y/N/y/n)!
Would you like to switch your door with Door #3? (Y/N/y/n):
n

Alright, lets see what's behind DOOR #1!
...
____________
|            |
|            |
|  DOOR #1   |
|            |
|            |
|GRAND PRIZE!|
|            |
|            |
|            |
|            |
|            |
|____________|

CONGRADULATIONS!!! You have won the grand prize of:

A brand new home entertainment system! Now you have
everything you need to entertain guests during a party or just
enjoy a movie night with your loved ones. This entertainment system
comes complete with a brand new television, wall mount, surround
sound speaker system, and a 10 year warranty on each item. Enjoy!

Well, that concludes this episode. See you next time on
The Price is Wrong!

Press any key to continue . . .


* (b) a run where the user switches and wins

Welcome to another exciting episode of The Price is Wrong!
____________       ____________       ____________
|            |     |            |     |            |
|            |     |            |     |            |
|  DOOR #1   |     |  DOOR #2   |     |  DOOR #3   |
|            |     |            |     |            |
|            |     |            |     |            |
| O          |     | O          |     | O          |
|            |     |            |     |            |
|            |     |            |     |            |
|            |     |            |     |            |
|            |     |            |     |            |
|            |     |            |     |            |
|____________|     |____________|     |____________|

Behind only one door lies a great prize; the other two doors
have a goat behind them.
Please select a door (1-3): 2

Lets make things interesting... Door #3 has a goat behind it!
____________
|            |
|            |
|  DOOR #3   |
|            |
|            |
|   (GOAT)   |
|            |
|            |
|            |
|            |
|            |
|____________|

Would you like to switch your door with Door #1? (Y/N/y/n):
Y

Alright, lets see what's behind DOOR #1!...
____________
|            |
|            |
|  DOOR #1   |
|            |
|            |
|GRAND PRIZE!|
|            |
|            |
|            |
|            |
|            |
|____________|

CONGRADULATIONS!!! You have won the grand prize of:

A brand new 2014 Ford Mustang! Man are you lucky; now
you can ride anywhere in style with this brand new muscle car! It
isn't even available to the public yet! Warning, may cause an 
excessive spike in popularity. Just don't forget to put gas in it...

Well, that concludes this episode. See you next time on
The Price is Wrong!

Press any key to continue . . .


* (c) a run where the user does not switch and looses

Welcome to another exciting episode of The Price is Wrong!
____________       ____________       ____________
|            |     |            |     |            |
|            |     |            |     |            |
|  DOOR #1   |     |  DOOR #2   |     |  DOOR #3   |
|            |     |            |     |            |
|            |     |            |     |            |
| O          |     | O          |     | O          |
|            |     |            |     |            |
|            |     |            |     |            |
|            |     |            |     |            |
|            |     |            |     |            |
|            |     |            |     |            |
|____________|     |____________|     |____________|

Behind only one door lies a great prize; the other two doors
have a goat behind them.
Please select a door (1-3): 3

Lets make things interesting... Door #1 has a goat behind it!
____________
|            |
|            |
|  DOOR #1   |
|            |
|            |
|   (GOAT)   |
|            |
|            |
|            |
|            |
|            |
|____________|

Would you like to switch your door with Door #2? (Y/N/y/n):
n

Alright, lets see what's behind DOOR #3!...
____________
|            |
|            |
|  DOOR #3   |
|            |
|            |
|   (GOAT)   |
|            |
|            |
|            |
|            |
|            |
|____________|

Ouch, looks like you ended up choosing the door with
a goat behind it. What bad luck :(. You missed out on the 
prize of a lifetime. Better luck next time!

That concludes this episode. Stay tuned for another episode
of The Price is Wrong, coming up next!

Press any key to continue . . .


* (d) a run where the user switches and loses

Welcome to another exciting episode of The Price is Wrong!
____________       ____________       ____________
|            |     |            |     |            |
|            |     |            |     |            |
|  DOOR #1   |     |  DOOR #2   |     |  DOOR #3   |
|            |     |            |     |            |
|            |     |            |     |            |
| O          |     | O          |     | O          |
|            |     |            |     |            |
|            |     |            |     |            |
|            |     |            |     |            |
|            |     |            |     |            |
|            |     |            |     |            |
|____________|     |____________|     |____________|

Behind only one door lies a great prize; the other two doors
have a goat behind them.
Please select a door (1-3): 1

Lets make things interesting... Door #2 has a goat behind it!
____________
|            |
|            |
|  DOOR #2   |
|            |
|            |
|   (GOAT)   |
|            |
|            |
|            |
|            |
|            |
|____________|

Would you like to switch your door with Door #3? (Y/N/y/n):
Neptune

Please only enter one character (Y/N/y/n)!
Would you like to switch your door with Door #3? (Y/N/y/n):
Y

Alright, lets see what's behind DOOR #3!...
____________
|            |
|            |
|  DOOR #3   |
|            |
|            |
|   (GOAT)   |
|            |
|            |
|            |
|            |
|            |
|____________|

Ouch, looks like you ended up choosing the door with
a goat behind it. What bad luck :(. You missed out on the
prize of a lifetime. Better luck next time!

That concludes this episode. Stay tuned for another episode
of The Price is Wrong, coming up next!

Press any key to continue . . .

*/
