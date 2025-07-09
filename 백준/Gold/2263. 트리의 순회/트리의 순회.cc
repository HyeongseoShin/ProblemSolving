#include <bits/stdc++.h>
using namespace std;

int n;
int inOrder[100001];
int postOrder[100001];
unordered_map<int, int> inIndex;

void getPreOrder(int inStart, int inEnd, int postStart, int postEnd) {
    if (inStart > inEnd || postStart > postEnd) return;

    int root = postOrder[postEnd];
    cout << root << " ";

    int rootIdx = inIndex[root];
    int leftSize = rootIdx - inStart;

    // 왼쪽 서브트리
    getPreOrder(inStart, rootIdx - 1, postStart, postStart + leftSize - 1);
    // 오른쪽 서브트리
    getPreOrder(rootIdx + 1, inEnd, postStart + leftSize, postEnd - 1);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for (int i = 0; i < n; i++) cin >> inOrder[i];
    for (int i = 0; i < n; i++) cin >> postOrder[i];

    for (int i = 0; i < n; i++) inIndex[inOrder[i]] = i;

    getPreOrder(0, n - 1, 0, n - 1);
    cout << "\n";

    return 0;
}
