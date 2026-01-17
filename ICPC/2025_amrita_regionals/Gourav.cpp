#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin >> n;
    vector<vector<int>> edges(n + 1,vector<int>());
    for(int i=0;i<n - 1;i++){
       int u,v;
       cin >> u >> v;
       edges[u].push_back(v);
       edges[v].push_back(u); 
    }
    vector<int> have(n + 1,0);
    auto dfs = [&](int curr, int parent, auto &&dfs) -> void{
        have[curr] = curr;
        for(auto it:edges[curr]){
           if(it != parent){
             dfs(it,curr,dfs);
             have[curr] += have[it];
           } 
        }
    };
    dfs(1,0,dfs);
    for(auto it:have){
       cout << it << " "; 
    }
    cout << endl;
    long long ans = 0;
    auto dfs1 = [&](int curr, int parent, auto &&dfs1) -> void{
        if(curr != 1){
          long long val1 = have[curr];
          long long val2 = (n * (n + 1LL) / 2LL) - val1;
          ans = max(ans,val1 * 1LL * val2);  
        }
        for(auto it:edges[curr]){
           if(it != parent){
             dfs1(it,curr,dfs1);
           } 
        }
    };
    dfs1(1,0,dfs1);
    cout << ans << endl;
    return 0;
}