/** BlackJack.cpp	   
 *	@author		Kody Beattie, Terrel Stephen, Ashante Smith
 *  @Date
 *	Description: This a blackjack program made as the final project for OOP II. It will contain a console UI,
 *				 A player with chips (money), An AI dealer, as well as some play options 
 * 				  
 */
 
#include <sstream>
#include <iomanip>
#include <sstream>
#include <cmath>


#include "MyInputValidation.h"
#include "StandardPlayingCard_Enum.h"
#include "StandardDeck.h"
#include "PlayerClass.h"


using namespace std;
using namespace myValidation;

void BlackJackGame();
void LoadPlayer();


	
int main()
{
	//Declerations
	char menuChoice; //Variable for controlling menus
	bool inputNeeded = true; //Variable for controlling when input on menus isnt needed anymore
	//Generate menu.
	//This menu will allow us to do things like Set names, veiw leaderboards, and whatever else later.
	do
	{
	cout << "Welcome to Group 11 Blackjack!" << endl << endl
	<< "A> Begin Game!" << endl
	<< "B> Load Player!" << endl
	<< "C> Walk Away.." << endl
	<< ": ";
	
	//Prepare for player choice
	fflush(stdin);
	menuChoice = cin.get();
	menuChoice = toupper(menuChoice);
	
		switch(menuChoice)
		{
		
			case 'A': //Start BlackJack 
			BlackJackGame();
			break;
			case 'B': //Load Player 
				inputNeeded = false;
				break;
			case 'C': //End the program premptivly
				inputNeeded = false;
				break;
			default:
				cout << "\nExcuse me? What's your choice?";	
		}
	
	}while (inputNeeded);

	cout << "\nHappy Trails!";	
	cout << endl << endl;
	return 0;
} // end of main()

void BlackJackGame()
{
	//Declare menu variables
	char menuChoice;
	bool inputNeeded = true;
	//Aquire and shuffle deck
	cout << "\nAquiring Deck..";
	StandardDeck deck;
	int numCards = deck.CardsRemaining();
	StandardPlayingCard card;	
	deck.Initialize();
	deck.Shuffle();
	
	//Ask for gamble amount
	//Create hand of 2 for player
	//Create hadn for dealer
	//Calculate Hand and dealer hand.
	//Generale Menu for play
	
	cout << "\nDealing Players..";
	//Get the human player and their Card Hand instanciated
	Player humanPlayer;
	CardHand myHand;
	
	//Display and ask how much the player wishes to bet
	cout << "\n" << "Your chip count is currently: " << humanPlayer.reportChipCount();
	cout << "\n" << "How much do you wish to bet?: ";
	//get bet
	humanPlayer.SetBet(myValidation::GetValidInteger(0, humanPlayer.reportChipCount()));
	
	
	//Add 2 cards to the players hand
	for (int i =0; i < 2; i++)
	{
		card = deck.DrawRandomCard();
		myHand.AddCard(card);
		myHand.setChipCount(i+1);
	}
	//Get the dealer Card Hand instanciated and give it AI
	//Player dealer;
	CardHand dealerHand;
	Dealer dealerAI;
	//Add 2 cards to the Dealers hand
	for (int i =0; i < 2; i++)
	{
		card = deck.DrawRandomCard();
		dealerHand.AddCard(card);
		dealerHand.setChipCount(i+1);
	}
	//Begin blackjack
	cout << "The first match of the session has begun!" << endl << endl;
	cout << "Your hand contains!: \n";	
	myHand.LookAtHand(); //Displays cards
	do
	{
		//If the player hasnt lost or the delear won then keep playing
		if(humanPlayer.isBusted == false || humanPlayer.isSurrender == false || dealerAi.isBusted == false || dealerHand.TotalCardValue() != 21 || myHand.TotalCardValue() != 21)
		{
			cout << "\nA>Would you like to double your bet? It is Currently... " << humanPlayer.betAmount; //Ask for double the bet
			cout << "\nB>Would you like to HIT? Your current hand value is... " << myHand.TotalCardValue(); //Ask for Hit
			cout << "\nC>Would you like to Stand? The Dealers current value is... " << dealerHand.TotalCardValue(); //Ask for Stand
			cout << "\nD>Display my hand!";
			cout << "\nE>I surrender! (Stay out of the round, gain half your gambled chips back)"; //Ask for surrender
			cout << "\n:";
	
			fflush(stdin);
			menuChoice = cin.get();
			menuChoice = toupper(menuChoice);
	
			switch(menuChoice)
			{
				case 'A': //double the bet
				humanPlayer.DoubleDown(humanPlayer.betAmount); //Double the bet
				break;
				case 'B': //Hit (draw and add card to hand and value)
				card = deck.DrawRandomCard();
				myHand.AddCard(card);
				break;
				case 'C': //Stand (stop drawing)
			 	humanPlayer.isStanding;
				break;
				case 'D': //Display Player Hand 
				myHand.LookAtHand();
				break;
				case 'E': //Surrender (Withdraw and take half of bet back)
				myHand.LookAtHand();
				break;
				default:
				cout << "\nThat was an Invalid Option you entered!";	
			}
		}
		else if (myHand.TotalCardValue() == 21 || dealer.isBusted)
		{
			// Player has won, explain why
			cout << "\n\n You won!";
			if (myHand.TotalCardValue() == 21)
			{
				cout << "\nYou have reached 21!";			
			}
			if (dealer.isBusted)
			{
				cout << "\nThe dealer has busted! Over 21!";
				cout << "\nDealer amount!" << dealerHand.TotalCardValue();	 //	Display dealers cards			
			}
			cout << "\nYour earnings!: " << humanPlayer.betAmount;
			humanPlayer.SetChips(humanPlayer.betAmount); // Add bet amount back to player chip count
		}	
		else if (humanPlayer.isSurrender)
		{
			//display recovery cash and give chips back to the player
				cout << "\nYou have surrendered! With: " << humanPlayer.betAmount / 2;
			humanPlayer.SetChips(humanPlayer.betAmount / 2);
		}
		else if (humanPlayer.isBusted || dealerHand.TotalCardValue() == 21)
		{
			// Player has lost, explain why
			cout << "\n\n You lost!";
			if (dealerHand.TotalCardValue() == 21)
			{
				cout << "\nThe dealer reached 21!";			
			}
			if (humanPlayer.isBusted)
			{
				cout << "\nYou busted! Over 21!";
				cout << "\nYour amount!" << myHand.TotalCardValue();					
			}
		}
		else
		{
			//If no one won or lost then the round continues with the delaerAI doing things
			dealerAI.HitOrStand();
		}
	}while (inputNeeded);
		
	//On hit then draw card and total
	//On stand let the dealer draw until they reach >=21
}

void LoadPlayer()
{
	//Start Stream
	//Search for player / OR make new one
	//Set as player name
	//close stream
}

