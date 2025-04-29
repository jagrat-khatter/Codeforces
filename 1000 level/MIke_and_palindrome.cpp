#include<bits/stdc++.h>
using namespace std;
using ll = long long;
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    string s;
    cin >> s;

    ll n = s.size();
    ll ct=0;
    for(ll i=0;i<(n/2);i++)
    {
        if(s[i]!=s[n-i-1]) ct++;
    }
    if(ct==1) cout << "YES" << '\n';    // if only one charcter needs to be changed 
    else if(ct==0 && n%2!=0) cout << "YES" << '\n'; // if a string is already a palindrome but size of string is odd
    else cout << "NO" << '\n' ;    // else there is no other case



    return 0;
}