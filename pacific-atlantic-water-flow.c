/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
void dfs(int prev, int r, int c, int** heights, int heightsSize, int heightsColSize, bool** visit){
    if(r < 0 || c < 0 || r >= heightsSize || c >= heightsColSize || visit[r][c] || heights[r][c] < prev)
        return;
    
    visit[r][c] = true;

    dfs(heights[r][c], r - 1, c, heights, heightsSize, heightsColSize, visit);
    dfs(heights[r][c], r + 1, c, heights, heightsSize, heightsColSize, visit);
    dfs(heights[r][c], r, c - 1, heights, heightsSize, heightsColSize, visit);
    dfs(heights[r][c], r, c + 1, heights, heightsSize, heightsColSize, visit);
}

int** pacificAtlantic(int** heights, int heightsSize, int* heightsColSize, int* returnSize, int** returnColumnSizes) {
    int max_size = heightsSize * heightsColSize[0];
    int** result = (int**)malloc(max_size * sizeof(int*));
    bool** pacific = (bool**)malloc(heightsSize * sizeof(bool*));
    bool** atlantic = (bool**)malloc(heightsSize * sizeof(bool*));

    *returnColumnSizes = (int*)malloc(max_size * sizeof(int));
    *returnSize = 0;

    for(int i = 0; i < heightsSize; i++){
        pacific[i] = (bool*)malloc(heightsColSize[0] * sizeof(bool));
        memset(pacific[i], 0, heightsColSize[0] * sizeof(bool));

        atlantic[i] = (bool*)malloc(heightsColSize[0] * sizeof(bool));
        memset(atlantic[i], 0, heightsColSize[0] * sizeof(bool));
    }

    for(int i = 0; i < heightsSize; i++){
        dfs(heights[i][0], i, 0, heights, heightsSize, heightsColSize[0], pacific);
        dfs(heights[i][heightsColSize[0]-1], i, heightsColSize[0]-1, heights, heightsSize, heightsColSize[0], atlantic);
    }

    for(int j = 0; j < heightsColSize[0]; j++){
        dfs(heights[0][j], 0, j, heights, heightsSize, heightsColSize[0], pacific);
        dfs(heights[heightsSize-1][j], heightsSize-1, j, heights, heightsSize, heightsColSize[0], atlantic);
    }

    for(int i = 0; i < heightsSize; i++){
        for(int j = 0; j < heightsColSize[0]; j++){
            if(pacific[i][j] && atlantic[i][j]){
                result[*returnSize] = (int*)malloc(2 * sizeof(int));
                result[*returnSize][0] = i;
                result[*returnSize][1] = j;
                (*returnColumnSizes)[*returnSize] = 2;

                (*returnSize)++;
            }
        }
    }

    for(int i = 0; i < heightsSize; i++){
        free(pacific[i]);
        free(atlantic[i]);
    }

    free(pacific);
    free(atlantic);

    return result;
}
