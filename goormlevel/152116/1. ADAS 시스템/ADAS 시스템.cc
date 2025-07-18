#include <bits/stdc++.h>

using namespace std;

// 상, 하, 좌, 우
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

// E : 0, P : 1, S : 2, 일반 : 3
int board[1001][1001];
bool vis[1001][1001];

int w, h;

int sX, sY;

int countP(int x, int y)
{
	int pCnt = 0;
	for(int i = -1; i <= 1; i++)
	{
		for(int j = -1; j <= 1; j++)
		{
			int nX = x + i;
			int nY = y + j;

			if(nX < 0 || nX >= w || nY < 0 || nY >= h) continue;
			if(nX == x && nY == y) continue;

			if(board[nX][nY] == 1) pCnt++;
		}
	}

	return pCnt;
}

int BFS(int x, int y)
{
	priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<>> pq;
	
	int ans = 0;
	
	pq.push({board[x][y], x, y});
	vis[x][y] = true;

	while(!pq.empty())
	{
		auto [curVal, curX, curY] = pq.top();
		pq.pop();

		// 도착점 도착 시 끝
		if(curVal == 0) return ans;

		int score = 0;
		
		for(int i = 0; i < 4; i++)
		{
			int nX = curX + dx[i];
			int nY = curY + dy[i];

			if(nX < 0 || nX >= w || nY < 0 || nY >= h) continue;
			if(vis[nX][nY]) continue;
			
			vis[nX][nY] = true;
			pq.push({board[nX][nY], nX, nY});
		}

		if(curVal != 2) ans += countP(curX, curY);
		
		// 현재 P인 경우 -3점
		if(board[curX][curY] == 1) ans -= 3;
	}


	return ans;
}

int main() {
	
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> w >> h;

	for(int i = 0; i < w; i++)
	{
		string s;
		cin >> s;
		for(int j = 0; j < h; j++)
		{
			if(s[j] == 'E')
			{
				board[i][j] = 0;
			}

			else if(s[j] == 'P')
			{
				board[i][j] = 1;
			}

			else if(s[j] == 'S')
			{
				sX = i;
				sY = j;

				board[i][j] = 2;
			}

			else board[i][j] = 3;
		}
	}

	int result = BFS(sX, sY);

	if(result < 0) result = 0;
	cout << result << "\n";
	
	return 0;
}