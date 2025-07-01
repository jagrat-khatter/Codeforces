#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll lmin = LLONG_MIN;
const ll lmax = LLONG_MAX;
vector<ll> pw2(31);
ll power(ll b , ll e){
    if(b==2 )return pw2[e];
    else return 0;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    vector<ll> v(32 , 0);
    ll ct=1;
    for(ll i=0;i<31;i++){
        pw2[i]=ct;
        ct *= 2;
    }
    ll t; cin >> t;
    while(t--){
        ll a,b; cin >> a >> b;
        
        if(a==1){
            v[b]++;
        }
        else{
            vector<ll> br; // binary represntation of that number
            ll cp = b;
            while(cp){
                br.push_back(cp%2);
                cp = cp / 2;
            }
            reverse(br.begin() , br.end()) ;
            vector<ll> vcp ; // copy of vector v
            for(auto i : v){
                vcp.push_back(i);
            }
            //********* */
            // for(auto i : vcp){
            //     cout << i << ' ';
            // }
            // cout << '\n';
            // *********
            ll fg=0;
            for(ll i=0;i<br.size() && fg!=1;i++){
                if(br[i]==1){
                    ll pw = br.size()-i-1;
                    ll num = power(2 , pw);
                    ll j = pw;
                    while(num && j>=0){
                        ll curVal = power(2 , j);
                        if(vcp[j]>0 && num-curVal>=0){
                            ll maxCoins = num / curVal;
                            ll coinsUsed = min(vcp[j] , maxCoins);
                            vcp[j] -= coinsUsed;

                            num = num - coinsUsed * curVal;
                        }
                        j--;
                    }
                    if(num!=0) {fg=1;} // if any of the bits cannot be made then ans is NO
                }
            }
            if(!fg) cout << "YES" << '\n';
            else cout << "NO" << '\n';
        }
    }



    return 0;
}