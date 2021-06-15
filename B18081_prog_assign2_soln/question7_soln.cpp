//importing all the libraries
#include<bits/stdc++.h>
using namespace std;
int func(string s){
    int n=(int)s.size();
    vector<int> prefix_function(n);
    for(int i=1, j; i<n; i++){
        j=prefix_function[i-1];
        while(j && s[i]!=s[j]){
            j=prefix_function[j-1];
        }
        if(s[i]==s[j])j++;
        prefix_function[i]=j;
    }
    int mx=0;
    for(int i=n-1; s[i]!='#'; i--){
        mx=max(mx, prefix_function[i]);
    }
    return mx;
}

int main()
{   
    string S, T, s;
    cout << "Enter one of the strings:\n";
    cin >> S;
    cout << "Enter one of the strings:\n";
    cin >> T;
    s= S+"#"+T;
    int ans=0, index=0;
    for(int i=0; i<S.size(); i++){
        int temp=func(s);
        if(ans<temp){
            index=i;
            ans=temp;
        }
        s.erase(s.begin());
    }
    if(ans==0){
        cout << "Not Found\n";
    }
    else{
        cout<<"The longest common substring is:\n";
        cout << S.substr(index, ans) << endl;
    }
    return 0;
}
