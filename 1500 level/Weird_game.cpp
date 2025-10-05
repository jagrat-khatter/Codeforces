#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
const ll lmin = LLONG_MIN;
const ll lmax = LLONG_MAX;
ll power(ll b,ll e){
    if(e==0) return 1;
    ll value = power(b , e/2);
    return value*value*((e%2==0) ? 1 : b);
}
ll gcd(ll a,ll b){
    if(b==0) return a;
    else return gcd(b , a%b);
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    ll t ; t=1;
    while(t--){
        ll n; cin >> n;
        string s1,s2 ; cin >> s1 >> s2;
        vector<ll> v1 , v2; ll ct=0;
        for(ll i=0;i<2*n;i++){
            if(s1[i]=='1' && s2[i]=='1') ct++;
            else {v1.push_back(s1[i] - 48);
            v2.push_back(s2[i] - 48);}
        }

        ll c1 = ((ct+2-1)/2) , c2 = ct - c1;

        sort(v1.begin() ,v1.end()); sort(v2.begin() , v2.end());
        // for(auto j : v1) cout << j << ' ';
        // cout << '\n';
        // for(auto j : v2) cout << j << ' ';
        // cout << '\n';
        ll lead;
        if(c1>c2) lead=2;
        else lead=1;

        //cout << c1 << ' '<< c2 << '\n';
        ll sz1 = ((v1.size() +2 -1) /2) , sz2 = v1.size()-sz1;
        //cout << sz1 <<' ' << sz2 << '\n';
        ll nz1=0 , nz2=0;
        if(lead==1){
            for(ll j=v1.size()-1;j>=v1.size()-sz1;j--){
                c1 += v1[j];
                if(!v1[j]) nz1++;
            }
            for(ll j=v2.size()-1;j>=v2.size()-sz2;j--){
                c2 += v2[j]; if(!v2[j]) nz2++;
            }
        }
        else {
            for(ll j=v1.size()-1;j>=v1.size()-sz2;j--){
                c1 += v1[j]; if(!v1[j]) nz1++;
            }
            for(ll j=v2.size()-1;j>=v2.size()-sz1;j--){
                c2 += v2[j]; if(!v2[j]) nz2++;
            }
        }
        nz1 /= 2; nz2 /= 2;
        //cout << c1 << ' ' << c2 << '\n';
        if(c1+nz1>c2+nz2) cout << "First\n";
        else if(c1+nz1<c2+nz2) cout << "Second\n";
        else cout << "Draw\n";  
    }




    return 0;
}