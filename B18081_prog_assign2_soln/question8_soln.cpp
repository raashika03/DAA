//importing all the libraries
#include<bits/stdc++.h>
using namespace std;

string shortestPalindrome(string s)//function returning the shortest palindrome using KMP lookup table generation
{
    int n = s.size();//function to find the length of the input string
    string rev(s);
    reverse(rev.begin(), rev.end());
    //Create new_s as s + "#" + reverse(s) 
    string s_new = s + "#" + rev;
    int n_new = s_new.size();
    vector<int> f(n_new, 0);
    for (int i = 1; i < n_new; i++) {
        int t = f[i - 1];
        while (t > 0 && s_new[i] != s_new[t])
            t = f[t - 1];
        if (s_new[i] == s_new[t])
            ++t;
        f[i] = t;
    }
    //Return reversed string after the largest palindrome from beginning length(given by n - f[n_new - 1]) + original string s
    return rev.substr(0, n - f[n_new - 1]) + s;
}

int main()
{
    string s;
    cout<<"Enter your string:\n";
    cin>>s;
    //printing the length of the shortest palindrome formed
    cout<<"Length of the shortest palindrome that can be created from "<<s<<" is: \n"<<shortestPalindrome(s).length()<<"\n";
}