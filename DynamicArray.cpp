// • Declare a 2-dimensional array, arr, of n empty arrays. All arrays are zero indexed.
// • Declare an integer, last Answer, and initialize it to 0.
// • There are 2 types of queries, given as an array of strings for you to parse:
// 1. Query: 1 x y
// 1. Let idx = ((x ^ last Answer) % n).
// 2. Append the integer y to arr[idx].
// 2. Query: 2 x y
// 1. Let idx = ((x ^ last Answer) % n).
// 2. Assign the value arr[idx][y % size (arr[idx])] to last Answer.
// 3. Store the new value of last Answer to an answers array.
// [" ^ " is a bitwise XOR operation]

#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, q;
    cin >> n >> q;

    vector<vector<int>> arr(n);
    int lastAnswer = 0;

    vector<int> answers;

    for (int i = 0; i < q; ++i) {
        int queryType, x, y;
        cin >> queryType >> x >> y;

        int idx = (x ^ lastAnswer) % n;

        if (queryType == 1) {
            arr[idx].push_back(y);
        } else if (queryType == 2) {
            int sizeArrIdx = arr[idx].size();
            lastAnswer = arr[idx][y % sizeArrIdx];
            answers.push_back(lastAnswer);
        }
    }

    // Output the answers array
    for (int ans : answers) {
        cout << ans << endl;
    }

    return 0;
}
