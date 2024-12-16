/*
완전탐색 / 브루트포스 / 백트래킹
스스로 못 풀었음
*/
#include <bits/stdc++.h>

using namespace std;

int grid[10][10];
vector<int> papers = {5, 5, 5, 5, 5}; // 1x1 ~ 5x5 색종이 개수 5장씩
int ans = 100;

// (x,y)에서 sz크기의 색종이를 붙일 수 있는가?
bool CanAttach(int x, int y, int sz)
{
    for(int i = 0; i <= sz; i++)
    {
        for(int j = 0; j <= sz; j++)
        {
            if(grid[x+i][y+j] == 0) return false;
        }
    }

    return true;
}

// 색종이를 붙이거나 원상복구 시키는 함수
void Fill(int x, int y, int sz, int val)
{
    for(int i = 0; i <= sz; i++)
    {
        for(int j = 0; j <= sz; j++)
        {
            grid[x+i][y+j] = val;
        }
    }
}

// 모든 곳에 색종이가 붙어있는지 확인하는 함수
bool CheckAllFill()
{
    for(int i = 0; i < 10; i++)
    {
        for(int j = 0; j < 10; j++)
        {
            if(grid[i][j] == 1) return false;
        }
    }

    return true;
}

bool CheckRange(int x, int y)
{
    if(x < 10 && y < 10) return true;

    return false;
}

// cnt: 현재 색종이 개수
void Recursion(int cnt)
{
    // 현재 붙어있는 색종이가 최소 색종이 개수보다 크면 더 이상 돌 필요 없음
    if(ans < cnt)
    {
        return;
    }
    // 모든 곳에 색종이가 붙어있으면 ans 업데이트 이후 종료
    if(CheckAllFill())
    {
        ans = min(ans, cnt);
        return;
    }

    for(int i = 0; i < 10; i++)
    {
        for(int j = 0; j < 10; j++)
        {
            if(grid[i][j] == 1) // 1이면 색종이 붙일 수 있는지 테스트 시작
            {
                for(int sz = 4; sz >= 0; sz--) // 5x5 ~ 1x1까지 테스트
                {
                    if(papers[sz] > 0 && CanAttach(i, j, sz) && CheckRange(i+sz, j+sz))
                    {
                        papers[sz]--;

                        // cout << "시작지점: (" << i << ", " << j << ") 크기: " << sz << "\n"; 

                        Fill(i, j, sz, 0); // 색종이를 붙인다.

                        Recursion(cnt+1);

                        papers[sz]++;

                        Fill(i, j, sz, 1); // 원상복구 시킨다.
                    }
                }
                return; // (i,j) 한 지점에서만 색종이 붙일 수 있는지 / 없는지 테스트하면 되기 때문에 나머지 반복문 돌 필요 없음
            }

            
        }
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    for(int i = 0; i < 10; i++)
    {
        for(int j = 0; j < 10; j++)
        {
            cin >> grid[i][j];
        }
    }

    Recursion(0);
    
    ans = (ans == 100) ? -1 : ans;

    cout << ans << "\n";

    return 0;
}