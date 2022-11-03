#include <bits/stdc++.h>
using namespace std;

#define vvii vector<vector<pair<int, int>>>
#define vi vector<int>

#define int_max 1e5

void dijkstra(vvii g, int v, int s, int destiny, int index){
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int, int>>> minHeap;
    vi visited(v);
    vi dist(v);

    minHeap.push(make_pair(0,s));

    for(int i = 0; i < v; i++){
        dist[i] = __INT_MAX__;
        visited[i] = 0;
    }

    dist[s] = 0;

    for(int i = 0; i < v; i++){
        pair<int,int> w;
        do{
            if(!minHeap.empty()){
                w = minHeap.top();
                minHeap.pop();
            }else{
                goto end;
            }
        }while(visited[w.second] == 1);
        visited[w.second] = 1;
        for(auto k: g[w.second]){

            if((!visited[k.second]) && (dist[k.second] > (dist[w.second]+k.first))){

                dist[k.second] = dist[w.second] + k.first;
                minHeap.push(make_pair(dist[k.second],k.second));
            }
        }
    }

    end:

    if(dist[destiny] != __INT_MAX__){
        printf("Case #%d: %d\n", index, dist[destiny]);
    }else{
        printf("Case #%d: unreachable\n", index);
    }
    return;
}

int main(){

    vvii g;
    int N, v, e, s, d;
    int v1, v2, w, source, j = 1;

    scanf("%d", &N);    

    while(N--){
        scanf("%d %d %d %d", &v, &e, &s, &d);
        source = s;
        g.resize(v);

        for(int i = 0; i < e; i++){
            scanf("%d %d %d", &v1, &v2, &w);
            g[v1].push_back(make_pair(w,v2));
            g[v2].push_back(make_pair(w,v1));
        }

        dijkstra(g, v, source, d, j++);
        
        g.clear();
    }

    return 0;
}