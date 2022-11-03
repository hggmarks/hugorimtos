#include <bits/stdc++.h>

using namespace std;

int movesX[] = {-2, -2, -1, -1, 1, 1, 2, 2};
int movesY[] = {-1, 1, -2, 2, -2, 2, -1, 1};
int board[11][11];
int visited = -1;

bool canJump(int startX, int startY, int row, int col){
    if( startX >= 0 && startX < row && startY >= 0 && startY < col){
        return true;
    }

    return false;
}

void knightJump(int startX, int startY, int row, int col, int prevJumps){
    board[startX][startY] = 1;
    bool flag = true;

    for(int i=0; i<8; i++){
        int r = startX + movesX[i];
        int c = startY + movesY[i];

        if (canJump(r, c, row, col) && board[r][c] == 0){
            flag = false;
            knightJump(r, c, row, col, prevJumps+1);
        }
    }
    
    if(flag == true){
        if(visited<prevJumps) visited = prevJumps;
    }

    board[startX][startY] = 0;
}

int main(){

    int n, total=0, nCase=0;


    while(1){
        scanf("%d", &n);

        if(n==0) break;

        memset(board, -1, sizeof(board));
        visited = -1;

        for(int i=0; i<n; i++){

            int n1, n2;
            
            scanf("%d %d", &n1, &n2);

            for(int j=n1; j<n1+n2; j++){

                board[i][j] = 0;
                total++;
            }
        }

        knightJump(0, 0, 10, 10, 1);

        nCase++;

        if(total - visited == 1){
            printf("Case %d, 1 square can not be reached.\n", nCase);
            
        } else {
            printf("Case %d, %d squares can not be reached.\n", nCase, total - visited);
        }

        total = 0;

    }
    return 0;
}
