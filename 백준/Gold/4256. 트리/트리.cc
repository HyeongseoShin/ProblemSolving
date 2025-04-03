#include <bits/stdc++.h>

using namespace std;

int t;
int n;

vector<int> preOrder;
vector<int> inOrder;

// 왼 - 오 - root
// (inOrder 시작, inOrder 끝, Pre에서 현재 root)
void postOrder (int st, int en, int pos)
{
    for(int i = st; i < en; i++)
    {
        // inOrder에서 현재 root를 찾고 좌 - 우로 분할 정복
        if(inOrder[i] == preOrder[pos])
        {
            // 왼쪽
            postOrder(st, i, pos + 1);
            // 오른쪽
            postOrder(i + 1, en, pos + 1 + i - st);

            // root
            cout << preOrder[pos] << " ";
        }
    }
    
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> t;

    while(t--)
    {
        cin >> n;

        // preOrder[0] : root
        preOrder.resize(n);
        for(int i = 0; i < n; i++)
        {
            cin >> preOrder[i];
        }

        // inOrder에서 root를 기준으로 왼쪽 Subtree, 오른쪽 Subtree로 나눌 수 있음
        inOrder.resize(n);
        for(int i = 0; i < n; i++)
        {
            cin >> inOrder[i];
        }

        // (inOrder 시작, inOrder 끝, Pre에서 현재 root)
        postOrder(0, n, 0);
        cout << "\n";
    }

    return 0;
}