#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
const ll lmin = LLONG_MIN;
const ll lmax = LLONG_MAX;
const ll imin = INT_MIN;
const ll imax = INT_MAX;
const ll MOD = 998244353;
ll power(ll b,ll e){
    if(e==0) return 1;
    ll value = power(b , e/2);
    return value*value*((e%2==0) ? 1 : b);
}
ll gcd(ll a,ll b){
    if(b==0) return a;
    else return gcd(b , a%b);
}
void debug(const vector<ll>&v){
    cerr << "[ ";
    for(auto j : v) cerr << j << ' ';
    cerr << "]\n" ; return ;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    ll t; cin >> t;
    while(t--){
        ll n; cin >> n;
        vector<ll> v;
        for(ll i=1;i<=n;i++) {
            ll x; cin >> x; v.push_back(x);
        }

        sort(v.begin() , v.end());
        map<ll,ll> mp;
        set<ll> s;
        ll id=-1;
        for(ll i=0;i<n;i++){
            if(i==n-1 && id!=-1){
                s.insert(i-id+1);
                mp[i-id+1]++;id=-1;
            }
            if(i==n-1) break;
            if(((v[i]+1) == (v[i+1])) && id==-1){
                id=i;
            }
            if(id!=-1 && (v[i]+1)!=v[i+1]){
                s.insert(i-id+1);
                mp[i-id+1]++;id=-1;
            }
            
        }

        //cout <<*(--s.end()) << ' '<<mp[*(--s.end())] << '\n';
        ll temp , rem;
        
        ll sz = (s.size() ? *(--s.end()) : 0);
        ll pw = 1;
        for(ll i=2;i<=sz;i++) {
            pw  = (pw*2)%MOD;
        }

        if(s.size()==0) {temp=1; rem=n;}
        else {temp = ((pw)%MOD * mp[*(--s.end())])%MOD; rem = (n - *(--s.end()));}
        //now remaining elements can be permutatted
        
        ll ans = temp;
        for(ll i=1;i<=rem;i++){
            ans = (ans * (i)%MOD)%MOD ;
        }

        cout << ans << '\n' ;
    }





    return 0;
}