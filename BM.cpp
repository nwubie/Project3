#include <iostream>
#include <string>
#include <unordered_map>
#include <iomanip>
#include "BM.h"
using namespace std;

void BMSearch(const string& txt, const string& pattern) { //Boyer-Moore Algorithm, using bad character heuristic
    int count = 0; // # occurrences in the text
    int patSize = pattern.length(); 
    int txtSize = txt.length();
    unordered_map<char, int> badChar; // this is used to shift the pattern right if a character is found, according to the int associated with it

    for (int i = 0; i < patSize; i++) { //this is the bad match table, where the value will be the length of the pattern - indexofactualcharacter - 1;
        badChar[pattern[i]] = max(1, (patSize - i - 1)); //repeated letters in the pattern will be updated in the map
    }
    
    //compare the txt index with the rightmost character of the badChar map, if they are the same keep, comparing to the left until the pattern matches the txt
    //if the character in the txt is present in the map, but not the rightmost, shift the pattern
    int i = patSize - 1;
    while (i < txtSize) {
        int j = patSize - 1;
        while (j >= 0 && txt[i] == pattern[j]) {
            i--;
            j--;
        }

        if (j == -1) { 
            count++;
            i += patSize + 1;
        }
        else {
            i += max(badChar[txt[i]], (patSize - j));
        }
    }
    cout << "Occurrences: " << count << endl;
}

