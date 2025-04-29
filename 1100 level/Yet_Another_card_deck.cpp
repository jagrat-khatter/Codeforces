#include <bits/stdc++.h>
using namespace std;
using  ll = long long;
const ll lmin = LLONG_MIN;
const ll lmax = LLONG_MAX;
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    ll t ; t=1;
    while(t--)
    {
        ll n , q; cin >> n >> q;
        map<ll , ll> mp;
        for(ll i=1;i<=50;i++)  mp[i] =-1; // there  are 50 colors initializing the with -1
        for(ll i=0;i<n;i++)
        {
            ll x ; cin >> x;
            if(mp[x]==-1) mp[x]=i; // getting the lowest index of the color 
        }
        // for(ll i=1;i<=4;i++)
        // {
        //     cout << mp[i] << '\n' ;
        // }

        for(ll i=1;i<=q;i++)
        {
            ll x;cin >> x;
            cout << mp[x] + 1 << ' ';
            if(mp[x]!=0)
            {
                for(ll j=1;j<=50;j++)
                {
                    if(mp[j]!= -1 && j!=x && mp[j]<mp[x]) // if that color is present has a index
                    {
                        mp[j]++;
                    }
                }
                mp[x]=0;
                
            }
            // for(ll i=1;i<=4;i++)
            // {
            //     cout << mp[i] << '\n' ;
            // }
        }

        
    }


    return 0;
}