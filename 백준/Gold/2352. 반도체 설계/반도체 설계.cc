/*
LIS - 최장 증가 부분 수열 알고리즘 (DP)
*/

#include <bits/stdc++.h>

using namespace std;

int n;

int arr[50000]; // 입력값
vector<int> lis; // 현재 최장 증가 부분 수열

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    for(int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    lis.push_back(arr[0]);
    int index = 0;

    for(int i = 1; i < n; i++)
    {
        // LIS 마지막 원소가 현재 arr값보다 크면
        // 현재 arr값이 들어갈 위치 찾고 삽입
        if(lis[index] > arr[i])
        {
            // lower_bound를 이용해 arr[i]보다 작은
            int tmpIndex = lower_bound(lis.begin(), lis.end(), arr[i]) - lis.begin();
            lis[tmpIndex] = arr[i];
        }
        else
        {
            lis.push_back(arr[i]);
            index++;
        }
    }

    cout << (int)lis.size() << "\n";

    return 0;
}