// https://www.acmicpc.net/problem/1205

#include <bits/stdc++.h>

using namespace std;

int n, score, p;

int minScore = 2000000000;

priority_queue<int> pq;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> score >> p;

    while(n--)
    {
        int x;

        cin >> x;

        minScore = min(minScore, x);
        pq.push(x);
    }

    if(pq.size() < p || (pq.size() == p && minScore < score))
    {
        pq.push(score);
    }
    else
    {
        cout << "-1\n";
        return 0;
    }

    int rank = 1;

    while(!pq.empty())
    {
        int cur = pq.top();
        pq.pop();

        if(cur == score) break;

        rank++;
    }

    cout << rank << "\n";

    return 0;
}