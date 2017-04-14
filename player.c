/*============================================================================
Source code: player.c

Description: handles all operations related to layer such as creating a player
    and showing players hand.
============================================================================*/

#include "studPoker.h"

/*____________________________________________________________________________
function countCards (aPlayer)

purpose: count the types of suits and ranks in players hand and then assigns
    them to their own arrays. after that it passes that array to find to
    findHandStrength function to which it will return a value based on the 
    values of the array.

@param aPlayer - the player you wish to assign a strength value 

@return aPlayer - the player after the hand strength has been evaluated
____________________________________________________________________________*/
struct player countCards(struct player aPlayer)
{
    int handRank[MAXRANK] = {ZERO};
    int handSuit[MAXSUIT] = {ZERO};
    int handIndex;

    for (handIndex = ZERO; handIndex < HANDSIZE; handIndex++)
    {
        handRank[aPlayer.cardInHand[handIndex].rank] += ONE;
        handSuit[aPlayer.cardInHand[handIndex].suit] += ONE;
    }
    aPlayer.strength = findHandStrength(handRank, handSuit);

    return aPlayer;
}

/*____________________________________________________________________________
Function: createPlayer(struct card **deckLocation)

Purpose: deckLocation is referencing the address of the array
    made by the deck, cycles through the array up to HANDSIZE
    in the loop it is incrementing the content of the pointer 
    to a pointer which means its actually incrementing through 
    the array to which the second pointer is passed.

@param deckLocation - pointer to the pointer that points to head of deck array

@return - createdPlayer returns a created player to be added to game
____________________________________________________________________________*/
struct player createPlayer(struct card **deckLocation)
{
    int handIndex = ZERO;
    struct player createdPlayer;
    while (handIndex < HANDSIZE)
    {
        createdPlayer.cardInHand[handIndex] = **deckLocation;
        handIndex++;
        (*deckLocation)++;
    }
    &(*deckLocation) + HANDSIZE;

    createdPlayer = sortPlayerHand(createdPlayer);
    createdPlayer = countCards(createdPlayer);

    return createdPlayer;
}

/*____________________________________________________________________________
function findHandStrength (handRank, handSuit)

purpose: checks the hand strength(rank) of the player first checks if it's a 
    flush and then assigns a true or false value to that. then it checks if
    it's a straight and assigns true or false to that. if both of those are
    true then returns straightFlush without checking for combos. if not then
    it checks for possible combos such as 3 of the same card with 2 which
    returns fullhouse or 2 and 2 which would give 2 pairs. after it has
    assigned values to combo variables it returns the strength based on the
    data learned as the enum handStrengths decribed in header

@param handRank - an array that holds how often a specific rank appeared
@param handSuit - an array that holds how often a specific suit appeared

@return enum of type handStrength - it returns the strength(rank) of the hand
____________________________________________________________________________*/
int findHandStrength(int handRank[], int handSuit[])
{
    int rankIndex;
    int suitIndex;
    int straightHandCounter = ONE;
    int flushHand = isFalse;
    int straightHand = isFalse;
    int firstCombo = ZERO;
    int secondCombo = ZERO;

    for (suitIndex = ZERO; suitIndex < MAXSUIT; suitIndex++)
    {
        if (handSuit[suitIndex] == HANDSIZE)
        {
            flushHand = isTrue;
        }
    }

    for (rankIndex = ZERO; rankIndex < MAXRANK; rankIndex++)
    {

        while (handRank[rankIndex] == ONE)
        {
            if (straightHandCounter == HANDSIZE)
            {
                straightHand = isTrue;
            }
            if (straightHand == isTrue && flushHand == isTrue)
            {
                return straightFlush;
            }
            rankIndex++;
            straightHandCounter++;
        }
        straightHandCounter = ONE;
    }

    for (rankIndex = ZERO; rankIndex < MAXRANK; rankIndex++)
    {
        if (handRank[rankIndex] >= secondCombo)
        {
            secondCombo = handRank[rankIndex];
        }
        if (handRank[rankIndex] >= firstCombo)
        {
            secondCombo = firstCombo;
            firstCombo = handRank[rankIndex];
        }
    }
    if (firstCombo == MAXSUIT)
    {
        return fourOfKind;
    }
    else if (firstCombo == THREEKIND && secondCombo == TWOKIND)
    {
        return fullHouse;
    }
    else if (flushHand == isTrue)
    {
        return flush;
    }
    else if (straightHand == isTrue)
    {
        return straight;
    }
    else if (firstCombo == THREEKIND)
    {
        return threeOfKind;
    }
    else if (firstCombo == TWOKIND && secondCombo == TWOKIND)
    {
        return twoPair;
    }
    else if (firstCombo == TWOKIND)
    {
        return onePair;
    }
    else

        return highCard;
}
/*____________________________________________________________________________
function findWinner(aGame)

purpose: finds the winner(s) of a poker game and saves it in an array the
    calls a print function

@param aGame - the game you wish to find the winner of

@return void
____________________________________________________________________________*/

void findWinner(struct game aGame)
{
    int playerIndex = ZERO;
    struct player gameWinner[MAXPLAYERS] = {1, ZERO};
    int winnerIndex = ZERO;
    while (playerIndex < aGame.amountOfPlayers)
    {
        if (aGame.gamePlayers[playerIndex].strength >
            gameWinner[winnerIndex].strength)
        {
            winnerIndex = ZERO;
            gameWinner[winnerIndex] = aGame.gamePlayers[playerIndex];
        }
        else if (aGame.gamePlayers[playerIndex].strength ==
                 gameWinner[winnerIndex].strength)
        {
            if (gameWinner[winnerIndex].playerNumber != ZERO)
            {
                winnerIndex++;
            }
            gameWinner[winnerIndex] = aGame.gamePlayers[playerIndex];
        }

        playerIndex++;
    }
    printf("Winner(s) \n");
    showWinner(gameWinner, winnerIndex);
}

/*____________________________________________________________________________
function showHandStrength(handStrength)

purpose: prints the rank of the hand in a readable string

@param handStrength - the hand strength value to be change to a string

@return void
____________________________________________________________________________*/
void showHandStrength(int handStrength)
{
    const char *HAND_RANK[] = {"High Card", "One Pair", "Two Pairs", 
                          "Three Of a Kind", "Straight", "Flush",
                          "FullHouse","Four Of a Kind", "Straight Flush"};

    printf("%s", HAND_RANK[handStrength]);                       
    printf("\n");
}
/*____________________________________________________________________________
Function: showPlayerHand(currentPlayer)

Purpose: print all the hands for the player in the game

@param aGame - current game who's player hands will be shown

@return void
____________________________________________________________________________*/
void showPlayerHand(struct game aGame)
{
    int handIndex;
    int playerIndex;

    for (playerIndex = ZERO; playerIndex < aGame.amountOfPlayers; playerIndex++)
    {
        printf("\nPlayer %i \nCards: ",
               aGame.gamePlayers[playerIndex].playerNumber);

        for (handIndex = ZERO; handIndex < HANDSIZE; handIndex++)
        {
            showCard(aGame.gamePlayers[playerIndex].cardInHand[handIndex]);
        }
        showHandStrength(aGame.gamePlayers[playerIndex].strength);
    }

    printf("\n");
}
/*____________________________________________________________________________
function showWinner(gameWinner, numberOfWinners)

purpose: print out the list of winners

@param gameWinner - an array of all the winners
@param numberOfWinners - number of winners

@return void
____________________________________________________________________________*/
void showWinner(struct player gameWinner[], int numberOfWinners)
{
    int winnerIndex = ZERO;
    int handIndex;
    while (winnerIndex <= numberOfWinners)
    {
        printf("\nPlayer %i \nCards: ", gameWinner[winnerIndex].playerNumber);
        for (handIndex = ZERO; handIndex < HANDSIZE; handIndex++)
        {
            showCard(gameWinner[winnerIndex].cardInHand[handIndex]);
        }
        winnerIndex++;
        printf("\n");
    }
}
/*____________________________________________________________________________
Function: sortPlayerHand (aPlayer)


Purpose: sort players hand using insertion sort. algorithm for inserstion sort
    recieved from https://en.wikipedia.org/wiki/Insertion_sort

@param aPlayer - player whose hand will be sorted by face value(rank)

@return aPlayer - the value of aPlayer after it has been sorted
____________________________________________________________________________*/
struct player sortPlayerHand(struct player aPlayer)
{
    int handIndex;
    int secondHandIndex;
    struct card tempCard;

    for (secondHandIndex = ONE; secondHandIndex < HANDSIZE; secondHandIndex++)
    {
        handIndex = secondHandIndex;
        while ((handIndex > ZERO) &&
               (aPlayer.cardInHand[handIndex].rank <
                aPlayer.cardInHand[handIndex - ONE].rank))
        {
            tempCard = aPlayer.cardInHand[handIndex];
            aPlayer.cardInHand[handIndex] = aPlayer.cardInHand[handIndex - ONE];
            aPlayer.cardInHand[handIndex - ONE] = tempCard;
            handIndex--;
        }
    }

    return aPlayer;
}