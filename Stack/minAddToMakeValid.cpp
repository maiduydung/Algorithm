//https://leetcode.com/problems/minimum-add-to-make-parentheses-valid/
// Given a string S of '(' and ')' parentheses, 
// we add the minimum number of parentheses ( '(' or ')', and in any positions ) 
// so that the resulting parentheses string is valid.
#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    int minAddToMakeValid(string S) {
        int balance = 0;
        int add = 0;
        for(int i= 0; i < S.length(); i++){
            if (S[i] == '(')
                balance++;
            if (S[i] == ')')
                balance--;
            
            if (balance < 0)
            {
                add++;;
                balance++;;
                //because we added a right para, so that we need to update balance
            }

        }
        //if the string is valid then balance = 0, no need to add
        //however for cases like these "(((" then balance = 3
        //or ))), then balance kept going up and down while add is increasing upto 3
        //()))((, then balane = 2, add = 2
        return add + balance;
    }
};
