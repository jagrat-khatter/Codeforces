#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll lmin = LLONG_MIN;
const ll lmax = LLONG_MAX;
vector<ll> v(5 * 1000000 + 1 , 0);// making vector of size() 5*10^6
    

set<ll> s;

ll gcd(ll a,ll b)
{
    if(b==0) return a;
    return gcd(b , a%b);
}
ll prime_factor(ll n)
{ // we need to get prime factor of a number if a number is divisible then its divisors<=root number
    for(auto i : s)
    {
        if(n%i == 0) return i;
        if(i*i > n) break;
    }
    return -1;
}// any composite number must have a prime factor less than or equal to sqrt(n) , but a general divisor can be more than sqrt(n) for a composite number n
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    // also making sure that when l==r l is not prime
    v[1]=1;
    v[0]=1;
    for(ll i=1;i*i<=5 * 1000000 + 1;i++)
    {
        if(v[i]==0)
        {
            for(ll j=i*i;j<=5*1000000;j+=i)
            {
                v[j]=1;
            }
        }
    }
    for(ll i=0;i<5 * 1000000 + 1;i++){
        if(v[i]==0) s.insert(i); // insert the values that are prime
    }

    ll t ; cin >> t;
    while(t--)
    {
        ll l,r ; cin >> l >> r;
        if(r<=3) {cout << -1 <<'\n' ; continue;}
        if(l==r)
        {
            ll fg=0;
            if(l%2==0) {cout << l/2 << ' ' << l/2<<'\n'; continue;}
            if(prime_factor(l)!= -1) cout << prime_factor(l) << ' ' << l-prime_factor(l) << '\n';
            else cout << -1 << '\n' ;
        }
        else{ // r > l
            ll i=l , fg=0;
            while(1)
            {
                if(i%2==0 && i!=2) {cout << i/2 << ' ' << i/2 << '\n'; fg=1; break;}
                i++;
            }
            
        }
    }

    return 0;
}