#include <bits/stdc++.h>

class Graph {

    public:

        int** matrix;
        int mSize;
        int nEdges;
        int* mark;

        Graph(int n){

            matrix = new int*[n];

            for(int i=0; i<n; i++){
                matrix[n] = new int[n];
            }

            mark = new int[n];
            
            mSize = n;
            nEdges = 0;
        }

        void setEdge(int x, int y){
            if (x > mSize || y > mSize) return;
            if (matrix[x][y] != 1) nEdges++;
            matrix[x][y] = 1;
        }

        void setMark(int v, int state){
            mark[v] = 1;
        }

        void BfsTraverse(int v){
            for(int i=0; i < mSize; i++){
                setMark(v, 0);
            }
        }

        
};

