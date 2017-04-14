/*============================================================================
Source code: deck.c

Description: handles all operations related to deck such as creating one
    copying and shuffling.  also creates a game.
============================================================================*/

#include "studPoker.h"

/*____________________________________________________________________________
function showDeck(showDeck)

purpose: print the cards of the deck thats is passed to it

@param showDeck - deck to be shown

@return void
____________________________________________________________________________*/
void showDeck(struct deck showDeck)
{
    int deckIndex;
    for (deckIndex = ZERO; deckIndex < MAXDECKSIZE; deckIndex++)
    {

        showCard(showDeck.deckCard[deckIndex]);
        if ((deckIndex % MAXRANK) == MAXRANK - ONE)
        {
            printf("\n");
        }
    }
}

/*____________________________________________________________________________
function struct deck createDeck()

purpose: creates a deck using the struct from header
    calls the creat card function and places in array

@return newDeck - the new deck that has been created
____________________________________________________________________________*/
struct deck createDeck()
{
    struct deck newDeck;
    int currentSuit = ZERO;
    int currentRank = ZERO;
    int deckIndex;

    for (deckIndex = ZERO; deckIndex < MAXDECKSIZE; deckIndex++)
    {
        newDeck.deckCard[deckIndex] = createCard(currentSuit, currentRank);
        currentRank++;

        if (currentRank % MAXRANK == ZERO)
        {
            currentSuit++;
        }
    }
    return newDeck;
}
/*____________________________________________________________________________
Function: createGame(shuffledDeck, playerAmount)

Purpose: creates a game from the deck passed and fills it with players using 
    the createplayer Function

@param aDeck - takes in a deck preferably shuffled
@param playerAmount - takes in the amount of players to play game

@return a full game with completed player
____________________________________________________________________________*/
struct game createGame(struct deck aDeck, int playerAmount)
{
    struct game createdGame;
    struct player createdPlayer;
    int currentPlayer = ZERO;
    struct card *deckLocation = aDeck.deckCard;
    createdGame.amountOfPlayers = playerAmount;

    while (currentPlayer < playerAmount)
    {
        createdPlayer = createPlayer(&deckLocation);
        createdPlayer.playerNumber = currentPlayer + ONE;
        createdGame.gamePlayers[currentPlayer] = createdPlayer;
        currentPlayer++;
    }

    return createdGame;
}

/*____________________________________________________________________________
function shuffle(OGDeck)

purpose: creates a pointer to the array of cards then shuffles 
    by iterating through deck and switching it with a randomly 
    selected index chosen by randIndex(self created algorithm)

@param OGDeck - original deck to be shuffled

@return shuffledDeck - a shuffled version of the orginal deck
____________________________________________________________________________*/
struct deck shuffle(struct deck OGDeck)
{
    int deckIndex;
    struct card *cardPoint = OGDeck.deckCard;
    struct deck shuffledDeck = OGDeck;

    for (deckIndex = ZERO; deckIndex < MAXDECKSIZE; deckIndex++)
    {
        int randIndex = (rand() % MAXDECKSIZE);
        swap(&shuffledDeck.deckCard[deckIndex],
             &shuffledDeck.deckCard[randIndex]);
    }

    return shuffledDeck;
}

/*____________________________________________________________________________
function swap(deckIndex, randIndex)

purpose: swaps the value of the pointers uses temp to hold content
     of pointer(self created algorithm)

@param deckIndex - an index in the deck usually chosen in order
@param randIndex - a randomly select index to swap with deckIndex

@return void
____________________________________________________________________________*/
void swap(struct card *deckIndex, struct card *randIndex)
{
    struct card temp = *deckIndex;
    *deckIndex = *randIndex;
    *randIndex = temp;
}
