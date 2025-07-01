#include <iostream>
#include <vector>
#include <algorithm>
 
using namespace std;
 
bool canSplit(const vector<int> &a, int k, int target) {
	int n = a.size();
	int segments = 0;
	vector<int> count(target, 0);
	int mexValue = 0;
	for (int i = 0; i < n; ++i) {
		if (a[i] < target) {
			count[a[i]]++;
			while (mexValue < target && count[mexValue] > 0) {
				mexValue++;
			}
		}
		if (mexValue == target) {
			segments++;
			fill(count.begin(), count.end(), 0);
			mexValue = 0;
		}
	}
	return segments >= k;
}
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

	int t;
	cin >> t;
 
	while (t--) {
		int n, k;
		cin >> n >> k;
 
		vector<int> a(n);
		for (int i = 0; i < n; ++i) {
			cin >> a[i];
		}
 
		int left = 0, right = n + 1;
		int result = 0;
		while (left < right) {
			int mid = left + (right - left + 1) / 2;
			if (canSplit(a, k, mid)) {
				result = mid;
				left = mid;
			} else {
				right = mid - 1;
			}
		}
 
		cout << result << '\n';
	}
 
	return 0;
}