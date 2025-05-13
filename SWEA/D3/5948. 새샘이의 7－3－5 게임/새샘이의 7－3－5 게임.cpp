// https://swexpertacademy.com/main/code/problem/problemDetail.do?problemLevel=3&contestProbId=AWZ2IErKCwUDFAUQ&categoryId=AWZ2IErKCwUDFAUQ&categoryType=CODE&problemTitle=&orderBy=RECOMMEND_COUNT&selectCodeLang=ALL&select-1=3&pageSize=10&pageIndex=3

// 시간 초과

// 조합
#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int testCase;
    cin >> testCase;

    // 조합 구할 때도 sort 진행되어야 함 --> 0 다 넣고 1 넣기
    int p[7] = {0, 0, 0, 0, 1, 1, 1};

    for(int t = 1; t <= testCase; t++)
    {
        int nums[7];

        for(int i = 0; i < 7; i++)
        {
            cin >> nums[i];
        }

        sort(nums, nums + 7);

        vector<int> ans;        
        
        do
        {
            int sum = 0;
            for(int i = 0; i < 7; i++)
            {
                if(p[i] == 1)
                {
                    sum += nums[i];
                }
                
            }
            
            ans.push_back(sum);
        } while(next_permutation(p, p + 7));
        // 조합 구할 때는 원본 배열이 아니라, {0, 1} 들어있는 배열로 next_permutation 진행


        // unique() 연산 진행 전에도 sort() 필요
        sort(ans.begin(), ans.end(), greater<>());
        ans.erase(unique(ans.begin(), ans.end()), ans.end());

        cout << "#" << t << " " << ans[4] << "\n";
    }
    return 0;
}