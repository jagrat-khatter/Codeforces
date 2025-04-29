#include <bits/stdc++.h>
using namespace std;
using ll = long long ;
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    ll t; cin >> t;
    while(t--) 
    {
        string a , b; cin >> a >> b;
        ll fg=0 , n=a.size();
        for(ll i=0;i<n-1;i++)
        {
            if(a[i]=='0' && b[i]=='0' && a[i+1]=='1' && b[i+1]=='1') fg=1;
        }

        if(fg) cout << "YES" << '\n';
        else cout << "NO" << '\n' ;
    }
    return 0;
}