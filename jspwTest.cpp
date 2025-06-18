#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const ll lmin = LLONG_MIN;
const ll lmax = LLONG_MAX;
ll power(ll b , ll e){
    if(e==0) return 1;

    ll value = power(b , e/2);
    if(e%2==0) return value * value;
    else return value * value *  b;
}
void func(vector<ll> v,set<ll> &s){
    // if all the numbers in the vector are non negative means recusrsion has to end 
    // cout << "control"<< '\n';
    ll l =0;
    while(v[l]!=-1){
        l++;
        if(l==v.size()) break;
    }
    // for(auto i : v) cout << i << ' ';
    // cout << '\n';

    if(l == v.size()){ // vector is complete
       // cout << "complete" << '\n';
        ll ct7 =0; ll ct4 =0;
        ll mul = power(10 , v.size()-1);
        ll num =0;
        for(ll i=0;i<v.size();i++){
            num += v[i] * mul;
            if(v[i] == 4) ct4++;
            else ct7++;

            mul = mul/10;
        }
        // cout << num << '\n';
        if(ct7 == ct4)s.insert(num);
        return ;
    }
    else{ // vector is incomplete
        v[l] = 4;
        func(v , s);
        v[l] = 7;
        func(v , s);
    }
}
signed main()
{
    // ios::sync_with_stdio(false);
    // cin.tie(NULL);

    vector<ll> v(6);
    for(auto & i : v) i = -1;
    // for(auto i : v) cout << i << ' ';
    set<ll> s;
    func(v , s);
    


    return 0;
}