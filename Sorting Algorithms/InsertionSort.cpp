#include <bits/stdc++.h>
using namespace std;
template<typename T> void insertionSort(vector<T>& data, string type, long long& compCount){
    int comparisons = data.size();
    for (int i = 1; i < comparisons; ++i, compCount++) {
        T key = data[i];
        int j = i - 1;
        if(type == "name"){
            while (j >= 0 && data[j] > key) {
                data[j + 1] = data[j];
                j--;
                compCount++;
            }
            compCount++;
        }
        else {
            while (j >= 0 && data[j].get_gpa() < key.get_gpa()) {
                data[j + 1] = data[j];
                j--;
                compCount++;
            }
            compCount++;
        }
        compCount++;
        data[j + 1] = key;
    }
    compCount++;
}
