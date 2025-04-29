#include <bits/stdc++.h>
using namespace std;
using ll= long long ;
bool search_1(ll a , ll b ,vector<pair<ll , ll>>& v)
{
    for(auto &i: v)
    {
        if(i.first>a && i.second==b) return 1;
    }

    return 0;
}
bool search_2(ll a , ll b ,vector<pair<ll , ll>>& v)
{
    for(auto &i: v)
    {
        if(i.first<a && i.second==b) return 1;
    }

    return 0;
}
bool search_3(ll a , ll b ,vector<pair<ll , ll>>& v)
{
    for(auto &i: v)
    {
        if(i.first==a && i.second>b) return 1;
    }

    return 0;
}
bool search_4(ll a , ll b ,vector<pair<ll , ll>>& v)
{
    for(auto &i: v)
    {
        if(i.first==a && i.second<b) return 1;
    }

    return 0;
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL) ;

    vector<pair<ll , ll>> v;
    ll n;
    cin >> n;
    for(ll i=0;i<n;i++)
    {
        ll a , b; cin >> a >> b;
        v.push_back({a,b}) ;
    }
    ll ct=0;
    for(ll i=0;i<v.size();i++)
    {
        ll p=v[i].first; ll q=v[i].second;
        if(search_1(p,q,v) && search_2(p,q,v) && search_3(p,q,v) && search_4(p,q,v)) ct++;

    }

    cout << ct << '\n' ;
    return 0;
}