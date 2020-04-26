#include<iostream>
#include<string>
using namespace std;

class Solution {
public:
    bool isValid(string str) {
        if(str.empty())
            return true;
        string stk="";
        //pass by reference so that no extra copies is created
        for(auto &curr:str){
            switch (curr)
            {
                case '(': stk.push_back(curr); break;
                case '{': stk.push_back(curr); break;
                case '[': stk.push_back(curr); break;
                //if current is closing paren 
                //but top of stack is not a opening paren
                case ')': 
                    if (stk.empty() || stk.back() != '(')
                        return false;
                    else{
                        stk.pop_back();
                        break;
                    }
                case ']': 
                    if (stk.empty() || stk.back() != '[')
                        return false;
                    else{
                        stk.pop_back();
                        break;
                    }
                case '}': 
                    if (stk.empty() || stk.back() != '{')
                        return false;
                    else{
                        stk.pop_back();
                        break;
                    }
                default:;
            }
        }
        return stk.empty();
    }
};