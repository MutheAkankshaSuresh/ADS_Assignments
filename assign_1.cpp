#include<iostream>
using namespace std;


bool isvalid(int arr[],int n)
{
    bool zero=false;
    for(int i=0;i<n;i++)
    {
        if(arr[i]==0)
        {
            zero=true;
        }

        if(zero && arr[i]==1)
        {
            return false;
        }
    }
    return true;
}

int main()
{
    int arr[]={1,1,0,0,0,0,0,0,0};
    int n=9;
    int l=0;
    int h=n-1;
    int mid,firstzero=-1;
    isvalid(arr,n);
    if(isvalid(arr,n))
    {
        while(l<=h)
        {
          mid=(l+h)/2;
          if(arr[mid]==0)
          {
            firstzero=mid;
            h=mid-1;
          }
          else{
            l=mid+1;
          }
        }

        if(firstzero==-1)
        {
            cout<<"No zero found in array";
        }

        else{
            cout<<"count of zero is"<<n-firstzero;
        }
       
    }

    else{
        cout<<"Invalid Format";
    }

    return 0;
}
