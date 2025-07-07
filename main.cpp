#include<iostream>
using namespace std;

// global declarations
string space[3][3]={{"1","2","3"},{"4","5","6"},{"7","8","9"}};
int row;
int column;
bool tie_match = false;
string inp = "x";
string n1;
string n2;

// function to display the board
void structure () {
    cout << " " << space[0][0] << " | " << space[0][1] << " | " << space[0][2] << " " << endl;
    cout << "---|---|---" << endl;
    cout << " " << space[1][0] << " | " << space[1][1] << " | " << space[1][2] << " " << endl;
    cout << "---|---|---" << endl;
    cout << " " << space[2][0] << " | " << space[2][1] << " | " << space[2][2] << " " << endl;
}

// function to take input and update the board
void logic () {
    int digit = 0;

    if (inp == "x") {
        cout << n1 << " Enter Your Position : ";
        cin >> digit;
    } else if (inp == "o") {
        cout << n2 << " Enter Your Position : ";
        cin >> digit;
    }

    // choosing cell on the basis of digit value
    switch (digit) {
        case 1: row = 0; column = 0; break;
        case 2: row = 0; column = 1; break;
        case 3: row = 0; column = 2; break;
        case 4: row = 1; column = 0; break;
        case 5: row = 1; column = 1; break;
        case 6: row = 1; column = 2; break;
        case 7: row = 2; column = 0; break;
        case 8: row = 2; column = 1; break;
        case 9: row = 2; column = 2; break;
        default:
            cout << "Invalid input" << endl;
            return;
    }

    // checking for empty cells
    if (space[row][column] != "x" && space[row][column] != "o") {
        space[row][column] = inp;
        inp = (inp == "x") ? "o" : "x";
    } else {
        cout << "Cell already taken!" << endl;
    }
}

// function to check win or draw condition
bool checker () {
    for(int i = 0; i < 3; i++) {
        if ((space[i][0]==space[i][1] && space[i][0]==space[i][2]) || (space[0][i]==space[1][i] && space[0][i]==space[2][i])) {
            return true;
        }
    }
    if ((space[0][0] == space[1][1] && space[1][1] == space[2][2]) || (space[0][2] == space[1][1] && space[1][1] == space[2][0])) {
        return true;
    }
    
    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) {
            if(space[i][j] != "x" && space[i][j] != "o") {
                return false;
            }
        }
    }
    tie_match = true;
    return false;
}

int main () {
    // Input player names once
    cout<<"Enter Player 1's Name (will play first) : ";
    getline(cin,n1);
    cout<<"Enter Player 2's Name (will play second) : ";
    getline(cin,n2);

    // Display initial board
    structure();

    // Game loop until a win or tie occurs
    while(!checker()) {
        logic();
        structure();
    }

    // Announce result based on tie or winner (last player to move wins)
    if(tie_match) {
        cout<<"It's a DRAW"<<endl;
    } else if(inp == "o") {
        // inp switched after last move, so if inp is "o", "x" played last and wins
        cout << n1 << " Wins" << endl;
    } else if(inp == "x") {
        // if inp is "x", "o" played last and wins
        cout << n2 << " Wins" << endl;
    }

    return 0;
}
