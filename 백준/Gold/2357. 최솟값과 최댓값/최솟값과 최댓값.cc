#include <bits/stdc++.h>

using namespace std;

#define MAX 100001
int n, m;

int nums[MAX];

int k;
int treeSize;

vector<int> maxSegTree;
vector<int> minSegTree;

// 트리 초기화
void SetMaxSegTree(int idx)
{
    while(idx != 1)
    {
        maxSegTree[idx/2] = max(maxSegTree[idx/2], maxSegTree[idx]);
        idx--;
    }
}

// 트리 초기화
void SetMinSegTree(int idx)
{
    while(idx != 1)
    {
        minSegTree[idx/2] = min(minSegTree[idx/2], minSegTree[idx]);
        idx--;
    }
}

// 구간 중 최댓값 찾기
int GetMaxVal(int a, int b)
{
    int ret = 0;

    int st = treeSize / 2 - 1 + a;
    int en = treeSize / 2 - 1 + b;

    while(st <= en)
    {
        if(st % 2 == 1) ret = max(ret, maxSegTree[st]);
        if(en % 2 == 0) ret = max(ret, maxSegTree[en]);

        st = (st + 1) / 2;
        en = (en - 1) / 2;
    }

    return ret;
}

// 구간 중 최솟값 찾기
int GetMinVal(int a, int b)
{
    int ret = INT_MAX;

    int st = pow(2, k) - 1 + a;
    int en = pow(2, k) - 1 + b;

    while(st <= en)
    {
        if(st % 2 == 1) ret = min(ret, minSegTree[st]);
        if(en % 2 == 0) ret = min(ret, minSegTree[en]);

        st = (st + 1) / 2;
        en = (en - 1) / 2;
    }

    return ret;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;

    for(int i = 1; i <= n; i++) cin >> nums[i];
    
    // 1. 트리 초기화하기
    while(pow(2, k) < n) k++;

    treeSize = pow(2, k) * 2;

    maxSegTree.resize(treeSize, 0);
    minSegTree.resize(treeSize, INT_MAX);

    for(int i = 1; i <= n; i++)
    {
        int idx = i + pow(2,k) - 1;
        maxSegTree[idx] = nums[i];
        minSegTree[idx] = nums[i];
    }

    // 2. 트리 업데이트
    SetMaxSegTree(treeSize - 1);
    SetMinSegTree(treeSize - 1);

    // 3. 질의 값 구하기
    for(int i = 0; i < m; i++)
    {
        int st, en;
        cin >> st >> en;

        int minVal = GetMinVal(st, en);
        int maxVal = GetMaxVal(st, en);

        cout << minVal << " " << maxVal << "\n";
    }

    return 0;
}