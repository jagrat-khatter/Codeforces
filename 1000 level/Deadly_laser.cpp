#include <bits/stdc++.h>
using namespace std;
using ll = long long;
ll mod(ll a)
{
    if(a<0) return -a;
    else return a;
}
ll dis(ll a, ll b , ll p , ll q)
{
    return mod(p-a)+mod(q-b);
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    ll t; cin >> t;
    while(t--)
    {
        ll n,m,sx,sy,d; cin >> n >> m>>sx>>sy>>d;
        ll f1=0,f2=0;
        // path1
        for(ll i=1;i<=n && f1!=1;i++)
        {
            if(dis(i,1 , sx,sy) <= d) f1=1;
            //cout << i << ' ' <<  1 << ' ' << dis(i,1 , sx,sy) << '\n';
        }
        for(ll j=1;j<=m && f1!=1;j++)
        {
            if(dis(n,j , sx,sy) <= d) f1=1;
            //cout << n<< ' ' <<  j << '\n';
        }
        // path2
        for(ll j=1;j<=m && f2!=1;j++)
        {
            if(dis(1,j , sx,sy) <= d) f2=1;
            //cout << 1 << ' ' <<  j << '\n';
        }
        for(ll i=1;i<=n && f2!=1;i++)
        {
            if(dis(i,m , sx,sy) <= d) f2=1;
            //cout << i << ' ' <<  m << '\n';
        }
       
        if(!f1 || !f2) cout << dis(1,1 ,n,m)  << '\n';
        else cout << -1 << '\n';
        
    }
    return 0;
}