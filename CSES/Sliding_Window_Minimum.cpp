#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll lmin = LLONG_MIN;
const ll lmax = LLONG_MAX;
const ll MOD = 1e9 + 7;
ll power(ll b,ll e){
    if(e==0) return 1;
    ll value = power(b,e/2);
    if(e%2==0) return value*value;
    else return value*value*b;
}
ll gcd(ll a,ll b){
    if(b==0) return a;
 
    else return (b , b%a);
}
void debug(const vector<ll>& v){
    cerr << "[ ";
    for(auto j : v) cerr << j << ' ';
    cerr<< "]\n"; return ;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
 
    ll n,k; cin >> n >> k;
    ll x,a,b,c; cin >> x >> a >> b >> c;
    vector<ll> v(n+1 ,0);
    v[1]=x;
    for(ll i=2;i<=n;i++){
        v[i] = (a*v[i-1] + b)%c;
    }
 
    
    deque<ll> dq={1};
    for(ll i=2;i<=k;i++){
        while(dq.size() && v[dq.back()]>=v[i]){
            dq.pop_back();
        }
        dq.push_back(i);
    }
    ll ans = v[dq[0]];
    //cout << dq[0] << '\n' ;
    for(ll i=k+1;i<=n;i++){
        while(dq.size() && dq[0]<i-k+1){
            dq.pop_front();
        }
        while(dq.size() && v[dq.back()]>=v[i]){
            dq.pop_back();
        }
        dq.push_back(i);

        //cout << dq[0] << '\n' ;
        ans ^= v[dq[0]];
    } 
    cout << ans << '\n' ;


    return 0;
}