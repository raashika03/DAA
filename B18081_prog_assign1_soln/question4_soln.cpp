#include<bits/stdc++.h>
using namespace std; 
//function to partition the array around x
int partitioning(int a[], int l, int r, int x) 
{ 
    int i; 
    //searching for x in the array
	for(i=l;i<r;i++) if(x==a[i]) break; 
	//moving x to the end of the array
	swap(a[r],a[i]); 
	i=l; 
	for(int j=l;j<r;j++) 
	{ 
		if(x>=a[j]) 
			swap(a[j],a[i++]); 
	} 
	swap(a[r],a[i]); 
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
	if (k<=r-l+1 && k>0) 
	{ 
	    //n = no. of elements in an array
		int n=r-l+1; 
		int i, median[(n+4)/5];
		//Dividing the array into arrays of size 5
		// find out median of each array using findMedian function
		//store those median values into median array defined above.
		for(i=0;i<n/5;i++) 
			median[i]=findMedian(a+l+i*5,5); 
		// If there's any group with elements less than 5	
		if(i*5<n) 
		{ 
			median[i]=findMedian(a+l+i*5,n%5); 
			i++; 
		}	 
		//find the median of medians of all the arrays of size 5 i.e., median of values of median array.
		int medianOfMedian=(i == 1)? median[i-1]:sorted_array_kthElement(median,0,i-1,i/2); 
		//partioning the array at a particular position
		int pos=partitioning(a,l,r,medianOfMedian); 
		// if that pivot position is same as k
		if(k-1==pos-l) return a[pos]; 
		//if pivot is greater than k, then recur for the left part of the array else for the right part	
		else if(k-1>pos-l) return sorted_array_kthElement(a,pos+1,r,k-pos+l-1); 
		return sorted_array_kthElement(a,l,pos-1,k); 
	} 
	//if k isn't valid i.e., k is greater than the no. of elements int he array
	return INT_MAX; 
} 
void quickSort(int a[],int l,int h)
{
    if(h>l)
    {
        // n=length of subarray
        int n=h+1-l;
        // Finding the median of a[].
        int med=sorted_array_kthElement(a,l,h,n/2);
        // Partitioning the array around median
        int p = partitioning(a,l,h,med);
        // Recur for left and right of partition
        quickSort(a,l,p-1);
        quickSort(a,p+1,h);
    }
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
	quickSort(a,0,n-1);
	cout<<"Sorted array: ";
	for(int i=0;i<n;i++)cout<<a[i]<<" ";
	cout<<"\n";
} 
