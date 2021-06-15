#include <bits/stdc++.h> 
using namespace std; 
int findMajority(int a[], int n) 
{ 
    //sorting the array using sort function from c++ stl library in O(nlog(n)) time complexity
    sort(a,a+n); 
    int temp=a[0],majority_element,count=1,max_count=0,f=0; 
    for(int i=1;i<n;i++) 
    { 
        //if same element is present then, increase the count 
        if(a[i]==temp)count++; 
        else
        { 
            //counting the new element
            count=1; 
            temp=a[i]; 
        }
        if(count>max_count) 
        { 
            max_count=count; 
            majority_element=a[i];
            //if majority element is present, then return that
            if(max_count>(n/2)) return majority_element;
        } 
    }
    //if no majority element is present, then return 0
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