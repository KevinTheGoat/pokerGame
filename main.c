/*============================================================================
    Source code:  main.c
    Author:  Kevin Moreau 
    Student ID:  4804471
    Assignment:  Program #4 Stud Poker
  
    Course:  COP 4338 - Advanced Programming 
    Section:  U04 
    Instructor:  William Feild  
    Due Date:  March 9th, by the end of class

	I hereby certify that this collective work is my own
	and none of it is the work of any other person or entity.
	______________________________________ [Signature]
  
    Language:  C

    Compile: make sure header is in same directory to compile input
    gcc -pedantic -ansi -o studPoker.out  main.c cards.c player.c deck.c
    or
    make build

    Run: to run input ./studPoker.out [hand size] [amount of players]
 			
  -------------------------------------------------------------------------- 
  
    Description:  Write algorithms and programs to implement a simulation of 
        a deck of cards for a game of cards.
                  
    Input:  Accept input via the command-line arguments. Validate command-line 
        input. Input will be the number of cards/hand and the number of hands 
        (players), in that order.
  
    Output:  Display the original deck, display the shuffled deck, and display 
        each of the hands of cards. Then, display the sorted hands, labeling 
        each hand with its poker rank. Decks, hands and cards should be clean, 
        clear and appropriately labeled - do not simply list as a simple column
        or row of values. Next, display a list of winner(s), or clearly 
        designate the winner(s) when you display the labeled hands.
  
    Process:  players, cards, and a deck 
  
    Required Features Not Included:   You may use any material discussed in the
        first seven chapters. Style requirements as discussed in class expected. 
        Efficiency should always be considered. Alway select the most 
        appropriate loop/decision structures and variable/constant types. 
        Functions should focus on a single task. Main() should be high-level 
        tasks only.           
  
    Known Bugs:  N/A
  
============================================================================*/

#include "studPoker.h"

/*____________________________________________________________________________
function main (argc , argv[])

purpose: calls functions to run program at the end of game it creates a "cheat"
    game that tests all possible ways to win

@param argc - number of arguments
@param *argv[] - pointer to a char of array of arguments

@return NOERROR - value returned if no errors were encountered
____________________________________________________________________________*/
int main(int argc, char *argv[])
{
    struct game newGame;
    struct deck OGDeck;
    struct deck shuffledDeck;
    struct deck cheatDeck;
    time_t unsignedTimeInt;
    int numberOfPlayers;
    srand(time(&unsignedTimeInt));

    if (atoi(argv[TWOKIND]) <= MAXPLAYERS && atoi(argv[TWOKIND]) > ZERO)
    {
    numberOfPlayers = atoi(argv[TWOKIND]);
    OGDeck = createDeck();
    printf("\nOriginal Deck\n");
    showDeck(OGDeck);

    shuffledDeck = shuffle(OGDeck);
    printf("\nShuffled Deck\n");
    showDeck(shuffledDeck);
    newGame = createGame(shuffledDeck, numberOfPlayers);
    showPlayerHand(newGame);
    findWinner(newGame);
    printf("*****End of Game*****\n");

    }
    else{
        printf("Invalid player size\n");
    }

    return NOERROR;
}

