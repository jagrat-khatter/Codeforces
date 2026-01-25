#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
const ll lmin = LLONG_MIN;
const ll lmax = LLONG_MAX;
const ll imin = INT_MIN;
const ll imax = INT_MAX;
ll power(ll b,ll e){
    if(e==0) return 1;
    ll value = power(b , e/2);
    return value*value*((e%2==0) ? 1 : b);
}
ll gcd(ll a,ll b){
    if(b==0) return a;
    else return gcd(b , a%b);
}
void debug(const vector<ll>& v){
    cerr << "[ ";
    for(auto j : v) cerr << j << ' ' ;
    cerr << "]\n"; return ;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    ll t; t=1;
    while(t--){
        ll n,m; cin >> n >> m;
        string s; cin >> s;
        // there are six cases how string should look 
        // abcabcabc... , bcabcabca... , cabcabcab... , bacbacbac... , cbacbacba... , acbacbacb...
        // if we try to make whole string in this way and make prefix array of no of operations then 
        // then for any specifc segment it will be in one of these 6 cases only 
        // then we find minimum opertaions required in all 6 cases for the substring

        vector<vector<ll>> pf(6 ,vector<ll> (n+1 ,0));
        for(ll i=1;i<=n;i++){// abcabcabc..
            if(i%3==1 && s[i-1]!='a') pf[0][i] = (1 + pf[0][i-1]);
            else if(i%3==2 && s[i-1]!='b') pf[0][i] = (1 + pf[0][i-1]);
            else if(i%3==0 && s[i-1]!='c') pf[0][i] = (1 + pf[0][i-1]);
            else pf[0][i] = (pf[0][i-1]);
        }
        for(ll i=1;i<=n;i++){// bcabcabca...
            if(i%3==1 && s[i-1]!='b') pf[1][i] = (1 + pf[1][i-1]);
            else if(i%3==2 && s[i-1]!='c') pf[1][i] = (1 + pf[1][i-1]);
            else if(i%3==0 && s[i-1]!='a') pf[1][i] = (1 + pf[1][i-1]);
            else pf[1][i] = (pf[1][i-1]);
        }
        for(ll i=1;i<=n;i++){// cabcabcab...
            if(i%3==1 && s[i-1]!='c') pf[2][i] = (1 + pf[2][i-1]);
            else if(i%3==2 && s[i-1]!='a') pf[2][i] = (1 + pf[2][i-1]);
            else if(i%3==0 && s[i-1]!='b') pf[2][i] = (1 + pf[2][i-1]);
            else pf[2][i] = (pf[2][i-1]);
        }
        for(ll i=1;i<=n;i++){// bacbacbac...
            if(i%3==1 && s[i-1]!='b') pf[3][i] = (1 + pf[3][i-1]);
            else if(i%3==2 && s[i-1]!='a') pf[3][i] = (1 + pf[3][i-1]);
            else if(i%3==0 && s[i-1]!='c') pf[3][i] = (1 + pf[3][i-1]);
            else pf[3][i] = (pf[3][i-1]);
        }
        for(ll i=1;i<=n;i++){// acbacbacb...
            if(i%3==1 && s[i-1]!='a') pf[4][i] = (1 + pf[4][i-1]);
            else if(i%3==2 && s[i-1]!='c') pf[4][i] = (1 + pf[4][i-1]);
            else if(i%3==0 && s[i-1]!='b') pf[4][i] = (1 + pf[4][i-1]);
            else pf[4][i] = (pf[4][i-1]);
        }
        for(ll i=1;i<=n;i++){// cbacbacba
            if(i%3==1 && s[i-1]!='c') pf[5][i] = (1 + pf[5][i-1]);
            else if(i%3==2 && s[i-1]!='b') pf[5][i] = (1 + pf[5][i-1]);
            else if(i%3==0 && s[i-1]!='a') pf[5][i] = (1 + pf[5][i-1]);
            else pf[5][i] = (pf[5][i-1]);
        }

        while(m--){
            ll l,r; cin >> l >> r;
            ll ans=lmax;
            for(ll i=0;i<6;i++){
                ans = min(ans , pf[i][r] - pf[i][l-1]);
            }

            cout << ans << '\n' ;
        }

    }




    return 0;
}