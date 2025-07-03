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
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    vector<ll> pw; // 0 to power of 63
    ll ct=1;
    for(ll i=0;i<64;i++){
        pw.push_back(ct);
        ct *= 2;
    }

    ll t; cin >> t;
    while(t--)
    {
        ll n,k; cin >> n >> k;
        vector<ll> v(n);
        for(auto &i : v) cin >> i;

        set<ll> s; map<ll , ll> mp;
        ll ans=0;
        for(auto i : v){
            vector<ll> br;
            ll e=i;
            //cout << e << ' '<< ans <<  '\n';
            while(e){
                br.push_back(e%2);
                e = e/2;
            }
            //reverse(br.begin() , br.end()); no need to reverse it will help in iterating over bits
            
            for(ll j=0;j<64;j++){ // bits that are empty need to filled in s
                if(j<br.size()){
                    if(br[j]==1) ans++;
                    else{
                        s.insert(j);
                        mp[j]++;
                    }
                }
                else{
                    mp[j]++;
                    s.insert(j);
                }
            }
            //cout << ans << '\n';
            
        }
        //for(auto i : s) cout << i << ' '<< mp[i] << '\n';
        while(s.size() || k){
            ll smb = *(s.begin()); // smallest bit in set
            ll dnm = pw[smb] ; // denomination of that bit 
            if(k < dnm) break; // k can not even increase smallest bit
            else {
                k = k - dnm;
                ans++;
                mp[smb]--;
                if(mp[smb] == 0) s.erase(smb);
            }
        }

        cout << ans << '\n';
    }
    
    

    return 0;
}