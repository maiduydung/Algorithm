//https://leetcode.com/problems/unique-paths/
// The robot can only move either down or right at any point in time.
// The robot is trying to reach the bottom-right corner of the grid 
// How many possible unique paths are there?
#include<vector>
using namespace std;
class Solution {
public:
    
    int uniquePaths(int x_dst, int y_dst) {
        int x_start = 0;
        int y_start = 0;
        vector<vector<int>> check_arr;
        return traverse(x_start, y_start, x_dst, y_dst);
    }

    int traverse(int x_start, int y_start, int x_dst, int y_dst){
        //cout << i << " " << j << endl;
        if(x_dst == 1 && y_dst == 1)
            return 1;
        if (x_start + 1 < x_dst && y_start + 1 < y_dst)
            return traverse(x_start+1, y_start, x_dst, y_dst) + traverse(x_start, y_start+1, x_dst, y_dst);
        if(x_start ==x_dst-1 && y_start == y_dst-1)
            return 1;
        if(x_start + 1 < x_dst)
            return traverse(x_start+1, y_start, x_dst, y_dst);
        if (y_start + 1 < y_dst)
            return traverse(x_start, y_start+1, x_dst, y_dst);

        return traverse(x_start+1, y_start, x_dst, y_dst) + traverse(x_start, y_start+1, x_dst, y_dst);
    }
};