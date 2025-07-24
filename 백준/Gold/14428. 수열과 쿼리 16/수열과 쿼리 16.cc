#include <bits/stdc++.h>

using namespace std;

#define MAX 100001

int nums[MAX];
int n, m;

// 범위 내 최솟값 인덱스 저장
vector<int> segTree;

int k, startIdx, treeSize;

void InitSegTree()
{
    for (int i = startIdx + 1; i <= startIdx + n; i++) {
        segTree[i] = i - startIdx; // 리프 노드에는 인덱스를 저장
    }

    for(int i = startIdx - 1; i >= 1; i--)
    {
        int l = segTree[i*2];
        int r = segTree[i*2+1];

        if(nums[l] < nums[r] || (nums[l] == nums[r] && l < r)) segTree[i] = l;
        else segTree[i] = r;
    }
}

void Update(int a)
{
    int idx = startIdx + a;
    
    while(idx > 1)
    {
        idx /= 2;

        int l = segTree[idx * 2];
        int r = segTree[idx * 2 + 1];

        if(nums[l] < nums[r] || (nums[l] == nums[r] && l < r)) segTree[idx] = l;
        else segTree[idx] = r;
    }
}

int GetMinVal(int a, int b)
{
    int st = startIdx + a;
    int en = startIdx + b;

    int ret = segTree[st];

    while(st <= en)
    {
        if(st % 2 == 1)
        {
            int idx = segTree[st];

            if(nums[ret] > nums[idx] || (nums[ret] == nums[idx] && ret > idx)) ret = idx;
            st++;
        }

        if(en % 2 == 0)
        {
            int idx = segTree[en];

            if(nums[ret] > nums[idx] || (nums[ret] == nums[idx] && ret > idx)) ret = idx;
            en--;
        }
        

        st/= 2;
        en /= 2;
    }

    return ret;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    
    for(int i = 1; i <= n; i++)
    {
        cin >> nums[i];
    }

    while((1 << k) < n) k++;

    startIdx = (1 << k);
    treeSize = startIdx * 2;

    segTree.resize(treeSize);

    InitSegTree();

    cin >> m;

    while(m--)
    {
        int op, a, b;

        cin >> op >> a >> b;

        if(op == 1)
        {
            nums[a] = b;
            Update(a);
        }

        else
        {
            cout << GetMinVal(a, b) << "\n";
        }
    }

    return 0;
}