#include <iostream>
#include <algorithm> // for sort()
using namespace std;

// Function to display the array
void displayArray(int arr[], int size) {
    cout << "Array: ";
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    // Initialize a one-dimensional array
    int studentGrades[] = {85, 90, 78, 92, 88};
    int size = 5;

    // 1. Traversing
    cout << "1. Traversing:" << endl;
    displayArray(studentGrades, size);

    // 2. Searching
    int searchGrade = 92;
    cout << "\n2. Searching for grade " << searchGrade << ":" << endl;
    bool found = false;
    for (int i = 0; i < size; i++) {
        if (studentGrades[i] == searchGrade) {
            cout << "Grade found at index " << i << endl;
            found = true;
            break;
        }
    }
    if (!found) {
        cout << "Grade not found." << endl;
    }

    // 3. Insertion (at the end)
    int newGrade = 95;
    studentGrades[size] = newGrade;
    size++;
    cout << "\n3. After inserting grade " << newGrade << ":" << endl;
    displayArray(studentGrades, size);

    // 4. Deletion (remove grade 78)
    int deleteGrade = 78;
    int deleteIndex = -1;
    for (int i = 0; i < size; i++) {
        if (studentGrades[i] == deleteGrade) {
            deleteIndex = i;
            break;
        }
    }
    if (deleteIndex != -1) {
        for (int i = deleteIndex; i < size - 1; i++) {
            studentGrades[i] = studentGrades[i + 1];
        }
        size--;
    }
    cout << "\n4. After deleting grade " << deleteGrade << ":" << endl;
    displayArray(studentGrades, size);

    // 5. Sorting
    sort(studentGrades, studentGrades + size);
    cout << "\n5. After sorting:" << endl;
    displayArray(studentGrades, size);

    // 6. Merging
    int extraGrades[] = {80, 87};
    int extraSize = 2;
    int mergedSize = size + extraSize;
    int mergedGrades[mergedSize];
    for (int i = 0; i < size; i++) {
        mergedGrades[i] = studentGrades[i];
    }
    for (int i = 0; i < extraSize; i++) {
        mergedGrades[size + i] = extraGrades[i];
    }
    size = mergedSize;
    cout << "\n6. After merging with extra grades:" << endl;
    displayArray(mergedGrades, size);

    // 7. Update
    int updateIndex = 2;
    int updatedGrade = 99;
    mergedGrades[updateIndex] = updatedGrade;
    cout << "\n7. After updating index " << updateIndex << " to grade " << updatedGrade << ":" << endl;
    displayArray(mergedGrades, size);

    // 8. Display
    cout << "\n8. Final array:" << endl;
    displayArray(mergedGrades, size);

    return 0;
}