#include<bits/stdc++.h>
using namespace std;
// 2D DP array will be created
//rows represent number of items
//columns represent the weight of the knapsack

int main()
{
    vector<int> price = {10,20,30,40};
    vector<int> weights = {12,13,15,19};
    int n=4,W=30;

    int dp[n+1][W+1];

    for(int i=0;i<=n;i++)
    {
        for(int j=0;j<=W;j++)
        {
            if(i==0 || j==0)
            {
                dp[i][j] = 0; //When weight of knapsack is 0, profit is 0. When number of items is zero, profit is again zero.
            }
            else if(weights[i] > j)
            {
                dp[i][j] = dp[i-1][j]; //when the weight of i'th item is more than weight of knapsack in j'th iteration.
            }
            else{
                    //now we can either include the item or exclude the item. Goal is to achieve max profit.
                int include = price[i-1] + dp[i-1][j-weights[i-1]];
                int exclude = dp[i-1][j];
                dp[i][j] = max(include,exclude);
            }
        }
    }


    cout<<"Maximum Profit: "<<dp[n][W];


    return 0;
}

