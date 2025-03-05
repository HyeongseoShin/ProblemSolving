#include <bits/stdc++.h>

using namespace std;

int n;

priority_queue<int, vector<int>, greater<>> minHeap; // 오름차순 정렬
priority_queue<int> maxHeap; // 내림차순 정렬

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    while(n--)
    {
        int x;
        cin >> x;

        if(maxHeap.size() <= minHeap.size()) maxHeap.push(x);
        else minHeap.push(x);

        if(!minHeap.empty() && minHeap.top() < maxHeap.top())
        {
            maxHeap.push(minHeap.top());
            minHeap.pop();

            minHeap.push(maxHeap.top());
            maxHeap.pop();
        }

        cout << maxHeap.top() << "\n";

    }

    return 0;
}