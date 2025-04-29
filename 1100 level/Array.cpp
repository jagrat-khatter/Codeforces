#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll lmin = LLONG_MIN;
const ll lmax = LLONG_MAX;
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    ll n ; cin >> n;
    ll ne=0,p=0 ,z=0; // number of negative and number of positive elements
    vector<ll> v;
    for(ll i=0;i<n;i++)
    {
        ll x; cin >> x;
        if(x>0) p++;
        else if(x<0) ne++;
        else z++;

        v.push_back(x);
    }// for solution to exist which is guranteed their should exist at least one -1
    sort(v.begin() , v.end());;
    cout << 1 << ' ' << v[0] << '\n';
    if(p>0) {
        cout << 1 << ' '<<v[n-1] << '\n'; 
        cout << n-2 << ' ';
        for(ll i=1;i<n-1;i++)
        {
            cout << v[i] << ' ';
        }
    }
    else { // p==0 then their should be two negative numbers after using v[0] as neagtive
        cout << 2 << ' ' << v[1] << ' ' <<v[2] << '\n';
        cout << n-3 << ' ';
        for(ll i=3;i<n;i++){
            cout << v[i] << ' ';
        }
    }
    


    return 0;
}