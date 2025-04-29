
#include <bits/stdc++.h>
using namespace std;
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n,fg=0;
    cin >> n;

    vector<char> arr(n);
    for(int i=0;i<n;i++)
    {
        cin >> arr[i];
        
        if(i>=1 && arr[i-1]>arr[i])
        {
            cout << "YES" << '\n';
            cout << i << ' ' << i+1 << '\n'; fg=1;
            break;
        }
    }
    if(!fg) cout << "NO" ;

    return 0;
}