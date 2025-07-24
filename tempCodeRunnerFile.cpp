#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t; 
    
    while (t--) {
        int n;
        cin >> n; 
        
        string s;
        cin >> s; 
        
        bool isGood = true;
        
       
        for (int i = 0; i < n - 1; ++i) {
            if (s[i] == '1' && s[i + 1] == '1') {
                isGood = false;
                break;
            }
        }
        
        
        if (isGood) {
            cout << "Yes" << '\n';
        } else {
            cout << "No" << '\n';
        }
    }
    
     return 0;
}