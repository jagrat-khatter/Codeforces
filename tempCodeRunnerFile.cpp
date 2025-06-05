#include <bits/stdc++.h>
using namespace std;
using ll = long long;
ll power(ll a ,ll b){
    if(b==0) return 1;
    ll value = power(a , b/2);
    if(b%2==0) return value*value;
    else return value*value*a;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cout << power(7 , 2);

}