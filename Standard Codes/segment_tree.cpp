#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
const ll lmin = LLONG_MIN;
const ll lmax = LLONG_MAX;
const ll imin = INT_MIN;
const ll imax = INT_MAX;
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
    cerr << "[ " ;
    for(auto &i : v) cerr << i << ' ';
    cerr << "] \n" ;
    return ;
}
vector<ll> segTree;
void build(vector<ll>& arr,ll start,ll end,ll index){ // build the segment tree
    // start and end refer to the starting and ending point of array

    // the array can be in 1 based indexing and in 0 based indexing does not make code wrong
    // if you are using one based in segTree
    
    // TC : O(n)
    // n + n/2 + n/4 .... 1 = 2n-1(if n is in power of 2)

    if(start==end){
        segTree[index] = arr[start];
        return ;
    }
    ll mid = (start + end) / 2;
    ll left = 2 * index , right = (2 * index) + 1;
    build(arr, start, mid, left);// do down left
    build(arr, mid+1, end, right);// go down right
    segTree[index] = segTree[left] + segTree[right];

    return ;
}
void update(vector<ll>& arr,ll start,ll end,ll index,ll pos,ll value){ // update at a given point in segment tree
    if(start == end){
        arr[pos] = value;
        segTree[index] = arr[pos];
        return ;
    }
    
    ll mid = (start + end) / 2;
    ll left = 2 * index , right = (2 * index) + 1;
    
    if(pos <= mid) update(arr, start, mid, left, pos, value);
    else update(arr, mid+1, end, right, pos, value);
    segTree[index] = segTree[left] + segTree[right];
}
ll query(ll start,ll end,ll index,ll l,ll r){// give sum from L to R
    // this will return sum of values in range l to r if elements are defined from start to end
    // if there is partial overlap between (l,r) and (start,end) only the values that intersect
    // in both the ranges only their sum will be given

    // complete overlap 
    if((l <= start) && (end <= r)) return segTree[index];
    // disjoint
    if(l > end || r < start) return 0;
    
    // partial overlap -> return something from left and something from right
    ll mid = (start + end)/2;
    ll left = 2*index , right = 2*index + 1;
    ll leftAnswer = query(start, mid, left, l, r);
    ll rightAnswer = query(mid+1, end, right, l, r);
    return leftAnswer + rightAnswer ;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    ll n; cin >> n;
    segTree.resize(2*n); // in segment tree 1 ... 2n-1 indices are required 
    vector<ll> arr(n);
    for(auto &i : arr) cin >> i;
    build(arr, 0, n-1, 1);

    debug(arr); 
    debug(segTree) ;

    // we are following one based indxing in segmentTree and 0 based indexing in arr
    cout << query(0 ,n-1, 1, 1 , 3) << endl;

    update( arr, 0, n-1, 1, 3, 6);
    debug(arr);
    debug(segTree);







    return 0;
}