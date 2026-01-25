#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
const ll lmin = LLONG_MIN;
const ll lmax = LLONG_MAX;
const ll imin = INT_MIN;
const ll imax = INT_MAX;
const ll MOD = 1e9 + 7;
ll power(ll b,ll e){
    if(e==0) return 1;
    ll value = power(b , e/2);
    return value*value*((e%2==0) ? 1 : b);
}
ll gcd(ll a,ll b){
    if(b==0) return a;
    else return gcd(b , a%b);
}
void debug(const vector<ll>& v){
    cerr << "[ ";
    for(auto j : v) cerr << j << ' ';
    cerr << "]\n";
    return ;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    ll n,k ; cin >> n >> k;
    string s; cin >> s;

    string news=""; // best prefix 
    news += s[0];
    ll ptr=1 , status=0;
    while(news.size()<s.size() && !status){
        ll tp = ptr%(s.size()); 
        if(s[tp]<s[0])  {news+=s[tp] ; ptr++;}
        else if(s[tp]>s[0]) break;
        else {
            //cout << "h" << '\n';
            ll p2=0 , ptrc=ptr;
            ll verdict = 0;
            while(p2<news.size()){
                
                tp = ptr%(s.size()); 
                //cout << tp << ' ' << p2 << '\n' ;
                if(s[tp]==news[p2]) {ptr++;p2++;}
                else if(s[tp]>news[p2]) {verdict=1;break;}
                else {verdict=2; break;}
            }

            //cout << ptr << ' ' << verdict << ' ' << news<<'\n' ;
            if(verdict==0){// means the further parts is same as news
                for(ll j=ptrc;j<min(ptr,ll(s.size()-1));j++){
                    tp = j%(s.size());
                    news += s[j];
                }
            }
            else if(verdict==1){// means further part is greater than news
                // news remain news and this is final answer
                status=1;
            }
            else if(verdict==2){// means further part is less than news
                for(ll j=ptrc;j<=min(ptr,ll(s.size()-1));j++){
                    tp = j%(s.size());
                    news += s[j];
                }
            }
            if(verdict!=0) ptr++;
        }

    }

    //cout << news << '\n' ;
    ll mul = k/(news.size());
    ll rem = k%(news.size());
    string ans = "";
    for(ll i=1;i<=mul;i++){
        ans += news;
    }
    for(ll i=0;i<rem;i++){
        ans += news[i];
    }

    cout << ans << '\n' ;




    return 0;
}