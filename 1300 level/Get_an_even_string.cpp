#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
const ll MOD = 1e9+ 7;
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
    else return (b ,a%b);
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    ll t; cin >> t;
    while(t--){
        string s; cin >> s;ll n = s.size();
        set<char> st;
        ll ans =0 ;
        for(ll i=0;i<n;i++){
            // cout << i << '\n';
            // for(auto j : st) cout << j <<  ' ';
            // cout << '\n';
            if(i!=n-1 && s[i]==s[i+1] && st.size()==0) i++;
            else {
                if(st.find(s[i]) != st.end()) {
                    ans += st.size()-1;
                    st.clear();
                }
                else st.insert(s[i]);
            }

            if(i==n-1 && st.size()!=0) ans+= st.size();
        }

        cout << ans << '\n';
    }




    return 0;
}