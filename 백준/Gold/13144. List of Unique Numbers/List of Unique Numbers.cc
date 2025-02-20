#include <bits/stdc++.h>

using namespace std;

int n;
int arr[100005];
bool check[100005];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    for(int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    int en = 0;
    long long cnt = 0;

    for(int st = 0; st < n; st++)
    {
        // 현재 원소가 처음 나오는 원소라면
        while(en < n && !check[arr[en]])
        {
            check[arr[en]] = true;
            en++;
        }
        
        cnt = cnt + en - st;

        // st원소 지우기
        check[arr[st]] = false;
    }

    cout << cnt << "\n";

    return 0;
}