#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
ll power(ll b,ll e){
    if(e==0) return 1;
    ll value = power(b , e/2);
    if(e%2==0) return value * value;
    else return value*value*b;
}
ll gcd(ll a,ll b){
    if(b==0) return a;

    return gcd(b , a%b);
}
ll mod(ll n){
    if(n>=0) return n;
    else return -n;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    ll a,x,y; cin >> a >> x >> y;
    if(x>a || x<-a || y%a==0) {cout << -1 << '\n';}
    else {
        ll rw = (y+a-1)/a ;
        if(rw==1 || rw%2==0){
            if(a%2!=0 && x>=((-a/2)) && x<=((a/2))){
                if(rw==1 || rw==2) cout << (ll)rw << '\n';
                else cout << (ll)((rw-4)/2 + rw-4  + 5)<< '\n';
            }
            else if(a%2==0 && x>((-a/2)) && x<((a/2))){
                if(rw==1 || rw==2) cout << (ll)rw << '\n';
                else cout << (ll)((rw-4)/2 + rw-4  + 5)<< '\n';
            }
            else cout << -1 << '\n';
        }
        else {
            if(x==0 || x==-a || x==a) cout << -1 << '\n';
            else {
                ll fb = (rw-3)/2 * 3 + 3 ;
                if(x<0) cout << fb << '\n';
                else cout << fb+1 << '\n' ;
            }
        }
    }



    return 0;
}