#include <bits/stdc++.h>
using namespace std;
int MinCoin(int m, vector<int> v)
{
    vector<int> dp(m + 1, 0);
    dp[0] = 0;
    for (int i = 1; i <= m; i++)
    {
        dp[i] = INT32_MAX;
        for (int c : v)
        {
            if (i - c >= 0 and dp[i - c] != INT32_MAX)
            {
                dp[i] = min(dp[i], dp[i - c] + 1);
            }
        }
    }
    return dp[m] == INT32_MAX ? -1 : dp[m];
}
int main()
{
    vector<int> v = {1, 5, 7, 8, 10};
    cout << MinCoin(16, v) << endl;
}