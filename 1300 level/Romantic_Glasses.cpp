#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll lmin = LLONG_MIN;
const ll lmax = LLONG_MIN;
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    ll t; cin >> t;
    while(t--)
    {
        ll n; cin >> n;
        vector<ll> v;
        for(ll i=0;i<n;i++){
            ll x; cin >> x;
            if((i+1)%2==0) v.push_back(-x);
            else v.push_back(x);
        }
        vector<ll> ans;
        for(ll i=0;i<n;i++)
        {
            if(i==0)  ans.push_back(v[0]);
            else ans.push_back(v[i] + ans[i-1]);
        }
        // for(auto i : ans) cout << i << ' ';
        // cout << '\n';
        map<ll,ll> mp1,mp2;
        for(ll i=0;i<n;i++)
        {
            if(mp1[ans[i]]==0) mp1[ans[i]]=i+1;     // storing the index in one based indexing 
            else mp2[ans[i]]=i+1;
        }// no map can be zero // both will be +ve if  more than one index exist for same number in prefix array 
        ll fg=0;
        for(ll i=0;i<n && fg==0;i++){
            if(mp1[0]>0) {cout << "YES"<< '\n'; fg=1;}
            else if(mp1[ans[i]]>0 && mp2[ans[i]]) {cout << "YES"<< '\n'; fg=1;}
        }
        if(!fg) cout << "NO" << '\n';
        
    }




    return 0;
}