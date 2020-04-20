//https://leetcode.com/problems/remove-all-adjacent-duplicates-in-string/
// Input: "abbaca"
// Output: "ca"

// In "abbaca" we could remove "bb" since the letters are adjacent and equal, 
// and this is the only possible move.  
// The result of this move is that the string is "aaca", 
// of which only "aa" is possible, so the final string is "ca".


#include<iostream>
#include <stack>

using namespace std;
class Solution {
public:
    string removeDuplicates(string in_str) {
        stack<char> check_stack;
        string result = "";
        for (auto c : in_str) {
            //if the stack is not empty and the current char is equal to top of stack
            //need check_stack.size() > 0 so that at the first iteration we can push c to stack
            if ((check_stack.size() > 0) && (c == check_stack.top()))
                check_stack.pop();
            else
                check_stack.push(c);
        }


        while (!check_stack.empty())
        {
            result = result + check_stack.top();
            check_stack.pop();
        }
        //elements in stack are reversed comparing to the original order
        reverse(result.begin(), result.end());
        return result;
    }
};