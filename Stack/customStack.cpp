//https://leetcode.com/problems/design-a-stack-with-increment-operation/
#include<iostream>
#include <vector>
using namespace std;

class CustomStack {

private:
    vector<int> stk;
    int maxSize;
public:  
    CustomStack(int max_size) {
        this->maxSize = max_size;
    }

    void push(int x) {
        if(stk.size() < maxSize)
            stk.push_back(x);

    }
    
    int pop() {
        if(stk.empty())
            return -1;
        int temp = stk.back();
        stk.pop_back();
        return temp;
    }
    
    void increment(int k, int val) {
        //dont forget to cast type, and use stk.size() instead maxSize, because the stack may not be filled up to that point yet, 
        //would result in a runtime error
        for (int i = 0; i < min( (int) stk.size(), k); i++)
            stk[i] += val;
    }
};