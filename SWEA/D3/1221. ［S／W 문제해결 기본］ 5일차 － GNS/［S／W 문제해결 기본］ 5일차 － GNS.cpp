#include <bits/stdc++.h>

using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int testCase;
	cin >> testCase;

	string order[10] = { "ZRO", "ONE", "TWO", "THR", "FOR", "FIV", "SIX", "SVN", "EGT", "NIN" };

	for (int t = 1; t <= testCase; t++)
	{
		string op;
		cin >> op;

		int n;
		cin >> n;

		vector<string> v;

		int cnt[10];
		fill(cnt, cnt + 10, 0);

		for (int i = 0; i < n; i++)
		{
			string s;
			cin >> s;
			
			for (int j = 0; j < 10; j++)
			{
				if (s == order[j]) cnt[j]++;
			}
		}

		cout << op << " ";
		for(int i = 0; i < 10; i++)
		{
			for (int j = 0; j < cnt[i]; j++)
			{
				cout << order[i] << " ";
			}
		}
		cout << "\n";

	}
	return 0;
}