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
    const char *CARD_RANK[] = {"2", "3", "4", "5", "6", "7",
                                "8","9", "T","J","Q","K","A"};
    printf("%s", CARD_RANK[rank]);

    return;
}
void showSuit(int suit)
{
    const char *CARD_SUIT[] = {"S", "H", "D", "C"};
    printf("%s", CARD_SUIT[suit]);
    printf(" ");
}
