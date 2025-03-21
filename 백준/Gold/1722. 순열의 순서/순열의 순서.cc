#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int n, type;

ll k;

// 미리 팩토리얼 저장
ll fact[21];

bool check[21]; // 1 ~ n 숫자 중 현재 순열에 있는지 없는지 확인

vector<int> v;

ll ans = 0;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    fact[0] = 1;
    for(int i = 1; i < 21; i++)
    {
        fact[i] = fact[i-1] * i;
    }

    cin >> n;

    cin >> type;

    // k번째 순열 출력
    if(type == 1)
    {
        cin >> k;

        v.resize(n);

        for(int i = 0; i < n; i++)
        {
            for(int j = 1; j <= n; j++)
            {
                // 이미 존재하는 값이면 Pass
                if(check[j]) continue;

                if(fact[n - i - 1] < k) k -= fact[n - i - 1];
                
                else
                {
                    v[i] = j;
                    check[j] = true;
                    break;
                }
            }
        }

        for(int i = 0; i < n; i++)
        {
            cout << v[i] << " ";
        }
        cout << "\n";
    }

   

    // 해당 순열이 몇 번째인지 출력
    else
    {
        for(int i = 0; i < n; i++)
        {
            int x;
            cin >> x;

            v.push_back(x);
        }

        for(int i = 0; i < n; i++)
        {
            for(int j = 1; j < v[i]; j++)
            {
                if(!check[j]) ans += fact[n - i - 1];
            }

            check[v[i]] = true;
        }

        cout << ans + 1 << "\n";
    }


    return 0;
}