#include<bits/stdc++.h>
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
    return value*value*((e%2==0) ? 1  : b);
}
ll gcd(ll a,ll b){
    if(b==0) return a;
    else return gcd(b , a%b);
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cout << setprecision(20);

    ll n; cin >> n;
   
    ll ct1=0,ct2=0,ct3=0;
    for(ll i=1;i<=n;i++){
        ll x; cin >> x; 
        if(x==1) ct1++;
        else if(x==2) ct2++;
        else if(x==3) ct3++;
    }

    // ct2+=ct3; // all the thress can be converted to twos
    // ct1+=ct2; // all the twos can be converted to ones
    //cout << ct1 << ' ' << ct2 << ' ' << ct3 << '\n' ;
    

    vector<vector<vector<ld>>> dp(300+1 , vector<vector<ld>> (300+1 , vector<ld> (300+1)));
    // first parameter for number of ones second paramter 
    // for number of twos third pa7ramter for number of threes
 
    dp[0][0][0] = 0.0;

    for(ll k=0;k<=ct3;k++){
        for(ll j=0;j<=ct3+ct2;j++){ // if all the 3s numbers are converted to 2s
            for(ll i=0;i<=ct3+ct2+ct1;i++){// max case if all the 3's & 2's are converted to 1
                if(i==0 && j==0 && k==0) continue;
                if(i+j+k>n) continue;
                
                ld temp = (ld)n;
                if(i-1>=0) temp+= (i)*(dp[i-1][j][k]);
                if(j-1>=0) temp+= (j)*(dp[i+1][j-1][k]);
                if(k-1>=0) temp+= (k)*(dp[i][j+1][k-1]);
                dp[i][j][k] = (temp)/(i+j+k) ;

                //cout << i <<  ' ' << j << ' ' << k << ' ' <<dp[i][j][k] << '\n' ;
            }
        }
    }

    cout << dp[ct1][ct2][ct3] << '\n' ;




    return 0;
}