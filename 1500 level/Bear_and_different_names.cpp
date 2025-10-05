#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
const ll lmin = LLONG_MIN;
const ll lmax = LLONG_MAX;
ll power(ll b,ll e){
    if(e==0) return 1;
    ll value = power(b,e/2);
    return value*value*((e%2==0) ? 1: b);
}
ll gcd(ll a,ll b){
    if(b==0) return a;
    else return gcd(b , a%b);
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    // first of all making 50 different names
    vector<string> str;
    for(ll i=1;i<=26;i++){
        string a = "Adam" ; a+= (char)(i+96);
        string b = "Bob"  ; b+= (char)(i+96);
        str.push_back(a); str.push_back(b);
    }

    ll n,k;cin >> n >> k;
    vector<string> v(n , "_");
    
    vector<string> rs;
    for(ll i=0;i<n-k+1;i++){
        string s; cin >> s;
        if(s[0]=='N') {rs.push_back("NO");}
        else {rs.push_back("YES");}
    }

    // for(auto i : rs) cout <<i << ' ';
    // cout << '\n';
    
    
    for(ll i=0;i<n-k+1;i++){
        ll fg;
        if(rs[i]=="YES") fg=1;
        else fg=0;

        // cout << fg << '\n';

        if(fg){// for YES
            if(v[i]!="_"){
                v[i+k-1]=str[str.size()-1]; str.pop_back();
            }
            else {// both v[i] and v[i+k-1] are "_"
                v[i]=str[str.size()-1]; str.pop_back();
                v[i+k-1]=str[str.size()-1]; str.pop_back();
            }
        }
        else{// for NO
            if(v[i]!="_"){
                v[i+k-1]=v[i];
            }
            else {
                v[i] = str[str.size()-1];
                v[i+k-1] = v[i]; str.pop_back();
            }
        }
    }

    for(auto j : v) {
        if(j=="_") {cout << str[str.size()-1] << ' ';str.pop_back();}
        else cout << j << ' ';
    }



    return 0;
}