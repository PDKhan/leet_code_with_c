bool checkSudoku(int r, int c, char** board, int boardSize, int boardColSize){
    int row[10] = {0};
    int col[10] = {0};
    int box[10] = {0};
    int r_start = (r / 3) * 3;
    int c_start = (c / 3) * 3;

    for(int i = 0; i < boardSize; i++){
        if(board[i][c] == '.')
            continue;

        if(row[board[i][c] - '0'])
            return false;
        
        row[board[i][c] - '0']++;
    }

    for(int j = 0; j < boardColSize; j++){
        if(board[r][j] == '.')
            continue;

        if(col[board[r][j] - '0'])
            return false;
        
        col[board[r][j] - '0']++;
    }

    for(int i = r_start; i < r_start + 3; i++){
        for(int j = c_start; j < c_start + 3; j++){
            if(board[i][j] == '.')
                continue;

            if(box[board[i][j] - '0'])
                return false;
        
            box[board[i][j] - '0']++;
        }
    }

    return true;
}

bool isValidSudoku(char** board, int boardSize, int* boardColSize) {
    for(int i = 0; i < boardSize; i++){
        for(int j = 0; j < boardColSize[0]; j++){
            if(checkSudoku(i, j, board, boardSize, boardColSize[0]) == false)
                return false;
        }
    }

    return true;
}
