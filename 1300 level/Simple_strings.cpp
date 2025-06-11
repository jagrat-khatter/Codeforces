#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll lmin = LLONG_MIN;
const ll lmax = LLONG_MAX;
char diff(ll id, string & s){
    
    set<ll> st={'a','b','c','d','e','f','g','h'};
    if(id==0 || id==s.size()-1){
       if(id==0) {
            for(auto i : st){
                if(i!= s[id+1])  return i;
            }
        }
        else{
            for(auto i : st){
                if(i!= s[id-1])  return i;
            }
        }
    }
    else{
        // cout << "control" << '\n';
        // cout  << s[i-1]
        for(auto i : st){
                if(i!= s[id-1] && i!= s[id+1]) return i;
            }
    }

    return 'z';
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    string s; cin >> s;
    ll n = s.size();
    for(ll i=0;i<n;i++){
        ll l , r;
        if(i!=n-1 && s[i]==s[i+1]){
            l = i;
            while(s[l] == s[i] && l<n){
                r = l;
                l++;
            }
            l = i;
            // now we have l and r 
            //cout << l <<  ' ' << r  << '\n';
            if((r-l+1) % 2 == 0){
                //cout << "even" << '\n';
                for(ll j=l;j<r;j+=2){
                    s[j] = diff(j , s);
                }
            }
            else{
                //cout << "odd" << '\n';
                for(ll j=l+1;j<r;j+=2){
                    // cout << j << '\n';
                    // cout << diff(j , s) << '\n';
                    s[j] = diff(j , s);
                }
            }

            i = r;
        }
        
    }
    cout << s  << '\n';
    


    return 0;
}