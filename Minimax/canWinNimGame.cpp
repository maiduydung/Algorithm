// https://leetcode.com/problems/nim-game/
// Input: 4
// Output: false 
// If there are 4 stones in the heap, then you will never win the game;
// No matter 1, 2, or 3 stones you remove, the last stone will always be 
// removed by your friend.

class Solution {
public:
    bool canWinNim(int n) {
        return n % 4 != 0;
        //because the max stone we can remove is 3
        //there will be always stone left for the friend
        //which means sth like 4, 8, 12, 16, etc would result in a loss

        //lets take an example n = 5
        //if we remove 3 stone. 2 left
        //2 stone, 3 left
        //1 stone, 4 left -> again this would result in our loss
    }
};
