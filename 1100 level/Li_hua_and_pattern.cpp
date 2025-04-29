#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll  lmax = LLONG_MAX;
const ll  lmin = LLONG_MIN;
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    ll t; cin >> t;
    while(t--)
    {
        ll n , k; cin >> n>> k;
        ll a[n][n];
        for(ll i=0;i<n;i++)
        {
            for(ll j=0;j<n;j++)
            {
                cin >> a[i][j];
            }
        }
        if(n==1){
            cout << "YES" << '\n';
            continue;
        }
        for(ll i=n-1;i>=n/2;i--) // for checking we'll go from the down row to upper row
        {
            for(ll j=n-1;j>=0;j--)
            {
                if(n%2!=0 && i==n/2 && j==n/2) break;
                if(a[i][j]!=a[n-i-1][n-j-1]) {k--;}
            }
        }
        //cout << k << '\n';
        if(k<0) cout << "NO" << '\n' ; // if it is not able to do necessary operations then it is NO
        else { // if k reamins it means arary is converted to 180 but still k remains so do operation such that array now reamins same
            if(k%2==0 || n%2!=0) cout << "YES" << "\n";
            else cout << "NO" << '\n' ;
        }
    }

    return 0;
}