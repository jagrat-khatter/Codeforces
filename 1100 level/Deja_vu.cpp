#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll lmin = LLONG_MIN;
const ll  lmax = LLONG_MAX;
ll power(ll b , ll p)
{
    if(p==0) return 1;

    ll value = power(b  ,p/2);
    if(p%2==0) return value * value;
    else return value * value * b;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

   ll t ; cin >> t;
   while(t--)
   {
        ll n , x; cin >> n>> x;
        vector<ll> v;
        ll min = lmax ;       // this min will store the minimum height of the coral so the possibility of height will start from there 
        for(ll i=0;i<n;i++)
        {
            ll x; cin >> x;
            v.push_back(x);

            if(x<min) min = x;
        }
        if(n==1) {cout << v[0] + x << '\n'; continue;}
        sort(v.begin() ,v.end());
        vector<ll> p;
        p.push_back(v[0]);
        for(ll i=1;i<n;i++)
        {
            p.push_back(v[i] + p[i-1]) ;
        }
    
        ll sum , temp=min;
        for(ll i=min+1 ; i<1000000 ;i++)
        {
            // now will find the last index of this coral 
            
            ll l = 0-1 , r=v.size() - 1+ 1 , target = i; // making this i has height
            while(l<r-1)
            {
                ll mid =  (l+r)/2;
                if(v[mid] <= target) l = mid;
                else r = mid;
            }// now the l will give the last index of that coral height
            if(l<v.size())
            {sum = i*(l+1) - (p[l]);
            if(sum>x) break;   // if the volume is less han or equal to x then it should store the height
            temp = i;}// storing the height
            else {
                sum = i*(v.size()) - (p[v.size()-1]);
                    if(sum>x) break;   // if the volume is less han or equal to x then it should store the height
                    temp = i;
            }
        }

        cout << temp << '\n' ;
   }

    return 0;
}