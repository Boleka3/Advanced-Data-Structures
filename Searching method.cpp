#include <iostream>
#include "bits/stdc++.h"
using namespace std;

int sequential_search(vector<int>& v, int x )
{
    for(int i = 0; i < v.size(); i++)
    {
        if(v[i]==x)
        {
            return i;
        }
    }
    return -1;
}

int recursive_search(vector<int>& v ,int x,  int i=0)
{
    if(i==v.size())
    {
        return -1;
    }
    if(x==v[i])
    {
        return i;
    }
    return recursive_search(v,x,i+1);
}

int Binary_search(vector<int>& v, int target) {
    int left=0 , right=(int)v.size()-1;
    while(left<=right)
    {
        int mid = left+(right-left) /2;
        if(v[mid]==target)
        {
            return mid;
        }
        else if(v[mid]<target)
        {
            left=mid+1;
        }
        else{
            right=mid-1;
        }
    }
    return -1;
}

int recursive_Binary_search(int left, int right, vector<int>&v, int target)
{
    if(left>right)
    {
        return -1;
    }
    int mid=left+(right-left)/2;
    if(v[mid]==target)
    {
        return mid;
    }
    if(v[mid]>target)
    {
       return recursive_Binary_search(left,mid-1,v,target);
    }
    else
    {
        return recursive_Binary_search(mid+1,right,v,target);
    }
}


int main() {
    vector<int>v;
    v={1,2,3,4,5};
    cout<<"choose number ";
    int target;
    cin>>target;
    cout<< recursive_search(v,target)<<"\n";
    

}
