#include <stdlib.h>
#include <iostream>
#include <time.h>
using namespace std;

char test(int guess){
    char ans;
    cout << "Is your number " << guess << "? Or is too high (h) or too low (l)? (y/h/l)" << "\n";
    cin >> ans;
    return ans;
}

int detJumpSize(int lowestHighe, int highestLow, char lastJump, int lastJumpSize){
    cout << "lowest high: " << lowestHighe << "\nhighest low: " << highestLow << "\n";
    if (lowestHighe and highestLow){
        int newJump = (highestLow-lowestHighe)/2;
        if (lastJump == 'h') return (newJump);
        else return newJump*-1;
    }
    else{
        if (lastJump == 'h') return lastJumpSize*-2;
        else return lastJumpSize*2;
    }
}
int main(){
    cout << "Think of a number between -1000 and 1000 and press enter to begin";
    cin.get();
    srand(time(NULL));
    int guess = rand()%1000, trye = 0;
    int lastJumpSize = 128, highestLow, lowestHighe;
    char lastJump;
    while (true){
        lastJump = test(guess);
        if (lastJump == 'y' or lastJump == 'h' or lastJump == 'l'){
          if (lastJump == 'y'){
            cout << "I guessed your number!\n";
            return 0;
        }
          if (lastJump == 'l' and highestLow == false) highestLow = guess;
          else if (lastJump == 'h' and lowestHighe == false) lowestHighe = guess;
          else if (lastJump == 'h' and guess < lowestHighe) 
            lowestHighe = guess;
          else if (lastJump == 'l' and guess > highestLow) highestLow = guess;
          lastJumpSize = abs(lastJumpSize);
          lastJumpSize = detJumpSize(lowestHighe, highestLow, lastJump, lastJumpSize);
          guess += lastJumpSize;
          trye++;}
        else cout << "that's not a valid choice" << "\n";

    }
}