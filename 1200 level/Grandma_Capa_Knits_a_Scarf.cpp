#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll lmin = LLONG_MIN;
const ll lmax = LLONG_MAX;
bool palindrome(string s){
    ll l=0,r=s.size()-1 , fg=0;
    while(l<=r){
        if(s[l] == s[r]){
            l++; r--;
        }else {fg=1; break;}
    }
    if(!fg) return true;
    else return false;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    ll t; cin >> t;
    while(t--){
        ll n; cin >> n;
        string s; cin >> s;
        map<char , ll> mp;
        for(ll i=0;i<s.size();i++){
            if(mp[s[i]] ==0) mp[s[i]] = 1;
        }
        vector<ll> ans;
        if(palindrome(s)) cout << 0 << '\n';
        else{

            // she can choose only one letter and remove its multiple occurences
            ll final=0;
            for(ll i=1;i<=26;i++){
                char e = (char)(96+i);
                // only for elemen which are present in the string can be removed
                
                if(mp[e]==1){
                    ll ct=0 , fg=0;
                    ll l=0,r=s.size()-1;
                    //cout << e << '\n';
                    while(l<=r && fg==0){
                        if(s[l]==s[r]){
                            l++;
                            r--;
                        }
                        else if(s[l]==e){
                            l++;
                            ct++;
                        }
                        else if(s[r]==e){
                            r--;
                            ct++;
                        }
                        else{
                            fg=1;
                        }
                    }
                    //cout << fg << '\n';
                    if(fg==0){
                    ans.push_back(ct);
                    }
                     
                }
                
            }
            
            if(ans.size()==0) cout << -1 << '\n';
            else {
                sort(ans.begin() , ans.end());
                cout << ans[0] << '\n' ;
            }
        }
    }




    return 0;
}