#include <iostream>
#include <set>
#include <vector>
#include <string>
#include <iterator>


using namespace std;


/// Check for x or o win ///
char win(string s) {
    ///iterate through board
    for(int i = 0; i < s.size(); i++) {
        if (s[0] == s[1] and s[1] == s[2]) {
            if (s[0] == 'X') {
                return 'X';
            } else if (s[0] == 'O') {
                return 'O';
            }
        } else if (s[0] == s[4] and s[4] == s[8]) {
            if (s[0] == 'X') {
                return 'X';
            } else if (s[0] == 'O') {
                return 'O';
            }
        } else if (s[0] == s[3] and s[3] == s[6]) {
            if (s[0] == 'X') {
                return 'X';
            } else if (s[0] == 'O') {
                return 'O';
            }

        } else if (s[1] == s[4] and s[4] == s[7]) {
            if (s[1] == 'X') {
                return 'X';
            } else if (s[1] == 'O') {
                return 'O';
            }
        } else if (s[2] == s[5] and s[5] == s[8]) {
            if (s[2] == 'X') {
                return 'X';
            } else if (s[2] == 'O') {
                return 'O';
            }

        } else if (s[2] == s[4] and s[4]== s[6]) {
            if (s[2] == 'X') {
                return 'X';
            } else if (s[2] == 'O') {
                return 'O';
            }

        } else if (s[3] == s[4] and s[4] == s[5]) {
            if (s[3] == 'X') {
                return 'X';
            } else if (s[3] == 'O') {
                return 'O';
            }
        } else if (s[6] == s[7] and s[7] == s[8]) {
            if (s[6] == 'X') {
                return 'X';
            } else if (s[6] == 'O') {
                return 'O';
            }
        }
        else{
            return 'd';
        }
    }


}

/// Check for tie///
char tie(string s){
    int full = 0;
    for(int i = 0; i < s.size(); i++){
        if(isspace(s[i])){
            full++;
        }
    }
    if(win(s) == 'd' and full == 0){
        return 't';
    }
    else{
        return 'n';
    }
}

void theBoard(set<string> &board, string b, int &c){

    //BASE CASES
    /// check for win ///
    if(win(b) == 'X' or win(b) == 'O'){
        //cout << "win" << endl;
        cout << b << endl;
        c++;
        return;
    }
    ///Check tie///
    else if(tie(b) == 't'){

        //cout << "tie" << endl;
        cout << b << endl;
        c++;
        return;
    }
    //

    ///full recurse
    else{
        board.insert(b);

        ///Check turn
        if (c % 2 == 1) {
            for (int i = 0; i < 9; i++) {

                if (b[i] == ' '){
                    b[i] = 'O';
                    board.insert(b);
                    theBoard(board, b, c);
                    b[i] = ' ';
                }


                /*if (b.at(i) != 'X' and b.at(i) != 'O') {
                    b.at(i) = 'X';
                    cout << b << endl;
                    c++;
                    theBoard(board, b, c);
                }*/
            }
        }
        else if (c % 2 == 0) {
            for (int i = 0; i < 9; i++) {

                if (b[i] == ' '){
                    b[i] = 'X';
                    board.insert(b);
                    theBoard(board, b, c);
                    b[i] = ' ';
                }

               /* if (b.at(i) != 'X' and b.at(i) != 'O') {
                    b.at(i) = 'O';
                    cout << b << endl;
                    c++;
                    theBoard(board, b, c, x, o, t);
                }*/
            }
        }

    }








    /// iterator for loop ///

        /*for(set<string>::iterator it = board.begin(); it != board.end(); it++){
                cout << *it << endl;

        }*/
    }



int main() {

    set<string> board;
    string b = "";
    int c = 0;
    for(int i = 0; i < 9; i++){
        b = "         ";
        b.at(i) = 'X';
        c = 1;
        theBoard(board, b, c);
    }
    int xw = 0;
    int ow = 0;
    int ties = 0;

    for(string s: board){
        if (win(s) == 'X'){
            xw += 1;
        }
        else if (win(s) == 'O'){
            ow += 1;
        }
        else if (tie(s) == 't'){
            ties += 1;
        }

    }


cout << "Total boards: " << c << ", wins for 'O': " << ow << ", wins for 'x': " << xw << ", ties: " << ties << endl;



    return 0;
}
