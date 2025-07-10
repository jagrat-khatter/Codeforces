#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll lmin = LLONG_MIN;
const ll lmax = LLONG_MAX;
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    long double n,x,y; cin >> n >> x >> y;
    ll smx = 0;// for special elements who have same x bcoz for them slopw will be infinite

    set<long double> slp;
    for(ll i=0;i<n;i++){
        long double px,py; cin >> px >> py;

        if(px==x) smx++;
        else  slp.insert((y-py)/(x-px));
            
        
    }
    cout << slp.size() + (ll)(smx!=0)<< '\n';



    return 0;
}