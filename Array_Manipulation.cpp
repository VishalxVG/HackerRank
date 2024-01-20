
//*Starting with a 1-indexed array of zeros and a list of operations, for each operation add 
//*a value to each the array element between two given indices, 
//*inclusive. Once all operations have been performed, return the maximum value in the array. 


#include <iostream>
#include <vector>

long arrayManipulation(int n, vector<vector<int>> queries) {
    vector<long> array(n + 2, 0);  // Use long to prevent overflow

    for (const auto& operation : queries) {
        int start_index = operation[0];
        int end_index = operation[1];
        int value_to_add = operation[2];

        array[start_index] += value_to_add;
        if (end_index + 1 <= n) {
            array[end_index + 1] -= value_to_add;
        }
    }

    long max_value = 0;
    long current_value = 0;

    for (int i = 1; i <= n; i++) {
        current_value += array[i];
        max_value = max(max_value, current_value);
    }

    return max_value;
}


int main() {
    // Example usage with dynamic arrays inside a vector
    int arraySize = 5;
    std::vector<std::vector<int>> operations = {
        {1, 3, 2},
        {2, 5, 5},
        {1, 2, 1}
    };

    int result = performOperationsAndGetMaxValue(arraySize, operations);

    std::cout << "Maximum value in the array after operations: " << result << std::endl;

    return 0;
}
