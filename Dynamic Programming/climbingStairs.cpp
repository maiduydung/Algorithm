//https://leetcode.com/problems/climbing-stairs/
// You are climbing a stair case. 
// It takes n steps to reach to the top.
// Each time you can either climb 1 or 2 steps. 
// In how many distinct ways can you climb to the top?

// Note: Given n will be a positive integer.

//basically a fib() with memoization
#include<vector>
#include<iostream>
using namespace std;
    int climb(int n, int checked[]){
        if(n<3)
            return n;
        if(checked[n-1] > 0)//if already exist
            return checked[n-1];//array go from 0->n :)
        checked[n-1] = climb(n-1, checked) + climb(n-2, checked);
        return checked[n-1];
    }

    int climbStairs(int n) {
        int *checked = new int[n];
        return climb(n, checked);
    }



    int main(){
        cout << climbStairs(12);
        return 0;
    }

// A very similar problem can be found at the book
// Cracking the Coding Interview p.134 Triple Step