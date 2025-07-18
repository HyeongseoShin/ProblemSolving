#include <bits/stdc++.h>

using namespace std;

// 개미 집합의 지름 = 임의의 두 개미 사이의 거리 중 가장 긴 거리
// 개미 집합 지름을 D 이하로 만들기 위해 제거해야하는 개미의 최소 수

// 1 <= n <= 10만
// 0 <= d <= 100만
// 1 <= Pi (개미 좌표) <= 100만

// 6 // 3
// 1 6 4 3 9 10
int n, d;

vector<int> p;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> d;

	for(int i = 0; i < n; i++)
	{
		int x;
		cin >> x;

		p.push_back(x);
	}

	sort(p.begin(), p.end());
	
	int l = 0;
	int r = 1;

	int ans = INT_MAX;
	
	while(r < n && l <= r)
	{
		if(p[r] - p[l] <= d)
		{
			ans = min(ans, n - (r - l + 1));
			r++;
		}
		else l++;
	}

	cout << ans << "\n";
	
	return 0;
}