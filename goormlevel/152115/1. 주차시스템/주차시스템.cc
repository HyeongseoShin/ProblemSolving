#include <bits/stdc++.h>

using namespace std;

// 0 자동차 없음
// 1 자동차 있음
// 2 자동차 없지만 장애인 전용 주차장

// 주차장의 상태를 여러 개의 구역으로 분리
// 같은 구역에 속한 두 주차 칸 사이 - 항상 상태가 1인 칸을 거치지 않고 이동하는 경로 존재

// 서로 다른 구역에 속한 두 주차 칸 사이에는 그런 경로 존재하지 않도록 주차 구역 나눔

// 각 분할 구역의 주차 분류 상태에 따라서 점수 측정
// 0의 개수 +1
// 2의 개수 -2

// 이 중 가장 점수가 높은 구역으로 차를 안내함

// 점수가 가장 높은 주차 구역의 점수 구하기

// 주차 구역이 존재하지 않거나 음수인 경우 0 출력

int parking[2001][2001];

int ans = INT_MIN;
int n, m;

bool vis[2001][2001];

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

void BFS(int x, int y)
{
	int score = 0;
	
	queue<pair<int, int>> q;
	q.push({x, y});

	vis[x][y] = true;

	if(parking[x][y] == 0) score++;
	else if(parking[x][y] == 2) score -= 2;

	while(!q.empty())
	{
		auto [curX, curY] = q.front();
		q.pop();

		for(int i = 0; i < 4; i++)
		{
			int nX = curX + dx[i];
			int nY = curY + dy[i];

			if(nX < 0 || nX >= n || nY < 0 || nY >= m) continue;
			if(parking[nX][nY] == 1) continue;
			if(vis[nX][nY]) continue;

			if(parking[nX][nY] == 0) score++;
			else if(parking[nX][nY] == 2) score -= 2;
			
			vis[nX][nY] = true;
			q.push({nX, nY});
		}
	}

	// cout << "ans: " << ans << " score: " << score << "\n";
	ans = max(ans, score);
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;

	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < m; j++)
		{
			cin >> parking[i][j];
		}
	}

	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < m; j++)
		{
			if(parking[i][j] != 1 && !vis[i][j])
			{
				// cout << "i: " << i << " j: " << j << "\n";
				BFS(i, j);
			}
		}
	}

	if(ans < 0) ans = 0;
	cout << ans << "\n";
	
	return 0;
}