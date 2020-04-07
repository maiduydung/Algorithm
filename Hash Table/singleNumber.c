// https://leetcode.com/problems/single-number/
// Given a non-empty array of integers, every element appears twice except for one.
// Find that single one.

// Input: [4,1,2,1,2]
// Output: 4

//(2 XOR 2) XOR (5 XOR 5) XOR 9 = 0 XOR 0 XOR 9 = 9

int singleNumber(int* nums, int numsSize)
{
    int re=0;//if left uninitialized, re will have random value to XOR, we dont want that
    for (int i = 0; i < numsSize; i++)
        re ^= nums[i];
    return re;
}

