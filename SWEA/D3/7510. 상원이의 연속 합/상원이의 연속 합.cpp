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
		int n;
		cin >> n;

		int st = 1;
		int en = 1;

		int sum = 0;
		int ans = 1;

		while (st <= en && en < n)
		{
			if (sum <= n)
			{
				if (sum == n) ans++;
				sum += en;
				en++;

			}
			
			else
			{
				sum -= st;
				st++;
			}

		}

		cout << "#" << t << " " << ans << "\n";

	}

	return 0;
}