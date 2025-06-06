#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll lmin = LLONG_MIN;
const ll lmax = LLONG_MAX;
ll mod(ll a){
    if(a>=0) return a;
    else return -a;
}
bool parity(ll p , ll q){
    if(p%2==0){
        if(q%2==0) return true;
        else return false;
    }
    else{
        if(q%2!=0) return true;
        else return false;
    }
}
bool check(ll a,ll b , ll n){
    // check is (a,b) is reachable by 0,0 
    a = mod(a-0);
    b = mod(b-0);
    if(n%2==0){
        ll e1= n/2 , e2= n/2;
        if(a<=e1 && parity(a,e1) && b<=e2 && parity(b,e2)) return true;

        return false;
    }
    else{
        ll c1= (n/2)+1 , c2= n/2;
        if(a<=c1 && parity(a,c1) && b<=c2 && parity(b,c2)) return true;

        c1 = n/2 ; c2= (n/2)+1;
        if(a<=c1 && parity(a,c1) && b<=c2 && parity(b,c2)) return true;

        return false;
    }
}
signed main()
{
    ll n ; cin >> n;
    ll ct=0;


    for(ll i=-n;i<=n;i++){
        for(ll j=-n;j<=n;j++){
            if(check(i , j , n)){
                ct++;
            }
        }
    }
    cout << ct ;


    return 0;
}