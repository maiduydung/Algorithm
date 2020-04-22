#include<vector>
using namespace std;
class MyQueue {
private:
    vector<int> v_queue={};

public:
    /** Initialize your data structure here. */
    //fifo
    
    /** Push element x to the back of queue. */
    void push(int x) {
        v_queue.push_back(x);
    }
    
    /** Removes the element from in front of queue and returns that element. */
    int pop() {
        int temp = v_queue[0];
        v_queue.erase(v_queue.begin()+ 0);
        return temp;
    }
    
    /** Get the front element. */
    int peek() {
        return v_queue[0];
    }
    
    /** Returns whether the queue is empty. */
    bool empty() {
        return v_queue.empty();
    }
};
