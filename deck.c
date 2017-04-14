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

/*____________________________________________________________________________
function zCheatGame(deckIndex, randIndex)

purpose: hardcodes deck to cheat a specific value in order to test for rare
    hand ranks

@param cheatDeck - deck to be overridden

@return cheatDeck - cheated deck with first 5 cards overridden
____________________________________________________________________________*/
struct deck zCheatGame(struct deck cheatDeck)
{
    /*straight flush*/
    cheatDeck.deckCard[0].suit = 0;
    cheatDeck.deckCard[0].rank = 0;
    cheatDeck.deckCard[1].suit = 0;
    cheatDeck.deckCard[1].rank = 1;
    cheatDeck.deckCard[2].suit = 0;
    cheatDeck.deckCard[2].rank = 2;
    cheatDeck.deckCard[3].suit = 0;
    cheatDeck.deckCard[3].rank = 3;
    cheatDeck.deckCard[4].suit = 0;
    cheatDeck.deckCard[4].rank = 4;
    /*Four of a Kind*/
    cheatDeck.deckCard[5].suit = 0;
    cheatDeck.deckCard[5].rank = 1;
    cheatDeck.deckCard[6].suit = 0;
    cheatDeck.deckCard[6].rank = 1;
    cheatDeck.deckCard[7].suit = 0;
    cheatDeck.deckCard[7].rank = 1;
    cheatDeck.deckCard[8].suit = 3;
    cheatDeck.deckCard[8].rank = 1;
    cheatDeck.deckCard[9].suit = 4;
    cheatDeck.deckCard[9].rank = 4;
    /*Full House*/
    cheatDeck.deckCard[10].suit = 0;
    cheatDeck.deckCard[10].rank = 0;
    cheatDeck.deckCard[11].suit = 2;
    cheatDeck.deckCard[11].rank = 0;
    cheatDeck.deckCard[12].suit = 0;
    cheatDeck.deckCard[12].rank = 0;
    cheatDeck.deckCard[13].suit = 0;
    cheatDeck.deckCard[13].rank = 4;
    cheatDeck.deckCard[14].suit = 0;
    cheatDeck.deckCard[14].rank = 4;
    /*Flush*/
    cheatDeck.deckCard[15].suit = 0;
    cheatDeck.deckCard[15].rank = 0;
    cheatDeck.deckCard[16].suit = 0;
    cheatDeck.deckCard[16].rank = 1;
    cheatDeck.deckCard[17].suit = 0;
    cheatDeck.deckCard[17].rank = 2;
    cheatDeck.deckCard[18].suit = 0;
    cheatDeck.deckCard[18].rank = 3;
    cheatDeck.deckCard[19].suit = 0;
    cheatDeck.deckCard[19].rank = 5;

    /*Straight*/
    cheatDeck.deckCard[20].suit = 2;
    cheatDeck.deckCard[20].rank = 0;
    cheatDeck.deckCard[21].suit = 0;
    cheatDeck.deckCard[21].rank = 1;
    cheatDeck.deckCard[22].suit = 0;
    cheatDeck.deckCard[22].rank = 2;
    cheatDeck.deckCard[23].suit = 0;
    cheatDeck.deckCard[23].rank = 3;
    cheatDeck.deckCard[24].suit = 0;
    cheatDeck.deckCard[24].rank = 4;

    /*Three of a kind*/
    cheatDeck.deckCard[25].suit = 0;
    cheatDeck.deckCard[25].rank = 0;
    cheatDeck.deckCard[26].suit = 2;
    cheatDeck.deckCard[26].rank = 0;
    cheatDeck.deckCard[27].suit = 0;
    cheatDeck.deckCard[27].rank = 0;
    cheatDeck.deckCard[28].suit = 0;
    cheatDeck.deckCard[28].rank = 3;
    cheatDeck.deckCard[29].suit = 0;
    cheatDeck.deckCard[29].rank = 4;

    /*Two pair*/
    cheatDeck.deckCard[30].suit = 0;
    cheatDeck.deckCard[30].rank = 0;
    cheatDeck.deckCard[31].suit = 2;
    cheatDeck.deckCard[31].rank = 0;
    cheatDeck.deckCard[32].suit = 0;
    cheatDeck.deckCard[32].rank = 2;
    cheatDeck.deckCard[33].suit = 0;
    cheatDeck.deckCard[33].rank = 2;
    cheatDeck.deckCard[34].suit = 0;
    cheatDeck.deckCard[34].rank = 4;

    /*One pair*/
    cheatDeck.deckCard[35].suit = 0;
    cheatDeck.deckCard[35].rank = 0;
    cheatDeck.deckCard[36].suit = 2;
    cheatDeck.deckCard[36].rank = 0;
    cheatDeck.deckCard[37].suit = 0;
    cheatDeck.deckCard[37].rank = 2;
    cheatDeck.deckCard[38].suit = 0;
    cheatDeck.deckCard[38].rank = 3;
    cheatDeck.deckCard[39].suit = 0;
    cheatDeck.deckCard[39].rank = 4;

    /*High card*/
    cheatDeck.deckCard[40].suit = 0;
    cheatDeck.deckCard[40].rank = 0;
    cheatDeck.deckCard[41].suit = 2;
    cheatDeck.deckCard[41].rank = 1;
    cheatDeck.deckCard[42].suit = 0;
    cheatDeck.deckCard[42].rank = 2;
    cheatDeck.deckCard[43].suit = 0;
    cheatDeck.deckCard[43].rank = 3;
    cheatDeck.deckCard[44].suit = 0;
    cheatDeck.deckCard[44].rank = 5;
    return cheatDeck;
}
