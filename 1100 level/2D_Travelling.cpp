#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll lmin = LLONG_MIN;
const ll lmax = LLONG_MAX;
ll mod(ll n)
{
    if(n>0) return n;
    else return -n;
}
ll min(ll a, ll b)
{
    if(a>b) return b;
    else return a;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    ll t ; cin >> t;
    while(t--)
    {
        vector<pair<ll ,ll>> v;
        ll n , k , a , b; cin >> n >> k >> a >> b;
        ll ax,ay,bx,by;
        for(ll i=0;i<n;i++)
        {   // Only those cities will be included in the array which are  major cities 
            ll p , q; cin >> p >> q;
            if(i+1<=k)
            {
                v.push_back({p,q});  // if major city then push
            }
            if((i+1)==a) {ax = p ; ay = q;}
            if((i+1)==b) {bx = p ; by = q;}
        }
        if(v.size()<=1) cout << mod(bx-ax) + mod(by-ay) << '\n';
        else { // if number of major cities are >=2
            // first finding the major city nearest to the orgin city
            ll m1x = INT_MAX  , m1y = INT_MAX;
            m1x = 3 * m1x ; m1y = 3 * m1y;
            for(ll i=0;i<v.size();i++)
            {
                //cout << mod(v[i].first - ax) + mod(v[i].second - ay) << ' ' << mod(ax - m1x) + mod(ay - m1y)<< '\n';
                if((mod(v[i].first - ax) + mod(v[i].second - ay)) < (mod(ax - m1x) + mod(ay - m1y))) {m1x = v[i].first ; m1y = v[i].second ;}
                else if((mod(v[i].first - ax) + mod(v[i].second - ay)) == (mod(ax - m1x) + mod(ay - m1y)))
                {
                    if((mod(v[i].first - bx) + mod(v[i].second - by)) < (mod(bx - m1x) + mod(by - m1y))) {m1x = v[i].first ; m1y = v[i].second ;}
                }
            }
            //cout << m1x << ' ' << m1y << '\n' ;
            // now finding the major city nearest to the destination city
            ll m2x = INT_MAX , m2y = INT_MAX;
            m2x = 3*m2x ; m2y = 3*m2y;
            for(ll i=0;i<v.size();i++)
            {
                if(mod(v[i].first - bx) + mod(v[i].second - by) < mod(bx - m2x) + mod(by - m2y)) {m2x = v[i].first ; m2y = v[i].second ;}
                else if(mod(v[i].first - bx) + mod(v[i].second - by) < mod(bx - m2x) + mod(by - m2y))
                {
                    if(mod(v[i].first - ax) + mod(v[i].second - ay) < mod(ax - m2x) + mod(ay - m2y)) {m2x = v[i].first ; m2y = v[i].second ;}
                }
            }
            //cout << m2x << ' ' << m2y << '\n' ;
            cout << min (mod(ax-m1x)+mod(ay-m1y) + mod(bx-m2x)+mod(by-m2y) , mod(ax-bx) + mod(ay-by)) << '\n';
        }

    }

    return 0;
}
