#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll lmin = LLONG_MIN;
const ll lmax = LLONG_MAX;
bool parity(ll a, ll b)
{
    bool p = (a%2==0) ;
    bool q = (b%2==0) ;
    if(p && q) return 0;
    else if(!p && q) return 1;
    else if(p && !q) return 1;
    else return 0;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

   multiset<char> s={'a','b','a' ,'a','c','b'};
   for(auto i : s) cout << i <<' ';

    return 0;
}

