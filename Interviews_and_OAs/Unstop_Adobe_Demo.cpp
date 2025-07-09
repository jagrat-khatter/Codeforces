// remove the special characters and a character to the right of special chracters given a list 
// of strings 
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll lmin = LLONG_MIN;
const ll lmax = LLONG_MAX;
ll max(ll a, ll b){
    if(a>b) return a;
    else return b;
}
ll min(ll a,ll b)
{
    if(a>b) return b;
    else return a;
}
ll power(ll b,ll e){
    if(e==0) return 1;

    ll value = power(b , e/2);
    if(e%2==0) return value * value;
    else return value * value * b;
}
ll mod(ll n){
    if(n>=0) return n;
    else return -n;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    //thw$ g##bjhdwd vdg*gh$vvdd#bdudhc

    int ct=0;
    vector<string> v;
    string str;
    while(cin >> str){
        v.push_back(str);
    }
    

    vector<string> ans;
    set<char> st={'*' , '#' , '$'};

    for(auto i : v){
        ans.push_back("");// initializing a new string 
        ll sz = ans.size();
        for(auto j : i){

        char e = j;
        int num = (int)(e);
        if(st.find(e) != st.end()){
            ct++;
        }
        else if(num>=97 && num<=122){
            if(ct==0){
                ans[sz-1].push_back(e);
            }
            else ct--;
        }
        else ans[sz-1].push_back(e);
        }
    }

    for(auto j : ans){
        cout << j << ' ' ;
    }
    

    return 0;
}