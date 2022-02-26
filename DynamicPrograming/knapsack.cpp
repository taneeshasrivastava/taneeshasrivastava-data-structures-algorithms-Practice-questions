#include<iostream>
#include<vector>
using namespace std;

int BottomUpKnapsackDp(int wts[],int price[],int N,int W){
    if(N==0 or W==0){
        return 0;
    }//Recursion
    int inc=0,exc=0;
    if(wts[N-1]<=W){
        inc=price[N-1]+ BottomUpKnapsackDp(wts,price,N-1,W-wts[N-1]);
    }
    exc= BottomUpKnapsackDp( wts, price,N-1,W);
    return max(inc,exc);
}

int topDownKnappsackDp(int wt[],int price[],int N,int W){
    vector<vector<int> > dp(N+1,vector<int>(W+1,0));
    for(int n=1;n<=N;n++){
        for(int w=1;w<=W;w++){
            int inc=0,exc=0;
            if(wt[n-1]<=w){
                inc=price[n-1]+dp[n-1][w-wt[n-1]];
            }
            exc=dp[n-1][w];

            dp[n][w]=max(inc,exc);

        }
    }
    return dp[N][W];
}

int main(){
    int wts[]={2,7,3,4};
    int prices[ ]={5,28,20,10};

    int N=4;
    int W=11;
    cout<< topDownKnappsackDp(wts,prices,N,W)<< endl;
    cout<< BottomUpKnapsackDp(wts,prices,N,W)<< endl;
    

    return 0 ;
}