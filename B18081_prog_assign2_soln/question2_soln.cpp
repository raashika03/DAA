//importing all the libraries
#include <bits/stdc++.h>
using namespace std;

int rate [100000 + 10];
long long values [100000 + 10];   

int main()
{
    int n;
    long long ans = 0, tmp = 0;
    cout<<"Enter number of students, n : \n";
    cin >> n;

    cout<<"Enter students grades : \n";
    for(int i = 0; i < n; i++) 
        cin >> rate[i];

    values[0] = 1;
    // scanning input array from left to right
    for(int i = 1; i < n; i++)   
    {         
        if(rate[i] > rate[i - 1])
            values[i] = values[i - 1] + 1; 
        else 
            values[i] = 1;
    }

    ans = values[n - 1];

    // scanning input array from right to left
    for(int i = n - 2; i >= 0; i--)     
    {   
        if(rate[i] > rate[i + 1])
            tmp = values[i + 1] + 1; 
        else 
            tmp = 1;

        // Finding the maximum of the two values for child i
        ans += max(tmp, values[i]);   
        values[i] = tmp;
    }

    cout<<"Minimum number of awards : "<<ans<<"\n";

    return 0;
}