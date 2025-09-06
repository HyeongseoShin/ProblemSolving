#include <bits/stdc++.h>

using namespace std;

int n;
int from, to;

bool isPrime[10001];
int dist[10001];

void BFS()
{
    memset(dist, -1, sizeof(dist));

    queue<int> q;
    q.push(from);
    dist[from] = 0;

    while(!q.empty())
    {
        int cur = q.front();
        q.pop();

        if(cur == to) return;
        
        int mul = 1;
        int div = 10;
        for(int i = 0; i < 4; i++)
        { 
            int tmp1 = cur % div;
            int tmp2 = cur - tmp1;
            int tmp3 = tmp2 + tmp1 % mul;
            int nxt = 0;

            // cout << "cur: " << cur << " tmp1: " << tmp1 << " tmp2: " << tmp2 << " tmp3: " << tmp3 << "\n";
            for(int j = 0; j < 10; j++)
            {
                nxt = tmp3 + j * mul;
                
                if(nxt < 1000 || nxt > 9999) continue;
                if(cur == nxt) continue;
                if(!isPrime[nxt]) continue;
                if(dist[nxt] != -1) continue;

                dist[nxt] = dist[cur] + 1;
                q.push(nxt);
            }

            div *= 10;
            mul *= 10;
        }
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    // 소수 판별
    fill(isPrime, isPrime + 10001, true);
    isPrime[0] = false;
    isPrime[1] = false;

    for(int i = 2; i * i <= 9999; i++)
    {
        if(!isPrime[i]) continue;

        for(int j = i + i; j <= 9999; j += i)
        {
            isPrime[j] = false;
        }
    }

    cin >> n;

    while(n--)
    {
        cin >> from >> to;

        BFS();
        cout << dist[to] << "\n";
    }

    return 0;
}