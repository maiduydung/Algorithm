//https://leetcode.com/problems/baseball-game/

// Input: ["5","2","C","D","+"]
// Output: 30

// Round 1: You could get 5 points. The sum is: 5.
// Round 2: You could get 2 points. The sum is: 7.
// Operation 1: The round 2's data was invalid. The sum is: 5.  
// Round 3: You could get 10 points (the round 2's data has been removed). The sum is: 15.
// Round 4: You could get 5 + 10 = 15 points. The sum is: 30.


#include<iostream>
#include<vector>
#include <ctype.h> //isdigit
#include<string>


using namespace std;

class Solution {
public:
    int calPoints(vector<string>& ops, vector<int>score = {}) {
        
        for(auto &current :ops){
            //continously update the size at the beginning of each loop
            auto score_size = static_cast<int>(score.size());
            //cancel previous score
            if (current == "C")
                score.pop_back();
            
            //double previous score
            else if (current == "D")
                score.push_back(score[score_size - 1]*2);
            
            //sum of 2 previous score
            else if(current == "+")
                score.push_back(score[score_size - 1] + score[score_size - 2]);
            
            else
                score.push_back(stoi(current));
        }

        return accumulate(score.begin(), score.end(), 0);
    }
};