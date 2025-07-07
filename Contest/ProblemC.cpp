#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll lmin = LLONG_MIN;
const ll lmax = LLONG_MAX;
ll max(ll a, ll b){
    if(a>b) return a;
    else return b;
}
ll min(ll a,ll b)
{
    if(a>b) return b;
    else return a;
}
ll power(ll b,ll e){
    if(e==0) return 1;

    ll value = power(b , e/2);
    if(e%2==0) return value * value;
    else return value * value * b;
}
bool check(ll mid , vector<pair<ll , ll>>& vp){
    vector<ll> xc,yc;
    for(auto j : vp){
    //cout << "vp"<< '\n';
        xc.push_back(j.first);
        yc.push_back(j.second);
    
    }
    // cout << mid << '\n';
    // for(auto j : xc) cout << j << ' ';cout << '\n';
    // for(auto j : yc) cout << j << ' ';cout << '\n';

    ll ans=0;
    for(auto i : xc){// we choose a xcoord 
        set<ll> sl;
        for(ll j=0;j<xc.size() && sl.size()<=1;j++){
            if(i != xc[j]) sl.insert(yc[j]);
        }
        if(sl.size()<=1) {ans=1; break;}
    }
    //if(ans==1) cout << "ans" << mid << '\n';
    if(ans == 1) return true;
    else return false;
    
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    ll t; cin >> t;
    while(t--){
        ll n,m; cin >> n >> m;
        vector<vector<ll>> v;
        ll mx=lmin;
        for(ll i=0;i<n;i++){
            v.push_back({});
            for(ll j=0;j<m;j++){
                ll x; cin >> x;
                v[i].push_back(x);
                mx = max(mx , x);
            }
        }
        ll ct=0;

        for(ll i=0;i<n;i++){
            for(ll j=0;j<m;j++){
                if(v[i][j]==mx) ct++;
            }
        }
        map<ll , ll> sr,sc;
        for(ll i=0;i<n;i++){
            ll sum=0;
            for(ll j=0;j<m;j++){
                if(v[i][j] == mx) sum++;
            }

            sr[i] = sum;
        }
        for(ll j=0;j<m;j++){
            ll sum=0;
            for(ll i=0;i<n;i++){
                if(v[i][j] == mx) sum++;
            }
            sc[j] = sum;
        }
        ll fg=0;
        for(ll i=0;i<n;i++){
            for(ll j=0;j<m;j++){
                if(sr[i]+sc[j]== ct && v[i][j]!=mx) {fg=1;break;}
                else if(sr[i]+sc[j]==ct+1 && v[i][j]==mx) {fg=1; break;}
            }
        }
        //cout << sr[3]<< ' ' << sc[1] << '\n';
        if(fg) cout << mx-1 << '\n';
        else cout << mx << '\n';

    }
    
    

    return 0;
}