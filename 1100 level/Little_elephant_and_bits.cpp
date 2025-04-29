#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll lmin = LLONG_MIN;
const ll lmax = LLONG_MAX;
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    ll t; t=1;
    while(t--)
    {
        string s; cin >> s;
        // now we need to find how many contigous blocks pf zeroes ar there in string s
        ll n = s.size();
        // if it has any zero or not 
        ll fg=0;
        for(ll i=0;i<n;i++)
        {
            if(s[i]=='0') fg=1;
        }
        vector<char> ans;
        //cout << fg << ' ';
        if(fg){
            
            ll ct=0;
            for(ll i=0;i<n;i++){
                
                //cout << s[i] << ' '<<ct ;
                if(s[i]!='0' || ct==1) {ans.push_back(s[i]);}
                else {ct=1;}// due this the first zero will be skipped
                
            }
        }
        else{
            
            for(ll i=0;i<n-1;i++){// this means only one is there in the binary
                ans.push_back(s[i]);
            }
        }

        for(auto i: ans) cout << i ;

        cout << '\n';

    }



    return 0;
}