#include <bits/stdc++.h>

using namespace std;

#define lli long long int
#define vi vector<int>

lli comp = 0;
lli parent[200001];
lli comp_size[200001];

struct Edge {
    lli u, v, w;
};

bool cmp(Edge e1, Edge e2){
    return e1.w < e2.w;
}

void makeSet(int v){
    parent[v] = v;
    comp_size[v] = 1;
    comp++;
}

lli find(int v){
    if(v == parent[v])
        return v;

    parent[v] = find(parent[v]);
    return parent[v];
}

void unite(lli u, lli v){
    u = find(u);
    v = find(v);

    if(u != v){
        if(comp_size[u] < comp_size[v])
            swap(u, v);
        
        parent[v] = u;
        comp_size[u] += comp_size[v];
        comp--;
    }
}

vi kruskal(lli n, vector<Edge>& edges){
    sort(edges.begin(), edges.end(), [](Edge a, Edge b){
        return a.w < b.w;
    });

    comp = 0;

    for(int i=0; i <= n; i++)
        makeSet(i);

    lli ans = 0;

    vi v;

    for(auto e: edges){
        if(find(e.u) == find(e.v)){
            v.push_back(e.w);
            continue;
        }

        unite(e.u, e.v);

        ans += e.w;
    }

    return v;

}

int main(){
    lli n, m;

    while(cin>>n>>m){
        if(n==0 && m==0)
            break;

        vector<Edge> g;

        int u, v, w;

        for(int i=0; i<m; i++){
            cin>>u>>v>>w;
            g.push_back({u, v, w});
        }

        vi ans = kruskal(n, g);

        sort(ans.begin(), ans.end());

        if(ans.size()){
            for(int i=0; i<ans.size(); i++){
                cout << ans[i];

                if(i<ans.size()-1)
                    cout << " ";
            }

            cout << '\n'; 
        } else{
            cout << "forest\n";
        }
    }

    return 0;
}