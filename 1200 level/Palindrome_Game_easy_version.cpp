#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll lmin = LLONG_MIN;
const ll lmax = LLONG_MAX;
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    ll t; cin >> t;
    while(t--){
        ll n ; cin >> n;
        string s; cin >> s;
        
        ll ct=0; // counting number of zeroes
        for(auto i : s){
            if(i=='0') ct++;
        }
        if(n%2!=0 && ct%2!=0 && n!=1 && ct!=1){
            cout << "ALICE" << '\n';
        }
        else{
            cout << "BOB" << '\n';
        }
    }




    return 0;
}