#include <iomanip>
#include <iostream>
#include <vector>
#include <string>
#include <fstream>
using namespace std;

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
            // BMSearch(file_content, word);
        // Exits the program
        case 3:
            break;
    }

    return 0;
}
