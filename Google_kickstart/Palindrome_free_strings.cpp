#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
const ll lmin = LLONG_MIN;
const ll lmax = LLONG_MAX;
const ll imin = INT_MIN;
const ll imax = INT_MAX;
ll power(ll b,ll e){
    if(e==0) return 1;
    ll value = power(b , e/2);
    return value*value*((e%2==0) ? 1 : b);
}
ll gcd(ll a,ll b){
    if(b==0) return a;
    else return gcd(b , a%b);
}
bool isPalindrome(string& s){ // return true if palindrome , false if not palindrome
    bool ans=true;
    for(ll i=0;i<(s.size()+2-1)/2;i++){
        if(s[i]!=s[s.size()-1-i]) {ans=false;break;}
    }

    return ans;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    ll t; cin >> t;
    while(t--){
        ll n , ans=0; cin >> n;
        string s; cin >> s;
        vector<map<string , ll>> dp(n+1);

        if(n<=4) {cout << "POSSIBLE" << '\n'; continue;}
        
        for(ll id=4;id<=n-1;id++){
            vector<string> str;
            for(ll i=id-4;i<=id;i++){
                if(s[i]=='?' && str.size()==0) {str.push_back("1"); str.push_back("0");}
                else if(s[i]=='0' && str.size()==0) {str.push_back("0");}
                else if(s[i]=='1' && str.size()==0) {str.push_back("1");}
                else if(str.size()!=0){
                    if(s[i]=='1') for(auto &j : str) j += '1';
                    else if(s[i]=='0') for(auto &j : str) j += '0';
                    else if(s[i]=='?') {
                        vector<string> strtemp;
                        for(auto &j : str){
                            strtemp.push_back(j);
                            j += '0';
                        }
                        for(auto &j : strtemp){
                            str.push_back(j+'1');
                        }
                    }
                }
            }
            // for(auto j : str) cout << j << ' ';
            // cout << '\n' ;

            if(id==4){
                for(auto j : str){
                    if(isPalindrome(j)==false) dp[id][j]=1;
                    else dp[id][j]=0;
                }
            }
            else {
                vector<string> strtemp;
                if(s[id-5]=='?'){
                    for(auto j : str) strtemp.push_back('1'+ j);
                    for(auto j : str) strtemp.push_back('0'+ j);
                }
                else if(s[id-5]=='1'){
                    for(auto j : str) strtemp.push_back('1'+ j);
                }
                else {
                    for(auto j : str) strtemp.push_back('0'+ j);
                }
                for(auto j : strtemp) {
                    string s1="" , s2="";
                    for(ll k=0;k<j.size()-1;k++){
                        s1 += j[k];
                    }
                    for(ll k=1;k<j.size();k++){
                        s2 += j[k];
                    }
                    if(isPalindrome(j)==false && dp[id-1][s1] && isPalindrome(s2)==false) dp[id][s2]=1;
                    // else dp[id][s2]=0;
                    // we dont do this because it may happen then for one j and same s2
                    // things work but for different j and same s2 things dont work 

                    //cout << j << ' '  << s1 << ' ' << s2 <<' ' << dp[id][s2] << '\n' ;
                }
            }

            if(id==n-1){
                for(auto j : str){
                    //cout << j << ' ' << dp[id][j] << '\n' ;
                    if(dp[id][j]==1) ans=1;
                }
            }
        }

        if(ans) cout << "POSSIBLE" ;
        else cout << "IMPOSSIBLE" ;
        cout << '\n' ;
    }



    return 0;
}