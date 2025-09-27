#include<iostream>
#include<unordered_set>
using namespace std;


 string logic(string str1)
 {
      if(str1.length()<2)
      {
        return "";
      }
   
    unordered_set<char> letter(str1.begin(),str1.end());
    for(int i=0;i<str1.length();i++)
    {
        char ch=str1[i];
        if(letter.count(tolower(ch)) && letter.count(toupper(ch)))
        {
            continue;
        }

        string left=logic(str1.substr(0,i));
        string right=logic(str1.substr(i+1));
        return (left.length()>=right.length()?left:right);
    }
    return str1;

 }

int main()
{
    string str="YazyYy";
    string result=logic(str);
    cout << result << endl;
    return 0;
}

