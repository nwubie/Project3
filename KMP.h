#include <vector>
#include <iostream>
#include <string>
#include "KMP.cpp"
using namespace std;

vector<int> buildLps(string s);
int patternInText(string pattern, string text);
void numOfOccurrances(string pattern, string text);