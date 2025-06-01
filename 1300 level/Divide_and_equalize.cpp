#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll lmin = LLONG_MIN;
const ll lmax = LLONG_MAX;
// sieve or eratosthenes
vector<ll> sv(1e6+1); // here wwe'll use one based indexing
vector<ll> pr;

void build_sieve(){
        
        sv[0]=1;
        sv[1]=1;
        for(ll i=1;i*i<1e6+1;i++){
            if(sv[i]==0)
            {
                for(ll j=i*i;j<1e6+1;j+=i)
                {
                    sv[j]=1;
                }
            }
        }

        for(ll i=1;i<=1e6;i++)
        {
            if(sv[i]==0) pr.push_back(i);
        }
}
void execute(ll n , map<ll,ll> &mp , set<ll> &s)
{
    for(ll i = 2; i * i <= n; ++i){
        if(n % i == 0){
            s.insert(i);
            ll ct = 0;
            while(n % i == 0){
                ct++;
                n /= i;
            }
            mp[i] += ct;
        }
    }
    if(n > 1){
        s.insert(n);
        mp[n]++;
    }
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    build_sieve();

    ll t; cin >> t;
    while(t--)
    {
        map<ll , ll> mp;
        ll n ; cin >> n;
        vector<ll> v(n);
        set<ll> s;
        for(auto &i : v) {cin >> i;
            execute(i , mp , s);
        }
        ll fg=0;
        for(auto i : s){
            //if(mp[i]) cout << i << ' ' << mp[i] << '\n';
            if(mp[i] && mp[i]%n !=0)  fg=1;
        } 
        if(fg) cout << "NO" << '\n';
        else cout << "YES" << '\n';
    }
    


    return 0;
}