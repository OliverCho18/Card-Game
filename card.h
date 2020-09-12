//Oliver Cho 5/31/20
#ifndef H_card
#define H_card
#include <string>
#include <iostream>

using namespace std;

//Class to represent a playing card
class card
{
	private:
		//string to represent the card's face or value
		//ex:Queen,Heart,Jack,Ace,One,Two
		string face;
		//string to represent the card's suit
		//ex:Hearts,Spades,Diamonds,Clovers
		string suit;

	public:
		card();
		card(string cardFace, string cardSuit);
		string print() const;
		string getFace();
		string getSuit();
};

/*
Parameters: None
Return type: None
Purpose: Card Class default constructor
*/
card::card()
{
	face="empty";
	suit="empty";
}

/*
Parameters: cardFace: A string to represent what the card's face should be
	cardSuit: A string to represent what the card's suit should be
Return type: None
Purpose: Card Class constructor where the face and suit can be specified
*/
card::card(string cardFace, string cardSuit)
{
	face=cardFace;
	suit=cardSuit;
}

/*
Parameters: None
Return type: String
Purpose: print the face and suit of the card
*/
string card::print() const
{
	return (face + "of" + suit);
}

/*
Parameters: None
Return type: String 
Purpose: get the suit of the card
*/
string card::getSuit()
{
	return suit;
}

/*
Parameters: None
Return type: String 
Purpose: get the face of the card
*/
string card::getFace()
{
	return face;
}

#endif