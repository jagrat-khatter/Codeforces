#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
const ll lmin = LLONG_MIN;
const ll lmax = LLONG_MAX;
ll func1(set<pair<ll,ll>> s1,set<pair<ll,ll>> s0 , ll x,map<pair<ll,ll>,ll> m1 , map<pair<ll,ll>,ll> m0){
    
    

    ll prv=0 , ct=0;
    while(s1.size() || s0.size()){
        // i'll find best pair in the whole set of s1 or s0 depending on whoseever turn 
        ll ict = ct;
        if((prv==1) && s0.size()){
            pair<ll,ll> mx={lmin , lmin};
            
            for(auto i : s0){
                if(i.first<=x && i.second>mx.second){
                    mx = i;
                }
            }
            
            if(mx.first!=lmin && mx.second!=lmin) {x+=mx.second; 
                prv=0;
                ct++; m0[mx]--; 
                if(!m0[mx]) s0.erase(mx);
            }
        }
        else if((prv==0) && s1.size()){
            pair<ll,ll> mx={lmin , lmin};

            for(auto i : s1){
                if(i.first<=x && i.second>mx.second){
                    mx = i;
                }
            }
            if(mx.first!=lmin && mx.second!=lmin) {x+=mx.second; 
                prv=1;
                ct++; m1[mx]--; 
                if(!m1[mx]) s1.erase(mx);
            }
        }
        if(ct-ict==0) break;
    }

    return ct;
}
ll func2(set<pair<ll,ll>> s1,set<pair<ll,ll>> s0 , ll x , map<pair<ll,ll>,ll> m1 , map<pair<ll,ll>,ll> m0){
    
    

    ll prv=1 , ct=0;
    while(s1.size() || s0.size()){
        // i'll find best pair in the whole set of s1 or s0 depending on whoseever turn 
        ll ict = ct;
        if((prv==1) && s0.size()){
            pair<ll,ll> mx={lmin , lmin};
            
            for(auto i : s0){
                if(i.first<=x && i.second>mx.second){
                    mx = i;
                }
            }
            //cout << '0' << ' ' << mx.first << ' ' << mx.second << '\n'; 
            if(mx.first!=lmin && mx.second!=lmin) {x+=mx.second; 
                prv=0;
                ct++; m0[mx]--; 
                if(!m0[mx]) s0.erase(mx);
            }
        }
        else if((prv==0) && s1.size()){
            pair<ll,ll> mx={lmin , lmin};

            for(auto i : s1){
                if(i.first<=x && i.second>mx.second){
                    mx = i;
                }
            }
            //cout << '1' << ' ' << mx.first << ' ' << mx.second << '\n'; 
            if(mx.first!=lmin && mx.second!=lmin) {x+=mx.second; 
                prv=1;
                ct++; m1[mx]--; 
                if(!m1[mx]) s1.erase(mx);
            }
        }
        if(ct-ict==0) break;
    }

    return ct;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    ll t; t=1;
    while(t--){
        ll n , x; cin >> n >> x;
        set<pair<ll,ll>> s1 ,s0; // this will store the candy belonging to type 1 and 0
        map<pair<ll,ll>,ll> m1,m0;
        for(ll i=0;i<n;i++){
            ll a,b,c; cin >> a >> b >> c;
            if(a==1) {s1.insert({b,c});m1[{b,c}]++;}
            else {s0.insert({b,c});m0[{b,c}]++;}
        }
        
        
        cout << max(func2(s1, s0, x ,m1,m0) , func1(s1,s0,x,m1,m0));
        
    }




    return 0;
}