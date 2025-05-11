#include <bits/stdc++.h>
using namespace std;

template<typename T> int partition(vector<T>& std, int l, int r, long long& compCount){
    auto piv = std[l];
    int i=l, j=r;
    while(i < j){
        do{
            i++;
            compCount++;
        }
        while(std[i] <= piv and i<r);
        do {
            j--;
            compCount++;
        }
        while(std[j] > piv and j>l);
        if(i < j)
            swap(std[i], std[j]);
        compCount++;
        compCount++;
    }
    compCount++;
    swap(std[l], std[j]);
    return j;
}

template<typename T> int partition_gpa(vector<T>& std, int l, int r, long long& compCount){
    auto piv = std[l];
    int i=l, j=r;
    while(i < j){
        do{
            i++;
            compCount++;
        }
        while(std[i].get_gpa() >= piv.get_gpa() and i < r);
        do {
            j--;
            compCount++;
        }
        while(std[j].get_gpa() < piv.get_gpa() and j > l);
        if (i < j)
            swap(std[i], std[j]);
        compCount++;
        compCount++;
    }
    compCount++;
    swap(std[l], std[j]);
    return j;
}

template<typename T> void quickSort(vector<T>& std, int l, int r, string type, long long& compCount){
    if(l >= r)
        return;
    compCount++;
    int piv;
    transform(type.begin(), type.end(), type.begin(), ::tolower);
    if(type == "name")
        piv = partition(std, l, r, compCount);
    else if(type == "gpa")
        piv = partition_gpa(std, l, r, compCount);
    compCount++;
    quickSort(std, l, piv, type, compCount);
    quickSort(std, piv+1, r, type, compCount);
}