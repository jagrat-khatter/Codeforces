#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll lmin = LLONG_MIN;
const ll lmax = LLONG_MAX;
map<ll ,ll> mp;
vector<ll> op;
void clear()
{
    ll n= op.size();
    for(ll i=n-1;i>=0;i--){
        mp[op[i]]=0;
        op.pop_back();
    }
    return;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    ll n,q; cin >> n >> q;
    ll sum=0;
    vector<ll> v(n);
    for(auto &i : v){
        ll x; cin >> x;
        i = x;
        sum +=x;
    }
    // for(auto i : v) cout << i << ' ';
    // cout << '\n';
    // There exist a global map for storing the values at index and a global vector for 
    //storing which values are altered in a session
    ll fg=0;// if fg=0 means so session has started only original array is altered
    
    while(q--){
        ll t,id,x; cin >> t ;
        if(t==2){
            //cout << "aq" << '\n';
            cin >> x;
            fg=x;
            clear();// for  clearing the op vector and reverting all the values of map to 0 
            //to indicate that index is not aletred in the new session 
            sum = x * n;
            cout << sum << '\n';
        }
        else if(t==1 && fg){
            //cout << "hy" << '\n';
            cin >> id >> x;
            id--; // one based id
            if(mp[id]==0) {// means in the current session this index is not altered
                sum = sum + x - fg;
                mp[id]=x;
                op.push_back(id);
            }
            else {
                sum = sum + x - mp[id];
                mp[id] = x;
            }
            cout << sum << '\n';
        }
        else{
            //cout << "oi" <<" " <<  sum <<  '\n';
            cin >> id >> x;
            id--; // one based id
            //cout << sum + x - v[id] << '\n' ;

            if(mp[id]==0)
            {sum =  sum + x - v[id];
            op.push_back(id);// save in op vector for record that this id is altered
            mp[id] = x;}

            else{
                sum = sum + x - mp[id];
                mp[id]=x;
            }
            cout << sum << '\n';
        }
    }


    return 0;
}