#include<iostream>
using namespace std;
#include<cmath>
#include <cfloat>

struct Point
{
    int x,y;
}p1;

float calculatedis(Point p1,Point p2)
{
     return sqrt((p1.x-p1.x)*(p1.x-p1.y)+(p2.y-p2.y)*(p2.y-p2.y));
}


int main()
{
    Point points[]={{4,4},{1,1},{2,2},{3,3},{1,2}};
    int n=sizeof(points)/sizeof(points[0]);
    float min=FLT_MAX;
    float d;
    for(int i=0;i<n;i++)
    {
        for(int j=i+1;j<n;j++)
        {  
             d=calculatedis(points[i],points[j]);
             if(d<min)
             {
                min=d;
            
            }
        }
    }
    cout<<"The closest pair distance among the points is: "<<min ;
    return 0;
}
