#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll lmax = LLONG_MAX;
const ll lmin = LLONG_MIN;
bool palindrome(vector<ll> &v)
{
    ll l=0 , r=v.size()-1;
    while(l<=r)
    {
        if(v[l]!=v[r]) return false;
        l++;
        r--;
    }
    return true;
}
// If you can make an array palidrome by choosing some element x and removing some of x elements in the 
// array this means that you can make that array palindrome by removing all x also, bcoz if an array is 
// a palindrome removing all the presence of a particular element will maintain array as palindrome
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    ll t; cin >> t;
    while(t--)
    {
        ll n; cin >> n;
        vector<ll> v;
        for(ll i=0;i<n;i++){
            ll x; cin >> x ; v.push_back(x);
        }
        ll l=0 , r=v.size()-1;
        ll e1=0,e2=0; // if conflict arises then these elements will not be zero
        while(l<=r)
        {
            if(v[l]!=v[r]){
                e1=v[l];
                e2=v[r];
                break;
            }
            l++;
            r--;
        }
        if(e1 && e2){
            // make a vector without e1 and make a vector without e2
            vector<ll> a1,a2;
            for(ll i=0;i<n;i++)
            {
                if(v[i] != e1) a1.push_back(v[i]);
                if(v[i] != e2) a2.push_back(v[i]);
            }
            if(palindrome(a1) || palindrome(a2)) cout << "YES" << '\n';
            else cout << "NO" << '\n';
        }
        else {
            cout << "YES" << '\n'; // It is a palindrome
        }
    }


    return 0;
}