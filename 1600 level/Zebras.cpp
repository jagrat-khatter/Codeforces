#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
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
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    string s; cin>> s;
    vector<vector<pair<ll,ll>>> v; bool ans=true;
    ll ct=1;
    set<ll> z , az;
    for(auto i : s){
        // if element is 1 then find a subsequnce where last element is 0
       
        if(i=='1'){
            bool fg= false;
            if(z.size()!=0){
                ll id = *(z.begin());
                v[id].push_back({1,ct}); fg=true;
                z.erase(id); az.insert(id);
            }

            if(fg==false) {ans=false; break;}
        }
        else {
            bool fg=false;
            
            if(az.size()!=0){
                ll id = *(az.begin());
                v[id].push_back({0,ct}); fg=true; 
                az.erase(id); z.insert(id);
            }
            if(fg==false) {
                vector<pair<ll,ll>> nv={{0,ct}}; v.push_back(nv);
                z.insert(v.size()-1);
            }
        }
        //cout << i <<' ' << v.size() <<'\n';
        // cout << i << "----" << '\n' ;
        // for(auto j : z) cout << j << ' ';
        // cout << '\n';
        // for(auto j : az) cout << j << ' ';
        // cout << '\n';
        ct++;
    }
    //also there should not be any subsequence which has last element as 1

    for(auto i : v){
        if(i[i.size()-1].first == 1) {ans=false; break;}
        // for(auto j : i) cout << j.first << ' ';
        // cout << '\n' ;
    }

    if(!ans)  cout << -1 << '\n';
    else {
        cout << v.size() << '\n';
        for(auto i : v) {
            cout << i.size() << ' ';
            for(auto j : i) cout << j.second << ' ';
            cout << '\n' ;
        }
    }

    return 0;
}