#include <iostream>
#include <vector>
using namespace std;


void print_vector(vector<int>& v)
{
    int n = v.size();
    cout<<"[";
    for (int i = 0;i < n-1; i++)
        cout<<v[i]<<",";
    cout<<v[n-1]<<"]\n";
}

void quicksort(vector<int>& v, int lo, int hi)
{
    if (lo >= hi)return;
    int l = lo + 1, r = hi;
    while(l<r)
    {
        while(l < r && v[l] < v[lo])l++;
        while(l < r && v[r] >= v[lo])r--;
        if (l < r)swap(v[l], v[r]);
    }
    if (v[l] > v[lo])
        l--;    
    swap(v[l], v[lo]);
    
    quicksort(v, lo, l-1);
    quicksort(v, r, hi);
}

int main()
{
    vector<int> a = {7,49,73,58,30,72,44,78,23,9,40,65,92,42,87,3,27,29,40,12,3};
    // vector<int> a = {6,5,4,3,2,1};
    // sort here
    quicksort(a, 0, a.size()-1);
    print_vector(a);
}