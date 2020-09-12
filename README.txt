Oliver Cho 5/31/20

Question #2:
Please solve this question in C++ or Objective-c. You can design and choose data structures of your choice.
Please prioritize optimizing for speed over memory and provide the space and time complexities of your solution in big-O notation.

1) create a deck of cards
2) implement a deal method for a card game of 4 players
3) shuffle the deck of cards, and display the cards (in their shuffled order)
4) deal the entire deck evenly among 4 players
5) If a player has a combination of two cards of the same value and one face card, save this player and
the combination of cards found.
6) Repeat step 4 and 5 until you save the same player twice at step 5.


Questions:
1) How might you adapt your code to check for sequences of N cards at step 5?  In a combination, the order of
cards does not matter. In a sequence, the order of cards does matter
2) How might you adapt your code to check for the sequence between two saved player?
4) Would you do differently if you were now optimizing for memory over speed?

---------------------------------------------------------------------------------------------------------------

EXPLANATION

Files:
	card.h
	deckOfCards.h
	player.h
	game.h
	Cards.cpp

card.h:
This file is a header file meant to contain a class object which represents a single standard playing card. The card
object expects both a face and suit to properly represent the card. The card can be printed and share information about
itself such as its suit and face.

deckOfCards.h:
This file is a header file meant to contain a class object which represents a deck of cards. This file includes the
card.h file as a deck of cards is comprised of 52 cards. The deck of cards has the ability to create 52 cards upon
instantiation. The deck can also be shuffled and each card can be dealt. Finally the deck of cards can be printed.

player.h:
This files is a header file meant to contain a class object which represent a player. This file includes the the card.h 
file as in order to play the game the player needs to hold cards. The player has the ability to add card to his hand
and identify if he or she has any duplicates of the same card. The player can also identify if he has won a round of
the game in game.h and keep track of how many rounds he or she has won. Finally the player has the ability to print
his hand

game.h:
This file is a header file meant to contain a class object which represents a game. The game follow the step listed above.
The game is completely simulated, and thus it will automatically make the 4 players and run the game until one of the
players has won. The game has the ability to create a deck of cards, deal the cards until one of the players has won the
round, and reset the round after a player has won the round. It is understood that a player has won a round if he or she
has 2 card with the same face/number and he or she has at least 1 face cards(Ace,King,Queen,Jack). This mean if the player
has two face cards he or she has won the game or if he or she has 1 face card and 2 number cards he or she has also won
the game. The game also has the ability to continue running rounds until a player has won the game. The game will then
identify who has won.

Cards.cpp:
This file creates an instance of the game from game.h in the main. The file then runs the game.

Time Complexity:
The file Cards.cpp has a runtime of O(logn). This is due to the function in player.h called addToHand. This function
requires that the map call the find function which runs in O(logn) time. The rest of the actions in Cards.cpp run at O(n)
time.

Space Complexity:
The file Cards.cpp has a space complexity of O(4a+n). a represents the map of each player, and since we have 4 players
we need to multiply that by 4. n represents the space for the 52 cards contained in the deck array of card pointers.
Outside of this there may be variables, but the are not significant enough to include in the space complexity.

Response to Questions:
1.My understanding of the sequence is that 2 duplicate cards must be values right before the face card. For example
10,10,Jack would qualify, but 10,10,King would not qualify. It is also my understanding that Queen,Queen is still a
sequence as they are a duplicate and they are occurring in order. It is also my understanding that Jack, Jack, 10 would
not qualify as yes there is a duplicate and face, but they are not occurring in sequence. To adapt my code for this I
would first only save cards to the hand if the card is Ace,King,Queen,Jack, or 10.  I would create a new function which
is triggered when there is a duplicate. When there is a duplicate the function will identify where the duplicate is and
check the amount of cards in the next face value up, and look at the amount of cards at the face value above it.

2.To adapt my code to check for a sequence between two saved players I would create a function to check. The function
would create a temporary map which would first copy one players map then insert the second players map into the
temporary map. Then based on the card counts in the map identify if any count is 2 or greater. If there is a count
two or greater check the amount of the card in the next face value up. If the amount of the cards in the next face value
up is greater than 0 there is a sequence between the two saved players

3.To optimize memory over speed I would not have each player have a map. Rather I would give each card a owner variable.
At first each card in the deck will have no owner, but upon dealing the deck the card will be assigned an owner. Once all
the cards have been dealt I would run through the deck in it dealt order, checking to see if any player has a card of
duplicate value. If so the duplicate variable of the player will be marked as true. While I run through the deck I will
also check if the any player has any face cards. If so the hasFaceCard variable will also be marked as true. After examining
each card a function will be called to check if any player has both the duplicate and hasFaceCArd variable marked as true.
If so this player has won the game. This saves space as now each player does not have a map. The only exchange is that the amount of space for each card grows by a string. This will also heavily affect run time, as by looking to see if
each player has a duplicate will require to iterators through the deck causing O(n^2).
