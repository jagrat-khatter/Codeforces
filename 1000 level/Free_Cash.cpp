#include<bits/stdc++.h>
using namespace std;
using ll = long long ;
ll max(ll a, ll b)
{
    if(a>b) return a;
    else return b;
}
ll min(ll a, ll b)
{
    if(a<b) return a;
    else return b;
}
ll mod(ll a)
{
    if(a>0) return a;
    else return -a;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    ll t; t =1;

    while(t--)
    {
        ll n ,a ,ans=0;
        cin >> n  >> a;

        vector<ll> v;
        for(auto i=0;i<n;i++)
        {
            ll x; cin >> x;
            v.push_back(x);
        }
        ll mmag = max (mod(n-a) , mod(a-0));

        if(v[a-1]) ans++;
        for(ll i=1 ; i<=mmag ;i++)
        {
            ll f1=0,f2=0;
            if(a-i-1>=0)
            {
                if(v[a-i-1]==1) f1=1;
            }
            else f1=2;     // if a city does not exist then making it 2 so that officer can take action on another city 
            if(a+i-1<n)
            {
                if(v[a+i-1]==1) f2=1;
            }
            else f2=2;    // if a city does not exist then making it 2 so that officer can take action on another city

            if(f1==0 || f2==0) ans += 0;
            else{
                if(f1==1) ans+= 1;
                if(f2==1) ans+= 1;
            }
        }

        cout << ans << '\n' ;

    }
    

    return 0;
}