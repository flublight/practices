#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <iostream>
#include <algorithm>
#include <functional>

using namespace std;


int dp[1001][10001];//本の数，日数に対していま読破したページ数の最大値を記録
int main(void) {
    
    int N,M;
    cin>>N>>M;
    
    int bi[1001]={},xi[1001]={};//本のページ数と予想読破日数と最大値

    for(int i=0;i<N;i++){
        cin>>bi[i]>>xi[i];
    }
    
    // DP初期条件: dp[0][M] 0本読むときは経過日数0
    for (int m = 0; m <= M; ++m) dp[0][m] = 0;
    
    // DPループ
    for (int n = 0; n < N; ++n) {//n(+1)番目の本を読もうとするとき
        for (int m = 0; m <= M; ++m) {//m日経過しているとする数
        //printf("n,m=%d,%d\n",n,m);
        //m番目はMを超えないことが既知のためm>=xi[n]であれば良い
        if (m >= xi[n] ) {
                dp[n+1][m] = max(dp[n][m-xi[n]] + bi[n], dp[n][m]);
                
                //printf("n,m = %d,%d ",n,m);
                //printf("dp %d -> %d\n",dp[n][m],dp[n+1][m]);
                
        }
        else  dp[n+1][m] = dp[n][m];
                
        }
    }

    for(int m=0;m<=M;m++){
        //printf("%d: %d\n",m,dp[N][m]);
        
    }
    printf("%d\n",dp[N][M]);

    
}
