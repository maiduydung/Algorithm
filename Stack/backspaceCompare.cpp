// https://leetcode.com/problems/backspace-string-compare/

// Given two strings S and T, 
// return if they are equal when both are typed into empty text editors. 
// # means a backspace character.
#include<string>
#include<ctype.h> //isalpha

using namespace std;
class Solution {
public:
    bool backspaceCompare(string S, string T) {
        string str_1="";
        string str_2="";

        for(auto &current :S){
            if(current=='#' && str_1.length()!= 0)
                str_1.pop_back();
            if(isalpha(current))
                str_1.push_back(current);
        }
        
        for(auto &current :T){
            if(current=='#' && str_2.length()!= 0)
                str_2.pop_back();
            if(isalpha(current))
                str_2.push_back(current);
        }       
        return str_1.compare(str_2) == 0? 1 : 0;
    }
};