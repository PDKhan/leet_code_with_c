bool dfs(int curr, int** graph, int* g_col, int* visited){
    if(visited[curr] == 1)
        return false;

    if(visited[curr] == 2)
        return true;
    
    visited[curr] = 1;

    for(int i = 0; i < g_col[curr]; i++){
        if(dfs(graph[curr][i], graph, g_col, visited) == false)
            return false;
    }

    visited[curr] = 2;

    return true;
}

bool canFinish(int numCourses, int** prerequisites, int prerequisitesSize, int* prerequisitesColSize) {
    int visited[numCourses];
    int g_col[numCourses];
    int* graph[numCourses];

    for(int i = 0; i < numCourses; i++){
        graph[i] = (int*)malloc(numCourses * sizeof(int));
        memset(graph[i], 0, numCourses * sizeof(int));
    }
    
    memset(g_col, 0, numCourses * sizeof(int));
    memset(visited, 0, numCourses * sizeof(int));

    for(int i = 0; i < prerequisitesSize; i++){
        int course = prerequisites[i][0];
        int pre = prerequisites[i][1];

        graph[pre][g_col[pre]++] = course;
    }

    for(int i = 0; i < numCourses; i++){
        if(dfs(i, graph, g_col, visited) == false){
            for(int j = 0; j < numCourses; j++)
                free(graph[j]);

            return false;
        }
    }

    for(int j = 0; j < numCourses; j++)
        free(graph[j]);
    
    return true;
}
