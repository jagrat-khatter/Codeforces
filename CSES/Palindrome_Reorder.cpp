#include <bits/stdc++.h>
using namespace std;
using ll = long long ;
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    map<char , ll> mp;
    string s;
    cin >> s;
    ll n = s.size();
    for(ll i=0;i<n;i++)
    {
        mp[s[i]]++;
    }
    // now going through each and every capital letter if more than one letter has frequency odd then 
    // palindrome can not be made
    ll fg=0; string ans="";
    for(ll i=65;i<=90;i++)
    {
        char x = (char)(i);
        if(mp[x]%2 !=0) fg++;       // frequency of letter is odd
    }

    if(fg>1) cout << "NO SOLUTION" ;
    else       // in this block it is sure that there is one or zero element which has odd ferquency
    {
        char z ;fg=0;
        for(ll i=65;i<=90;i++)
        {
            char x = (char)(i);
            if(mp[x]%2 ==0)
            {
                ll n = mp[x];
                for(ll i=1;i<=(n)/2;i++)
                {
                    ans += x;
                }
            }
            else{
                fg=1;
                z = x;
            }
        }
        string rev_ans = ans ;
        reverse(rev_ans.begin() , rev_ans.end()) ;
        if(fg==0) {
            ans = ans + rev_ans;
        }
        else {ans = ans ;
            for(ll i=1;i<=mp[z];i++)
            {
                ans += z;
            }
            ans += rev_ans;}

        cout << ans ;
        
    }


    return 0;
}