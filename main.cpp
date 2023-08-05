#include <iomanip>
#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <unordered_map>
#include "KMP.h"
#include "BM.h"
using namespace std;

// A function used to load the contents of a .txt file, returns a string
bool LoadFile(string filename, string& file_content) {
    ifstream file(filename);
    // If the file exists
    if(file.is_open())
    {
        string text((istreambuf_iterator<char>(file)), istreambuf_iterator<char>());
        file_content = text;
        return true;
    }
    // If the file does not exist
    else
    {
        cout << "The file '" << filename << "'" << " does not exist!" << endl << endl;
        return false;
    }
}

int main() {
    bool program = true;
    
        // Prompts user to input a .txt file to load, file must be in 'cmake-build-debug' folder
        string filename;
        string file_content = "";
        bool validFile = false;
        do {
            cout << "Load a .txt file:" << endl;
            cin >> filename;

            validFile = LoadFile(filename, file_content);
        } while (!validFile);

    while (program) {
        // Prompts user with 3 options
        cout << "Please select an option:" << endl;
        cout << "1. Knuth-Morris-Pratt (KMP) Search" << endl;
        cout << "2. Boyer-Moore (BM) Search" << endl;
        cout << "3. Full Search (KMP vs. BM)" << endl;
        cout << "4. Exit" << endl;

        string option = ""; //needs to be a string and then convert to an int, the program broke when I entered a letter and kept printing else the cout statement
        int opt = -1;
        bool validOpt = false;
        do {
            cin >> option;
            
            try { 
                opt = stoi(option);
            } catch (exception e) {
               
            }

            if (opt < 1 || opt > 4) {
                cout << "Enter a valid option!" << endl;
            } else {
                validOpt = true;
            }
        } while (!validOpt);
        string word;

        switch(opt)
        {
            //
            case 1: {
                cout << "Enter a string to 'KMP' Search:" << endl;
                cin >> word;
                clock_t start, stop; //time/clock function to measure seconds https://www.geeksforgeeks.org/measure-execution-time-with-high-precision-in-c-c/
                start = clock();
                numOfOccurrances(word, file_content);
                stop = clock();
                double duration = double(stop - start) / double(CLOCKS_PER_SEC);
                cout << "Execution Time: " << fixed << setprecision(7) << duration << " seconds" << endl << endl;
                continue;
            }
            //
            case 2: {
                cout << "Enter a string to 'BM' Search:" << endl;
                cin >> word;
                clock_t start, stop; //time/clock function to measure seconds https://www.geeksforgeeks.org/measure-execution-time-with-high-precision-in-c-c/
                start = clock();
                BMSearch(file_content, word);
                stop = clock();
                double duration = double(stop - start) / double(CLOCKS_PER_SEC);
                cout << "Execution Time: " << fixed << setprecision(7) << duration << " seconds" << endl << endl;
                continue;
            }
            // performs
            case 3: {
                cout << "Enter a string to Full Search:" << endl;
                cin >> word;

                clock_t start, stop; //time/clock function to measure seconds https://www.geeksforgeeks.org/measure-execution-time-with-high-precision-in-c-c/
                start = clock();
                numOfOccurrances(word, file_content);
                stop = clock();
                double duration = double(stop - start) / double(CLOCKS_PER_SEC);
                cout << "'KMP' Search Execution Time: " << fixed << setprecision(7) << duration << " seconds" << endl;

                start = clock();
                BMSearch(file_content, word);
                stop = clock();
                duration = double(stop - start) / double(CLOCKS_PER_SEC);
                cout << "'BM' Search Execution Time: " << fixed << setprecision(7) << duration << " seconds" << endl;

                continue;
            }
            // Exits the program
            case 4: {
                program = false;
                continue;
            }
            default: {
                program = true;
                continue;
            }
        }
    }
    return 0;
}