#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll lmin = LLONG_MIN;
const ll lmax = LLONG_MAX;
ll max(ll a, ll b){
    if(a>b) return a;
    else return b;
}
ll min(ll a,ll b)
{
    if(a>b) return b;
    else return a;
}
ll power(ll b,ll e){
    if(e==0) return 1;

    ll value = power(b , e/2);
    if(e%2==0) return value * value;
    else return value * value * b;
}
ll maxSq(vector<string>& v ,ll i , ll j ,ll r ,ll c){

    
    if(i==r-1 || j==c-1) return 1; 
    else if(v[i+1][j]=='0' || v[i][j+1]=='0') return 1;
    // recursion will never reach an element which is zero 
    
    ll down = maxSq(v , i+1 , j , r, c);
    ll right = maxSq(v , i , j+1 , r , c);
    if(down == right){
        // cout << i << " " << j << ' ' << 's' << '\n';
        // cout<< down << ' ' << right << '\n';
        if()
        if (i+down<=r-1 && j+down<=c-1 && v[i+down][j+down]=='1' ) return right+1;
        else return right;
    }
    else{
        //cout << i << " " << j << ' ' << 's'<< '\n';
        return min(down , right) + 1;
    }

}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    
    ll r,c; cin >> r >> c;
    vector<string> v(r);

    for(auto &i : v){
        cin >> i;
    }
    cout << maxSq(v , 0 , 0 , r , c) << '\n';
    

    return 0;
}