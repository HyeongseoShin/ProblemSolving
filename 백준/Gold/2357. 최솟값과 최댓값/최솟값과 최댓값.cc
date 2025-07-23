#include <bits/stdc++.h>
using namespace std;

#define MAX 100001
int n, m;
int nums[MAX];

int k;
int leafStart;
vector<int> maxSegTree;
vector<int> minSegTree;

void BuildSegmentTrees() {
    // 세그먼트 트리 하단에 값 삽입
    for(int i = 1; i <= n; i++) {
        maxSegTree[leafStart + i] = nums[i];
        minSegTree[leafStart + i] = nums[i];
    }

    // bottom-up 방식으로 내부 노드 채우기
    for(int i = leafStart - 1; i > 0; i--) {
        maxSegTree[i] = max(maxSegTree[i * 2], maxSegTree[i * 2 + 1]);
        minSegTree[i] = min(minSegTree[i * 2], minSegTree[i * 2 + 1]);
    }
}

int GetMaxVal(int a, int b) {
    int ret = 0;
    int st = leafStart + a;
    int en = leafStart + b;

    while(st <= en) {
        if(st % 2 == 1) ret = max(ret, maxSegTree[st++]);
        if(en % 2 == 0) ret = max(ret, maxSegTree[en--]);
        st /= 2;
        en /= 2;
    }

    return ret;
}

int GetMinVal(int a, int b) {
    int ret = INT_MAX;
    int st = leafStart + a;
    int en = leafStart + b;

    while(st <= en) {
        if(st % 2 == 1) ret = min(ret, minSegTree[st++]);
        if(en % 2 == 0) ret = min(ret, minSegTree[en--]);
        st /= 2;
        en /= 2;
    }

    return ret;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;

    for(int i = 1; i <= n; i++) cin >> nums[i];

    // 트리 크기 계산
    while((1 << k) < n) k++;
    leafStart = 1 << k; // 리프 노드 시작 인덱스
    int treeSize = leafStart * 2;

    maxSegTree.resize(treeSize, 0);
    minSegTree.resize(treeSize, INT_MAX);

    BuildSegmentTrees();

    // 질의 처리
    for(int i = 0; i < m; i++) {
        int st, en;
        cin >> st >> en;

        int minVal = GetMinVal(st, en);
        int maxVal = GetMaxVal(st, en);

        cout << minVal << " " << maxVal << "\n";
    }

    return 0;
}
