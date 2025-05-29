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
    while(t--){
        ll n; cin >> n;
        string a,b ; cin >> a >> b;
        vector<char>  v;
        for(ll i=0;i<n;i++){
            if(a[i]==b[i]) v.push_back('s'); // if both the elements are in same  
            else v.push_back('w'); 
        }
        ll fg=0;
        for(ll i=n-1;i>=0 && fg==0;i--){
            if(v[i]=='s') v.pop_back();
            else fg=1;
        }
        // for(auto i : v) cout << i ;
        // cout << '\n';
        if(v.size()==0) {cout << "YES" << '\n';continue;}
        ll c0=0,c1=0;
        char e  = v[0];
        ll ans=1;
        for(ll i=0;i<=v.size() && ans==1;i++){
            
            if(e!=v[i] || i==v.size()){ // notice v.size() and n are not same after pop back

                if(c0!=c1) {ans=0; break;}
                else{
                    c1=0;c0=0;
                    e=v[i];
                }
            }
                if(i!=v.size()){if(a[i]=='0') c0++;
                else c1++;}
        }
        if(ans) cout << "YES" << '\n';
        else cout << "NO" << '\n';
    }




    return 0;
}