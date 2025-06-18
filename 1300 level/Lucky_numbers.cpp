#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll lmin = LLONG_MIN;
const ll lmax = LLONG_MAX;
ll digits(ll n){
    ll ct=0;
    while(n){
        n = n/10;
        ct++;
    }
    return ct;
}
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
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    ll n; cin >> n;
    ll dg = digits(n);

    if(dg%2==0){
        ll l = 0 , r=0;
        ll mu = power(10 , dg-1);
        for(ll i=dg;i>=1;i--){
            if(i>(dg/2)) r = mu * 7 + r;
            else r = mu * 4 + r;
            mu = mu/10;
        }

        mu = power(10 , dg-1);
        for(ll i=dg;i>=1;i--){
            if(i>(dg/2)) l = mu * 4 + l;
            else l = mu * 7 + l;
            mu = mu/10;
        }

        if(n<l) cout << l << '\n';
        else if(n>=l && n<=r){
            vector<ll> vf;
            for(ll i=0;i<dg;i++){
                vf.push_back(-1);
            }
            set<ll> s;
            func(vf , s);
            for(auto i : s){
                if(n<=i) {cout << i << '\n'; break;}
            }
        }
        else {
            ll as =0;
            mu = power(10 , dg+2-1);
            for(ll i=dg+2;i>=1;i--){
                if(i>((dg+2)/2)) as = mu * 4 + as;
                else as = mu * 7 + as;
                mu = mu/10;
            }

            cout << as << '\n';
        }
    }
    else{ // for odd digit
        ll l=0;
        ll mu = power(10 , dg+1-1);
        for(ll i=dg+1;i>=1;i--){
            if(i>((dg+1)/2)) l = mu * 4 + l;
            else l = mu * 7 + l;
            mu = mu/10;
        }

        cout << l << '\n';
    }



    return 0;
}