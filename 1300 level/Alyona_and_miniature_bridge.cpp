#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll lmin = LLONG_MIN;
const ll lmax = LLONG_MAX;
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    ll n , h; cin >> n >> h;
    multiset<ll> s;vector<ll> v;
    ll i;
    for (i=0;i<n;i++)
    {
        ll x; cin >> x;
        s.insert(x);
        ll ct=0, ht =0;


        if((i+1)%2 != 0){ // if number of bottle is odd
            for(auto j : s){
                if(ct==0 || ct%2==0){
                    ht += j;
                }
                ct++;
            }
            if(ht > h) break;
        }
        else{   // if number of bottles is even
            for(auto j : s){
                if(ct%2!=0){
                    ht += j;
                }
                ct++;
            }
            if(ht > h) break;
        }

        //cout << i << ' ' << ht << '\n';
    }

    cout << i << '\n';  // the loop breaks at index more than one of what answer is so no need of 
    // one based index adjusting 

    return 0;
}