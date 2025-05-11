#include <bits/stdc++.h>
using namespace std;
template<typename T> void bubbleSort(vector<T>& data, string type, long long& compCount) {
    int comparisons = data.size();
    for (int i = 0; i < comparisons - 1; i++, compCount++) {
        for (int j = 0; j < comparisons - i - 1; j++, compCount++) {
            if(type == "name"){
                if (data[j] > data[j + 1])
                    swap(data[j], data[j + 1]);
                compCount++;
            }
            else{
                if (data[j].get_gpa() <= data[j + 1].get_gpa())
                    swap(data[j], data[j + 1]);
                compCount++;
            }
            compCount++;
        }
        compCount++;
    }
    compCount++;
}
