/*============================================================================
Source code:  studPoker.h

Decription: header file for program. contains libraries, constants, structs,
    enums, and prototypes
============================================================================*/

/*libraries*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
/*constants*/
#define MAXSUIT 4    /*size for the number of suits*/
#define MAXRANK 13    /*size for the number of rank*/
#define MAXDECKSIZE (MAXRANK * MAXSUIT)    /*total number of cards in a deck*/
#define HANDSIZE 5    /*the hand size for the current game*/
#define MAXPLAYERS 7    /*max number of players in the game*/
#define NOERROR 0    /*no errors*/
#define ZERO 0    /*value of zero*/
#define ONE 1 /*value of one*/
#define TWOKIND 2 /*value for 2 cards being the same*/
#define THREEKIND 3 /*value for 3 cards being the same*/
#define WAYSTOWIN 9 /*total number of ways to win in poker*/

/*structs*/
struct card
{
    int suit;
    int rank;
};

struct player
{
    struct card cardInHand[HANDSIZE];
    int playerNumber;
    int strength;
};

struct deck
{
    struct card deckCard[MAXDECKSIZE];
};
struct game
{
    struct player gamePlayers[WAYSTOWIN];
    int amountOfPlayers;
};

/*emuns*/
enum handStrength
{
    highCard, onePair, twoPair, threeOfKind, straight, flush, fullHouse,
    fourOfKind, straightFlush
};

enum typesOfSuit
{
    spades, hearts, diamonds, clubs
};

enum typesOfRank
{
    two, three, four, five, six, seven, eight, nine, ten, 
    jack, queen, king, ace
};
enum boolean
{
    isFalse, isTrue 
};

/*prototypes*/
struct player countCards(struct player aPlayer);
struct deck createDeck();
struct card createCard(int currentSuit, int currentRank);
struct game createGame(struct deck shuffledDeck, int playerAmount);
struct player createPlayer(struct card **deckLocation);
struct deck shuffle(struct deck OGDeck);
void showDeck(struct deck showDeck);
void showHandStrength(int handStrength);
void showCard(struct card currentCard);
void showRank(int rank);
void showSuit(int suit);
void showPlayerHand(struct game aGame);
void showWinner(struct player winner[], int numberOfWinners);
struct player sortPlayerHand(struct player aPlayer);
void swap(struct card *deckIndex, struct card *randIndex);
struct deck zCheatGame(struct deck cheatDeck);