#include<iostream>
using namespace std;

int main()
{
    int arr[5]={1,5,3,8,12};
    int profit=0;
    int buy=0;
    int n=5;

    for(int i=0;i<n;i++)
    {
        if(i<n-1 && arr[i]<arr[i+1])  //Buy the Stock
        {
            buy++;
            profit-=arr[i];
        }
        else if(buy>0)
        {
            profit+=buy*arr[i];
            buy=0;
        }
    }

    cout<<"The total Profit of the stocks prize are"<<profit;
}