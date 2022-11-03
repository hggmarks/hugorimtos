#include <bits/stdc++.h>

using std::cin;

#define INF -1

class Node {
    public:
        int visited;
        int distAhmad;
        char name[25];
        
        Node(){
            visited = 0;
        }
};

class Graph {

    public:

        int** matrix;
        int mSize;
        int nVertex;
        Node* node;

        Graph(int n){

            matrix = new int*[n];

            for(int i=0; i<n; i++){
                matrix[i] = new int[n];
            }

            node = new Node[n];
            
            mSize = n;
            nVertex = 0;
        }

        void setEdge(int x, int y){
            //if (x > mSize || y > mSize) return;
            //if (matrix[x][y] != 1) nEdges++;
            matrix[x][y] = 1;
        }

        void setMark(int v, int state){
            node[v].visited = state;
        }

        int getMark(int v){
            return node[v].visited;
        }

        int first(int v){
            for(int i=0; i<nVertex; i++){
                if(matrix[v][i] != 0){
                    return i;
                }
            }
            //return mSize;
            return nVertex;
        }

        int next(int v, int w){
            for(int i=w+1; i < nVertex; i++){
                if (matrix[v][i] != 0)
                    return i;
            }
            //return mSize;
            //return nEdges;
            return nVertex;
        }

        void setDistAhmad(int d, int i){
            if(d < node[i].distAhmad)
                node[i].distAhmad = d;
        }


        void graphTraverse(){
            for(int i=0; i<nVertex; i++){
                setMark(i, 0);
            }
            for(int i=0; i<nVertex; i++){
                if(!strcmp("Ahmad", node[i].name))
                    BfsTraverse(i);
            }
        }

        void BfsTraverse(int start){
            std::queue<int> q;
            int dist = 0;
            q.push(start);
            setMark(start, 1);
            setDistAhmad(dist, start);
            while(!q.empty()){
                int v = q.front();
                q.pop();
                dist = node[v].distAhmad + 1;
                int w = first(v);
                
                while( w < nVertex ){
                    setDistAhmad(dist, w);
                    if(getMark(w) == 0){
                        setMark(w, 1);
                        q.push(w);
                    }

                    w = next(v, w);
                }
                //posvisit
            }
        }
    
        int setNode(){
            char name[25];
            scanf(" %s", name);
            for(int i=0; i<nVertex; i++){
                if (!strcmp(name, node[i].name)) return i;
            }

            strcpy(node[nVertex].name, name);
            node[nVertex].distAhmad = __INT_MAX__;
            nVertex++;
            return nVertex-1;
        }
    
        
};

void swap(Node* node, int a, int b){
    Node temp;
    temp = node[a];
    node[a] = node[b];
    node[b] = temp;
}

int hoarePartition(Node* node, int low, int high){
    char s[25];
    strcpy(s, node[low].name);

    int i = low, j = high + 1;

    do{
        do{
            i++;
        } while ((strcasecmp(s, node[i].name) > 0) && (high > i));

        do{
            j--;
        } while(strcasecmp(s, node[j].name) < 0);
        
        swap(node, i, j);
    } while (i < j);
    swap(node, i, j);
    swap(node, j, low);
    return j;
}

void quicksort(Node* node, int low, int high){
    if(low < high){
        int splitPos = hoarePartition(node, low, high);
        quicksort(node, low, splitPos - 1);
        quicksort(node, splitPos + 1, high);
    }
}

void merge(Node* node, int low, int high){
    Node* tempArr = new Node[high+1];

    for(int count = low; count <= high; count++){
        tempArr[count] = node[count];
    }

    int mid = low + (high - low)/2;

    int i = low;
    int j = mid+1;

    for(int cursor = low; cursor <= high; cursor++){

        if( i == (mid+1) ){
            node[cursor] = tempArr[j++];
        } else if (j > high) {
            node[cursor] = tempArr[i++];
        } else if( strcasecmp(tempArr[i].name, tempArr[j].name) <= 0){
            node[cursor] = tempArr[i++];
        } else if( strcasecmp(tempArr[i].name, tempArr[j].name) >= 0 ){
            node[cursor] = tempArr[j++];
        }

    }
}

void mergeSort(Node* node, int low, int high){
    if(low < high){
        int mid = low + (high-low)/2;
        mergeSort(node, low, mid);
        mergeSort(node, mid+1, high);
        merge(node, low, high);
    }
}

int main(){
    int t, n;
    scanf("%d", &t);
    for(int i=0; i<t; i++){
        scanf("%d", &n);
        Graph g((3*n));

        for(int j=0; j<n; j++){
            int k1 = g.setNode();
            int k2 = g.setNode();
            int k3 = g.setNode();

            g.setEdge(k1, k2);
            g.setEdge(k2, k1);

            g.setEdge(k1, k3);
            g.setEdge(k3, k1);

            g.setEdge(k2, k3);
            g.setEdge(k3, k2);

        }

        g.graphTraverse();
        
        mergeSort(g.node, 0, g.nVertex-1);

        printf("%d\n", g.nVertex);

        for(int x=0; x<g.nVertex; x++){
            for(int y=0; y<g.nVertex; y++){
                if(g.node[y].distAhmad == x)
                    printf("%s %d\n", g.node[y].name, g.node[y].distAhmad);
            }
        }

        for(int z=0; z<g.nVertex; z++){
            if(g.node[z].distAhmad == __INT_MAX__){
                //if (z!=0) printf("\n");
                printf("%s undefined\n", g.node[z].name);
                }
        }

        

    }
    return 0;
}