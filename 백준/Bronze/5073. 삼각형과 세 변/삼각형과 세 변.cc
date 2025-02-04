#include <bits/stdc++.h>

using namespace std;

int triangle[3];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    while(true)
    {
        cin >> triangle[0] >> triangle[1] >> triangle[2];

        sort(triangle, triangle + 3, greater<>());

        if(triangle[0] == 0) break;

        else if(triangle[0] == triangle[1] && triangle[0] == triangle[2] && triangle[1] == triangle[2]) cout << "Equilateral\n";
        else if(triangle[0] >= triangle[1] + triangle[2]) cout << "Invalid\n";
        else if(triangle[0] == triangle[1] || triangle[0] == triangle[2] || triangle[1] == triangle[2]) cout << "Isosceles\n";
        else cout << "Scalene\n";   
    }
    
    return 0;
}