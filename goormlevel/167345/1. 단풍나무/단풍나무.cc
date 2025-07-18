#include <bits/stdc++.h>

using namespace std;

int n;
int board[41][41];
int cnt;
int ans = 0;

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

int main() {

	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;	
	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < n; j++)
		{
			cin >> board[i][j];
			if(board[i][j] > 0) cnt++;
		}
	}

	while(cnt > 0)
	{
		int tmp[41][41];
		memcpy(tmp, board, sizeof(board));

		for(int i = 0; i < n; i++)
		{
			for(int j = 0; j < n; j++)
			{
				if(board[i][j] <= 0) continue;

				int zeroCnt = 0;
				for(int dir = 0; dir < 4; dir++)
				{
					int nX = i + dx[dir];
					int nY = j + dy[dir];

					if(nX < 0 || nX >= n || nY < 0 || nY >= n) continue;
					if(tmp[nX][nY] > 0) continue;

					zeroCnt++;
				}

				board[i][j] -= zeroCnt;
				if(board[i][j] <= 0)
				{
					board[i][j] = 0;
					cnt--;
				}
			}
		}

		ans++;
		
	}

	
	

	cout << ans << "\n";
	return 0;
}