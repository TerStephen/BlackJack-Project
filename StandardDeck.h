/** StandardDeck.h
 *	
 *	A class representing a standard playing card deck.
 * Some of the code for this file was written when
 * referencing Thom Macdonalds StandardPlayingCard.h
 * C++ class file. 
 *
 *   
 *	@authors	Terrel Stephen / Kody Beattie
  *              (100588120)     (100638859)
 *	@version	2017.01
 *	@since		December 27, 2017
*/

#ifndef _STD_DECK
#define _STD_DECK

#include <iostream>
#include <stdexcept>
#include <sstream>
#include <time.h>
#include "StandardPlayingCard_Enum.h"
using namespace std;	

/*
A class representing a standard deck of 52 playing cards.
If you'd like to see the card class created by Thom Macdonald please
view StandardPlayingCard.h.
*/
class StandardDeck
{
	public:	
		//defualt constructor
		// Calls Initialize to take care of setting up the deck
		StandardDeck(): cards(0) {Initialize();}
		
		virtual void Initialize();
		
		~StandardDeck(){delete [] cards;} //Deck destructor
		StandardDeck(const StandardDeck &oldStandardDeck); // Copy constructor
		StandardDeck & operator=(const StandardDeck &oldStandardDeck); // Assignment Operator overload
		int CardsRemaining() const {return remainingCards;} // returns the number of cards remaining in deck
		StandardPlayingCard DrawNextCard(); // Draws the next card from the deck
		StandardPlayingCard DrawRandomCard(); // Draws a random card fromm the deck
		void Shuffle(); // shuffles the deck into a random order
		
	private:
		
		int remainingCards;	// tracks the number of cards remaining in the deck
		StandardPlayingCard *cards;
};

/*
Method Name: Initialize
Created: 2017-12-27
Description: This is a method used to set or reset the cards in the deck.
			It first checks to see if the deck is already set with some
			configuration of cards, if so, it clears the old cards out of
			memory. If the deck has not been set or the memory has been 
			cleared, the size of the deck is set to 52, and the deck is
			populated with all the cards you would find in a standard deck
			excluding jokers.
*/
void StandardDeck::Initialize()
{
	if(!cards) // check if deck is already set
	{
		delete [] cards; // if so delete current deck
	}
	const int SIZE=52; // set number of cards in deck to 52 
	remainingCards = SIZE; // set remaining cards in deck to the same as the deck size
	cards = new StandardPlayingCard [SIZE]; // create a card object
	int card = 0; // use as a counter to track number of cards created
	while(card < SIZE)
	{
		// create all cards in a standard deck, grouped by suit
		for(int i=StandardPlayingCard::MIN_SUIT;i<=StandardPlayingCard::MAX_SUIT;i++)
		{
			for(int j=StandardPlayingCard::MIN_RANK;j<=StandardPlayingCard::MAX_RANK;j++)
			{
				Suit suit = (Suit) i;
				Rank rank = (Rank) j;
				cards[card] = StandardPlayingCard(rank,suit,true);
				card++;
			}
		}
	}
}

/*
Method Name: Copy Constructor
Created: 2017-12-27
Description: Create a new deck based on a copy of a source deck.
*/
StandardDeck::StandardDeck(const StandardDeck &oldStandardDeck)
{
	remainingCards = oldStandardDeck.remainingCards; // determine the number of cards in the source deck
	cards = new StandardPlayingCard [remainingCards]; // create a deck the size of the source deck
	// for every card in the source deck, add the same card to the new deck
	for(int card=0;card<(remainingCards);card++)
	{
		cards[card] = oldStandardDeck.cards[card];
	}
}

/*
Method Name: Assignment Operator Overload
Created: 2017-12-27
Description: Overloads the behaviour of '=' when working with the deck class.
*/
StandardDeck& StandardDeck::operator=(const StandardDeck &oldStandardDeck)
{
	delete [] cards;// clear the old cards from the deck we are editing
	remainingCards = oldStandardDeck.remainingCards; // track the remainging cards in the source deck
	cards = new StandardPlayingCard [remainingCards]; // build a new deck based on the number of cards in the source deck
	// for every card in the source deck, add that card to the deck we are editing
	for(int card=0;card<(remainingCards);card++)
	{
		cards[card] = oldStandardDeck.cards[card];
	}
	return *this;
}

/*
Method Name: DrawNextCard
Created: 2017-12-27
Description: Gets the card object at the 0 th element of the deck i.e. the
			first card of the deck.
*/
StandardPlayingCard StandardDeck::DrawNextCard()
{
	StandardPlayingCard nextCard; // create a new card object
	nextCard = cards[0]; // grab the first card from the deck
	remainingCards--; // update the remaining cards in the deck to be one less
	// for every card in the deck, shift them one position to the front
	for(int i = 0; i < remainingCards; i++)
	{
		cards[i] = cards[i+1];
	}
	return nextCard;	
} 

/*
Method Name: DrawRandomCard
Created: 2017-12-27
Description: Draws a random card from the deck.
*/
StandardPlayingCard StandardDeck::DrawRandomCard()
{
	StandardPlayingCard randomCard; // create a playing card object
	int randomIndex = rand() % remainingCards; // create the random index
	randomCard = cards[randomIndex]; // grab the card at the random index
	remainingCards--; // update the remaining cards to be one less
	// for every card after the random index, shift up one to the front
	for(int i = randomIndex; i < remainingCards; i++)
	{
		cards[i] = cards[i+1];
	}
	return randomCard;	
}

/*
Method Name: Shuffle
Created: 2017-12-27
Description: Places cards in a random order.
*/
void StandardDeck::Shuffle()
{
	StandardPlayingCard card1; // create one instance of a card
	StandardPlayingCard card2; // create a second instance of a card
	int randomIndex; // set a random index
	// for every card in the deck, select a random index and swap the current card
	// with the card at the random index. Like a swap sort in a way.
	for(int card=0; card < remainingCards; card++)
	{
		randomIndex = rand() % remainingCards; // select a random index
		card1 = cards[card]; // get the current selected card
		card2 = cards[randomIndex]; // get the card at the random index
		cards[card] = card2; // put the random card at the current selected position
		cards[randomIndex] = card1; // put the current card at the randomly selected index
	}
}
#endif
