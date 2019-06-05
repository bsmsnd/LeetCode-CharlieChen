#include <iostream>
#include <climits>
using namespace std;

void swap(int *x, int *y);

class MinHeap
{
    int *harr; // pointer to array of elements in heap
    int capacity;  // maximum possible size of the min heap
    int heap_size; //current number of elements in the heap
public:
    MinHeap(int capacity);  // constructor
    void MinHeapify(int );  // to heapify a subtree with the root at given index
    int parent(int i) {return (i-1)/2;}  // get the parent index
    int left(int i) { return (2*i + 1); }  // to get the index of the left child of node at index i  // note how it is computed
    int right(int i) { return (2*i + 2); }  // right child
    int extractMin(); // to extract the root, which is the min. value, i.e., remove min. value and return it.
    void decreaseKey(int i, int new_val);  // decrease key value of key at index i to new_val
    int getMin(){return harr[0];}  // return the minimum key from minHeap
    void deleteKey(int i);  // deletes a key stored at index i
    void insertKey(int k);  // insert a new key 'k'
};

MinHeap::MinHeap(int cap)
{
    heap_size = 0;
    capacity = cap;
    harr = new int[cap];
}

void MinHeap::insertKey(int k)
{
    if (heap_size == capacity)
    {
        cout << "\nOverflow: Could not insertKey\n"; 
        return; 
    }

    // First insert the new key at the end
    heap_size++;
    int i = heap_size - 1;
    harr[i] = k;  // first fill in at the last index
    // Then fix the heap property if violated
    while(i!=0 && harr[parent(i)] > harr[i])
    {
        swap(&harr[i], &harr[parent(i)]);  // swap w/ its parent
        i = parent(i); // continue on the new inserted key until fixed
    }
}

void MinHeap::decreaseKey(int i, int new_val)  // assume that new_val < harr[i]
{
    harr[i] = new_val; // first change the value
    // then fix the heap
     while (i != 0 && harr[parent(i)] > harr[i]) 
    { 
       swap(&harr[i], &harr[parent(i)]); 
       i = parent(i); 
    } 
}

int MinHeap::extractMin()
{
    if (heap_size <= 0)
        return INT_MAX;
    if (heap_size == 1)
    {
        heap_size--;
        return harr[0];
    }

    int root = harr[0];
    harr[0] = harr[heap_size - 1];
    heap_size--;
    MinHeapify(0);
    return root;
}

void MinHeap::deleteKey(int i)
{
    decreaseKey(i, INT_MIN);
    extractMin();
}

void MinHeap::MinHeapify(int i)
{
    int l = left(i);
    int r = left(i);
    int smallest = i;
    if (l < heap_size && harr[l] < harr[i])
        smallest = l;
    if (r < heap_size && harr[r] < harr[smallest])
        smallest = r;
    if (smallest != i)
    {
        swap(&harr[i], &harr[smallest]);
        MinHeapify(smallest);
    }
}

void swap(int *x, int *y)
{ 
    int temp = *x; 
    *x = *y; 
    *y = temp; 
} 


