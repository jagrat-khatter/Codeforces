#include <bits/stdc++.h>
using namespace std;
using ll = long long;
ll func(ll n , ll t)
{
    if(n==t) return 1;

    if(n%3 !=0) return 0;
    else 
    {
        return (func(n/3 , t) || func(2*n/3 , t));
    }
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    ll t ;
    cin >> t;


    vector<ll> v={3,4,8,9,4,7,1};
    sort(v.begin() , v.end() , greater<ll>());
    for(ll  i=0;i<v.size();i++) cout << v[i] << ' ' ;

    return 0;
}