//importing all the libraries
#include <bits/stdc++.h>
using namespace std;
//Matrix to store results
int dp[100001][3];
int solve(int a[][3],int n,int i,int j)
{
	//base condition
    if(n<0) return 0;
    //filling the matrix, if it's not filled
    if(dp[n][i]==0) dp[n][i] = a[n][i]+solve(a,n-1,(i+1)%3,(i+2)%3);
    if(dp[n][j]==0) dp[n][j] = a[n][j]+solve(a,n-1,(j+1)%3,(j+2)%3);
    //returning the minimum of the above calculated values
    return min(dp[n][i],dp[n][j]);
}
int main()
{
	    int n;
	    cout<<"Enter no. of shops:\n";
	    cin>>n;
	    //input matrix
	    int arr[n][3];
	    //initialising dp with zeroes
	    memset(dp,0,sizeof(dp));
	    for(int i=0;i<n;i++) {
	    	cout<<"Enter prices of vegetables in shop "<<(i+1)<<"\n";
	    	cin>>arr[i][0]>>arr[i][1]>>arr[i][2];
	    }
	    int x = solve(arr,n-1,0,1);
	    int y = min(x,solve(arr,n-1,1,2));
	    cout<<"\nMin amount of money to be spent on the inspection:\n"<<min(y,solve(arr,n-1,0,2))<<"\n";
}