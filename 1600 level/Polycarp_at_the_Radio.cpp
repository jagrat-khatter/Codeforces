#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
const ll lmin = LLONG_MIN;
const ll lmax = LLONG_MAX;
ll power(ll b,ll e){
    if(e==0) return 1;
    ll value = power(b , e/2);
    if(e%2==0) return value*value;
    else return value*value*b;
}
ll gcd(ll a,ll b){
    if(b==0) return a;
    else return gcd(b , a%b);
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    ll t; t=1;
    while(t--){
        ll n,m; cin >> n >> m;
        vector<ll> v(n); for(auto & i : v) cin >> i;

        map<ll,ll> mp;
        for(auto i : v) mp[i]++;ll ct=0 , mn=lmax;
        vector<ll> b;
        for(ll i=1;i<=m;i++){ // now seeing for bands 1 to m how much they will play 
            b.push_back(mp[i]); ct+= mp[i]; mn = min(mn , mp[i]);
        }
        // so ans should be between mn and n-ct;
        ll l=mn-1 , r=n+1;// maximum answer that we can provide is if we add everything to the min 
        //cout << l << ' ' << r<< '\n';
        while(r-1 > l){
            ll mid = (l+r)/2;
            // now we'll count the minimum cost required to make min{b1,b2,b3...bm} = mid
            ll cst=0 , rem=0;
            for(auto j : b) {
                if(j<mid) cst += mid-j;
                else rem += j-mid;// this will be used to support if number of unfavoured bands removed
                // are not able to fulfill the gap for making minimum
            }

            if(cst<=n-ct+rem) l=mid;
            else r=mid;
        }
        map<ll,ll> ff;
        vector<ll> ans , ax , ax2;ll sum=0;
        for(ll i=1;i<=m;i++){
            if(mp[i]>l) {
                // this should be present
                ff[i] += l;
                for(ll j=l+1;j<=mp[i];j++) ax.push_back(i);// we'll see if we have to use this favoured songs also 
            }
            else {ff[i]+=mp[i];
                for(ll j=mp[i]+1;j<=l;j++) ax2.push_back(i);
            }

            mp[i]<l ? sum += l-mp[i] : sum +=0;
        }

        
        cout << l << ' ' <<sum<< '\n';
        for(auto i: ans) cout << i << ' ';
        // how many favoured songs are used if(sum > (n-ct))
        ll rem;
        if(sum > (n-ct)) rem=sum-(n-ct);
        else rem=0;
        for(ll j=rem;j<ax.size();j++) ff[ax[j]]++;

        ll ctr = ((sum>n-ct) ? 0 : n-ct-sum);
        vector<ll> az;
        for(ll i=0;i<n;i++){
            if(v[i]<=m && ff[v[i]]>0) {az.push_back(v[i]); ff[v[i]]--;}
            else if(v[i]>m && ctr>0) {az.push_back(v[i]);ctr--;}
            else az.push_back(-1);
        }
        for(auto &i : az){
            if(i==-1) {ll e = ax2[ax2.size()-1];
            i=e;
            ax2.pop_back();}
        }
        for(auto i : az) cout <<i << ' ';


        cout << '\n';
    }




    return 0;
}