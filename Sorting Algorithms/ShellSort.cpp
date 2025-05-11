#include <bits/stdc++.h>
using namespace std;
template<typename T> void shellSort(vector<T>& data, string type, long long& compCount) {
    int comparisons = data.size();
    for (int space = comparisons / 2; space > 0; space = space/2, compCount++) {
        for (int i = space; i < comparisons; i++, compCount++) {
            T temp = data[i];
            int j;
            if(type == "name"){
                for ( j = i; j >= space && data[j - space] > temp; j = j-space, compCount++)
                    data[j] = data[j - space];
            }
            else {
                for ( j = i; j >= space && data[j - space].get_gpa() < temp.get_gpa(); j = j-space, compCount++)
                    data[j] = data[j - space];
            }
            compCount++;
            data[j] = temp;
        }
        compCount++;
    }
    compCount++;
}