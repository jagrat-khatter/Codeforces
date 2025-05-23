#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll lmin = LLONG_MIN;
const ll lmax = LLONG_MAX;
ll ops(ll a){
    ll ct=1 , ans=0;
    while(a>ct){
        ct = ct*2;
        ans++;
    }
    ll p;
    if(ct!=a) {ans--;p = ct/2;
        while(p!=a){
            ll  e = ((p +a -p -1)/(a-p));      // to ceil it
            p = p+(p/e);
            ans++;
        }
        return ans;
    }
    else return ans;

}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    // if imagine any subsegment , its starting point is any element of array only 
    cout << ops(5) <<' '<< ops(7) << ' '<<ops(8) << ' ' << ops(77) << ' '<< ops(15);



    return 0;
}