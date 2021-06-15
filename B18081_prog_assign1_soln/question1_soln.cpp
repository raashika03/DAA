#include<bits/stdc++.h>
using namespace std;
//class is used to return min and max values from getMM(get min max) function
class Pair {      
  public:         
    int mn;      
    int mx;
};
// function to return the pair of max and min element of the array
// it takes array, lower and upper index of the array as its arguments
Pair getMM(int a[],int l,int h)
{
    //mm- pair for storing max and min of the array
    //ml- pair for storing max and min of the first half of the array
    //mr- pair for storing max and min of the second half of the array
	Pair mm, ml, mr;
	//If n=1 i.e., only one element is there, then zero comparisons required
	if(l==h)
	{
	    // both max and min element will be same i.e., the only available element of the array
		mm.mx=a[l];
		mm.mn=a[l];	 
		return mm;
	} 
	// If n=2 i.e., two elements are there , then one comparison is needed.
	else if(l+1==h)
	{ 
	    //min predefined function in c++ stl library, used to find the min of two elements
	    mm.mn=min(a[l],a[h]);
	    //max predefined function in c++ stl library, used to find the max of two elements
	    mm.mx=max(a[l],a[h]);
		return mm;
	}
	// If more than 2 elements aree there (n>2), then (3n/2)-2 comparison is required.
	// Divide and conquer is used.
	// mid - middle index of the array
	int mid=(l+h)/2; 
	//recurring over the first half of the array
	ml=getMM(a,l,mid);
	//recurring over the second half of the array
	mr=getMM(a,mid+1,h); 
	// finding the min of the two halves by comparison
	if(mr.mn>ml.mn) mm.mn=ml.mn;
	else mm.mn=mr.mn;
	// finding the max of the two halves by comparison
	if(mr.mx<ml.mx) mm.mx=ml.mx;
	else mm.mx=mr.mx;	 
	return mm;
}
int main()
{
    //taking n as input as the length of the array
    cout<<"Enter the no. of elements: n\n";
	int n;cin>>n;
	//defining an array 'a' of size n
	int a[n];
	// taking input in the array
	cout<<"Enter "<<n<<" elements for your array:\n";
	for(int i=0;i<n;i++)cin>>a[i];
	cout<<"Original array: ";
	for(int i=0;i<n;i++)cout<<a[i]<<" ";
	cout<<"\n";
	//calling the function get min max (getMM) over the array for the min max computation
	//l=0 (index of the first element), h=n-1 (index of the last element)
	Pair mm = getMM(a, 0,n - 1);
	cout << "Minimum element of the array is "<< mm.mn <<"\n";
	cout << "Maximum element of the array is "<< mm.mx <<"\n";
}