//https://swexpertacademy.com/main/code/problem/problemDetail.do?problemLevel=3&contestProbId=AW8Wj7cqbY0DFAXN&categoryId=AW8Wj7cqbY0DFAXN&categoryType=CODE&problemTitle=&orderBy=RECOMMEND_COUNT&selectCodeLang=ALL&select-1=3&pageSize=10&pageIndex=5

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

		sort(snacks.begin(), snacks.end(), greater<>());

		int ans = 0;

		for (int i = 0; i < n; i++)
		{
			for (int j = i + 1; j < n; j++)
			{
				if (snacks[i] + snacks[j] <= m)
				{
					ans = max(ans, snacks[i] + snacks[j]);
				}
			}
		}

		if (ans == 0) ans = -1;

		cout << "#" << t << " " << ans << "\n";
	}
	return 0;
}