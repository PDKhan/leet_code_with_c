void dfs(int r, int c, char** grid, int gridSize, int gridColSize){
    if(r < 0 || r >= gridSize || c < 0 || c >= gridColSize || grid[r][c] == '0')
        return;

    grid[r][c] = '0';
    
    dfs(r - 1, c, grid, gridSize, gridColSize);
    dfs(r + 1, c, grid, gridSize, gridColSize);
    dfs(r, c - 1, grid, gridSize, gridColSize);
    dfs(r, c + 1, grid, gridSize, gridColSize);
}

int numIslands(char** grid, int gridSize, int* gridColSize) {
    int result = 0;

    for(int i = 0; i < gridSize; i++){
        for(int j = 0; j < gridColSize[0]; j++){
            if(grid[i][j] == '1'){
                dfs(i, j, grid, gridSize, gridColSize[0]);
                result++;
            }
        }
    }

    return result;
}
