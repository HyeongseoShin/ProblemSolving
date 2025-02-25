#include <bits/stdc++.h>

using namespace std;

int n, a, b;

deque<int> dq;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> a >> b;

    if(a + b > n + 1)
    {
        cout << "-1\n";
        return 0;
    }

    // 1 ~ (a - 1) 까지 순차적으로 삽입
    for(int i = 1; i < a; i++)
    {
        dq.push_back(i);        
    }

    dq.push_back(max(a, b)); // a, b 중 더 큰 값을 공통으로 볼 수 있는 가장 높은 빌딩으로 설정

    // (b - 1) ~ 1까지 순차적으로 삽입
    for(int i = b - 1; i >= 1; i--)
    {
        dq.push_back(i);
    }

    // a가 1인 경우 두 번째 자리부터 push_front(1) 해야하기 때문에 front 빼서 저장해놓기
    int minH = dq.front();
    dq.pop_front();

    while(dq.size() < n - 1)
    {
        dq.push_front(1);
    }

    dq.push_front(minH);

    while(!dq.empty())
    {
        cout << dq.front() << " ";
        dq.pop_front();
    }
    cout << "\n";

    return 0;
}