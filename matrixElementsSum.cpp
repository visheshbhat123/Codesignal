/*Given matrix, a rectangular matrix of integers, where each value represents the cost of the room, your task is to return the total sum of all rooms that are suitable for the CodeBots (ie: add up all the values that don't appear below a 0).

Example

For

matrix = [[0, 1, 1, 2], 
          [0, 5, 0, 0], 
          [2, 0, 3, 3]]
the output should be
solution(matrix) = 9.*/

int solution(vector<vector<int>> matrix) {
int totalSum = 0;
    int numRows = matrix.size();
    int numCols = matrix[0].size();

    // Create a boolean flag to keep track of whether a room is suitable or not
    vector<vector<bool>> isSuitable(numRows, vector<bool>(numCols, true));

    // Check each room starting from the top row
    for (int i = 0; i < numRows; i++) {
        for (int j = 0; j < numCols; j++) {
            // If the current room is below a 0, mark it as unsuitable
            if (i > 0 && matrix[i-1][j] <= 0) {
                isSuitable[i][j] = false;
            }
            if (i > 1 && !isSuitable[i-1][j]) {
                isSuitable[i][j] = false;
            }
            // If the current room is suitable, add its cost to the total sum
            if (isSuitable[i][j]) {
                totalSum += matrix[i][j];
            }
        }
    }

    return totalSum;
}
