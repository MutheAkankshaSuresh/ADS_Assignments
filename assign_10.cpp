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