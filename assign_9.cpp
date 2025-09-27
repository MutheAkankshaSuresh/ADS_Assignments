#include<iostream>
#include<vector>
using namespace std;

int comb(vector<int>coins,int sum)
{
   vector<long long> dp(sum+1,0);
    
   dp[0]=1;   //base case 

   for(int coin:coins)
   {
      for(int j=coin;j<=sum;j++)
      {
         dp[j]+=dp[j-coin];
      }
   }

   return dp[sum];
}

int main()
{
    int n,sum;
   
    cout<<"Enter the no of array element";
    cin>>n;
    vector<int>coins(n);
    cout<<"Enter the  array element";
    for(int i=0;i<n;i++)
    {
       cin>>coins[i];
    }
     cout<<"Enter the  target element";
     cin>>sum;

     cout<<"The combinations of different coins in array which will be equal to target value is "<<comb(coins,sum);



}



// # Coin Change Problem – Count Combinations (C++ Dynamic Programming)

// This project solves the **Coin Change Problem (Combinations)** using **Dynamic Programming (DP)**.  
// It counts the **number of different ways** to make up a target sum using the given coins.

// ---

// ## 📌 Problem Statement
// Given an array of coins of different denominations and a total amount, determine how many combinations of coins can be used to make up that amount.  
// - You may assume you have **infinite supply** of each coin.  
// - Order of coins does **not** matter (combinations, not permutations).

// ---

// ## 💡 Approach
// We use **Dynamic Programming with a 1D array**:
// - `dp[j] = number of ways to make sum j`
// - Base case: `dp[0] = 1` (only one way to make sum 0 → no coins).
// - Transition:
