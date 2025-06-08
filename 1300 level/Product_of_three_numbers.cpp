#include <bits/stdc++.h>
using namespace std;
using ll = long long ; 
const ll lmin = LLONG_MIN;
const ll lmax = LLONG_MAX; 
// sieve till 10^5
vector<ll> v(1e5+1);

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    v[0]=1;v[1]=1;
    for(ll i=2;i*i<=1e5;i++)
    {
        if(v[i]==0){
            for(ll j=i*i;j<=1e5;j+=i){
                v[j]=1;
            }
        }
    }

    ll t; cin >> t;
    while(t--)
    {
        ll n; cin >> n;
        ll cp=n;
        vector<pair<ll , ll>> v2;
        for(ll i=2;i<=1e5 && cp!=1;i++){ // finding all the prime divisors and their powers
            if(v[i]==0 && cp% i==0){
                v2.push_back({i , 0});
                while(cp%i==0){
                    cp = cp/i;
                    v2[v2.size()-1].second ++;
                }
            }
        }
        if(cp!=1) v2.push_back({cp , 1});
        if(v2.size()>=3) cout << "YES" << '\n' << v2[0].first << ' ' << v2[1].first << ' ' << n/(v2[1].first * v2[0].first) << '\n';
        else if(v2.size()==2 && v2[0].second>=2 && v2[1].second>=2) cout << "YES" << '\n' << v2[0].first << ' ' << v2[1].first << ' ' << n/(v2[1].first *  v2[0].first) << '\n';
        else if(v2.size()==2 && v2[0].second>=3 && v2[1].second>=1) cout << "YES" << '\n' << v2[0].first << ' ' << v2[1].first << ' ' << n/(v2[1].first *  v2[0].first) << '\n';
        else if(v2.size()==2 && v2[0].second>=1 && v2[1].second>=3) cout << "YES" << '\n' << v2[0].first << ' ' << v2[1].first << ' ' << n/(v2[1].first *  v2[0].first) << '\n';
        else if(v2.size()==1 && v2[0].second>=6) cout << "YES" << '\n' << v2[0].first << ' ' << v2[0].first* v2[0].first << ' ' << n/(v2[0].first *  v2[0].first * v2[0].first) << '\n';
        else cout << "NO" << '\n';
    }


    return 0;
}