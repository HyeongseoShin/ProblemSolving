#include <bits/stdc++.h>

using namespace std;

int bst[10001];

void postOrder(int st, int en)
{
    if(st >= en) return;
    if(st == en - 1)
    {
        cout << bst[st] << "\n";
        return;
    }

    int idx = st + 1;

    while(idx < en)
    {
        if(bst[st] < bst[idx]) break;
        idx++;
    }

    postOrder(st + 1, idx);
    postOrder(idx, en);

    cout << bst[st] << "\n";

}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int x;
    int idx = 0;
    while(cin >> x)
    {
        bst[idx++] = x;
    }

    postOrder(0, idx);

    return 0;
}