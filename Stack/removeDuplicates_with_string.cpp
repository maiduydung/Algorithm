//https://leetcode.com/problems/remove-all-adjacent-duplicates-in-string/
// Input: "abbaca"
// Output: "ca"

// In "abbaca" we could remove "bb" since the letters are adjacent and equal, 
// and this is the only possible move.  
// The result of this move is that the string is "aaca", 
// of which only "aa" is possible, so the final string is "ca".


#include<iostream>


using namespace std;
class Solution {
public:
    string removeDuplicates(string in_str) {
        string result="";
        for(auto current:in_str){
            if(result.size() && result.back() == current)
                result.pop_back();
            else
                result.push_back(current);
        }
        return result;
    }
};