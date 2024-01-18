import random

class WarCardGame:
    ACE_RANK = 14
    QUEEN_RANK = 12
    QUEEN_SUIT = "Hearts"
    MAX_ROUNDS = 5

    def __init__(self):
        self.deck = [] #Initializes an empty list to store the deck of cards. This is where the cards for the game will be stored.#
        self.player_one_cards = [] #Initializes an empty list to store the cards held by player one during the game.#
        self.player_two_cards = [] #Initializes an empty list to store the cards held by player two during the game.#
        self.player_one_name = "" #Initializes an empty string to store the name of player one.#
        self.player_two_name = "" #Initializes an empty string to store the name of player two.# 
        self.rounds_played = 0 #Initializes an empty string to store the name of player two.#

    def populate_deck(self):
        for suit in ("Hearts", "Diamonds", "Clubs", "Spades"): #This represents the four suits in a standard deck of playing cards.#
            for rank in range(2, 15): #This line initiates an inner loop that iterates over each rank in the range from 2 to 14 (15 is exclusive).#
                self.deck.append((rank, suit)) #This tuple represents a single card in the deck, where rank is the numeric value of the card, and suit is the suit of the card.#

    def printable_card(self, card):
        rank_names = {11: "Jack", 12: "Queen", 13: "King", self.ACE_RANK: "Ace"} #This line creates a dictionary named rank_names.#
        rank = rank_names.get(card[0], str(card[0])) #This line retrieves the rank of the card from the rank_names dictionary.#
        return f"{rank} of {card[1]}" #This line constructs and returns a formatted string representing the printable version of the card.#

    def draw_cards(self, num_cards): #This line defines a method named draw_cards.#
        cards = random.sample(self.deck, num_cards) # This line uses the random.sample function to select a specified number of unique cards (num_cards) from the self.deck attribute#
        self.deck = [card for card in self.deck if card not in cards] #This line updates the deck by removing the cards that were just drawn.# 
        return cards #This line returns the list of cards that were drawn from the deck.#

    def play_round(self): #This line defines a method named play_round.#
        self.rounds_played += 1 #This line increments the rounds_played attribute of the class instance by 1.#
        print(f"\nRound {self.rounds_played}") # This line prints a formatted string indicating the current round number. #

        player_one_card = self.draw_cards(1)[0] 
        player_two_card = self.draw_cards(1)[0]

        print(f"{self.player_one_name} drew {self.printable_card(player_one_card)}") #This line uses an f-string to print a message indicating that Player One drew a card.#
        print(f"{self.player_two_name} drew {self.printable_card(player_two_card)}")#Similarly, this line prints a message indicating that Player Two drew a card.#

        # Check for Aces
        if player_one_card[0] == self.ACE_RANK: #This line checks if the rank of the card drawn #
            print(f"{self.player_one_name} drew an Ace! Skipping {self.player_two_name}'s turn.") #If this condition is true, it means Player One drew an Ace. The code inside this block is executed#
            self.player_one_cards.extend([player_one_card, player_two_card])
        elif player_two_card[0] == self.ACE_RANK:
            print(f"{self.player_two_name} drew an Ace! Skipping {self.player_one_name}'s turn.")
            self.player_two_cards.extend([player_one_card, player_two_card])
        else:
            # Check for Queen of Hearts
            if (
                player_one_card[0] == self.QUEEN_RANK # This part of the condition checks if the rank of the card drawn by Player One (player_one_card) is equal to the constant self.QUEEN_RANK.#
                and player_one_card[1] == self.QUEEN_SUIT # This part of the condition checks if the suit of the card drawn by Player One is equal to the constant self.QUEEN_SUIT.#
                and player_two_card[0] == self.QUEEN_RANK
                and player_two_card[1] == self.QUEEN_SUIT
            ):
                self.swap_scores()
            else:
                self.compare_and_update_scores(player_one_card, player_two_card)

    def swap_scores(self):
        print("Queen of Hearts drawn! Swapping scores.") #This line prints a message indicating that the Queen of Hearts has been drawn, and the scores are about to be swapped.#
        self.player_one_cards, self.player_two_cards = self.player_two_cards, self.player_one_cards #This line performs a simultaneous assignment, effectively swapping the card collections between Player One and Player Two.#
        self.reset_scores() #This line calls the reset_scores method.#

    def reset_scores(self):
        self.player_one_cards = [] #This line sets the player_one_cards attribute to an empty list ([]).#
        self.player_two_cards = [] #Similarly, this line sets the player_two_cards attribute to an empty list ([]).#

    def compare_and_update_scores(self, player_one_card, player_two_card):
        if player_one_card[0] > player_two_card[0]: #his line checks if the rank of the card drawn by Player One (player_one_card[0]) is greater than the rank of the card drawn by Player Two (player_two_card[0]).#
            self.player_one_cards.extend([player_one_card, player_two_card]) #The cards drawn by both players are added to Player One's card collection using extend.#
            print(f"{self.player_one_name} wins the round!")
        elif player_one_card[0] < player_two_card[0]:
            self.player_two_cards.extend([player_one_card, player_two_card])
            print(f"{self.player_two_name} wins the round!")
        else:
            print("It's a tie! War begins...")
            self.play_war()

    def play_war(self):
        war_size = min(len(self.player_one_cards), len(self.player_two_cards), 3) #This line calculates the size of the war by taking the minimum of the number of cards in Player One's collection, Player Two's collection, and the constant value 3. #
        if war_size < 2: #If war_size is less than 2, it means there are not enough cards for a war.#
            print("Not enough cards for war. The game is over.")
            return

        war_cards_one = self.draw_cards(war_size)
        war_cards_two = self.draw_cards(war_size)

        print(f"{self.player_one_name} plays {war_size} cards face down in the war.")
        print(f"{self.player_two_name} plays {war_size} cards face down in the war.")

        war_winner = None

        if war_cards_one[-1][0] > war_cards_two[-1][0]: #This line checks if the rank of the last card played by Player One (war_cards_one[-1][0]) is greater than the rank of the last card played by Player Two (war_cards_two[-1][0]).#
            self.player_one_cards.extend(war_cards_one + war_cards_two)
            war_winner = self.player_one_name
        elif war_cards_one[-1][0] < war_cards_two[-1][0]:
            self.player_two_cards.extend(war_cards_one + war_cards_two)
            war_winner = self.player_two_name

        if war_winner:
            print(f"{war_winner} wins the war!")

    def display_score(self):
        print("\nScoreboard:")
        print(f"{self.player_one_name}: {len(self.player_one_cards)} cards") #This line prints the current score for Player One. It includes Player One's name and the number of cards in their card collection (len(self.player_one_cards)).#
        print(f"{self.player_two_name}: {len(self.player_two_cards)} cards")

    def play_game(self):
        self.populate_deck()
        random.shuffle(self.deck)

        self.player_one_name = input("Enter Player One's name: ").strip()
        self.player_two_name = input("Enter Player Two's name: ").strip()

        while not self.player_one_name or not self.player_two_name:
            print("Player names cannot be empty. Try again.")
            self.player_one_name = input("Enter Player One's name: ").strip()
            self.player_two_name = input("Enter Player Two's name: ").strip()

        for _ in range(self.MAX_ROUNDS):
            input("Press Enter to play a round...")
            self.play_round()

            if not self.deck:
                print("The deck is empty. The game is over.")
                break

            input("Press Enter to display the current score...")
            self.display_score()

        self.display_final_results()

    def display_final_results(self):
        winner = self.determine_winner()
        print(f"\nCongratulations, {winner}! You are the winner of the game!")

        loser = self.player_one_name if winner == self.player_two_name else self.player_two_name
        random_response = random.choice(["receive a slap from the winner", "give the winner access to your savings account", "never play this game again"])
        print(f"{loser}, {random_response}")

        play_again = input("Do you want to play again? (yes/no): ").lower()
        if play_again == 'yes':
            self.reset_game()
            self.play_game()
        else:
            print("Thanks for playing! Exiting the game.")

    def reset_game(self):
        self.deck = []
        self.player_one_cards = []
        self.player_two_cards = []
        self.rounds_played = 0

    def determine_winner(self):
        if len(self.player_one_cards) > len(self.player_two_cards):
            return self.player_one_name
        elif len(self.player_one_cards) < len(self.player_two_cards):
            return self.player_two_name
        else:
            return "It's a tie!"

if __name__ == "__main__":
    game = WarCardGame()
    game.play_game()

            


             
