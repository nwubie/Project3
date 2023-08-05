#include <vector>
#include <iostream>
#include <string>
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

    int i = 0; int j = 0; int occurrances = 0;
    bool flag = false;

    while (i < text.length())
    {
        if (text[i] == pattern[j])
        {
            
            while (text[i] == pattern[j])
            {
                //i++; 
                j++;
                if (j == pattern.length()) //we found it!   
                {
                    occurrances++;
                    j = lps.at(j-1);
                    //flag = true;
                    

                }
                
                
            }
            
                j = lps.at(j-1); //when no longer matching
            
            
            
            
            
            
            
            
            
           
            
        }
        else
        {
            i++;
            if (j != 0)
            {
                j = lps.at(j-1);
            }
        }
        
        
    }

    return occurrances;
    

}

void KMPSearch(string pattern, string text)
{
    vector<int> lps = buildLps(pattern);

    int i = 0; int j = 0; int occurrances = 0;

    while ((text.length() - i) >= (pattern.length() - j))
    {
        if (text[i] == pattern[j])
        {
            i++; j++;
        }

        if ( j == pattern.length())
        {
            occurrances++;
            j = lps.at(j-1);
        }

        else if (i < text.length() && text[i] != pattern[j])
        {
            if (j != 0)
            {
                j = lps.at(j-1);
            }
            else
            {
                i++;
            }
            
        }
        
        
    }

    cout << "Occurrences: " << occurrances << endl;
    
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