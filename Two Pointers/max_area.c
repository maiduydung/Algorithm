//https://leetcode.com/problems/container-with-most-water/
// Input: [1,8,6,2,5,4,8,3,7]
// Output: 49

int max(int a,  int b){
    if (a > b)
        return a;
    return b;
}

int min(int a,  int b){
    if (a < b)
        return a;
    return b;
}


int maxArea(int* height, int heightSize){
    int left = 0;
    int right = heightSize - 1;
    int area = 0;
    while (left < right){
        int h = min(height[left], height[right]);
        int temp = h * (right - left);
        area = max(area, temp );
        if (height[left] < height[right])
            left++;
        else
            right --;

    }
    return area;
}

