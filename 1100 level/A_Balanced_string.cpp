#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll lmin = LLONG_MIN;
const ll lmax = LLONG_MAX;
ll min(ll a,ll b)
{
    if(a>b) return b;
    else return a;
}
ll max(ll a,ll b)
{
    if(a>b) return a;
    else return b;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    ll t ; cin >> t;
    while(t--)
    {
        string s; cin >> s; 
        ll n=s.size() , ct=0;
        map<char , ll> mp;
        // first task is to find out the number of distinct characters 
        for(ll i=0;i<n;i++)
        {
            ll e = s[i];
            if(mp[e]==0)
            {
                mp[e]++;
                ct++;
            }else mp[e]++;
        }
        // now we'll extract the first ct elements of the string 
        map<char , ll> m2;
        vector<char> v;
        ll fg=0;
        for(ll i=0;i<ct;i++) // we also want to ensure that the first k elements all should have frequency 1
        {  // ex- pqr , qrp , rpq , rqp
            ll e = s[i];
            if(m2[e]>0) {fg=1;break;}
            v.push_back(e);
        }
        // now the pattern recorded in v should repeat 
        // size of s should be multiple of ct(no of distict characters)
        
            for(ll i=ct;i<n;i++)
            {
                ll p = i%ct;
                if(v[p]!=s[i]) fg=1;
            }
        
        if(fg==0) cout << "YES" << '\n';
        else cout << "NO" << '\n';
    }


    return 0;
}