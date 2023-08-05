#include <vector>
#include <iostream>
#include <string>
#include "KMP.h"
using namespace std;

vector<int> buildLps(string s) //creates the lps array needed for KMP algorithm
{
 int j = 0; int i = 1; bool isMatch = false;
 vector<int> returnVal(s.length(), 0);

 while (i < s.length())
 {
    if (isMatch) //continued match
    {
        if (s[i] == s[j])//match continues
        {
            returnVal.at(i) = j + 1;
            i++; j++; isMatch = true;
        }
        else //match over
        {
            do
            {
                j = returnVal.at(j - 1);
            } while (!((j == 0) || (s[i] == s[j])));
            
            
            isMatch = false;
        }
        
        
    }
    else
    {
        if (s[i] == s[j])//match starts
        {
            returnVal.at(i) = j + 1;
            i++; j++; isMatch = true;
        }
        else //keep trying
        {
            i++;
            isMatch = false;
        }

    }
    
 }

 return returnVal;
}

int patternInText(string pattern, string text) //returns the location of the start of match, -1 if no match exists
{
    vector<int> lps = buildLps(pattern);

    int i = 0; int j = 0;

    while (i < text.length())
    {
        if (text[i] == pattern[j])
        {
            while (text[i] == pattern[j])
            {
                i++; j++;
                if (j == pattern.length()) //we found it!   
                {
                    return (i - pattern.length());
                }
            }
            j = lps.at(j-1); //when no longer matching
            
           
            
        }
        else
        {
            i++;
        }
        
        
    }

    return -1;
    

}

void numOfOccurrances(string pattern, string text)
{
    int isFoundAt = -1;
    int occurrances = 0;
    do
    {
        isFoundAt = patternInText(pattern, text);

        if (isFoundAt != -1)
        {
            occurrances++;
            text = text.substr(isFoundAt + pattern.length());
        }
        

    } while (isFoundAt != -1);

    cout << "Occurrences: " << occurrances << endl;
    
    
}