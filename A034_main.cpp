#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <iostream>
#include <algorithm>
#include <functional>

using namespace std;
int main(void) {
    
    int N,X,tmp,change;
    
    //dpはN回まで異なる種類の買い物をするとして，
    //合計金額がx円(0<= x <=X)のであるとき，買ったものの合計金額を（お釣りが最小になるように）記録する．
    int xi[21];//N+1の最大値
    int dp[20][5000];
    
    
    cin>>N>>X;

    N++;


    
    for(int i=0;i<N;i++){
        cin>>xi[i];
    }
    
    // DP初期条件: dp[0][X] = 0:合計0円のときは0個選んだよね
    for (int x = 0; x <= X; ++x) dp[0][x] = 0;
    
    //sort(Xi, Xi + N);

  // DPループ
    for (int i = 0; i < N; ++i) {//i番目のものを買う機会が与えられたとき
        for (int x = 0; x <= X; ++x) {//合計金額がX円を越えないまで繰り返す

            //今のx円の買い物をするときにxi[i]円の品物が，かえるなら
            if (x >= xi[i]) dp[i+1][x] = max(dp[i][x-xi[i]] + xi[i], dp[i][x]);
            //買わないときの値段か，買ったときの値段が大きい方の値を記録する
            
            //買えないなら，選ぼうと試みたときの合計金額を維持する
            else dp[i+1][x] = dp[i][x];
            
    }
  }


    for(int x=0;x<=X;x++){
        printf("%d: %d\n",x,dp[N-1][x]);
    }
  
  //一部問題で失敗するのが解せない
  printf("%d\n",X-dp[N-1][X]);
      
    return 0;
}
