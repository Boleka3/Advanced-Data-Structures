#include <bits/stdc++.h>
using namespace std;
template<typename T> void merge(vector<T>& stds, int l, int mid, int r, long long& compCount){
    int n = mid - l + 1, m = r-mid;
    T subone[n], subtwo[m];
    for(int i=0; i<n; i++, compCount++)
        subone[i] = stds[i+ l];
    compCount++;
    for(int i=0; i<m; i++, compCount++)
        subtwo[i] = stds[i + mid+1];
    compCount++;
    int i=0, j=0, k=l;

    while(i<n and j<m){
        if(subone[i] < subtwo[j])
            stds[k++] = subone[i++];
        else
            stds[k++] = subtwo[j++];
        compCount++;
        compCount++;
    }
    for(; i<n; i++, compCount++)
        stds[k++] = subone[i];
    compCount++;
    for(; j<m; j++, compCount++)
        stds[k++] = subtwo[j];
    compCount++;
}

template<typename T> void merge_gpa(vector<T>& stds, int l, int mid, int r, long long& compCount){
    int n = mid - l + 1, m = r-mid;
    T subone[n], subtwo[m];
    for(int i=0; i<n; i++, compCount++)
        subone[i] = stds[i+ l];
    compCount++;
    for(int i=0; i<m; i++, compCount++)
        subtwo[i] = stds[i + mid+1];
    compCount++;
    int i=0, j=0, k=l;

    while(i<n and j<m){
        if(subone[i].get_gpa() >= subtwo[j].get_gpa())
            stds[k++] = subone[i++];
        else
            stds[k++] = subtwo[j++];
        compCount++;
        compCount++;
    }
    compCount++;
    for(; i<n; i++, compCount++)
        stds[k++] = subone[i];
    compCount++;
    for(; j<m; j++, compCount++)
        stds[k++] = subtwo[j];
    compCount++;
}


template<typename T> void mergeSort(vector<T> &stds, int l, int r, string type, long long&compCount) {
    if(l < r){
        int mid = (l+r)/2;
        mergeSort(stds, mid + 1, r, type, compCount);
        mergeSort(stds, l, mid, type, compCount);
        transform(type.begin(), type.end(), type.begin(), ::tolower);
        if(type == "name")
            merge(stds, l, mid, r, compCount);
        else
            merge_gpa(stds, l, mid, r, compCount);
        compCount++;
    }
    compCount++;
}
