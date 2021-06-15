#include <bits/stdc++.h> 
using namespace std; 
int findMajority(int a[], int n) 
{ 
    //unordered map to store the frequency of each element of the array
	unordered_map<int,int> umap; 
	//storing the frequency of each element
	for(int i=0;i<n;i++) umap[a[i]]++; 
	//checking if any majority element exists in the array
	for(auto i:umap) if(i.second>n/2) return i.first; 
	//if no majority element is present, then the function is returning zero
	return 0;
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
	int out=findMajority(a,n);
	(out)?(cout<<"Majority element is "<<out):(cout<<"Majority element is not present.");
	cout<<"\n";
}