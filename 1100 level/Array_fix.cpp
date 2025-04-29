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
    while(t--)
    {
        ll n ; cin >> n;
        vector<ll> v(n);
        for(ll i=0;i<n;i++) cin >> v[i];
        // first we'll find the last index where the array is descending
        ll id=lmin;
        for(ll i=1;i<n;i++)
        {
            if(v[i]<v[i-1]) id=i;
        }
        //cout<< id << '\n' ;
        if(id == lmin ) {cout << "YES" << '\n'; continue;} // else we need to fragmentize all the elements upto index id
        // bcoz if you fragmentize a element then you have to fragmentize all its previous elements also
        // just to check if there is any posibility of making array non-descending 
         
        ll fg=0 , le=0;
        for(ll i=0;i<n;i++) // when indexex are <id we need to fragmentize 
        {
            if(i<id){ll e = v[i];
            if(e<10){ // single digit number
                if(e%10 >= le) {le= e%10;}
                else {fg=1; break;}
            }
            else{ // two digit number 
                if((e/10)%10 >= le) {le= (e/10)%10;}
                else {fg=1; break;}
                if(e%10 >= le) {le= e%10;}
                else {fg=1; break;}
            }}
            else{  // when indexex are >=id we need not to fragmentize (on fragmentization value of array element remains same or get decreased)
                // cout << v[i] <<  ' ' << le << '\n';
                if(v[i]>=le) {le=v[i];}
                else {fg=1;break;}
            }

        }
        if(!fg) cout << "YES" << "\n";
        else cout << "NO" << '\n' ;
    }


    return 0;
}