#include<iostream>
using namespace std;


void merge(int arr[],int lb,int mid,int ub)
{
    int i=lb;
    int k=lb;
    int j=mid+1;
    int b[10];
    while(i<=mid && j<=ub)
    {
        if(arr[i]>=arr[j])
        {
           b[k]=arr[i];
           i++;
           k++;
        }
        else
        {
            b[k]=arr[j];
            j++;
            k++;
        }
    }

    while(i<=mid)
    {
        b[k]=arr[i];
        i++;
        k++;
    }

    while(j<=ub)
    {
        b[k]=arr[j];
        j++;
        k++;

    }

    for(int l=lb;l<=ub;l++)
    {
        arr[l]=b[l];
    }
}

void merge(int arr[],int lb,int ub)
{
int mid;
  if(lb<ub)
  {
    mid=(lb+ub)/2;
    merge(arr,lb,mid);
    merge(arr,mid+1,ub);
    merge(arr,lb,mid,ub);
  }
}

int main()
{
    int arr[10]={2,0,1,6,0,4,7,8};
    int n=8;
    int lb=0;
    int ub=n;
    merge(arr,lb,ub);
    for(int i=0;i<n;i++)
    {
        cout<<arr[i];
    }

}
