#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll lmax = LLONG_MAX;
const ll lmin = LLONG_MIN;
bool check(ll n)
{
    ll fg=0;
    while(n) // max % operations per number
    {
        if(n%10!=0 && n%10!=1) {fg=1 ; break;} // digit is neither 1 nor 0
        n /= 10;
    }
    if(!fg) return true;
    else return false;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    set<ll> s;
    for(ll i=1;i<=99999;i++){
        if(check(i)) s.insert(i);
    }// in the end the size of set is 35 bcoz 2^5-1 = 31  (we have not included zero)
    //for(auto &i : s) cout << i << ' ' ;
    
    ll t ; cin >> t;
    while(t--)
    {
        ll n ; cin >> n;
        if(n==100000) {cout << "YES" << '\n'; continue;}

        
        // try to divide the number again and again with the numbers given in set
        while(n!=1)
        {
            //cout << n << '\n';
            ll p=0;
            for(auto i : s){
                if(s.find(n) != s.end()) {n=1;p=0;} // if n is itself present then just do it else search for factors
                if(n%i ==0 && i!=1) {n /= i; p=1;}
            }
            if(p==0) break; // if n passes through set once and does not finds any thing it can be 
            // divided by then ans = "NO"
        }

        if(n==1) cout << "YES";
        else cout << "NO" ;
        cout << '\n';
    }



    return 0;
}