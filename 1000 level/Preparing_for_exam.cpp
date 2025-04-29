#include <bits/stdc++.h>
using namespace std;
using ll = long long ;
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    ll t;
    cin >> t;
    
    while(t--)
    { //n= total number of questions in one exam paper //m=different number of exam papers 
        ll n,m,k; cin >> n>> m>> k;     // if(n-k) > 1 then it is sure he will fail in every exam 
        if(n-k>1) // he does not know more than one question
        {
            for(ll i=0;i<m+k;i++)
            {
                ll x ; cin >> x;
            }
            for(ll i=0;i<m;i++)
            {
                cout << 0 ;
            }
        }
        else if(n-k==1)
        {
            vector<ll> v;
            for(ll i=0;i<m;i++)
            {
                ll x; cin >> x;
                v.push_back(x);
            }
            ll sum=0 , ans;
            for(ll i=0;i<k;i++)
            {
                ll x ; cin >> x;
                sum+= x;  
            }
            ans  = n*(n+1)/2  - sum; // will give that on question that monocarp will not be able to answer

            for(ll i=0;i<v.size();i++)
            {
                if(v[i]==ans) cout << 1 ;
                else cout << 0 ;
            }
        }
        else{
            for(ll i=0;i<m+k;i++)
            {
                ll x; cin >> x;      // monocarp is preapred for each and every question
            }
            for(ll i=0;i<m;i++)
            {
                cout << 1 ;
            }
        }

        cout << '\n' ;
    }

    return 0;
}