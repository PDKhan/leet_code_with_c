void rotate(int** matrix, int matrixSize, int* matrixColSize) {
    for(int i = 0; i < matrixSize; i++){
        for(int j = i + 1; j < matrixColSize[i]; j++){
            int tmp = matrix[i][j];
            matrix[i][j] = matrix[j][i];
            matrix[j][i] = tmp;
        }
    }

    for(int i = 0; i < matrixSize; i++){
        for(int j = 0; j < matrixColSize[i] / 2; j++){
            int tmp = matrix[i][j];
            matrix[i][j] = matrix[i][matrixColSize[i] - 1 - j];
            matrix[i][matrixColSize[i] - 1 - j] = tmp;
        }
    }
}
