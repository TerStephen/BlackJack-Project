// Dealer Class


#include "GamblerClass.h"
#include "StandardDeck.h"

using namespace std;

class Dealer:public Gambler
{
	// The Dealer class handles dealer actions and states
	public:
		Dealer(bool isBust=false, bool isStanding=false):Gambler(){}
		
		StandardPlayingCard DealCard();
		
		void HitOrStand();
		
		bool isStanding;
		bool isBust;
		
	private:
		CardHand hand;
};

StandardPlayingCard Dealer::DealCard(StandardDeck deck)
{
	StandardPlayingCard card;
	card = deck.DrawRandomCard();
	return card;
} 

void Dealer::HitOrStand()
{
	if(isBust=false)
	{
		if(isStanding = false)
		{
			if((hand.GetCardRank(0) ==1) || (hand.GetCardRank(1) ==1) && ((hand.TotalCardValue()-hand.GetCardRank(0)) <=6)|| hand.TotalCardValue()-hand.GetCardRank(0) <=6 && hand.TotalCardValue() < 17)
			{
				Dealer.Hit(); 
			}
			else
			{
				Dealer.Stand();
			}
		}
		
	}	
}


