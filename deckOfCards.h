//Oliver Cho 5/31/20
#ifndef H_deckOfCards
#define H_deckOfCards
#include "card.h"
#include <cstdlib>
#include <ctime>
#include <iomanip>

using namespace std;

//constant integer of 52 to represent the number of cards in the deck
const int CARDS_PER_DECK=52;

//Class to represent a deck of standard playing cards
class deckOfCards
{
	private:
		//a pointer to a card to represent the deck
		card* deck;
		//the number of the current card we are looking at
		int currentCard;

	public:
		deckOfCards();
		void shuffle();
		card dealCard();
		void printDeck() const;
	
};

/*
Parameters: None
Return type: None
Purpose: deckOfCards Class default constructor
*/
deckOfCards::deckOfCards()
{
	//string array of all possible faces
	string faces[]={"Ace","One","Two","Three","Four","Five","Six","Seven","Eight","Nine",
		"Ten","Jack","Queen","King"};
	//string array of all possible suits
	string suits[]={"Hearts","Diamonds","Clubs","Spades"};

	//deck gets a new array of 52 because that is the size of a standard playing card deck
	deck=new card[CARDS_PER_DECK];
	//start the curent card we are looking at to 0
	currentCard=0;
	//for each spot in the deck
	for(int count=0;count<CARDS_PER_DECK;count ++)
	{
		//add a card with a face and a suit based on the mod or division
		deck[count]=card(faces[count%13], suits[count/13]);
	}
}

/*
Parameters: None
Return type: None
Purpose: Shuffle the deck of cards
*/
void deckOfCards::shuffle()
{
	//reset the currentCard to 0 in case it has been moved
	currentCard=0;
	//for each card in the deck
	for(int first=0;first<CARDS_PER_DECK;first++)
	{
		//use rand and time to create a "random" location in the deck
		int second=(rand()+time(0)) % CARDS_PER_DECK;

		//swap the card of the current location and the random selected location
		card temp=deck[first];
		deck[first]=deck[second];
		deck[second]=temp;
	}
}

/*
Parameters: None
Return type: Class Object Card
Purpose: give out a card from the deck
*/
card deckOfCards::dealCard()
{
	//if the currentCard value is greater than 52 we have gone through the whole
	//deck, you need to reshuffle
	if(currentCard>CARDS_PER_DECK)
	{
		shuffle();
	}
	//if the currentCard is less than 52 we can still deal cards
	if(currentCard <CARDS_PER_DECK)
	{
		//return the next card
		return (deck[currentCard++]);
	}
	//otherwise return the first card in the deck
	return deck[0];
}

/*
Parameters: None
Return type: None
Purpose: print the card in the deck in their current order
*/
void deckOfCards::printDeck() const
{

	cout<<left;
	//fore each card in the deck
	for(int i=0;i<CARDS_PER_DECK;i++)
	{
		//print
		cout<<setw(19)<<deck[i].print();
		if((i+1)%4==0)
		{
			cout<<endl;
		}
	}
}

#endif