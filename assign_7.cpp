#include<iostream>
#include<vector>
#include<cmath>
#include<algorithm>
using namespace std;

int isvalid(int N,int D,vector<int> task,int mid)
{
    int days=0;
    for(int i=0;i<N;i++)
    {
        days += (int)ceil((double)task[i]/mid);  
    }
    return days;
}

int main()
{
    int N,D;
    int sum=0;
    cout<<"Enter the No of Tasks in Array: ";
    cin>>N;
    cout<<"Enter the no of Days: ";
    cin>>D;
    vector<int> task(N);
    cout<<"Enter the amount of work done in each task: ";
    for(int i=0;i<N;i++)
    {
        cin>>task[i];
    }
    for(int i:task)
    {
        sum += i;
    }

    sort(task.begin(),task.end());

    if(N <= D)
    {
         int low = 1;
         int high = sum;   //  should be total sum
         int ans = high;

         while(low <= high)
         {
             int mid = (low+high)/2;
             int current = isvalid(N,D,task,mid);

             if(current <= D)   // valid, store answer
             {
                 ans = mid;
                 high = mid-1;
             }
             else
             {
                 low = mid+1;
             }
         }

         cout<<"The capacity of each work is "<<ans<<endl;
   }
   else
   {
        cout<<"The No of Task is greater than No of Days so not possible"<<endl;
   }
   return 0;
}
