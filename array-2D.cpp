#include <iostream>
#include <algorithm> // for sort()
using namespace std;

// Function to display the 2D array
void displayMatrix(int matrix[][3], int rows, int cols) {
    cout << "Matrix:" << endl;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
}

int main() {
    // Initialize a 2D array (3x3 matrix)
    int classroomGrades[3][3] = {
        {85, 90, 78},
        {92, 88, 95},
        {80, 87, 82}
    };
    int rows = 3, cols = 3;

    // 1. Traversing
    cout << "1. Traversing:" << endl;
    displayMatrix(classroomGrades, rows, cols);

    // 2. Searching
    int searchGrade = 88;
    cout << "\n2. Searching for grade " << searchGrade << ":" << endl;
    bool found = false;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (classroomGrades[i][j] == searchGrade) {
                cout << "Grade found at position (" << i << ", " << j << ")" << endl;
                found = true;
                break;
            }
        }
        if (found) break;
    }
    if (!found) {
        cout << "Grade not found." << endl;
    }

    // 3. Insertion (not applicable for fixed-size 2D arrays)

    // 4. Deletion (set grade at (1, 1) to 0)
    int deleteRow = 1, deleteCol = 1;
    classroomGrades[deleteRow][deleteCol] = 0;
    cout << "\n4. After deleting grade at (" << deleteRow << ", " << deleteCol << "):" << endl;
    displayMatrix(classroomGrades, rows, cols);

    // 5. Sorting (flatten, sort, and reshape)
    int flatArray[rows * cols];
    int index = 0;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            flatArray[index++] = classroomGrades[i][j];
        }
    }
    sort(flatArray, flatArray + (rows * cols));
    index = 0;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            classroomGrades[i][j] = flatArray[index++];
        }
    }
    cout << "\n5. After sorting:" << endl;
    displayMatrix(classroomGrades, rows, cols);

    // 6. Merging (not applicable for fixed-size 2D arrays)

    // 7. Update
    int updateRow = 2, updateCol = 2;
    int updatedGrade = 99;
    classroomGrades[updateRow][updateCol] = updatedGrade;
    cout << "\n7. After updating position (" << updateRow << ", " << updateCol << ") to grade " << updatedGrade << ":" << endl;
    displayMatrix(classroomGrades, rows, cols);

    // 8. Display
    cout << "\n8. Final matrix:" << endl;
    displayMatrix(classroomGrades, rows, cols);

    return 0;
}