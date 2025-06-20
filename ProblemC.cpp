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
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    ll t; cin>> t;
    while(t--)
    {
        ll n,k ; cin >>  n >> k;
        vector<ll> a(n),b;
        ll fg1=0;
        ll id=0;
        for(auto &i : a) cin >> i;
        for(ll i=0;i<n;i++) {ll x;cin >> x;b.push_back(x); 
            if(x!= -1) {fg1=1;id=i;}}

        if(fg1==0) { // all the elements in b are -1
            ll mx=lmin , mn=lmax;
            for(auto i: a){
                mx = max(mx , i);
                mn = min(mn , i);
            }
            if(k >= (mx-mn)) cout << k - (mx - mn) +1 << '\n';
            else cout << 0 << '\n';
        }
        else {// id=i will save the last indx where element of vector b was not -1
            //cout << id << '\n';
            ll tgt = a[id] + b[id];
            // two condition 
            // if now any of element of b is -1 it shoudld search-a<=k
            // if both a and b are not -1 they should be a + b == search
            //cout << tgt << '\n';
            ll fg2=0;
            for(ll i=0;i<n;i++){
                if(b[i]==-1){
                    if(tgt - a[i] > k || tgt-a[i]<0) {fg2=1; break;}
                }
                else{
                    if(a[i] + b[i] != tgt) {fg2=1; break;}
                }
            }
            if(fg2) cout << 0 << '\n';
            else cout << 1 << '\n';

        }
    }

    return 0;
}