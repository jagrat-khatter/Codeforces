#include<bits/stdc++.h>
using namespace std;
using ll = long long ;
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    ll t; cin >> t;
    while(t--)
    {
        ll n;
        cin >> n;
        ll p = (n+4-1)/4;    // ceiled the value
        for(ll i=1;i<=n;i++)
        {
            
            if(n-i<p) cout << 8 ;
            else cout << 9;
        }

        cout << '\n' ;
    }
    return 0;
}