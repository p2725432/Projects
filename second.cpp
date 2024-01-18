#include <cstdlib>
#include <vector>
#include <ctime>
#include <string>
#include <iostream>
using namespace std;

class Player {      //stores the player and enemies points
private:
    int score;
public:
    int getScore() {
        return score;
    }
    
    void incrementScore() {
        score++;
    }
    //constructor
    Player(int points);
};

//constructor
Player::Player(int points)
    : score {points} {
}

int convertToInt(string pChoice) {      //converts the player input into integers
    if (pChoice == "Rock" || pChoice == "rock") {
        return 0;
    }
    else if (pChoice == "Paper" || pChoice == "paper") {
        return 1;
    }
    else if (pChoice == "Scissor" || pChoice == "scissor") {
        return 2;
    }
    
    return 0;
}

bool inputValidation(const vector <string> choices, string pChoice) {      //this validates player input
    bool boolean {};
    for (const string selection : choices) {     //this checks that vector the contains a list of all possible options
        if (selection == pChoice) {        
            boolean = true;
            break;
        }
        else {
            boolean = false;
        }
    }
    return boolean;
}

void printEnemyChoice(unsigned int &enemyRand, string &enemyChoice) {   //prints opponent selection
//0, 1 and 2 correspond to rock, paper and scissor
    switch (enemyRand) {
        case 0: {
            enemyChoice = "Rock";
            cout << "Enemy picked: " << enemyChoice << endl;
            break;
        }
        case 1: {
            enemyChoice = "Paper";
            cout << "Enemy picked: " << enemyChoice << endl;
            break;
        }
        case 2: {
            enemyChoice = "Scissors";
            cout << "Enemy picked: " << enemyChoice << endl;
            break;
        }
    }
}

void checkResult(Player &playerScore, Player &enemyScore, unsigned int &playerIChoice, unsigned int &enemyRand) {   //determines the winner
//a 2D array is used to compared playerIChoice (the player's selection) and the enemy's selection (randomly generated)
 // 0 represents draw,  1 represents player's win, 2 represents enemy's win//
  

    int resultArray[3][3] {
        {0, 2, 1},  
        {1, 0, 2},
        {2, 1, 0}
    };
        
    int result = resultArray[playerIChoice][enemyRand];
    switch (result) {
        case 0: {
            cout << "Result is: Draw" << endl;
            break;
        }
        case 1: {
            cout << "Result is: You win!" << endl;
            playerScore.incrementScore();
            break;
        }
        case 2: {
            cout << "Result is: You lose!" << endl;
            enemyScore.incrementScore();
            break;
        }
    }
}
const int NUM_USERS = 6;
const std::string valid_users[NUM_USERS] = {"login1", "login2", "login3", "login4", "login5", "login6"};
const std::string valid_passwords[NUM_USERS] = {"password1", "password2", "password3", "password4", "password5", "password6"};



bool validate(std::string user, std::string pass){      
//stored in the arrays valid_users and valid_passwords//
for (int i = 0; i < NUM_USERS; i++) {
if (user == valid_users[i] && pass == valid_passwords[i]) {
return true;
 }
 }
return false;
}



int main() { 
   cout << "Rock Paper Scissors!\n\n";
 cout << "Rock crushes Scissors\n";
cout << "Paper covers Rock\n";
cout << "Scissors cuts Paper\n\n";
cout << "To play, you will choose either rock, paper, or scissors.\n";
cout << "The opponent will also choose a random option.\n";
 cout << "If your selection beats the opponent's selection, you win!\n";
 cout << "If the opponent's selection beats your selection, you lose.\n";
 cout << "If both you and the opennent choose the same option, it's a draw.\n\n";
cout << "Let's start!\n\n";
   
   
   
    std::string username, password;
 while (true) {
 // Get username//
 for (int i = 1; i <= 6; i++) {
cout << "Enter login and password for user " <<": \n";
cin >> username >> password;
//validates login and password making sure it aligns with usernames and passwords stored in 'login' and 'password' arrays//
 if (validate(username, password)) {
 cout<< "\n"<< "Welcome " << username ;
 break;
 } else {
 cout << "Username or password invalid." << endl;
cout << " Enter details again." << endl;
}
 }
    
    
    Player playerScore {0};
    Player enemyScore {0};
    bool gameLoop {true};
    const vector <string> choices {"Rock", "rock", "Paper", "paper", "Scissor", "scissor", "Q", "q"};
    std::string playerChoice {};
    std::string enemyChoice {};
    unsigned int playerIChoice {};
    unsigned int enemyRand {};
    

    
    while (gameLoop) {
        cout << "\nChoose rock, paper, or scissor: " << endl;
        cout << "Press Q to quit the game." << endl;
        cin >> playerChoice;
        
        if (playerChoice == "Q" || playerChoice == "q") {
            cout << "Thanks for playing." << endl;
            gameLoop = false;
            break;
        }
        
        if (inputValidation(choices, playerChoice) == false) {      //passes vector with valid input and player's input to compare//
            cout << "Invalid input, try again!" << endl;
            continue;
        }
        
        cout << "You picked: " << playerChoice << endl;
        playerIChoice = convertToInt(playerChoice);         //converts valid input into integers to compare with enemy's selection//
        
        srand (time(NULL));
        enemyRand = rand() % 3;     //generates random number from 0-2//
        
        printEnemyChoice(enemyRand, enemyChoice);
        checkResult(playerScore, enemyScore, playerIChoice, enemyRand);
        
        cout << "\nYour score is: " << playerScore.getScore() << endl;
        cout << "Enemy score is: " << enemyScore.getScore() << endl;
    }
    
    return 0;
}
}