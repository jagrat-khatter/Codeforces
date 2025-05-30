#include <bits/stdc++.h>
using namespace std;
using ll = long long ;
const ll lmin = LLONG_MIN;
const ll lmax = LLONG_MAX;
ll max(ll a,ll b){
    if(a>b) return a;
    else return b;
}
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    ll t; cin >> t;
    while(t--){
        ll n ; cin >> n;
        ll e ,id1 , id2=-1; // e is element which will be connected to every other city except 
        // the cities which have value e 
        // id1 = address of city  e;
        // id2 = address of any city other than t
        vector<ll> v;
        for(ll i=0;i<n;i++){
            ll x; cin >> x;
            v.push_back(x);
            if(i==0) {e = x;
            id1 = i;}
            if(x != e && id2==-1){
                id2=i;
            }
        }
        if(id2== -1) {cout << "NO" << '\n' ; continue;}
        cout << "YES" << '\n';
        ll fg=0;
        for(ll i=0;i<n;i++){
            if(v[i]==e){
                if(fg) cout << i+1 << ' ' << id2+1 << '\n'; // the first e which has all the connections does not make any new connection
                fg=1;
             }
             else{
                cout << i+1 << ' ' << id1+1 << '\n';
             }
        }
        
    }


    return 0;
}