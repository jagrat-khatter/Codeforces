#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll lmin = LLONG_MIN;
const ll lmax = LLONG_MAX;

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    ll t;cin >> t;
    while(t--)
    {
        ll n,m ; cin >> n >> m;
        vector<ll> a(n),b(m);
        for(auto &i : a) cin >> i ;
        for(auto &i : b) cin >> i ;

        

        ll p1=0 , p2=0;
        ll lst=-1;
        while(p1!=n && p2!=m){
            
            if(a[p1] >= b[p2]) {p1++; p2++; lst = p1;} // last transaction happened at p1
            else p1++;
        }
        cout << p1 << ' ' << p2 << ' ' << lst << '\n';
        if(p2==m){
            cout << 0 << '\n';
        }
        else {// 
            vector<ll> v;
            set<ll> s2;
            map<ll ,ll> mp;
            for(ll i=0;i<a.size();i++){
                s2.insert(a[i]);
                mp[a[i]]++;
            }
            for(auto i : s2) v.push_back(i);
            for(auto i : v) cout << i << ' ';
            
            set<ll> s; // all the elements for which there is no element 
            for(ll i=0;i<b.size();i++)
            {   ll l=0-1 , r = v.size()-1+1;
                ll target = b[i];
                while(r-1>l){
                    ll mid = (l+r) / 2;
                    if(v[mid]<target || mp[v[mid]] == 0) l = mid;
                    else {r = mid; mp[v[r]] -- ;}
                }
                if(r == n) cout << b[i] << '\n';
            }
        }
    }


    return 0;
}