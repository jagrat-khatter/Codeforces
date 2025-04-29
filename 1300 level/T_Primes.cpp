#include <bits/stdc++.h>
using namespace std;
using ll = long long ;

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    vector<ll> v(1000000 , 0); // objective is to get all the prime numbers till 10^6
    v[1]=1;
    for(ll i=1;i*i<=1000000;i++)
    {
        if(v[i]==0) // if a number is itself prime then it can makr others composite
        {
            for(ll j=i*i;j<=1000000;j+=i)
            {
                v[j]=1;
            }
        }
    }
    map<ll ,ll> mp;
    for(ll i=1;i<=1000000;i++)
    {
        if(v[i]==0)
        {
            ll e = i*i;
            mp[e]++;
        }
    }


    ll n ; cin >> n;
    for(ll i=0;i<n;i++)
    {
        ll x; cin >> x;
        if(mp[x]!=0) cout << "YES" << '\n';
        else cout << "NO" << '\n' ;
    }

}