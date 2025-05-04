#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    for(int t = 1; t <= 10; t++)
    {
        int n;
        cin >> n;
        
        int box[100];
        
        for(int i = 0; i < 100; i++)
        {
        	cin >> box[i];    
        }
        
        while(n--)
        {
        	auto maxVal = max_element(box, box + 100) - box;
            auto minVal = min_element(box, box + 100) - box;
            
           	box[maxVal]--;
            box[minVal]++;
        }
        
        cout << "#" << t << " " << *max_element(box, box + 100) - *min_element(box, box + 100) << "\n";
    }
    return 0;
}