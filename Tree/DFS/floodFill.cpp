// https://leetcode.com/problems/flood-fill/
#include <iostream>
#include <vector>

using namespace std;
class Solution {
private:
    void dfs(vector<vector<int>>& image, int sr, int sc, int oldColor ,int newColor){
        //boundary check
        if((sr < 0) || (sc < 0) || (sr >= image.size()) || (sc >= image[0].size()) || (image[sr][sc] != oldColor))//making sure the color change is only applied to those with the same color
            return;
        image[sr][sc] = newColor;
        dfs(image, sr + 1, sc, oldColor, newColor );
        dfs(image, sr, sc + 1, oldColor, newColor );
        dfs(image, sr - 1, sc, oldColor, newColor );
        dfs(image, sr, sc - 1, oldColor, newColor );
    }
public:

    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        int oldColor = image[sr][sc];
        if(oldColor != newColor)
            dfs(image, sr, sc, image[sr][sc], newColor);
        return image;
    }

};