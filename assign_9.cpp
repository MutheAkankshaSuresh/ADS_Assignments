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