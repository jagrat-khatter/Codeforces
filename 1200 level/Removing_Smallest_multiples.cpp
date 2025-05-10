#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll lmin = LLONG_MIN;
const ll lmax = LLONG_MAX;
ll min(ll a, ll b){
    if(a>b) return b;
    else return a;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    ll t; cin >> t;
    while(t--)
    {
        ll n; cin >> n;
        string s; cin >> s;
        string marked(n , '1');
        ll ans=0;
        for(ll i=0;i<n;i++)
        {
            if(s[i] == '0')
            {for(ll j=i;j<n;j+=i+1){
                if(s[j] == '0'){
                    if(s[j]=='1') break; // if element is not be removed from the original set
                    if(marked[j]=='0') continue;
                    marked[j] = '0';
                    ans += i+1;
                }
                else break;
            }}
        }
        
        cout << ans << '\n';
    }


    return 0;
}