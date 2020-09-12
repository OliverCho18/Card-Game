//Oliver Cho 5/31/20
#ifndef H_player
#define H_player
#include "card.h"
#include <map>

using namespace std;



//Class to represent a player playing the game
class player
{
	private:
		//number of wins
		int numOfWins;
		//number of facecards in the hand
		int numOfFaceCards;
		//number of duplicates in the hand
		int numOfDuplicates;

		//map of current hand, key is the card's face value in a string
		//value is the number of cards of that face value the player has 
		//in his hand represented by a string
		map <string, int> hand;

	public:
		player();
		void addToHand(card);
		void printHand();
		bool checkIfWonRound();
		void resetRound();
		int getNumOfWins();
};

/*
Parameters: None
Return type: None
Purpose: player Class default constructor
*/
player::player()
{
	//set number of duplicates to 0
	numOfDuplicates=0;
	//set number of wins to 0
	numOfWins=0;
	//set number of face cards to 0
	numOfFaceCards=0;
}

/*
Parameters: entry: a instance of the class object card to represent the card 
	to be added to the players hand
Return type: None
Purpose: Function to add a card to the player's hand
*/
void player::addToHand(card entry)
{
	//save the card's face value as a string cardFace
	string cardFace=entry.getFace();
	//check if the card is a face card
	if(cardFace=="Jack" || cardFace=="Queen" || cardFace=="King" || cardFace=="Ace")
	{
		cout<<"this is a face card"<<endl;
		//if yes the increment the number of face cards in the hand
		numOfFaceCards++;
	}

	//if a card with the same face value already exists in the hand 
	if (hand.count(cardFace)==1)
	{
		cout<<"this face already existed in the hand and the count right now is "<<hand.find(cardFace)->second<<endl;
		//get the integer currently associated with the cardFace
		int currentCount=hand.find(cardFace)->second;
		//increment the int associated with the face
		currentCount++;

		//insert the card by replacing the card and updating the int
		hand[cardFace]=currentCount;
		cout<<"the count for this card is now "<< hand.find(cardFace)->second<<endl;
		//increase the duplicate count
		numOfDuplicates++;
	}
	//otherwise insert the card into the map
	else
	{
		//put the cardFace value into the map with a count of 1
		//because this is the first time we are seeing this card face value
		hand.insert(pair<string,int>(cardFace,1));
	}
}

/*
Parameters: None
Return type: None
Purpose: Function to print the cards in the player's hand
*/
void player::printHand()
{
	//for each entry in the map hand
	for (map<string,int>::iterator it=hand.begin(); it!=hand.end(); it++)
	{
		cout << it->first << " => " << it->second << '\n';
	}
}

/*
Parameters: None
Return type: boolean to say true if the player won the round
Purpose: Function to check if the player has won the round based 
	on his current hand
*/
bool player::checkIfWonRound()
{
	//if the player has a duplicate and has at least 1 face card
	if(numOfFaceCards>=1 && numOfDuplicates==1)
	{
		//increment the number of total win
		numOfWins++;
		cout<<"player won round"<<endl;
		cout<<"player has now won "<<numOfWins<<" games"<<endl;
		return true;
	}
	//otherwise return false
	else
	{
		return false;
	}
	

}

/*
Parameters: None
Return type: None
Purpose: Function to reset the players hand and the count of FaceCards 
	and the count of Duplicates
*/
void player::resetRound()
{
	//clear the map hand
	hand.clear();
	//reset the count of FaceCards to 0
	numOfFaceCards=0;
	//reset the count of Duplicates to 0
	numOfDuplicates=0;

}

/*
Parameters: None
Return type: integer representing the number of wins for this player
Purpose: Function to get the number of games this player has won
*/
int player::getNumOfWins()
{
	return numOfWins;
}
#endif
