#include <bits/stdc++.h>
using namespace std;
using ll  = long long;
const ll lmin = LLONG_MIN;
const ll lmax = LLONG_MAX;
ll power(ll b, ll e){
    if(e==0) return 1;
    ll value = power(b,e/2);
    if(e%2==0) return value*value;
    else return value*value*b;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    ll t; cin >> t;
    while(t--){
        ll n,a,b; cin >> n >> a >> b;
        // first we need to calculate on going from 0 to n-1 indexed bit the number of bits 
        // where bitofA != bitofB
        ll diff =0;
        for(ll i=0;i<n;i++){
            if((a & (1<<(i))) != (b & (1<<(i)))) diff++;
        }

        cout << diff << '\n';
        ll x=0;
        ll mul=1;
        for(ll i=0;i<n;i++){
            if((a & (1<<(i))) == (b & (1<<(i)))){
                if((a & (1<<(i)))) x += 0;// if bit is 1 bit should remain 1
                else x+=mul;// if bit is 0 bit should be converted to 1
            }else{
                if(diff==1){ // only bit of a should be set
                    if((a & (1<<(i)))) x+=0;
                    else x+=mul;
                }else{// only bit of b should be set
                    if((b & (1<<(i)))) x+=0;
                    else x+=mul;
                    diff--;
                }
            }
            mul *= 2;
        }
        cout << x << '\n';
             
    }


    return 0;
}