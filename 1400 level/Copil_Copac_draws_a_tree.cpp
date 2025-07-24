#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll lmin = LLONG_MIN;
const ll lmax = LLONG_MAX;
ll power(ll b,ll e){
    if(e==0) return 1;
    ll value = power(b , e/2);
    if(e%2==0) return value*value;
    else return value*value*b;
}
ll gcd(ll a,ll b){
    
    if(b==0) return a;

    return gcd(b , a%b);
}
ll max(ll a,ll b){
    if(a>b) return a;
    else return b;
}
ll min(ll a,ll b){
    if(a>b) return b;
    else return a;
}
ll mod(ll n){
    if(n>=0) return n;
    else return -n;
}
void dfs(ll e , set<ll>& s, map<ll , set<ll>>& mp,map<pair<ll,ll> , ll>& rank,ll prv,ll trv,ll& ans){
    ans = max(ans , trv) ;
    //cout << e << '\n' ;
    for(auto i : mp[e]){
        if(s.find(i)==s.end()){
            
            s.insert(i);
            if(rank[{e,i}]>prv){
                //cout << e << ' ' << i <<'b' <<  '\n';
                dfs(i , s, mp , rank,rank[{e,i}],trv , ans);
            }
            else {
                //cout << e << ' ' << i << 'd' << '\n';
                dfs(i , s , mp , rank,rank[{e,i}],trv+1 , ans);
            }
        }
    }

    return ;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    ll t; cin >> t;
    while(t--){
        ll n; cin >> n;
        map<ll , set<ll>> mp;
        map<pair<ll,ll> , ll> rank;
        for(ll i=0;i<n-1;i++){
            ll a,b; cin >> a >> b;
            mp[a].insert(b);
            mp[b].insert(a);
            rank[{a,b}] = i+1;
            rank[{b,a}] = i+1;
        }
        // for(ll i=1;i<=n;i++){
        //     for(auto j : mp[i]) cout << j << ' ' ;
        //     cout << '\n';
        // }
        set<ll> s;
        s.insert(1);
        ll ans=0;
        dfs(1 , s , mp,rank, 0 , 1 , ans);
        cout << ans << '\n' ;
    }



    return 0;
}