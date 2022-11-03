#include <bits/stdc++.h>

using namespace std;

#define _int long long int

int main(){

    _int dep[1000010];

    _int nV, cases;
    cin >> nV >> cases;

    vector<_int> adjList[nV+1], visited(nV+1), ans;
    

    for(_int i=0; i<cases; i++){
        _int vA, vB;
        scanf(" %lld", &vA);
        scanf(" %lld", &vB);

        adjList[vA].push_back(vB);
        
        dep[vB]++;

    }

    priority_queue<_int, vector<_int>, greater<_int>> mHeap;

    for(_int i=1; i<nV+1; i++){
        if(dep[i] == 0) mHeap.push(i);
    }


    while(!mHeap.empty()){
        _int w = mHeap.top(); mHeap.pop();
        ans.push_back(w);
        for(_int i: adjList[w]){
            dep[i]--;
            if(dep[i] == 0) mHeap.push(i);
        }
    }

    if(ans.size() != nV){
        printf("Sandro fails.");
        return 0;
    } else {
        for(auto i: ans){
            cout << i << ' ';
        }
        return 0;
    }


}