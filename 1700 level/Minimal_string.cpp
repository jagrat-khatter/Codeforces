#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
const ll MOD = 1e9 + 7;
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

    ll t; t=1;
    while(t--){
        string s; cin >> s;
        stack<char> sc;
        map<char , ll> mp; set<char> st;
        for(auto i : s){
            mp[i] ++; st.insert(i);
        }
        string ans = "";
        for(auto i : s){
            mp[i]--;
            if(! mp[i]) st.erase(i);
            sc.push(i);
            char tp = sc.top();
            char mn = *(st.begin());
            while(tp<=mn) { // more than one elements can be removed if elements that 
                // are ahead are greater than those in stack 
                sc.pop(); ans += tp;
                if(!sc.size()) break;
                tp = sc.top();
            }
        }
        while(sc.size()){
            ans += sc.top(); sc.pop();
        }

        cout << ans << '\n' ;
    }




    return 0;
}