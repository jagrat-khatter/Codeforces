#include <bits/stdc++.h>
using namespace std;
using ll = long long  ;
ll gcd(ll a , ll b)
{
    if(b%a==0) return a;

    return gcd(b%a , a);
}
ll lcm(ll a ,ll b)
{
    return (a*b) / gcd(a,b);
}
ll mod(ll x)
{
    if(x>0) return x;
    else return -x;
}
ll max(ll a , ll b)
{
    if(a>b) return a;
    else return b;
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    ll t;
    cin >> t;

    while(t--)
    {
        ll n ,m;
        cin >> n >> m;

        ll s[n][m];

        for(ll i=0;i<n;i++)
        {
            for(ll j=0;j<m;j++) cin>> s[i][j];
        }
        for(ll j=0;j<m;j++)
        {
            for(ll i=0;i<n;i++)
            {
                ll fg1=1, fg2=1,fg3=1,fg4=1 , ans=0;
                if(s[i][j] > s[i+1][j] && i!=n-1) 
                {
                    fg1=1;
                    ans = max(ans , s[i+1][j]) ;
                }
                else if(i!=n-1) fg1=0;
                if(s[i][j] > s[i-1][j] && i!=0) {
                    fg2=1;
                    ans = max(ans , s[i-1][j]) ;
                }
                else if(i!=0) fg2=0;
                if(s[i][j] > s[i][j+1] && j!=m-1) 
                {
                    fg3=1;
                    ans = max(ans , s[i][j+1]);
                }
                else if(j!=m-1) fg3=0;
                if(s[i][j] > s[i][j-1] && j!=0)
                {
                    fg4=1;
                    ans = max(ans , s[i][j-1]);
                }
                else if(j!=0) fg4=0;

                //cout << fg1 << ' ' << fg2 << ' ' << fg3 << ' ' << fg4 << '\n';

                if(fg1 && fg2 && fg3 && fg4) s[i][j]=ans ;

            }
        }
        for(ll i=0;i<n;i++)
        {
            for(ll j=0;j<m;j++) cout << s[i][j] << ' ';

            cout << '\n' ;
        }
    }

    return 0;
}