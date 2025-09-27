#include<iostream>
#include<vector>
using namespace std;


void merge_sort(int arr[],int low,int mid,int high)
{
    vector<int> temp;
    int left=low;
    int right=mid+1;
    while(left<=mid && right<=high)
    {
        if(arr[left]<=arr[right])
        {
            temp.push_back(arr[left]);
            left++;
        }
        else{
            temp.push_back(arr[right]);
            right++;
        }
    }

    while(left<=mid)
    {
           temp.push_back(arr[left]);
            left++;
    }
        while(right<=high)
    {
           temp.push_back(arr[right]);
            right++;
    }

    for(int i=0;i<temp.size();i++)
    {
        arr[low+i]=temp[i];
    }
}

void merge_divide(int arr[],int low,int high)
{
     if(low>=high)
     {
        return;
     }
    
        int mid=(low+high)/2;
        merge_divide(arr,low,mid);
        merge_divide(arr,mid+1,high);
        merge_sort(arr,low,mid,high);
   
}

int main()
{
    int arr[]={3,1,2,4,1,5,2,6,4};
    int n=9;
    int low=0;
    int high=n-1;
    merge_divide(arr,low,high);
    cout << "The sorted array is: ";
      for (int i = 0; i < n; i++) 
      {
        cout << arr[i] << " ";
      }
    cout << endl;

}