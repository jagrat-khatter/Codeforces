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

    ll n,k ; cin >> n >> k;
    ll x,a,b,c; cin >> x >> a >> b >> c;
    vector<ll> v(n+1 ,0);
    v[1]=x;
    for(ll i=2;i<=n;i++) {
        v[i] = (a*v[i-1] + b)%c;
        //cout << v[i] << ' ' ;
    }
    vector<pair<ll,ll>> st1 , st2;
    ll orr=0;
    for(ll i=1;i<k;i++){
        orr = orr | v[i];
        st1.push_back({v[i] , orr});
    } 
    ll ans=0;

    for(ll i=k;i<=n;i++){
        ll prevOr = (st1.size() ? st1.back().second : 0);
        st1.push_back({v[i] , v[i] | prevOr});

        if(st1.size()==k){
            orr =0;
            while(st1.size()){
                orr = (orr | st1.back().first);
                st2.push_back({st1.back().first , orr});
                st1.pop_back();
            }
        }
        // if(st1.size()) cout << i << " st1 " << st1.front().second << '\n' ;
        // if(st2.size()) cout << i << " st2 " << st1.front().second << '\n' ;

        if(st1.size()) {ans ^= (st1.back().second | st2.back().second);
        //cout << (st1.back().second | st2.back().second) << '\n';
        }
        else {ans ^= (st2.back().second);
        //cout << (st2.back().second)<< '\n' ;
        }

        st2.pop_back();
    }


    cout << ans << '\n' ;



    return 0;
}