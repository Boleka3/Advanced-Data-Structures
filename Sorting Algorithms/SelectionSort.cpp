#include <bits/stdc++.h>
using namespace std;
template<typename T> void selectionSort(vector<T>& data, string type, long long& compCount) {
    int comparisons = data.size();
    for (int i = 0; i < comparisons - 1; i++, compCount++) {
        int Minimum = i;
        for (int j = i + 1; j < comparisons; j++, compCount++) {
            if(type == "name"){
                if (data[j] < data[Minimum])
                    Minimum = j;
                compCount++;
            }
            else {
                if (data[j].get_gpa() >= data[Minimum].get_gpa())
                    Minimum = j;
                compCount++;
            }
            compCount++;
        }
        if (Minimum != i)
            swap(data[Minimum],data[i] );
        compCount++;
        compCount++;
    }
    compCount++;
}
