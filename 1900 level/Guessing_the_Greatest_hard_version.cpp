#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
const ll lmin = LLONG_MIN;
const ll lmax = LLONG_MAX;
const ll MOD = 1e9 + 7;
ll power(ll b,ll e){
    if(e==0) return 1;
    ll value = power(b , e/2);
    return value*value*((e%2==0) ? b : 1);
}
ll gcd(ll a,ll b){
    if(b==0) return a;
    else return gcd(b , a%b);
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    ll t; t=1;
    while(t--){
        ll n; cin >> n;
        // first figuring the index of second max of whole subsequence
        ll id;
        cout <<"? " <<  1 <<' ' << n << endl;
        cin >> id;
        // now figuring out if maximum element is in right of 2nd max or in left of 2nd max
        ll tmp,md;
        if(id!=1) {cout <<"? " <<  1 << ' ' << id << endl;
        cin >> tmp;}

        if(n==2 && id==1) {cout << "! " << 2 << endl;continue;}
        else  if(n==2 && id==2) {cout << "! "  << 1 <<endl ;continue;}
        
        if(tmp==id) md=1; // means max element is in left of 2nd max element
        else if(id==1 || tmp!=id) md=2;

        if(md==1){
            ll l=1-1 , r=n+1;
            while(r-1 > l){
                ll ptr = (l+r)/2;
                ll st;
                cout <<"? " <<  ptr << ' ' << n << endl ;
                cin >> st;
                if(st==id) l=ptr;
                else r=ptr;
            }

            cout <<"! " <<  l << endl;
        }
        else {
            ll l=1-1 , r=n+1;
            while(r-1 > l){
                ll ptr = (l+r)/2;
                ll st;
                cout <<"? " <<  1 << ' ' << ptr << endl;
                cin >> st;
                if(st==id) r=ptr;
                else l=ptr;
            }

            cout <<"! " <<  r << endl;
        }
        
    }
    



    return 0;
}