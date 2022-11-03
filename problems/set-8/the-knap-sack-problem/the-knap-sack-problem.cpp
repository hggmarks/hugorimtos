#include <bits/stdc++.h>

using namespace std;
int itemW[2005];
int itemV[2005];
int F[2005][2005];

void knapSack(int n, int s){
    for(int i=1; i<s+1; i++){
        for(int j=1; j<n+1; j++){
            if(i-itemW[j]<0){
                F[i][j] = F[i][j-1];
            } else {
                F[i][j] = max(F[i][j-1], F[i-itemW[j]][j-1] + itemV[j]);
            }
        }
    }
    

}
    
int main(){
    int S, N;
    int w, v;
    cin>>S>>N;
    
    for(int i=0; i<N; i++){
        cin>>w>>v;
        itemW[i+1] = w;
        itemV[i+1] = v;
    }

    knapSack(N, S);
    cout<<F[S][N];
    }