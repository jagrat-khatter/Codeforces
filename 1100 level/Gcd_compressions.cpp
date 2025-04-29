#include <bits/stdc++.h>
using namespace std;
using  ll = long long;
const ll lmin = LLONG_MAX;
const ll lmax = LLONG_MIN;
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    // performing sieve for getting all the prime numbers less than 2000
    vector<ll> s(2000+1 , 0);
    s[0]=1; s[1]=1;
    for(ll i=1;i*i<=2000;i++)
    {
        if(s[i]==0) // if v[i] is itself prime
        {for(ll j=i*i;j<=2000;j+=i)
        {
            s[j]=1;
        }
        }
    }
    vector<ll> sf;
    for(ll i=0;i<2001;i++)
    {
        if(!s[i]) sf.push_back(i);
    }


    ll t;  cin >> t;
    while(t--)
    {
        ll n ; cin >> n;
        n = 2*n;
        vector<pair<ll , ll>> v;
        for(ll i=0;i<n;i++){
            ll x; cin >> x;
            v.push_back({0 , x});
        }
        
        for(auto i: sf) // checking for each prime number 
        {
            ll ct=0 , fg=0;
            map<ll , ll> mp; // index , used-1 notused-0
            for(ll j=0;j<n-1;j++)
            {
                if(mp[j]==1) continue;
                ct=0;
                ll e1 = v[j].second;
                for(ll k=j+1;k<n;k++)
                {
                    if(mp[k]==1) continue;
                    ll e2 = v[k].second;
                    if((e1+e2)%i != 0) ct = ct; // this j and k will go through each pair 
                    else {ct++;
                        mp[j]=1;        // index k and j are used 
                    mp[k]=1;
                    break;}
                }
                if(ct==0) {fg++;}
                if(fg>2) break;
            }
            if(fg<=2){
                ll z =0;
                map<ll , ll> mp2;
                for(ll j=0;j<n-1;j++)
                {
                    if(mp2[j]==1) continue;
                    
                    ll e1 = v[j].second;
                    for(ll k=j+1;k<n;k++)
                    {
                        if(mp2[k]==1) continue;
                        ll e2 = v[k].second;
                        if((e1+e2)%i != 0) ct = ct; // this j and k will go through each pair 
                        else {cout << j+1 << ' ' << k+1 << '\n' ;
                            z++;
                            mp2[j]=1;        // index k and j are used 
                        mp2[k]=1;
                        break;}
                    }
                    if(z==n/2-1) break;
                }
                break;
            }
            
        }


        
    }




    return 0;
}