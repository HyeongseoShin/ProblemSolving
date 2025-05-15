#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define MAX 10000001

ll n;

bool isNotPrime[MAX];

vector<int> primeNums;
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int testCase;
	cin >> testCase;

	// 소수 구해서 primeNums에 저장
	for (int i = 2; i <= sqrt(MAX); i++)
	{
		if (isNotPrime[i]) continue;
		primeNums.push_back(i);

		for (int j = i + i; j <= MAX; j += i)
		{
			isNotPrime[j] = true;
		}
	}

	for (int t = 1; t <= testCase; t++)
	{
		cin >> n;

		int idx = 0;
		int ans = 1;
		int cnt = 0;

		// 소수로 소인수분해 진행
		while (n > 0)
		{
			if (n % primeNums[idx] == 0)
			{
				cnt++;
				n /= primeNums[idx];
			}

			else
			{
				if (cnt % 2 != 0) ans *= primeNums[idx];

				// n이 소수이면 끝
				if (!isNotPrime[n])
				{
					ans *= n;
					break;
				}

				idx++;

				// 모든 소수를 다 순회했으면 끝
				if (idx == (int)primeNums.size())
				{
					ans *= n;
					break;
				}
				cnt = 0;
			}
		}

		cout << "#" << t << " " << ans << "\n";

		
	}
	return 0;
}