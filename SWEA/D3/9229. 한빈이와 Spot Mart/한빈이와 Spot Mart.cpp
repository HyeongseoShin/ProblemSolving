#include <bits/stdc++.h>

using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int testCase;
	cin >> testCase;

	for (int t = 1; t <= testCase; t++)
	{
		int n, m;
		cin >> n >> m;

		vector<int> snacks;

		for (int i = 0; i < n; i++)
		{
			int x;
			cin >> x;
			
			snacks.push_back(x);
		}

		sort(snacks.begin(), snacks.end());

		int ans = 0;

		for (int l = 0; l < n; l++)
		{
			int r = n - 1;

			while (snacks[l] + snacks[r] > m && l < r) r--;
			
			if (l >= r) continue;
			ans = max(ans, snacks[l] + snacks[r]);
		}

		if (ans == 0) ans = -1;

		cout << "#" << t << " " << ans << "\n";
	}
	return 0;
}