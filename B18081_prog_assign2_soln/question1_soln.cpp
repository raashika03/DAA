//importing all the libraries
#include<bits/stdc++.h>
using namespace std;
 
int maxStolen(int n, int values[])
{
    //array to store results
    int dp[n+1];
 
    //dp[i]=maximum stolen value from first i houses
    dp[0]=0;
    dp[1]=values[1];
 
    for(int i=2;i<=n;i++)
    {
        //maximum stolen value from first i houses of the line can be 
        //either the maximum stolen value from first i-1 houses of the line
        //or maximum stolen value from i-2 houses of the line plus value in ith house
        //so, we will choose maximum of these
        dp[i]=max(dp[i-1],dp[i-2]+values[i]);
    }
    return dp[n];
}


int main()
{
    int n;
    cout<<"Enter the number of houses\n";
    cin>>n;
 
    int values[n+1];
    cout<<"Enter the values in the houses\n";
    for(int i=1;i<=n;i++)
        cin>>values[i];
 
    cout<<"Maximum stolen value is \n";
    cout<<maxStolen(n, values);
 
    cout<<"\n";
}