#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;

int main()
{
    int S[]={1, 2, 3, 3, 5, 6};    //Starting time
    int E[]={4, 5, 6, 7, 8, 9};   //End time
    int k=2;     //no. of peoples
    int n=6;     //no of shops
    int count=0;
    priority_queue<int,vector<int>,greater<int>> mh;

    vector<pair<int,int>> shops;
    for(int i=0;i<n;i++)
    {
        shops.push_back({S[i],E[i]});
    }

    //sort by end only
    sort(shops.begin(),shops.end(),[](auto &a,auto &b){return a.second<b.second;});
     
    for(auto &p:shops)
    {
        int start=p.first;
        int end=p.second;

        if(mh.size()<k)
        {
            mh.push(end);
            count++;
        }
       
        else if(!mh.empty()&& mh.top()<=start)
        {
            mh.pop();
            mh.push(end);
            count++;

        }
        else{
            continue;
        }

    }
    cout<<"The no. of shops visited are"<<count;
    

    return 0;
}