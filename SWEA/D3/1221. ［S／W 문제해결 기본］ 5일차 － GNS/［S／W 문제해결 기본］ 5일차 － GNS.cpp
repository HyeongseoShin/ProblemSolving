#include <bits/stdc++.h>

using namespace std;

unordered_map<string, int> um;

bool cmp(string A, string B)
{
	return um[A] < um[B];
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int testCase;
	cin >> testCase;

	um["ZRO"] = 0;
	um["ONE"] = 1;
	um["TWO"] = 2;
	um["THR"] = 3;
	um["FOR"] = 4;
	um["FIV"] = 5;
	um["SIX"] = 6;
	um["SVN"] = 7;
	um["EGT"] = 8;
	um["NIN"] = 9;

	for (int t = 1; t <= testCase; t++)
	{
		string op;
		cin >> op;

		int n;
		cin >> n;

		vector<string> v;

		for (int i = 0; i < n; i++)
		{
			string s;
			cin >> s;
			v.push_back(s);
		}

		sort(v.begin(), v.end(), cmp);

		cout << op << " ";
		for (auto word : v)
		{
			cout << word << " ";
		}
		cout << "\n";
	}
	return 0;
}