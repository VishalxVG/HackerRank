//*There is a collection of input strings and a collection of query strings. 
//*For each query string, determine how many times it occurs in the list of input strings. Return an array of the results. 

#include <iostream>
#include <vector>
#include <unordered_map>

std::vector<int> countOccurrences(const std::vector<std::string>& firstVector, const std::vector<std::string>& secondVector) {
    // Create a map to store the count of occurrences for each element in the first vector
    std::unordered_map<std::string, int> occurrenceCount;

    // Count occurrences for each element in the first vector
    for (const auto& element : firstVector) {
        occurrenceCount[element]++;
    }

    // Initialize the result vector to store the counts for each element in the second vector
    std::vector<int> result;

    // Count occurrences for each element in the second vector
    for (const auto& element : secondVector) {
        // If the element is found in the map, store its count; otherwise, store 0
        result.push_back(occurrenceCount.find(element) != occurrenceCount.end() ? occurrenceCount[element] : 0);
    }

    return result;
}

int main() {
    // Example vectors
    std::vector<std::string> firstVector = {"apple", "banana", "orange", "apple", "banana"};
    std::vector<std::string> secondVector = {"apple", "banana", "grape", "orange"};

    // Get the occurrence counts
    std::vector<int> occurrenceCounts = countOccurrences(firstVector, secondVector);

    // Display the result
    std::cout << "Occurrence Counts: ";
    for (int count : occurrenceCounts) {
        std::cout << count << " ";
    }
    std::cout << std::endl;

    return 0;
}
