#include<iostream>
#include<vector>
using namespace std;

int findsubset(vector<int> arr,int sum)
{
    vector<bool> dp(sum+1,false);
    dp[0]=true;
    for(int num:arr)
    {
        for(int j=sum;j>=num;j--)
        {
            dp[j]=dp[j]||dp[j-num];
        }
    }
    return dp[sum];
}

int main()
{
    int n,sum;
   
    cout<<"Enter the length of array";
    cin>>n;
     vector<int> arr(n);
    cout<<"Enter the non negative numbers in a array";
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    cout<<"Enter the sum to check subset exist or not";
    cin>>sum;

    if(findsubset(arr,sum))
    {
        cout<<"Yes, There is the subset of given set  whose sum is equal to given sum";
    }
    else
    {
        cout<<"No, There is the subset of given set  whose sum is equal to given sum";
    }

    return 0;

}


// # Subset Sum Problem (C++ Dynamic Programming)

// This project solves the classic **Subset Sum Problem** using **Dynamic Programming (DP)**.  
// It checks whether there exists a subset of a given array such that the subset's sum equals a given target value.

// ---

// ## 📌 Problem Statement
// Given an array of non-negative integers and a target sum, determine if there exists a subset of the array whose sum is equal to the target sum.

// ---

// ## 💡 Approach
// We use **Dynamic Programming with a 1D boolean DP array**:
// - `dp[j] = true` → if a subset with sum `j` is possible.
// - Base case: `dp[0] = true` (empty subset always possible).
// - Transition:  

   // DEBUG Example trace for understanding:
        // arr = [3,34,4,12,5,2], sum = 9
        // num = 3 → dp[3] becomes true
        // num = 34 → ignored since > 9
        // num = 4 → dp[7] = true (because dp[7-4=3] was true)
        // num = 5 → dp[9] = true (because dp[9-5=4] was true) → subset found!
