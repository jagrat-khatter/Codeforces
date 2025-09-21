#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
const ll MOD = 1e9 + 7;
const ll MOD2 = 1e9 + 9;
const ll MOD3 = 1e9 + 21;
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
    else return gcd(b , a%b);
}
ll mod(ll n){
    if(n>=0) return n;
    else return -n;
}
struct TripleHash {
    size_t operator()(const pair<pair<ll, ll>, ll>& p) const {
        // Get the individual hash values of each long long.
        size_t h1 = std::hash<ll>{}(p.first.first);
        size_t h2 = std::hash<ll>{}(p.first.second);
        size_t h3 = std::hash<ll>{}(p.second);
        // Combine the hashes using a common hash-combining approach.
        size_t res = h1;
        res ^= h2 + 0x9e3779b97f4a7c15ULL + (res << 6) + (res >> 2);
        res ^= h3 + 0x9e3779b97f4a7c15ULL + (res << 6) + (res >> 2);
        return res;
    }
};
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    string s; cin >> s;ll n = s.size();
    map<char , ll> mp;
    string gd; cin >> gd;
    for(ll i=0;i<26;i++){
        ll x = gd[i] - 48;
        char c = (char)(i + 97);
        mp[c]=x; // if mp[c] is 1 that is good character if 0 it is bad character 
    }
    unordered_set<pair<pair<ll,ll>,ll> , Tripleus
    Hash> st;
    ll k ; cin >> k;

    for(ll i=0;i<n;i++){
        ll ct=0;
        ll h1=0 ,h2=0 , h3=0;
        for(ll j=i;j<n;j++){
            if(mp[s[j]]==0) ct++;
            if(ct>k) break;
            
            h1= ((h1*31)%MOD  +  (s[j]-'a'+1)%MOD) %MOD;
            h2= ((h2*37)%MOD2  + (s[j]-'a'+1)%MOD2) % MOD2;
            h3= ((h3*41)%MOD3  + (s[j]-'a'+1)%MOD3) % MOD3;
            st.insert({{h1,h2},h3}); // inserting pairs of hashes just to make sure every unique string is calculated even though there is collision

        }
    }

    cout << st.size();


    return 0;
}