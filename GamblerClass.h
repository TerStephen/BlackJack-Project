//Gambler Class

#include "CardHand.h"
#include "StandardPlayingCard_Enum.h"

using namespace std;

class Gambler{
	
	public:
		Gambler(): hand(), isStanding(false){}
		void Hit(StandardPlayingCard newCard);
		void Stand() {isStanding=true;}
		bool isStanding;
		bool isBusted = false;
	private:
		CardHand hand;	
			
};

void Gambler::Hit(StandardPlayingCard newCard)
{
	hand.AddCard(newCard);
}

