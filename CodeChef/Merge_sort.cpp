#include <bits/stdc++.h>
using namespace std;
using ll = long long ;
void merge(vector<ll> &v ,ll l , ll mid , ll r)
{
    vector<ll> arr;
    ll p1=l , p2=mid+1;
    while(p1<=mid && p2<=r)
    {
        if(v[p1]<=v[p2])
        {
            arr.push_back(v[p1]);
            p1++;
        }
        else{
            arr.push_back(v[p2]);
            p2++;
        }
    }

    if(p1<=mid) // p1 will break the while loop or p2 will break the while loop
    {
        for(ll i=p1;i<=mid;i++)
        {
            arr.push_back(v[i]);
        }
    }else
    {
        for(ll i=p2;i<=r;i++)
        {
            arr.push_back(v[i]);
        }
    }
    for(ll i=l;i<=r;i++)
    {
        v[i] = arr[i-l];
    }
}
void mergesort(vector<ll> &v ,ll l ,ll r)
{
    if(l==r) return ;
    mergesort(v , l , (l+r)/2);
    mergesort(v , (l+r)/2 + 1 , r);
    merge(v , l , (l+r)/2 , r);
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    vector<ll> v={3,1,2,4,1,5,2,6,4};
    mergesort(v , 0 , v.size()-1);
    for(auto i: v) cout << i << ' ';


    return 0;
}