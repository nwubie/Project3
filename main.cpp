#include <iomanip>
#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <unordered_map>
#include <bits/stdc++.h>
using namespace std;

void BMSearch(const string& txt, const string& pattern) { //Boyer-Moore Algorithm, using bad character heuristic
    int count = 0; //# occurrences in the text
    int patSize = pattern.length();
    int txtSize = txt.length();
    unordered_map<char, int> badChar; //this is used to shift characters if found

    for (int i = 0; i < patSize; i++) {
        badChar[pattern[i]] = max(1, (patSize - i - 1));
    }

    int i = patSize - 1;
    while (i < txtSize) { //boyer-moore goes backwards to search, and if a character is not found, shifts pattern until a char found in txt
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
    cout << "Occurences: " << count << " ";
}

// A function used to load the contents of a .txt file, returns a string
string LoadFile(string filename) {
    ifstream file(filename);
    // If the file exists
    if(file.is_open())
    {
        string text((istreambuf_iterator<char>(file)), istreambuf_iterator<char>());
        return text;
    }
    // If the file does not exist
    else
    {
        cout << "The file '" << filename << "'" << " does not exist!" << endl;
        return "";
    }
}

int main() {
    // Prompts user to input a .txt file to load, file must be in 'cmake-build-debug' folder
    string filename;
    cout << "Load a .txt file:" << endl;
    cin >> filename;

    string file_content = LoadFile(filename);
    cout << file_content << endl;

    // Prompts user with 3 options
    cout << "Please select an option:" << endl;
    cout << "1. Knuth-Morris-Pratt (KMP) Search" << endl;
    cout << "2. Boyer-Moore (BM) Search" << endl;
    cout << "3. Exit" << endl;

    int option;
    cin >> option;

    string word;

    switch(option)
    {
        //
        case 1:
            cout << "Enter a string to 'KMP' Search:" << endl;
            cin >> word;
            // KMPSearch(file_content, word);
            break;
        //
        case 2:
            cout << "Enter a string to 'BM' Search:" << endl;
            cin >> word;
            clock_t start, stop; //time/clock function to measure seconds https://www.geeksforgeeks.org/measure-execution-time-with-high-precision-in-c-c/
            start = clock(); 
            BMSearch(file_content, word);
            stop = clock();
            double duration = double(stop - start) / double(CLOCKS_PER_SEC);
            cout << "Time: " << fixed << setprecision(7) << duration << " seconds";
        // Exits the program
        
    }

    return 0;
}
