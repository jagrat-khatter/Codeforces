#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll lmin = LLONG_MIN;
const ll lmax = LLONG_MAX;
ll min(ll a,ll b)
{
    if(a<b) return a;
    else return b;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    // if imagine any subsegment , its starting point is any element of array only 
    ll t; cin >> t;
    while(t--)
    {
        ll n,m; cin >> n >> m;
        // for each element we have to store element which is closer to it but is in right side of it
        map<ll , ll> mp; 
        for(ll i=1;i<=m;i++)
        {
            ll x,y ; cin >> x >> y; // all the things are in one based indexing as given by 
            if(x>y) {y = x+y;x=y-x;y=y-x;} // exchange x and y if x>y
            if(mp[x]==0){ // if we have found first element which is in right side of that element
                mp[x] = y;
            }
            else if(mp[x]>y){ // if already have an element which is right side to that element we'll 
                //see which is closer the new element or the older one
                mp[x] = y;
            }
        }
        ll ans=0;
        for(ll i=n-1;i>0;i--){
            if(mp[i]==0) mp[i]=mp[i+1];
            else if(mp[i+1]) mp[i]=min(mp[i] , mp[i+1]);// if some elements don't have mp[] value they will 
            // get it from their rightwards element
            //cout << i << ' ' << mp[i] << '\n';
            if(mp[i]==0) ans+= n-i;
            else ans+= mp[i]-i-1;
        }
        cout << ans+n << '\n';
    }



    return 0;
}