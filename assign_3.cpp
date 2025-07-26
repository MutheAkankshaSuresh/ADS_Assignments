#include<iostream>
using namespace std;

// Function to count trailing zeroes in factorial of x
int findzeroes(int x)
{
    int temp = 5;
    int ans = 0;
    while (x / temp != 0)
    {
        ans += x / temp;
        temp *= 5;
    }
    return ans;
}

int main()
{
    int n = 5; 
    int lb = 1;
    int hb = n * 5; 
    int mid, zeros;
    int res = -1;

    while (lb <= hb)
    {
        mid = (lb + hb) / 2;
        zeros = findzeroes(mid);

        if (zeros < n)
        {
            lb = mid + 1;
        }
        else
        {
            // Even if zeros == n, try to find smaller such number
            if (zeros == n)
                res = mid;
                hb = mid - 1;
        }
    }

    if (res != -1)
        cout << "The smallest number whose factorial has exactly " << n << " trailing zeroes is: " << res << endl;
    else
        cout << "No such number found for " << n << " trailing zeroes." << endl;

    return 0;
}
