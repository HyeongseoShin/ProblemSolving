#include <bits/stdc++.h>

using namespace std;

int n;
int cnt;

int status[105];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    for(int i = 1; i <= n; i++)
    {
        cin >> status[i];
    }

    cin >> cnt;

    while(cnt--)
    {
        int gender, num;

        cin >> gender >> num;

        // 남자이면 자신의 배수 전부 상태 바꾸기
        if(gender == 1)
        {
            for(int i = num; i <= n; i += num)
            {
                status[i] = (1 - status[i]);
            }
        }

        // 여자면 투포인터로 대칭인지 검사
        else
        {
            int st = num;
            int en = num;

            while(st >= 1 && en <= n && status[st] == status[en])
            {
                st--;
                en++;
            }

            for(int i = st+1; i <= en-1; i++)
            {
                status[i] = (1 - status[i]);
            }
        }
    }

    for(int i = 1; i <= n; i++)
    {
        cout << status[i] << " ";
        if(i % 20 == 0) cout << "\n";
    }
    cout << "\n";

    return 0;
}