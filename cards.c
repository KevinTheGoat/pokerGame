/*============================================================================
Source code: cards.c

Description: handles all operations of cards such as creating and showing
    strength of hand
============================================================================*/

#include "studPoker.h"

/*____________________________________________________________________________
function createCard(currentSuit, currentRank)

purpose: creates a card based on the current card
    value function is used to created card for deck

@param currentSuit - the value of the suit of the card to be created
@param currentRank - the value of the rank of the card to be created

@return createCard - the card created by currentSuit and currentPlayer
____________________________________________________________________________*/
struct card createCard(int currentSuit, int currentRank)
{
    struct card createdCard;
    createdCard.suit = currentSuit % MAXSUIT;
    createdCard.rank = currentRank % MAXRANK;

    return createdCard;
}

/*____________________________________________________________________________
function showCard(currentCard)

purpose: prints cards that are passed to it

@param currentCard - currentCard to be printed

@return void
____________________________________________________________________________*/
void showCard(struct card currentCard)
{

    showRank(currentCard.rank);
    showSuit(currentCard.suit);
}

void showRank(int rank)
{

    if (rank == two)
    {
        printf("2");
    }
    else if (rank == three)
    {
        printf("3");
    }
    else if (rank == four)
    {
        printf("4");
    }
    else if (rank == five)
    {
        printf("5");
    }
    else if (rank == six)
    {
        printf("6");
    }
    else if (rank == seven)
    {
        printf("7");
    }
    else if (rank == eight)
    {
        printf("8");
    }
    else if (rank == nine)
    {
        printf("9");
    }
    else if (rank == ten)
    {
        printf("T");
    }
    else if (rank == jack)
    {
        printf("J");
    }
    else if (rank == queen)
    {
        printf("Q");
    }
    else if (rank == king)
    {
        printf("K");
    }
    else if (rank == ace)
    {
        printf("A");
    }
}
void showSuit(int suit)
{
    if (suit == spades)
    {
        printf("S");
    }
    else if (suit == hearts)
    {
        printf("H");
    }
    else if (suit == diamonds)
    {
        printf("D");
    }
    else if (suit == clubs)
    {
        printf("C");
    }
    printf(" ");
}
