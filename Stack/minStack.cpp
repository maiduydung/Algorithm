// https://leetcode.com/problems/min-stack/

// Design a stack that supports push, pop, top, 
// and retrieving the minimum element in constant time.

// Input
// ["MinStack","push","push","push","getMin","pop","top","getMin"]
// [[],[-2],[0],[-3],[],[],[],[]]

// Output
// [null,null,null,null,-3,null,0,-2]

// MinStack minStack = new MinStack();
// minStack.push(-2);
// minStack.push(0);
// minStack.push(-3);
// minStack.getMin(); // return -3
// minStack.pop();
// minStack.top();    // return 0
// minStack.getMin(); // return -2
#include<vector>
using namespace std;

class MinStack {
    private:
        vector<int> MyStack={};
        int min_val = INT_MAX;
    public:
        void push(int x) {
            MyStack.push_back(x);
        }
        
        void pop() {
            MyStack.pop_back();
        }
        
        int top() {
            return MyStack[MyStack.size()-1];
        }
        
        int getMin() {
            //for(auto num:MyStack)
            //    cout << num << endl;
            for(int current:MyStack)
                if(current < min_val)
                    min_val = current;
            return min_val;
        }
};