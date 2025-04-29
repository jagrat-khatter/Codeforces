#include <bits/stdc++.h>
using namespace std;
using ll = long long;
void merge(vector<ll> &v ,vector<ll> &temp ,ll l , ll mid , ll r , ll &ct)
{
    ll p1=l , p2=mid+1 , k=l;
    while(p1<=mid && p2<=r)
    {
        if(v[p1]<=v[p2])
        {
            temp[k++]=v[p1++];
        }
        else{
            ct += (mid - p1 + 1);
            temp[k++]=v[p2++];
        }
    }

    if(p1<=mid) // p1 will break the while loop or p2 will break the while loop
    {
        for(ll i=p1;i<=mid;i++)
        {
            temp[k++]=v[p1++];
        }
    }else
    {
        for(ll i=p2;i<=r;i++)
        {
            temp[k++]=v[p2++];
        }
    }
    for(ll i=l;i<=r;i++)
    {
        v[i] = temp[i];
    }
}
void mergesort(vector<ll> &v ,vector<ll> &temp,ll l ,ll r , ll &ct)
{
    if(l>=r) return ;
    mergesort(v ,temp, l , (l+r)/2 , ct);
    mergesort(v ,temp, (l+r)/2 + 1 , r , ct);
    merge(v , temp,l , (l+r)/2 , r , ct);
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    ll n , ct=0;
    cin >> n;
    vector<ll> v(n);
    vector<ll> temp(n);
    for(ll i=0;i<n;i++)
    {
        ll x;cin>> x;
        v[i]=x;
    }
    mergesort(v ,temp, 0 , v.size()-1 , ct);
    cout << ct ;



    return 0;
}