#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll lmin = LLONG_MIN;
const ll lmax = LLONG_MAX;
const power(ll b,ll e){
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
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    ll t; cin >> t;
    while(t--){
        ll n; cin >> n;
        ll fg=0 , fg2=0;
        vector<ll> v(n);
        for(auto &i : v) {
            cin >> i;
            if(i%10==5 || i%10==0) fg=1;
            else fg2=1;
        }

        if(fg){
            if(fg2) {cout << "NO" << '\n' ; continue;}

            for(ll i=0;i<n;i++){
                ll e = v[i];
                if(e%10==5) v[i] = e+5;
            }
            ll ans=1;
            for(ll i=1;i<n;i++){
                if(v[i] != v[i-1]) {ans=0;break;}
            }
            if(ans==0) cout << "NO" << '\n';
            else cout << "YES" << '\n' ;

        }
        else{
            sort(v.begin() , v.end()) ;
            vector<ll> line;
            for(ll i=0;i<n;i++){
                ll e=v[i];
                while(1){
                    if(e%10==2 || e%10==4 || e%10==8 || e%10==6) break;
                    e += e%10;
                }
                if(e%10==2 || e%10==4 || e%10==8){
                    e=e/10;
                    if(e%2==0) line.push_back(1);
                    else line.push_back(2);
                }
                else{
                    e=e/10;
                    if(e%2==0) line.push_back(2);
                    else line.push_back(1);
                }
            }
            ll ans=1;
            for(ll i=1;i<n;i++){
                if(line[i] != line[i-1]) {ans=0;break;}
            }
            if(ans==0) cout << "NO" << '\n';
            else cout << "YES" << '\n' ;
        }
    }




    return 0;
}