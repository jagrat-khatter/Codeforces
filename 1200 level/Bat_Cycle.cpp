#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll lmin = LLONG_MIN;
const ll lmax = LLONG_MAX;
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    ll t; cin>> t;
    while(t--){
        ll n , k; cin >>n>> k;
        if(n%2==0){
            if(k%n == 0) cout << n << '\n';
            else cout << k%n << '\n';
        }
        else{
            ll s =( k +(n-1) -1)/ (n-1);
            ll e;
            if(k%(n-1) != 0) e = k%(n-1);
            else e= n-1;

            ll fst ;
            if(s%n==0) fst = n;
            else fst = s%n;

            //cout << s << ' ' << e << ' ' << fst << '\n';
            if(e>((n-1)/2)){
                ll ad = fst +1 + (e-1);
                if(ad%n==0) cout << n << '\n';
                else cout << ad%n << '\n';
            }
            else{
                ll ad = fst + (e-1);
                 if(ad%n==0) cout << n << '\n';
                else cout << ad%n << '\n';
            }
            

        }

    }




    return 0;
}