#include<bits/stdc++.h>
using namespace std;

int knapsack(int n, int W, vector<int> price, vector<int> wts){
    if(n==0 || W==0){
        return 0;
    }

    if(wts[n-1] > W){
        return knapsack(n-1, W, price , wts);
    }
        int inc = price[n-1] + knapsack(n-1, W - wts[n-1], price, wts);
        int exl = knapsack(n-1 , W, price, wts);
        return max(inc,exl);

}

int main()
{
    vector<int> price = {10,20,30,40};
    vector<int> weights = {12,13,15,19};
    int n=4,W=30;

    cout<<"Maximum profit: "<<knapsack(n,W,price,weights);
    return 0;
}


