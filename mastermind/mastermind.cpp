/*	Author: Gerald Liu
 *	GitHub Repository: https://github.com/gerald-liu/misc
 *	Algorithm by Frans van Gool: http://jmastermind.sourceforge.net/algorithm.html
 */

#include <iostream>
using namespace std;

struct Score {
    int black = 0;
    int white = 0;
};

Score feedback(const int guess[], const int code[]) {
    int blacks[4] = {0};
    int whites[4] = {0};
 
    for(int i=0; i<4; i++) blacks[i] = (guess[i] == code[i] ? 1 : 0);
    
    for(int i=0; i<4; i++) {
        if (blacks[i] != 1) {
            for (int j=0; j<4; j++) {
                if (j == i) continue;
                if (guess[i] == code[j] && blacks[j] != 1 && whites[j] == 0) {
                    whites[j]=1;
                    break;
                }
            }
        }
    }

    Score s;
    for(int i=0; i<4; i++) {
        s.black += blacks[i];
        s.white += whites[i];
    }
    return s;
}
 
void senaryCounter(int num[]) {
    num[3]++;
    if(num[3] == 6) {
        num[2]++;
        if(num[2] == 6) {
            num[1]++;
            if(num[1] == 6) {
                num[0]++;
                if (num[0] == 6) num[0] = 0;
                num[1] = 0;
            }
            num[2] = 0;
        }
        num[3] = 0;
    }
}
 
int main() {
    int code[4] = {0};
    cout << "Put 4 number code in with values from 0 to 5! (with spaces)" << endl << "For example: 0 3 4 2" << endl;
    cin >> code[0] >> code[1] >> code[2] >> code[3];
    int guessNum = 0;
    
    int guess[] = {0, 0, 1, 1};
    int prevGuess[10][4];
    Score prevScore[10];
    Score score;

    while (guessNum < 10) {
        guessNum++;
        cout << "Guess " << guessNum << " : " << guess[0] << ' ' << guess[1] << ' ' << guess[2] << ' ' << guess[3] << '\n';
        
        score = feedback(guess, code);
        if (score.black == 4) break;

        prevScore[guessNum-1] = score;
        prevGuess[guessNum-1][0] = guess[0];
        prevGuess[guessNum-1][1] = guess[1];
        prevGuess[guessNum-1][2] = guess[2];
        prevGuess[guessNum-1][3] = guess[3];

        while (true) {
            bool consistent = true;            
            for (int i=0; i<guessNum; i++) {
                score = feedback(guess, prevGuess[i]);
                if (score.black != prevScore[i].black || score.white != prevScore[i].white) {
                    consistent = false;
                    break;
                }
            }
            if (consistent) break;
            senaryCounter(guess);

            if (guess[0] == 0 && guess[1] == 0 && guess[2] == 1 && guess[3] == 1) {                
                cerr << "ERROR: No solution possible!\n";
                break;
            }
        }
 
        cout << "Feedback: [ " << score.black << " : " << score.white << " ]\n";
    }
 
    if (score.black == 4) {
        cout << "\nCode broken in " << guessNum << " turns!\n";
        cout << "The code is: " << guess[0] << ' ' << guess[1] << ' ' << guess[2] << ' ' << guess[3] << '\n';
    }
    else cout << "\nCode-breaking failed." << endl;
 
    return 0;
}
