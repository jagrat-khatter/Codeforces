#include <bits/stdc++.h>
using namespace std;
using ll = long long ;
using ld = long double;
const ll lmin = LLONG_MIN;
const ll lmax = LLONG_MAX;
ll power(ll b,ll e){
    if(e==0) return 1;
    ll value = power(b , e/2);
    if(e%2==0) return value * value;
    else return value * value * b;
}
ll gcd(ll a,ll b){
    if(b==0) return a;
    else return gcd(b , a%b);
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    ll t; cin >> t;
    while(t--){
        string s; cin >> s; ll k ; cin >> k;
        set<char> st;
        map<char , ll> mp;
        string ans="";
        for(ll i=0;i<=k;i++){
            st.insert(s[i]); mp[s[i]]++;
        }
        // number of elemets present in end result = total elements - removed
        ll el = s.size() - k;
        ll l=0 , r=k;
        while(r<s.size()){
            
            if(l!=0) {st.insert(s[r]); mp[s[r]]++;}

            char mn = *(st.begin());
            if(l==0 && mn=='0') mn = *(++(st.begin()));

            //cout << l << ' ' << r << ' ' << mn << '\n';
            ans += mn;
            for(ll i=l;i<=r;i++){
                l=i;
                if(--mp[s[i]]==0) st.erase(s[i]);
                if(s[i] == mn) break;
            }
            l++;
            r++;
        }

        
        cout << ans << '\n';
    }



    return 0;
}