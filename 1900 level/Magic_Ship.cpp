#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
const ll lmin = LLONG_MIN;
const ll lmax = LLONG_MAX;
ll power(ll b,ll e){
    if(e==0) return 1;
    ll value = power(b ,e/2);
    return ((e%2==0) ? 1 : b);
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
        ll x1,y1,x2,y2; cin >> x1>>y1>>x2>>y2;
        ll n; cin >> n;
        string s; cin >> s;

        vector<ll> U,D,L,R;U.push_back(0);D.push_back(0);L.push_back(0);R.push_back(0);

        if(s[0]=='U') U[0]++;
        else if(s[0]=='D') D[0]++;
        else if(s[0]=='L') L[0]++;
        else if(s[0]=='R') R[0]++;

        for(ll i=1;i<s.size();i++){
            if(s[i]=='U') U.push_back(U[i-1]+1);
            else U.push_back(U[i-1]);

            if(s[i]=='D') D.push_back(D[i-1]+1);
            else D.push_back(D[i-1]);

            if(s[i]=='L') L.push_back(L[i-1]+1);
            else L.push_back(L[i-1]);

            if(s[i]=='R') R.push_back(R[i-1]+1);
            else R.push_back(R[i-1]);
        }

        ll l=0-1 , r=1e18+1;// maximum assuming each day he has to move on its own wind is not supporting 
        while(r-1 > l){
            ll mid= (l+r)/2;
            ll xc=x1 , yc=y1;
            ll cU=0,cD=0,cL=0,cR=0; // number of ups downs lefts rights which will happen for sure  in these mid number of days
            cU = (U[n-1] * (mid/n)) ; if(mid%n!=0) cU+= U[(mid%n) - 1];
            cD = (D[n-1] * (mid/n)) ; if(mid%n!=0) cD+= D[(mid%n) - 1];
            cL = (L[n-1] * (mid/n)) ; if(mid%n!=0) cL+= L[(mid%n) - 1];
            cR = (R[n-1] * (mid/n)) ; if(mid%n!=0) cR+= R[(mid%n) - 1];
            xc += cR; xc -= cL; yc += cU; yc -= cD;

            //cout << mid << ' ' << xc << ' ' << yc << '\n' ;
            ll ct= abs(x2-xc) + abs(y2-yc);
            if(ct>mid) l=mid;
            else r=mid;
            
            // ll rU=0,rD=0,rL=0,rR=0; // requirements in the directions

            // if(x2>x1) rR += abs(x2-x1); // we have to go right
            // else rL += abs(x1-x2);// we have to go left

            // if(y2>y1) rU += abs(y2-y1);
            // else rD += abs(y1-y2);

            
            // cout << mid << ' ' << cU << ' '<<cD << ' ' << cL << ' ' << cR << '\n';
            // cout << mid << ' ' << rU << ' '<<rD << ' ' << rL << ' ' << rR << '\n';
            // ll ct =0;
            // if(rU > cU) ct+= rU-cU;
            // if(rD > cD) ct+= rD-cD;
            // if(rL > cL) ct+= rL-cL;
            // if(rR > cR) ct+= rR-cR;

            // cout << ct << '\n';
            // if(ct>mid) l=mid;
            // else r=mid;
        }
        if(r!=1e18+1) cout << r << '\n' ;
        else cout << -1 << '\n';
    }



    return 0;
}