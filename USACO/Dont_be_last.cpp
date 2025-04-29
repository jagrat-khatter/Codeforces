#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll lmin = LLONG_MIN;
const ll lmax = LLONG_MAX;
bool special(pair<string , ll> a,pair<string , ll> b)
{
    return a.second<b.second ;
}
signed main()
{
    ifstream fin("notlast.in");
    ofstream fout("notlast.out");

    ios::sync_with_stdio(false);
    cin.tie(NULL);

    ll n ; fin >> n;
    map<string , ll> mp ;
    while(n--)
    {
        string s; fin >> s;
        ll p ; fin >> p;
        mp[s] += p;
    }

    vector<pair<string , ll>> p;
    p.push_back({"Bessie" , mp["Bessie"]});
    p.push_back({"Gertie" , mp["Gertie"]});
    p.push_back({"Annabelle" , mp["Annabelle"]});
    p.push_back({"Elsie" , mp["Elsie"]});
    p.push_back({"Daisy" , mp["Daisy"]});
    p.push_back({"Maggie" , mp["Maggie"]});
    p.push_back({"Henrietta" , mp["Henrietta"]});
    sort(p.begin() , p.end() , special);
    ll lp = p[0].second; // this is east production
    ll fg=0;
    string ans;
    for(ll i=1;i<7;i++)
    {
        if(p[i].second>lp) {
            if(i==6 || p[i].second!=p[i+1].second){ // means tie is not happening
                fout << p[i].first  << '\n';fg=1; break;
            }
            else break; // if there are two or more candiadates for second position then exit
        }
    }
    if(fg==0) fout << "Tie" << '\n';

    return 0;
}