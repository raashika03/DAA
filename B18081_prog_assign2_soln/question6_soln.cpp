#include <bits/stdc++.h> 
using namespace std; 
int main()
{   ios_base::sync_with_stdio(false);cin.tie(NULL);
    int cash, n, years, f1, f2;
    cin >> cash >> n >> years >> f1 >> f2;
    vector<vector<double>> return_rate(n+1,vector<double> (years+1)), dp(n+1, vector<double> (years+1));
    for(int i=1; i<=n; i++){
        for(int j=1; j<=years; j++){
            cin >> return_rate[i][j];
        }
    }
    double max_prev_year=cash;
    for(int curr_year=1; curr_year<=years; curr_year++){
        for(int curr_strategy=1; curr_strategy<=n; curr_strategy++){
            dp[curr_strategy][curr_year]=max(dp[curr_strategy][curr_year-1]+f1, max_prev_year+f2);
        }
        max_prev_year=0;
        for(int curr_strategy=1; curr_strategy<=n; curr_strategy++){
            max_prev_year=max(max_prev_year, dp[curr_strategy][curr_year]);
        }
    }
    double ans = max_prev_year;
    cout << ans << '\n';
    return 0;
}