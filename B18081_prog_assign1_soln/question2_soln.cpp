#include <bits/stdc++.h> 
using namespace std;
//creating a binary tree node, with pointer to its left and right child
class node 
{ 
	public:
	int data; 
	node *lt,*rt; 
}; 
//function to allocate a new node with the given data, and NULL left and right pointers
node* NewNode(int data) 
{ 
	node* t=new node; 
	t->lt=t->rt=NULL; 
	t->data=data; 
	return(t); 
} 
//function to traverse tree across height
void Htraversal(node* root,int a[],int &out) 
{ 
	//Base Case
	if(root==NULL||(root->rt==NULL&&root->lt==NULL))return;
	//updating the output and recurring the function for its subarray
	if(out>a[root->rt->data]&&root->data!=root->rt->data) 
	{ 
		out=a[root->rt->data]; 
		Htraversal(root->lt,a,out); 
	} 
	else if(out>a[root->lt->data]&&root->data!=root->lt->data) 
	{ 
		out=a[root->lt->data]; 
		Htraversal(root->rt,a,out); 
	}  
} 
//function for printing the min and second min element of the array
void minAndSecondMin(int a[],int n) 
{ 
	list<node*>v; //list creation for storage of current level nodes
	node* root=NULL; 
	for(int i=0;i<n;i++) 
	{ 
		node *t1=NewNode(i),*t2=NULL; 
		if(++i<n) 
		{  
			t2=NewNode(i); //node creation for next element
			root=(a[i-1]>a[i])? NewNode(i):NewNode(i-1); //updating root with the smaller element
			root->lt=t1; 
			root->rt=t2; 
			v.push_back(root); 
		} 
		else v.push_back(t1); 
	} 
	int vsize=v.size(); 
	//tree construction
	while(vsize!=1) 
	{ 
		int last=(vsize&1)? (vsize-2):(vsize-1); 
		for(int i=0;i<last;i+=2) 
		{ 
			node *f1=v.front(); 
			v.pop_front(); 
			node *f2=v.front(); 
			v.pop_front(); 
			root=(a[f2->data]>a[f1->data])?NewNode(f1->data):NewNode(f2->data); 
			root->lt=f1; 
			root->rt=f2;  
			v.push_back(root); 
		} 
		if(vsize) 
		{ 
			v.push_back(v.front()); 
			v.pop_front(); 
		} 
		vsize=v.size(); 
	} 
	int out=INT_MAX; 
	Htraversal(root,a,out); 
	cout<<"Minimum element: "<<a[root->data]<<"\nSecond minimum element: "<<out<<"\n"; 
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
	minAndSecondMin(a, n); 
} 
