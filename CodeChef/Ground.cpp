#include<bits/stdc++.h>
using namespace std;
using ll = long long;

ll power(ll p , ll q)
{
    if(q==1) return p;

    ll value = power(p , q/2);

    if(q%2==0) return value * value ;
    else return value * value * p;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    string s= "hyuqwawa" ;
    sort(s.begin() , s.end());

    cout << s ;
    return 0;
}