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
    while(t--)
    {
        ll n; cin >> n;
        string s; cin >> s;
        map<string , ll> mp;
        for(ll i=0;i<n;i++){
            string ch(1 , s[i]);
            if(mp[ch] ==0) mp[ch]=1;
        }
        for(ll i=0;i<n-1;i++){
            string x;
            x.push_back(s[i]);
            x.push_back(s[i+1]);
            if(mp[x]==0) mp[x]=1;
        }
        for(ll i=0;i<n-2;i++){
            string x;
            x.push_back(s[i]);
            x.push_back(s[i+1]);
            x.push_back(s[i+2]);
            if(mp[x]==0)  mp[x]=1;
        }
        ll fg=0;
        for(ll i=1;i<=26;i++){
            string ch(1 , char(96+i));
            //cout << ch << '\n';
            if(mp[ch] == 0){
                 cout << ch << '\n';
                fg=1;
                break;
            }
        }
        for(ll i=1;i<=26 && fg==0;i++){
            for(ll j=1;j<=26 && fg==0;j++){
                string x;
                x.push_back(char(i+96));
                x.push_back(char(j+96));
                if(mp[x]==0){ cout << x << '\n';fg=1;}
                
            }
        }
        for(ll i=1;i<=26 && fg==0 ;i++){
            for(ll j=1;j<=26 && fg==0 ;j++){
                for(ll k=1;k<=26 && fg==0;k++){
                    string x;
                    x.push_back(char(i+96));
                    x.push_back(char(j+96));\
                    x.push_back(char(k+96));
                    if(mp[x] == 0) {
                        cout << x << '\n';
                        fg=1; 
                    }
                }
            }
        }
    }




    return 0;
}