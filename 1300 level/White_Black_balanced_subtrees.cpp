#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll lmin = LLONG_MIN;
const ll lmax = LLONG_MAX;
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    ll t; cin >> t;
    while(t--)
    {
        ll n; cin >> n;
        // vector<ll> v(n-1);
        map<ll , ll> mb,mw   ,mp;
        ll ct=0;
        map<ll ,set<ll>> fd;
        for(ll i=0;i<n-1;i++) {ll x; cin >> x; fd[x].insert(i+2);}
        string s; cin >> s;
        for(ll i=n;i>=1;i--){
            // searching that is this connected to any other node so it can make a subtree
            // ll l= 0-1 , r= v.size()-1+1;
            // ll l1= 0-1 , r1= v.size()-1+1;
            ll target = i;

            if(fd[target].size()!=0) // doing binary search when we are sure that element is present in v
            {   
                for(auto j : fd[target]){
                    mb[target]+=mb[j];
                    mw[target]+=mw[j];
                }
                if(s[i-1]=='W') mw[target]++;
                else mb[target]++;

                if(mb[target]==mw[target]) ct++;
                //cout << target  << ' ' << mw[target] << ' ' << mb[target] << '\n';
            }
            else{
                if(s[i-1]=='W') mw[target]++;
                else mb[target]++;
            }
        }
        cout << ct << '\n';
    }

    return 0;
}