/** PlayerClass.h	   
 *	@author		Kody Beattie, Terrel Stephen, Ashante Storm Smith
 *  @Date
 *	Description: This class file represents a basic player and dealer in the game
 *        		of Black Jack.
 * 				  
 */
#include "GamblerClass.h"
#include "StandardDeck.h"
using namespace std;

// A class representing a dealer in the game of black jack
class Dealer:public Gambler
{
	// The Dealer class handles dealer actions and states
	public:
		Dealer(bool isBust=false, bool isStanding=false):Gambler(){} // default constructor
		
		StandardPlayingCard DealCard(StandardDeck deck); // Deals a card
		
		void HitOrStand(); // Allows the dealer to decide if he should stay or hit
		
		bool isStanding; // has the dealer decided to stand
		bool isBust; // has the dealer busted
		
	private:
		CardHand hand; // the dealers hand
};

//DealCard()
//Created: 2018-01-07
// Allows the dealer to deal cards when needed
//   Takes in a Standard card deck
StandardPlayingCard Dealer::DealCard(StandardDeck deck)
{
	StandardPlayingCard card; // the card the dealer will choose
	card = deck.DrawRandomCard(); // get the card from the deck
	return card; // return the selected card
} 

// Hit or Stand ()
//Date Created: 2018-01-07
// Allows the dealer to decide if they should hit or stand
void Dealer::HitOrStand()
{
	// has the dealer busted
	if(isBust==false)
	{
		// is the dealer standing
		if(isStanding == false)
		{
			// determine if 1st or 2nd card is ace or soft 17 or less than 17
			if((hand.GetCardRank(0) ==1) || (hand.GetCardRank(1) ==1) && ((hand.TotalCardValue()-hand.GetCardRank(0)) <=6)|| hand.TotalCardValue()-hand.GetCardRank(0) <=6 && hand.TotalCardValue() < 17)
			{
				// hit if so
				Dealer.Hit(); 
			}
			else
			{
				// stand if not
				Dealer.Stand();
			}
		}
		
	}	
}

// Player Class
//Created: 2018-02-07
//Represents a Player in the game of poker
class Player:public Gambler
{
	// The player class handles Player actions and states including chipcount
	public:
		Player(int chips=100, bool isSurrender=false):Gambler(){} // default constructor
		
		
		int betAmount; // the amount to be betted
		bool isStanding; // is the player standing
		bool isSurrender; // si the player surrendering
		
		
		void DoubleDown(int betAmount); // allow the player to double down
		void Surrender() {isSurrender=true;} // allow the player to surrender
				
		void SetBet(int bet) { betAmount = bet; chips = chips - betAmount;} // set the players bet
		void SetChips(int chipPayout) { chips = chips + chipPayout;} // set the player chip number
		
		int reportChipCount() const {return chips;} // report the number of chips the player has
		
		
	private:
		int chips = 100; // the players chip
		CardHand hand;	// the players hand
		
	
};

// DoubleDown
//Date: 2018-01-10
// Allows player to double down on their hand if they choose to
//     accepts the number of chips a player has bet
void Player::DoubleDown(int betAmount)
{
	//Double down only if the player has enough chips remaining
	if (betAmount*2 < reportChipCount())
	{
		betAmount = betAmount*2;
	}
	else
	{
		cout << "\nYour increased wager would be too high!";
	}
	//Take one more card
	//then stand
	
}



