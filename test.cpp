#include<iostream>
#include<unordered_map>
#include<vector> 
using namespace std;

int main()
{
    unordered_map<char,int> f1;
     string s="aabcccdefgggg";
     vector<char> res;
     for(char i:s)
     {
        f1[i]++;
     }

     for(auto& pair:f1)
     {
        if(pair.second>=2)
        {
           res.push_back(pair.first); 
        }
        else
        {
            continue;
        }
     }
     for(int i=0;i<res.size();i++)
     {
        cout<<res[i]<<",";
     }
    
    return 0;
}