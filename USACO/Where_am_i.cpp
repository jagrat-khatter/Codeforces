#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll lmin = LLONG_MIN;
const ll lmax = LLONG_MAX;
signed main()
{
    ifstream fin("whereami.in");
    ofstream fout("whereami.out");

    ios::sync_with_stdio(false);
    cin.tie(NULL);

    ll n ; fin >> n;
    string s; fin >> s;
    // so maximum value of size of subsequence can be n 
    for(ll i=1;i<n;i++)
    {
        ll fg=0;
        map<vector<char> , ll> mp;
        for(ll j=0;j<=n-i;j++)
        {
            vector<char> v;
            for(ll k=j;k<j+i;k++)
            {
                v.push_back(s[k]);
            }
            if(mp[v]==0) mp[v]++;
            else {fg=1; break;}
        }
        if(fg==0) {fout << i ; break;}
    }


    return 0;
}