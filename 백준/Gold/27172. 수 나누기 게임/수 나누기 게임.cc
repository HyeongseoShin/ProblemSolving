#include <bits/stdc++.h>

using namespace std;

#define MAX 100001
#define NUM_MAX 1000001
int x[MAX];
int scores[MAX];

// check[i] : i를 갖고 있는 플레이어 번호 저장
int check[NUM_MAX];

int n;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    fill(check, check + NUM_MAX, -1);
    for(int i = 0; i < n; i++)
    {
        cin >> x[i];
        check[x[i]] = i;
    }

    for(int i = 0; i < n; i++)
    {
        for(int j = x[i] + x[i]; j < NUM_MAX; j += x[i])
        {
            if(check[j] != -1)
            {
                scores[i]++;
                scores[check[j]]--;
            }
        }
    }

    for(int i = 0; i < n; i++)
    {
        cout << scores[i] << " ";
    }
    cout << "\n";

    return 0;
}