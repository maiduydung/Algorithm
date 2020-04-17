//https://leetcode.com/problems/unique-paths
#include<vector>
using namespace std;


class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> check_arr(m, vector<int>(n, 1));
        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++)
                check_arr[i][j] = check_arr[i - 1][j] + check_arr[i][j - 1];
        }
        return check_arr[m - 1][n - 1];
    }
};

//because the robot can only go down or right
//which means at arr[m][n], the robot came from arr[m-1][n] or arr[m][n-1]

//also, at every cell, there's only 2 ways to reach there, hence
//check_arr[i][j] = check_arr[i - 1][j] + check_arr[i][j - 1];

//O(m^n) 

// A very similar problem can be found at the book
// Cracking the Coding Interview p.134 Robot in a grid