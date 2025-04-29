#include<bits/stdc++.h>
using namespace std;
using ll=long long;

// ll sumd(ll n)
// {
//     ll sum=0;
//     while(n)
//     {
//         sum += n%10;
//         n/=10;
//     }

//     return sum;
// }
ll check(ll n)
{
    ll digit,fg=0,cp=n;

    while (cp)
    {
        digit= cp%10;
        if(digit == 0) continue;
        cp /=10;
        if(n%digit !=0 )
        {
            fg=1;
            break;
        }
    }

    if(fg) return 0;  // will return  0 if all the digits do not divide the n 
    else return 1;   // will return 1 if all digits completely divide te n
    
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    ll t;
    cin >> t;

    while(t--)
    {
        ll n;
        cin >> n;

        if(n%2520 == 0) cout << n << '\n';
        else 
        {
            ll m= n/2520 + 1;

            for(ll i=n ; i <= m*2520 ;i++)
            {
                if(check(i))
                {
                    cout << i << '\n';
                    break;
                }
            }
        }
    }

    return 0;
}
