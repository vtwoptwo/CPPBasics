#include <iostream>

using namespace std;

class TicTacToe{
private:
    string name; //name of the game
    char space[3][3] = {{' ',' ',' ',},{' ',' ',' '},{' ',' ',' '}};
    string player_1;
    string player_2;

public:
    TicTacToe( string name){
        this->name = name;

    }
    //destructor
    ~TicTacToe( ){
        cout << "Game Over" << endl;
    };

    bool endGame(){

        //check for horizontal win
        for(int i = 0; i < 3; i++){
            if(space[i][0] == space[i][1] && space[i][1] == space[i][2] && space[i][0] != ' '){
                return true;
            }
        }

        //check for vertical win
        for(int i = 0; i < 3; i++){
            if(space[0][i] == space[1][i] && space[1][i] == space[2][i] && space[0][i] != ' '){
                return true;
            }
        }

        //check for diagonal win
        if(space[0][0] == space[1][1] && space[1][1] == space[2][2] && space[0][0] != ' '){
            return true;
        }
        if(space[0][2] == space[1][1] && space[1][1] == space[2][0] && space[0][2] != ' '){
            return true;
        }

        return false;

        
    };
    
    void playGame(){
    int row, col;
    int turn = 0;
    while(endGame() == false){
        if(turn%2 == 0){
            cout<<player_1<<"'s turn"<<endl;
            cout<<"Enter row: ";
            cin>>row;
            cout<<"Enter col: ";
            cin>>col;
            space[row][col] = 'X';
            printBoard();
        }
        else{
            cout<<player_2<<"'s turn"<<endl;
            cout<<"Enter row: ";
            cin>>row;
            cout<<"Enter col: ";
            cin>>col;
            space[row][col] = 'O';
            printBoard();
        }
        turn++;
    }
    if(turn%2 == 0){
        cout<<player_2<<" wins!"<<endl;
    }
    else{
        cout<<player_1<<" wins!"<<endl;
    }
    };



    void printBoard(){

    cout<<" "<<space[0][0]<<" | "<<space[0][1]<<" | "<<space[0][2]<<endl;
    cout<<"---|---|---"<<endl;
    cout<<" "<<space[1][0]<<" | "<<space[1][1]<<" | "<<space[1][2]<<endl;
    cout<<"---|---|---"<<endl;
    cout<<" "<<space[2][0]<<" | "<<space[2][1]<<" | "<<space[2][2]<<endl;
}

    void get_players(){
        cout<<"Player 1: ";
        cin>>player_1;
        cout<<"Player 2: ";
        cin>>player_2;
        cout<<player_1<<" plays X "<<endl;
        cout<<player_2<<" plays O"<<endl;
    }

    friend class External; // friend class to be able to add another class to the game if desired

    friend void Rules(); // just print the rules of the game 
    friend void Checks(); //  friend function to make more check in the game in order to avoid bugs

};

void debugRules(){
    cout<<"Rules: "<<endl;
    cout<<"1. The game is played on a grid that's 3 squares by 3 squares."<<endl;
    cout<<"2. You are X, your friend is O. Players take turns putting their marks in empty squares."<<endl;
    cout<<"3. The first player to get 3 of her marks in a row (up, down, across, or diagonally) is the winner."<<endl;
    cout<<"4. When all 9 squares are full, the game is over. If no player has 3 marks in a row, the game ends in a tie."<<endl;
}

//create  a 2-d array 

int main(){

    // defining the game board
    

    // initiate game
    TicTacToe game("TicTacToe");
    // see who is playing
    game.get_players();
    // begin game loop
    game.playGame();

    return 0;
    
}