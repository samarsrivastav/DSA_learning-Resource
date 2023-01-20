#include <bits/stdc++.h>
using namespace std;
int LIS( vector<int> v)
{
    int m=v.size();
    vector<int> dp(m , 1);
    dp[0] = 1;
    int len=1;
    for (int i = 1; i < m; i++)
    {
        for (int j=0;j<i;j++)
        {
            if (v[j]<v[i])
            {
                dp[i] = max(dp[i], dp[j] + 1);
                len=max(len,dp[i]);
            }
        }
    }
    return len;
}
int main()
{
    vector<int> v = {1, 50, 7, 8, 10};
    cout << LIS(v) << endl;
}