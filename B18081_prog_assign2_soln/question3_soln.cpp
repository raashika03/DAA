//importing all the libraries
#include <bits/stdc++.h>
using namespace std;

// function to calculate min steps in which dynamic approach has been used
int getMinSteps(int n, int *memo)
{
	// base case
	if (n == 1)
	return 0;
	if (memo[n] != -1)
	return memo[n];

	// store temp value for n as min( f(n-1),
	// f(n/2), f(n/3)) +1
	int res = getMinSteps(n-1, memo);

	if (n%2 == 0)
		res = min(res, getMinSteps(n/2, memo));
	if (n%3 == 0)
		res = min(res, getMinSteps(n/3, memo));

	// store memo[n] and return
	memo[n] = 1 + res;
	return memo[n];
}

// This function mainly initializes memo[] and
// calls getMinSteps(n, memo)
int getMinSteps(int n)
{
	int memo[n+1];

	// initialize memoized array
	for (int i=0; i<=n; i++)
		memo[i] = -1;

	return getMinSteps(n, memo);
}


int main()
{
	int n;
	cout<<"Enter positive integer n:\n";
	cin>>n;
	cout <<"Min no. of steps taken from "<<n<<" to 1:\n"<<getMinSteps(n);
	cout<<"\n";
}
