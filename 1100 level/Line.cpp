#include <bits/stdc++.h>
using namespace std;
using ll  = long long;
const ll lmin = LLONG_MIN;
const ll lmax = LLONG_MAX;
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    ll t; cin >> t;
    while(t--)
    {
        ll n ; cin >> n;
        string s; cin >> s;
        ll l=0 , r=s.size()-1 , sum=0;
        multiset<ll> ms;
        for(ll i=0;i<n;i++)
        {
            if(s[i]=='L') sum += i;
            else sum += n-i-1;

            if(i<(n/2) && s[i]!='R') ms.insert(i);
            if(i>=((n +2-1)/2) && s[i]!='L') ms.insert(n-i-1); 
        }
        // we'll make a multiset storing all indexes which need to be fixed;
        // cout << sum << '\n';
        // for(auto i : ms) cout << i << ' ';
        // cout << '\n' ;
        auto it = ms.begin();
        for(ll i=1;i<=n;i++)
        {
            if(it == ms.end()) cout << sum << ' ';
            else {
                ll id= *it; // dereferencing the index
                sum = sum - (id) + (n-id-1);
                cout << sum << ' ';
                it++;
            }
        }
        cout << '\n' ;
    }


    return 0;
}