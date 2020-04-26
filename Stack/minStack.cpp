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

//Methods pop, top and getMin operations will always be called on non-empty stacks.
#include<stack>
using namespace std;

class MinStack {
private:
    stack<int> stk1;
    stack<int> stk2;
public:   
    void push(int x) {
        stk1.push(x);
        //there may be multiple equal value so x <= stk2.top()
        //when we pop those value, its remaining min still remains
        if(stk2.empty() || x <= stk2.top()) 
            stk2.push(x);            
    }
    
    void pop() {
        if(stk1.top() == stk2.top())
            stk2.pop();
        stk1.pop();
    }
    
    int top() {
        return stk1.top();
    }
    
    int getMin() {
        return stk2.top();
    }
};