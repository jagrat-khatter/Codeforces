#include <bits/stdc++.h>
using namespace std;
using ll = long long ;
ll fact(ll n)
{
    if(n==1) return 1;
    
    return n*fact(n-1) ;
}
ll power(ll b , ll e)
{
    if(e==1) return b;
    ll value = power(b , e/2) ;

    if(e%2==0) return value*value ;
    else return value * value * b ;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    ll t; cin >> t;
    while(t--)
    {
        string s1,s2;
        cin >> s1>> s2 ;

        ll f1=0,f2=0; // if string t contains 'a' element;

        for(ll i=0;i<s2.size();i++)
        {
            if(s2[i]=='a') {
                f1=1; break; 
            }
        }

        if(f1==1 && s2.size()==1) cout << 1<< '\n' ;  // when there is only a element in the string t
        else if(f1==1 && s2.size()>1) cout << -1 << '\n' ;
        else cout << power( 2, s1.size()) << '\n' ;
    }

}