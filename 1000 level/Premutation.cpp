#include <bits/stdc++.h>
using namespace std;
using ll = long long ;
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL) ;

    ll t;
    cin >> t;
    
    while(t--)
    {
        ll n;
        cin >> n ;

        string s;
        cin >> s;

        ll a=0 , sum=0;
        map<char , ll> mp;

        for(ll i=0;i<s.size();i++)
        {
            if(mp[s[i]] == 0)
            {
                a++;
                sum+= a;
                mp[s[i]] ++;
            }
            else{
                sum += a;
            }
        }

        cout << sum << '\n' ;

    }


    return 0;
}