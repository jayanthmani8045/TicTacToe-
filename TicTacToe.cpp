#include<iostream>

using namespace std; // new addition to C++ to resolve std to all standard keywords like cout, cin, int...

// basic
char board[3][3] = {{'1','2','3'},{'4','5','6'},{'7','8','9'}};
char slot;
char turn = 'x';
char winner;

void drawboard(){
    cout<<"\n";
    cout<<" TicTacToe \n";
    cout<<"---|---|---\n";
    cout<<" "<<board[0][0]<<" | "<<board[0][1]<<" | "<<board[0][2]<<" \n";
    cout<<"---|---|---\n";
    cout<<" "<<board[1][0]<<" | "<<board[1][1]<<" | "<<board[1][2]<<" \n";
    cout<<"---|---|---\n";
    cout<<" "<<board[2][0]<<" | "<<board[2][1]<<" | "<<board[2][2]<<" \n";
    cout<<"---|---|---\n";
    cout<<"\n";
    cout<<"choose a slot with a number in place \n";
}

void placemarker(int s){
    board[s/3][(s%3)-1] = turn;
    // next turn
    if (turn == 'x'){
        turn = 'o';
    } else {
        turn = 'x';
    }
}

char winnerfn(){

    // row winner
    for (int i=0; i<3 ;i++){
        if (board[i][0]==board[i][1] && board[i][1]==board[i][2]){
            return board[i][0];
        }
    }

    // col winner
    for (int i=0; i<3 ;i++){
        if (board[0][i]==board[1][i] && board[1][i]==board[2][i]){
            return board[0][i];
        }
    }

    // dia winner
    if (board[0][0]==board[1][1] && board[1][1]==board[2][2]){
            return board[1][1];
    }
    if (board[2][0]==board[1][1] && board[1][1]==board[0][2]){
            return board[1][1];
    }

    return ' ';
}

int main(){

    int s='1'-'0';
    // Game Code
    for (int i=0;i<9;i++){
        drawboard();
        cout<<"Choose a slot for "<<turn<<": ";
        cin>>slot;
        if (isdigit(slot)){
            s = slot - '0';
            cout<<'\n'<<s<<'\n';
        } else {
            --i;
            continue;
        }
        if (s<1 || s>9){
            cout<<"\n";
            cout<<"-----------\n";
            cout<<"Invalid slot \n";
            cout<<"-----------\n";
            i--;
            continue;
        }

    // Place marker
    placemarker(s); 

    // Cal winner
    winner = winnerfn();
    if (winner != ' '){
        cout<<"Congrats: The winner is "<<winner;
        return 0;
        }
    }
    
    return 0;
}