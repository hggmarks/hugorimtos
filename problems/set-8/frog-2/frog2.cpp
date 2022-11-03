#include <bits/stdc++.h>

#define lli long long int

using namespace std;
int N, K;
vector<lli> LUT;
vector<lli> stones;

lli minimalCost(lli i){
    if(i == N-1)
        return 0;

    if(LUT[i] != -1) return LUT[i];

    lli ans = __INT_MAX__;

    for(lli j=1; j<K+1; j++){
        if(i+j < N){
            ans = min(abs(stones[i]-stones[i+j]) + minimalCost(i+j), ans);
        }
    }
    
    return LUT[i] = ans;
}

int main(){
    cin >> N >> K;
    LUT = vector<lli>(N+1);
    stones = vector<lli>(N);
    //memset(LUT, -1, sizeof(LUT));
    fill(LUT.begin(), LUT.end(), -1);

    for(auto &i: stones){
        cin >> i;
    }

    cout << minimalCost(0);

    return 0;
}

