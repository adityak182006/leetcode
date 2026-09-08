char* convert(char* s, int numRows) {
    
    int len = strlen(s);

    // Edge cases: No zigzag needed
    if (numRows <= 1 || len <= numRows) {
        char* result = (char*)malloc((len + 1) * sizeof(char));
        strcpy(result, s);
        return result;
    }

    // Allocate array of pointers for each row buffer
    char** rows = (char**)malloc(numRows * sizeof(char*));
    int* rowSizes = (int*)calloc(numRows, sizeof(int));

    for (int i = 0; i < numRows; i++) {
        // Allocate worst-case memory per row (+1 for null terminator)
        rows[i] = (char*)malloc((len + 1) * sizeof(char));
    }

    int currRow = 0;
    bool goingDown = false;

    // Traverse input string and append characters to corresponding rows
    for (int i = 0; i < len; i++) {
        rows[currRow][rowSizes[currRow]++] = s[i];

        // Change direction at boundary rows
        if (currRow == 0 || currRow == numRows - 1) {
            goingDown = !goingDown;
        }

        currRow += goingDown ? 1 : -1;
    }

    // Combine all rows into final result string
    char* result = (char*)malloc((len + 1) * sizeof(char));
    int idx = 0;

    for (int i = 0; i < numRows; i++) {
        for (int j = 0; j < rowSizes[i]; j++) {
            result[idx++] = rows[i][j];
        }
        free(rows[i]); // Free row memory
    }

    result[idx] = '\0'; // Null-terminate result

    free(rows);
    free(rowSizes);

    return result;
}
