#include<bits/stdc++.h>
using namespace std;
using ll = long long;
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    ll t;
    cin>> t;
    while(t--)
    {
        ll n; cin >> n;

        vector<ll> v;
        vector<ll> as;
        for(ll i=0;i<n;i++)
        {
            ll p ; cin >> p;

            v.push_back(p);
        }
        ll ct=0;
        as.push_back(v[0]);   //inserting the first disk as first stack
        for(ll i=1;i<n;i++)
        {
            // first will make element go through every stack top element if they are samller than top most element then replace it else create a new stak for that 
            ll fg=0;
            ll l=0-1, r=as.size()+1-1,target=v[i];    // i want to find the first element such that it is > target
            while(r-1>l)
            {
                ll mid=(l+r)/2;
                if(as[mid]<= target) l = mid;
                else r=mid;
            }
            if(r<as.size()) as[r]= target;  // if there is no such element then it will give index of outside the vector
            else as.push_back(target);
            // for(ll j=0;j<as.size();j++)
            // {
            //     if(v[i] < as[j]) 
            //     {
            //         as[j] = v[i];
            //         fg=1;
            //         break;  
            //     }
            // }
            // if(!fg) as.push_back(v[i]);
        }
        cout << as.size() << ' ';
        for(ll i=0;i<as.size();i++) cout << as[i] << ' ';

        cout << '\n';
    }

    return 0;
}