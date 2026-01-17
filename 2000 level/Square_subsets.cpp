#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
const ll lmin = LLONG_MIN;
const ll lmax = LLONG_MAX;
const ll imin = INT_MIN;
const ll imax = INT_MAX;
const ll MOD = 1e9 + 7;
ll power(ll b,ll e){
    if(e==0) return 1;
    ll value = power(b , e/2)%MOD;
    return ((value*value)%MOD * ((e%2==0) ? 1 : b)%MOD)%MOD;
}
ll gcd(ll a,ll b){
    if(b==0) return a;
    else return gcd(b , a%b);
}
vector<ll> sieve(ll n){// returns vector of prime numbers up until n
    vector<ll> sv(n+1 , 1);
    sv[1]=0;
    for(ll i=2;i*i<=n;i++){
        for(ll j=i*i;j<=n;j+=i){
            sv[j]=0;// marking number as composite
        }
    }
    vector<ll> ans;
    for(ll i=2;i<=n;i++){
        if(sv[i]) ans.push_back(i);
    }

    return ans;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    ll n; cin >> n;
    vector<ll> v(70 + 1);// for maintaining the freqency of elements
    ll fst = lmax;
    for(ll i=1;i<=n;i++){
        ll x; cin >> x; v[x]++; fst = min(fst , x); // minimum element to have 
    }

    vector<ll> pr={0};
    for(auto j : sieve(70)){// now all the prime numbers are accessible in one 
        pr.push_back(j);
    }
    
    // now creating the bitmask if the frequency of that kth prime number is odd then bit 1 else 0
    vector<ll> bm(70+1 , 0);
    for(ll i=1;i<=70;i++){
        for(ll j=1;j<=19;j++){
            ll ct=0 , e=i;

            while(e % pr[j]==0){
                ct++; e /= pr[j];
            }
            if(ct%2==1) bm[i] += (1 << (j-1)); 
        }
    }


    
    // in bm[i] if jth bit is set means jth prime numbers frequency for i is odd

    // vector<ll> f1(70+1) , f0(70+1);// for each number we are calculating the number of ways 
    // // to select odd and even amount of a element since a subsequence will be if any element
    // // with different id id there

    //cout << bm[6] <<  ' ' << bm[7] << ' ' <<  bm[8] << ' ' << bm[9] << ' '<<  bm[10] << '\n' ;
    
    ll mx = (1 << 19) - 1;// mask when all the prime numbers are in odd frequency
    
    vector<ll> prev(mx + 1 , 0) , curr(mx + 1 ,0);
    for(ll id=fst;id<=70;id++){
        ll f0,f1;
        f0=f1= (v[id]>=1 ? power(2 , v[id]-1) : 0);

        if(id==fst) {curr[0] +=f0; curr[bm[id]]+=f1;}
        for(ll mask=0;mask<mx && id!=fst;mask++){
        
            curr[mask] = (curr[mask] + (prev[mask]%MOD * (f0%MOD))%MOD)%MOD;
            curr[mask ^ bm[id]] = (curr[mask ^ bm[id]] + (prev[mask]%MOD * (f1%MOD)%MOD)%MOD)%MOD;
            
            if(!curr[mask] && prev[mask]) curr[mask] = prev[mask];
            
        }
        // for(ll mask=0;mask<mx;mask++) {
        //     if(curr[mask]) cout << id << ' ' << mask << ' '<< curr[mask] << '\n' ;
        // }

        swap(prev , curr);
        fill(curr.begin(), curr.end(), 0); // beacuse we have to do add operations 
    }

    cout << prev[0] - 1 ; // this prev[0] represnts dp[70][0] 70 means all numbers are covered and 
    // 0 means no prime number has power odd in product since empty subsequnce can also be answer 
    // then ans - 1




    return 0;
}