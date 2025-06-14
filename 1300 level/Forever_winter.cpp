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
        ll n,m; cin >> n >> m;
        map<ll , ll> mp;
        set<ll> s;
        for(ll i=0;i<m;i++){
            ll a,b;  cin >>  a >> b; s.insert(a);s.insert(b);
            mp[a]++;
            mp[b]++;
        }
        vector<ll> v2;
        
        ll nt1 =0;
        for(auto i : s){
            v2.push_back(mp[i]);
            if(mp[i] != 1) nt1++;
        }
        // for(auto i : v2) cout << i << ' ';
        // cout << '\n';
        if(nt1 == 0) cout << 1 << ' ' << 1 << '\n';
        else if(nt1 == 1) {
            ll e;ll fq=0;
            for(auto i : v2) {
                if(i!=1) {e=i;fq++;}
            }
            cout << 1 << ' ' << e-1 <<'\n';
        }
        else{
            ll e1=0,e2=0; ll ct1=0,ct2=0;
            for(auto i : v2){
                if(i==e1) ct1++;
                else if(i==e2) ct2++;

                if(i != 1 && e1==0){
                    e1=i;
                    ct1++;
                }
                else if(i !=1 && i!=e1 && e2==0){
                    e2=i;
                    ct2++;
                }
            }
            
            // cout << e1 << ' ' << ct1 << '\n';
            // cout << e2 << ' ' << ct2 << '\n';
            if(e2==0) cout << e1 << ' ' << e1-1 << '\n'; 
            else if(ct1==1) cout << e1 << ' ' << e2-1 << '\n';
            else cout << e2 << ' ' << e1-1 << '\n';
        }
        
    }


    return 0;
}