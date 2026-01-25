#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
const ll lmin = LLONG_MIN;
const ll lmax = LLONG_MAX;
const ll imin = INT_MIN;
const ll imax = INT_MAX;
ll power(ll b,ll e){
    if(e==0) return 1;
    ll value = power(b , e/2);
    return value*value*((e%2==0) ? 1 : b);
}
ll gcd(ll a,ll b){
    if(b==0) return a;
    else return gcd(b , a%b);
}
void debug(vector<ll>& v){
    cerr << "[ ";
    for(auto j : v) cerr << j << ' ';
    cerr << "]\n";
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    ll t; cin >> t;
    while(t--){
        ll n,k ; cin >> n >> k;
        string s; cin >> s;
        map<ll , set<char>> mp;

        for(ll i=1;i<=n;i++){
            if(s[i-1]=='1') mp[i%k].insert('1');
            else if(s[i-1]=='0') mp[i%k].insert('0');
        }
        bool ans = true;
        for(ll j=0;j<k;j++){
            //cout << j << ' ' << mp[j].size() << '\n' ;
            if(mp[j].size() == 2) ans=false;
        }
        if(!ans) {cout << "No" << '\n' ; continue;}
        
        for(ll i=1;i<=n;i++){
            if((mp[i%k].size())) {s[i-1]= *(mp[i%k].begin()); 
                //cout << i << ' '<<*(mp[i%k].begin()) << '\n';
            }
        }

        ll c0=0 , c1=0;
        for(ll i=0;i<=0+k-1;i++){
            if(s[i]=='0') c0++;
            else if(s[i]=='1') c1++;
            if(c0>(k/2) || c1>(k/2)) ans=false;
        }
        for(ll i=1;i<=n-k;i++){
            if(s[i-1]=='0') c0--;
            else c1--;

            if(s[i+k-1]=='0') c0++;
            else c1++;
            if(c0>(k/2) || c1>(k/2)) ans=false;
        }

        if(!ans) cout << "No\n";
        else cout << "Yes\n" ;
    }




    return 0;
}