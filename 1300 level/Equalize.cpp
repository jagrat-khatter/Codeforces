#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll lmin = LLONG_MIN;
const ll lmax = LLONG_MAX;
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    ll n , cst=0; cin >> n;
    string a,b; cin >> a >> b;

    for(ll i=0;i<n;i++){
        if(a[i]=='0' && b[i]=='1'){
            if(a[i+1]=='1' && b[i+1]=='0' && i!=n-1){
                cst++;
                i++;
            }
            else cst++;
        }
        else if(a[i]=='1' && b[i]=='0'){
            if(a[i+1]=='0' && b[i+1]=='1' && i!=n-1){
                cst++;
                i++;
            }
            else cst++;
        }
    }

    cout << cst << '\n';


    return 0;
}