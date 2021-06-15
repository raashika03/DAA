#include<bits/stdc++.h>
using namespace std;
//function to merge two sorted arrays
void merge(int a[],int l,int m,int r)
{
    //n1= size of 1st sub array
    //n2= size of 2nd sub array
    //i= starting index of 1st subarray
    //j= starting index of 2nd subarray
    //k= starting index of merged subarray
	int n1=m+1-l,n2=r-m,j=0,k=l,i=0;
	//creating two temporary arrays for storing data of two subarrays
	int L[n1],R[n2];
	for(int i=0;i<n1;i++)L[i]=a[i+l];
	for(int j=0;j<n2;j++)R[j]=a[j+m+1];
	while(n1>i&&n2>j) {
		if(R[j]<L[i]) a[k]=R[j++];
		else a[k]=L[i++];
		k++;
	}
	//copying the elements of L[] which are left to be copied
	while (n1>i) a[k++]=L[i++];
    //copying the elements of R[] which are left to be copied
	while (n2>j) a[k++]=R[j++];
}
void mergeSort(int a[],int l,int r){
	if(r<=l)return;
	int m=(r-l)/2+l;
	mergeSort(a,l,m);
	mergeSort(a,m+1,r);
	merge(a,l,m,r);
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
	mergeSort(a,0,n-1);
	cout<<"Sorted array: ";
	for(int i=0;i<n;i++)cout<<a[i]<<" ";
	cout<<"\n";
}