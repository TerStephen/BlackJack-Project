// CardHand Class
#include "StandardPlayingCard_Enum.h"
#include <vector>
#include <iostream>
#include <string>
#include <sstream>
using namespace std;

class CardHand{
		// The CardHand Class handles actions that can be done with a blackjack hand
	public:
		CardHand(): cards(0){}
		void ClearHand(); //Destroys cards in hand
		void LookAtHand(); //Returns and displays cards in hand
		void AddCard(StandardPlayingCard newCard); //Adds new card to hand
		string ShowCard(int cardIndex) const {return cards.at(cardIndex);} //Show SPECIFIC cards
		int GetCardRank(int cardIndex) {return (cards.at(cardIndex)).getRankInteger();} //Show specific card's rank
		int TotalCardValue(); //The total rank value to be used on blackjack cards
		
		
		int reportCardCount() const {return totalCards;} //returns the privae totalCards variable for use elsewhere
		void setChipCount(int x) { totalCards = x; } //Adds this many chips to the user
		//Maybe use a get and set for individual card count?
	private:
		std::vector<StandardPlayingCard> cards; // A vector of cards to store them
		int totalCards=0; //The amount of cards in a players hand
};

void CardHand::ClearHand()
{
	cards.clear();
	std::vector<StandardPlayingCard>(cards).swap(cards);
} 

void CardHand::AddCard(StandardPlayingCard newCard)
{
	cards.push_back(newCard);
}

void CardHand::LookAtHand()
{
	for(int handIndex = 0; handIndex < totalCards; handIndex++)
	{
		cout << ShowCard(handIndex) << endl;
	}	
}

int CardHand::TotalCardValue()
{
	int totalCardValue = 0;
	int rank;
	//cout << "Debug: " << totalCards << "\n";
	
	for(int handIndex = 0; handIndex < totalCards; handIndex++)
	{
		rank = GetCardRank(handIndex);
		//cout << "Debug: " << rank << " rank for card " << handIndex;
		if(rank == 11 || rank == 12 || rank == 13)
		{
			rank = 10;
		}
		else if(rank == 1 && (totalCardValue + 11) <= 21)
		{
			rank = 11;
		}
		totalCardValue += rank;	
	}
	return totalCardValue;
} 


