/** StandardPlayingCard.h
 *	
 *	Incorporating enumerated types into the StandardPlayingCard class.   
 *
 *   
 *	@author		Thom MacDonald
 *	@version	2014.03
 *	@since		Oct 2014
 *	@see		Bronson, G. (2012).  Chapter 10 Introduction to Classes. 
 *				  In A First Book of C++ (4th ed.). Boston, MA: Course Technology.
 *	@see		Classes.StaticMembers.Solution.cpp
*/

#ifndef _STD_PLAYINGCARD_ICE
#define _STD_PLAYINGCARD_ICE

#include <iostream>
#include <stdexcept>
#include <sstream>
using namespace std;	

// Added: an enumerated type to represent the rank of the playing card
enum Rank // converts implicitly to int
{
	Ace = 1, // explicity set Ace to 1. Remainding enumerations will follow in sequence
	Two, 
	Three, 
	Four, 
	Five, 
	Six, 
	Seven, 
	Eight, 
	Nine, 
	Ten, 
	Jack, 
	Queen, 
	King
};

// Added: an enumerated type to represent the suit of the playing card
enum Suit // converts implicitly to int
{
	Spades, 
	Hearts, 
	Diamonds, 
	Clubs
};

class StandardPlayingCard // Class declaration section
{
	public:	
		
		// Static data members: shared between all objects of the class
		
		static const string RANKS[]; // an array that holds the names of the ranks								
		static const string SUITS[]; // an array that holds the names of the suits
		static const Rank MIN_RANK;	// UPDATED
		static const Rank MAX_RANK;	// UPDATED
		static const Suit MIN_SUIT; // New! Added for consistancy
		static const Suit MAX_SUIT;	// UPDATED
		
		// Constructor(s):
		// UPDATED: Default constructor using an initialization list
		StandardPlayingCard(): myRank(Rank::Ace), mySuit(Suit::Diamonds), isFaceUp(true) {}
		
		// UPDATED: Parameterized constructor
		StandardPlayingCard(Rank rank, Suit suit, bool faceUp = true);
		
		// UPDATED: Accessor(s):
		string getRankString() const {return RANKS[(int) myRank];} 
		string getSuitString() const {return SUITS[(int) mySuit];} 
		int getRankInteger() {return (int) myRank;}
		// Operators		
		operator string () const; // convert the obj to a string.

		// UPDATED: Mutator(s):
		void setRank(Rank rank); // sets the rank number
		void setSuit(Suit suit); // sets the suit number

		// Other Mutator(s):
		bool flipCard() {return (isFaceUp = !isFaceUp);} // changes the face up state

		// Public member variables
		bool isFaceUp; // true if face-up, false if face-down
	
	// UPDATED: Private members are only accessible inside the class
	private:
		Rank myRank; // value to represent the rank
		Suit mySuit; // value to represent the suit
		
		
}; // end of class declaration section


// Class defintion section

// Static data member initialization
const string StandardPlayingCard::SUITS[] = { "Spades", "Hearts", "Diamonds", "Clubs" };
const string StandardPlayingCard::RANKS[] = { "Not Used", "Ace", "Two", "Three", "Four", "Five", 
								"Six", "Seven", "Eight", "Nine", "Ten", "Jack", "Queen", "King"};
const Rank StandardPlayingCard::MIN_RANK = Rank::Ace;	// UPDATED
const Rank StandardPlayingCard::MAX_RANK = Rank::King;	// UPDATED
const Suit StandardPlayingCard::MIN_SUIT = Suit::Spades; // New! Added for consistancy
const Suit StandardPlayingCard::MAX_SUIT = Suit::Clubs;	// UPDATED


/** UPDATED: Parameterized Constructor for StandardPlayingCard class
 *  @param	rank: Rank (converts to a number between 1 and 13)
 *  @param	suit: Suit (converts to a number between 0 and 3)
 *  @param	faceUp: bool (true if face-up, false if not)
 *	@throws	out_of_range exception if rank or suit params are invalid
 */
StandardPlayingCard::StandardPlayingCard(Rank rank, Suit suit, bool faceUp)
{
	// Set the rank and suit with validation
	setRank(rank); 
	setSuit(suit);
	// set the face-up field
	isFaceUp = faceUp;
}
 
/** UPDATED: setRank Method for StandardPlayingCard class
 *	Sets the rank of this StandardPlayingCard object.
 *  @param	rank: Rank (converts to a number between 1 and 13)
 *	@throws	out_of_range exception if the param is invalid
 */
void StandardPlayingCard::setRank(Rank rank)
{
	// if the rank parameter is not a valid rank number
	if(rank < MIN_RANK || rank > MAX_RANK)
	{
		// declare a stringstream object
		stringstream strOut; 
		// build a descriptive error string.
		strOut << "Rank argument: " << rank
			   << " is out of range. Rank must be between "
			   << MIN_RANK << " and " << MAX_RANK << ". ";
		// throw an out_of_range exception initialized with
		// the error string
		throw out_of_range(strOut.str());
	}
	else // otherwise, the rank parameter is fine
	{
		// assign the parameter to the member variable
		myRank = rank;
	}
}

/** UPDATED: setSuit Method for StandardPlayingCard class
 *	Sets the suit of this StandardPlayingCard object.
 *  @param	suit: Suit (converts to a number between 0 and 3)
 *	@throws	out_of_range exception if the param is invalid
 */
void StandardPlayingCard::setSuit(Suit suit)
{
	// if the suit parameter is not a valid suit number
	if(suit < MIN_SUIT || suit > MAX_SUIT)
	{
		// declare a stringstream object
		stringstream strOut; 
		// build a descriptive error string.
		strOut << "Suit argument: " << suit
			   << " is out of range. Suit must be between "
			   << MIN_SUIT << " and " << MAX_SUIT << ". ";
		// throw an out_of_range exception initialized with
		// the error string
		throw out_of_range(strOut.str());
	}
	else // otherwise, the rank parameter is fine
	{
		// assign the parameter to the member variable
		mySuit = suit;
	}
}

/** operator string() Method for StandardPlayingCard class
 *	Converts the obj to a string.
 *	@return	the obj state as a string
 */
StandardPlayingCard::operator string () const
{
	// declare a stringstream object
	stringstream strOut; 
	// if the card is face-up
	if(isFaceUp)
	{
		// build a descriptive string from the obj state
		strOut << getRankString() << " of " << getSuitString();
	}
	else // card is face-down
	{
		// string indicates face-down
		strOut << "Face-Down";
	}
	// return the string
	return strOut.str();
}

#endif
