#include <bits/stdc++.h>
using namespace std;
using ll = long long;
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    ll t;
    cin >> t;

    while(t--)
    {
        ll n,fg=0; cin >> n;
        vector<ll> v;
        string fst;
        for(ll i=0;i<n;i++)
        {
            ll x; cin >> x;
            ll p = v.size(); // to get the length of vector in  this pass
            if(i>0)
            {
                if(x >= v[p-1] && fg==0) { v.push_back(x); cout << 1 ;}
                else if(x<v[p-1] && x<=v[0] && fg==0)
                {
                    cout << 1;
                    v.push_back(x); 
                    fg=1;
                }
                else if(x>=v[p-1] && x<=v[0] && fg==1) {
                    cout << 1 ;
                    v.push_back(x);
                }
                else cout << 0 ;

            }
            else{
                v.push_back(x);
                cout << 1;
            }
        }
        cout << '\n';
    }

    return 0;
}