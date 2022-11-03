#include <bits/stdc++.h>

using namespace std;

int movesX[] = {0, 0, 1, -1};
int movesY[] = {-1, 1, 0, 0};

bool canWalk(vector<vector<char>> maze, int sizeX, int sizeY, int x, int y){
    if(x>=0 && x<sizeX && y>=0 && y<sizeY && maze[x][y] != '#' && maze[x][y] != '%'){
        return true;
    }
    return false;
}

bool mazeSolve(vector<vector<char>> maze, int x, int y, int spikes){
    int sizeX = maze.size();
    int sizeY = maze[0].size();

    if(maze[x][y] == 'x') return true;
    if(maze[x][y] == 's') spikes-=2;
    if(spikes<0) return false;

    maze[x][y] = '%';

    for(int i=0; i<4; i++){
        int r = x + movesX[i];
        int c = y + movesY[i];

        if(canWalk(maze, sizeX, sizeY, r, c) && mazeSolve(maze, r, c, spikes)){
            return true;
        }
    }

    return 0;
}

int main(){
    int n, m, j, startX, startY;

    scanf("%d %d %d", &n, &m, &j);

    vector<vector<char>> maze(n, vector<char> (m));

    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            char c;
            cin>>c;

            maze[i][j] = c;

            if(c=='@'){
                startX = i;
                startY = j;
            }
        }
    }

    if(mazeSolve(maze, startX, startY, j)){
        printf("SUCCESS");
    } else {
        printf("IMPOSSIBLE");
    }

}