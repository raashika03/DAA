#include<bits/stdc++.h>
using namespace std; 
//function to partition the array around x
int partitioning(int a[], int l, int r, int x) 
{ 
    int i; 
    //searching for x in the array
	for(i=l;i<r;i++) if(a[i]==x) break; 
	//moving x to the end of the array
	swap(a[i],a[r]); 
	i=l; 
	for(int j=l;j<=r-1;j++) 
	{ 
		if(a[j] <= x) 
		{ 
			swap(a[i],a[j]); 
			i++; 
		} 
	} 
	swap(a[i],a[r]); 
	return i; 
} 
//Function to find the median of an array of size 5
int findMedian(int a[],int len) 
{ 
    //sorting the array of size 5 using sort function in stl library
	sort(a,a+len); 
	//returning the middle i.e., 3rd element
	return a[len/2];
} 
//returns the kth element in an array sorted in ascending order
int sorted_array_kthElement(int a[],int l,int r,int k) 
{ 
    //r-l+1 is the no. of elements in an array
    //if k is a valid no. i.e., k is smaller than the total no. of elements in an array
	if (k>0 && k<=r-l+1) 
	{ 
	    //n = no. of elements in an array
		int n=r-l+1; 
		int i, median[(n+4)/5];
		//Dividing the array into arrays of size 5
		// find out median of each array using findMedian function
		//store those median values into median array defined above.
		for(i=0; i<n/5; i++) 
			median[i] = findMedian(a+l+i*5,5); 
		// If there's any group with elements less than 5	
		if (i*5<n) 
		{ 
			median[i]=findMedian(a+l+i*5,n%5); 
			i++; 
		}	 
		//find the median of medians of all the arrays of size 5 i.e., median of values of median array.
		int medianOfMedian=(i == 1)? median[i-1]:sorted_array_kthElement(median,0,i-1,i/2); 
		//partioning the array at a particular position
		int pos=partitioning(a,l,r,medianOfMedian); 
		// if that pivot position is same as k
		if(pos-l==k-1) return a[pos]; 
		//if pivot is greater than k, then recur for the left part of the array else for the right part	
		if(pos-l>k-1) return sorted_array_kthElement(a,l,pos-1,k); 
		return sorted_array_kthElement(a,pos+1,r,k-pos+l-1); 
	} 
	//if k isn't valid i.e., k is greater than the no. of elements int he array
	return INT_MAX; 
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
	cout<<"Median of the array is: ";
	if(n%2==1)cout<<sorted_array_kthElement(a, 0, n-1, (n/2)+1);
	else cout<<(sorted_array_kthElement(a, 0, n-1, n/2)+sorted_array_kthElement(a, 0, n-1, (n/2)+1))/2.0;
	cout<<"\n";
} 
