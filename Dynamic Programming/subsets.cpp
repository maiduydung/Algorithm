//https://leetcode.com/problems/subsets
// Given a set of distinct integers, nums, 
// return all possible subsets (the power set).

// Note: The solution set must not contain duplicate subsets.

// Input: nums = [1,2,3]
// Output:
// [
//   [3],
//   [1],
//   [2],
//   [1,2,3],
//   [1,3],
//   [2,3],
//   [1,2],
//   []
// ]
#include<vector>
using namespace std;
class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        //creating an empty sub, so that its size = 1 at the beginning
        vector<vector<int>> all_subs = {{}};
        for (auto element : nums)
        {
            int size_subs = all_subs.size();
            //cout << size_subs << endl;
            for (int j = 0; j < size_subs; j++)
            {
                all_subs.push_back(all_subs[j]); //adding new sub to all_sub
                all_subs[j].push_back(element);  //adding element to each sub in all_sub
            }
        }
        return all_subs;
    }

    //nothing to see here

    // void print_set(vector<vector<int>> vect)
    // {
    //     for(auto i: vect)
    //     {
    //         for(int j = 0; j < i.size(); j++)
    //         {
    //             cout << i[j] << endl;
    //         }
    //     }
    // }
};



// A very similar problem can be found at the book
// Cracking the Coding Interview p.134 Powersub