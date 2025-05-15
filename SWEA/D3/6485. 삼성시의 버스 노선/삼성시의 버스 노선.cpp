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

		int A[501];
		int B[501];

		int bus[5001];
		fill(bus, bus + 5001, 0);

		for (int i = 0; i < n; i++)
		{
			cin >> A[i] >> B[i];

			for (int j = A[i]; j <= B[i]; j++)
			{
				bus[j]++;
			}
		}

		int p;
		cin >> p;

		cout << "#" << t << " ";
		for (int i = 0; i < p; i++)
		{
			int x;
			cin >> x;

			cout << bus[x] << " ";
		}
		cout << "\n";

	}

	return 0;
}