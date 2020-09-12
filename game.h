//Oliver Cho 5/31/20
#ifndef H_game
#define H_game

#include "deckOfCards.h"
#include "player.h"
#include "card.h"
using namespace std;

//Class to represent a card game 
class game
{
	private:
		//player 0
		player player0;
		//player 1
		player player1;
		//player 2
		player player2;
		//player 3
		player player3;
		//boolean detemine if the game has been won
		bool gameWinner;
		//bollean determine if the round has been won
		bool roundWinner;

		//create a deck of cards
		deckOfCards deck;
		//create a current card
		card currentCard;
		//integer to show which round were one
		int roundNumber;
	public:
		game();
		void initializeGame();
		void runGameRounds();
		void testresults();
		void playGame();
		bool numOfWins();
};


/*
Parameters: None
Return type: None
Purpose: game class default constructor
*/
game::game()
{
	roundNumber=1;
}

/*
Parameters: None
Return type: None
Purpose: function to initalized the game and show the card deck
*/
void game::initializeGame()
{	
	cout<<"__________________This is a fresh deck___________________"<<endl;
	deck.printDeck();
}

/*
Parameters: None
Return type: None
Purpose: function to run one round of the game and determine if anyone has won the round
*/
void game::runGameRounds()
{
	cout<<"__________________This is round "<<roundNumber<< " of the game___________________"<<endl;

	//shuffle the deck
	deck.shuffle();
	cout<<"__________________This is the shuffled deck___________________"<<endl;
	
	//print the current deck
	deck.printDeck();
	cout<<"__________________Dealing the Deck___________________"<<endl;

	//for the 52 cards in the deck
	for(int i=0;i<52;i++)
	{
		//put the card to be dealt to current card
		currentCard=deck.dealCard();
		//print the current card
		cout<<currentCard.print()<<endl;

		//use mod 4 determine which player to give the card to among the 4 players
		int playerSelect=i%4;
		cout<<"card dealt "<<i<<endl;

		//select the right player
		switch(playerSelect)
		{
			case 0:
				cout<<"card went to player 0"<<endl;
				//add card to player 0 hand
				player0.addToHand(currentCard);
				//check if player 0 won the round
				roundWinner=player0.checkIfWonRound();
				break;
			case 1:
				cout<<"card went to player 1"<<endl;
				//add card to player 1 hand
				player1.addToHand(currentCard);
				//check if player 1 won the round
				roundWinner=player1.checkIfWonRound();
				break;
			case 2:
				cout<<"card went to player 2"<<endl;
				//add card to player 2 hand
				player2.addToHand(currentCard);
				//check if player 2 won the round
				roundWinner=player2.checkIfWonRound();
				break;
			case 3:
				cout<<"card went to player 3"<<endl;
				//add card to player 3 hand
				player3.addToHand(currentCard);
				//check if player 3 won the round
				roundWinner=player3.checkIfWonRound();
				break;
		}

		//if someone has won the round break the for loop for dealing cards
		if(roundWinner==true)
		{
			break;
		}
	}
	roundNumber++;
}

/*
Parameters: None
Return type: None
Purpose: function to print hands of each of the players and reset their hands after
*/
void game::testresults()
{

	cout<<"__________________This is player 0 hand___________________"<<endl;
	//print player0's hand
	player0.printHand();
	//reset player 0 and continue game
	player0.resetRound();

	cout<<"__________________This is player 1 hand___________________"<<endl;
	//print player 1's hand
	player1.printHand();
	//reset player 1 and continue game
	player1.resetRound();

	cout<<"__________________This is player 2 hand___________________"<<endl;
	//print player 2's hand
	player2.printHand();
	//reset player 2 and continue game
	player2.resetRound();

	cout<<"__________________This is player 3 hand___________________"<<endl;
	//print player 3's hand
	player3.printHand();
	//reset player 3 and continue gmame
	player3.resetRound();
}

/*
Parameters: None
Return type: boolean to determine if the game is over
Purpose: function to see how many round have been won by each player
	and determine if the game should be over
*/
bool game::numOfWins()
{
	cout<<"__________________The Rounds Results___________________"<<endl;
	cout<<"player 0 has won "<< player0.getNumOfWins()<<" games"<<endl;
	//get the number of wins for player 0
	int p0=player0.getNumOfWins();
	cout<<"player 1 has won "<< player1.getNumOfWins()<<" games"<<endl;
	//get the number of wins for player 1
	int p1=player1.getNumOfWins();
	cout<<"player 2 has won "<< player2.getNumOfWins()<<" games"<<endl;
	//get the number of wins for player 2
	int p2=player3.getNumOfWins();
	cout<<"player 3 has won "<< player3.getNumOfWins()<<" games"<<endl;
	//get the number of wins for player 3
	int p3=player3.getNumOfWins();

	//if any player has won twice
	if(p0==2||p1==2||p2==2||p3==2)
	{
		//the game is over
		return true;
	}

	else
	{
		return false;
	}
}

void game::playGame()
{
	//initialize the game
	initializeGame();
	bool gameIsRunning=false;
	//while the game is running
	while(gameIsRunning==false)
	{
		//run a round of the game
		runGameRounds();
		//print the results
		testresults();
		//check if the game is over
		gameIsRunning=numOfWins();
	}
	
}

#endif