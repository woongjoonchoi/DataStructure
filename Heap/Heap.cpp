// 1.insert
// 2.remove
// 3.swap

// MinHeap

#include<vector>
#include<iostream>
using namespace std;



class Heap{
    private:
        vector<int> tree;   

    public:

        // Heap();

        void remove();

        void insert(int data);

        void heapify(int level);

        void print();

};
// 

void Heap::heapify(int level)
{
    // int l = tree.size()-1;

    if(level==0){
        while(tree[level] >tree[2*level] && level<tree.size() ){
            int temp = tree[level];
            tree[level] = tree[2*level];
            tree[2*level] = temp;
            level=  2*level;
        }
    }
    else{
        while(tree[level] <tree[level/2] && level>=0 ){
            int temp = tree[level];
            tree[level] = tree[level/2];
            tree[level/2] = temp;
            level=  level/2;
        }
    }
    
}

void Heap::print()
{
    for(auto c: tree){
        cout<<c<<" ";
    }
}

void Heap::remove()
{
    // 1. swap last and root element. then pop back last
    int temp = tree.front();
    tree.front() = tree.back();
    tree.back() =tree.front();
    tree.pop_back();

    heapify(0);
    
}

void Heap::insert(int data)
{

    tree.push_back(data);

    heapify(tree.size()-1);
    
}


int main()
{

    Heap h;

    h.insert(4);

    h.insert(5);

    h.insert(30);
    h.insert(9);
    h.insert(7);
    h.print();
    return 0;
}