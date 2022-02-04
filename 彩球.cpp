#include <iostream>
#include <vector>
#include <random>
#include <algorithm>

using namespace std;

std::random_device rd;
std::default_random_engine gen = std::default_random_engine(rd());

vector<int> generateUniqueRandomArray(int n, int rangeL, int rangeR) {
    vector<int> arr(n);
    std::uniform_int_distribution<int> dis(rangeL, rangeR);
    int random;
    for (int i = 0; i < n; i++) {
        do {
            random = dis(gen);
        } while (std::find(arr.begin(), arr.end(), random) != arr.end());
        arr[i] = random;
    }
    return arr;
}

int main() {
    cout << "彩球遊戲" << endl;
    vector<int> answer;
    int size;
    cout << "how many balls do you want to play?" << endl;
    cin >> size;
    cout << "what are the balls' range?" << endl;
    int rangeL, rangeR;
    cin >> rangeL >> rangeR;
    //check if range is valid
    if (rangeL > rangeR) {
        cerr << "range is invalid" << endl;
        return 0;
    }
    //check if range is smaller than size
    if (rangeR - rangeL + 1 < size) {
        cerr << "range is too small" << endl;
        return 0;
    }
    answer = generateUniqueRandomArray(size, rangeL, rangeR);
    printf("User input (%d~%d)\n", rangeL, rangeR);
    vector<int> input(size);
    for (int i = 0; i < size; i++) {
        cin >> input[i];
    }
    //check if the input's sizes are valid
    for (int i = 0; i < size; i++) {
        if (input[i] < rangeL || input[i] > rangeR) {
            cerr << "input error" << endl;
            return 0;
        }
    }
    //check if there are duplicate numbers in inputs
    vector<int> temp_check;
    temp_check = input;
    sort(temp_check.begin(), temp_check.end());
    if (std::adjacent_find(temp_check.begin(), temp_check.end()) != temp_check.end()) {
        cerr << "Duplicate numbers are not allowed." << endl;
        return 0;
    }
    //compare input and answer
    int count = 0;
    for (int i = 0; i < size; i++) {
        if (input[i] == answer[i]) {
            count++;
        }
    }
    cout << "You got " << count << " numbers right." << endl;
    //print all answers
    cout << "Answer: ";
    for (int i = 0; i < size; i++) {
        cout << answer[i] << " ";
    }
    //print input
    cout << "\nInput: ";
    for (int i = 0; i < size; i++) {
        cout << input[i] << " ";
    }
    return 0;
}