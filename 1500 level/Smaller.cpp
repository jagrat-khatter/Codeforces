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

    ll t; cin >> t;
    while(t--){
        ll n; cin >> n;
    
        map<char , ll> m1 , m2;
        m1['a']++; m2['a']++;
        ll mns=(ll)('a') , mnt=(ll)('a') , mxs=(ll)('a') , mxt=(ll)('a');
        while(n--){
            ll d,k; cin >> d >> k; string s; cin >> s;
            for(auto i : s){
                if(d==1){
                    m1[i]+= k;
                    mns = min(mns , (ll)(i));
                    mxs = max(mxs , (ll)(i));
                }
                else {
                    m2[i]+=k;
                    mnt = min(mnt , (ll)(i));
                    mxt = max(mxt , (ll)(i));
                }
                
            }
            
            if(mns<mxt) cout << "YES" << '\n';
            else if(mns==mxt && m1[(char)(mns)]<m2[(char)(mxt)] && mns==mxs) cout << "YES\n" ;
            else cout << "NO\n" ;

            //cout << (char)(mxs) << ' '<< (char)(mns) << ' '<< (char)(mxt) << ' '<< (char)(mnt) << '\n';
        }
    }




    return 0;
}