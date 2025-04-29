#include <bits/stdc++.h>
using namespace std;
using ll = long long ;
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    ll s=100000;
    vector<ll> sv(100001 , 0);       // initialiing a vector such that all its elements are 0 
    sv[1]=1;        // all the numbers which are not prime will be marked 1 
    for(ll i=2;i*i<=s;i++)
    {
        if(sv[i]!=1)
        {
            for(ll j=i*i;j<=s;j += i)
            {
                sv[j]=1;
            }
        }
    }

    ll t; cin >> t;
    while(t--)
    {
        ll n; cin >> n;
        if(n==2) {cout << 1 << ' ' << 2 << '\n'; continue;} 
        cout << 1 << ' ';
        if(n%2==0)
        {
            for(ll i=2;i<=(n/2);i++)
            {
                cout << i << ' ' << 2*i <<  ' ';
            }
        }
        else{
            for(ll i=2;i<=(n/2);i++)
            {
                cout << i << ' ' << 2*i <<  ' ';
            }
            cout << n/2 +1 << ' ' << n << ' ';
        }

        cout << '\n' ;
    }
}