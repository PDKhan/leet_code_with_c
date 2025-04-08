/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* spiralOrder(int** matrix, int matrixSize, int* matrixColSize, int* returnSize) {
    enum direction { R, D, L, U };
    enum direction dir = R;
    int r = 0;
    int c = 0;
    int minR = 0, maxR = matrixSize - 1;
    int minC = 0, maxC = matrixColSize[0] - 1;
    int len = matrixSize * matrixColSize[0];
    int* result = (int*)malloc(sizeof(int) * len);

    *returnSize = 0;

    while(*returnSize < len){
        result[(*returnSize)++] = matrix[r][c];

        switch(dir){
            case R:
                if(c == maxC){
                    dir = D;
                    r++;
                    minR++;
                }else
                    c++;
                break;
            case D:
                if(r == maxR){
                    dir = L;
                    c--;
                    maxC--;
                }else
                    r++;
                break;
            case L:
                if(c == minC){
                    dir = U;
                    r--;
                    maxR--;
                }else
                    c--;
                break;
            case U:
                if( r == minR){
                    dir = R;
                    c++;
                    minC++;
                }else
                    r--;
                break;
        }
    }

    return result;
}
