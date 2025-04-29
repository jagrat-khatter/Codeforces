#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const ll lmin = LLONG_MIN;
const ll lmax = LLONG_MAX;
ll result(vector<pair<ll ,ll>> &v1 , vector<pair<ll ,ll>> &v2 , vector<pair<ll ,ll>> &v3){
    // first priority pe v1
    ll ans =0;
    ll n = v1.size();
    ans += v1[n-1].second;
    if(v2[n-1].first == v1[n-1].first) {ans += v2[n-2].second;
        // index of v3 can not be equal to v1[n-1].second and v2[n-2].second
        if(v3[n-1].first!=v1[n-1].first && v3[n-1].first!=v2[n-2].first) ans += v3[n-1].second;
        else if(v3[n-2].first!=v1[n-1].first && v3[n-2].first!=v2[n-2].first) ans+= v3[n-2].second;
        else ans += v3[n-3].second;
    }
    else { ans+= v2[n-1].second; // both indexes used up until now is 
        if(v3[n-1].first!=v1[n-1].first && v3[n-1].first!=v2[n-1].first) ans += v3[n-1].second;
        else if(v3[n-2].first!=v1[n-1].first && v3[n-2].first!=v2[n-1].first) ans += v3[n-2].second;
        else ans += v3[n-3].second;
    }

    return ans;
}
bool comparator(pair<ll,ll> a, pair<ll ,ll> b){
    return a.second < b.second;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    ll t; cin >> t;
    while(t--)
    {
        ll n ; cin >> n;
        vector<pair<ll ,ll>> v1;
        vector<pair<ll ,ll>> v2;
        vector<pair<ll ,ll>> v3;
        for(ll i=0;i<n;i++){
            ll x; cin >> x;
            v1.push_back({i+1 , x});
        }
        for(ll i=0;i<n;i++){
            ll x; cin >> x;
            v2.push_back({i+1 , x});
        }
        for(ll i=0;i<n;i++){
            ll x; cin >> x;
            v3.push_back({i+1 , x});
        }
        sort(v1.begin() , v1.end() , comparator);
        sort(v2.begin() , v2.end() , comparator);
        sort(v3.begin() , v3.end() , comparator);
       
        set<ll> s;
        s.insert(result(v1,v2,v3));
        s.insert(result(v1,v3,v2));
        s.insert(result(v2,v1,v3));
        s.insert(result(v2,v3,v1));
        s.insert(result(v3,v1,v2));
        s.insert(result(v3,v2,v1));
        cout << *(--s.end())<< '\n';


    }



    return 0;
}