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


        void remove(int key);
        void insert(int data);

        void downheapify(int level);

        void upheapify(int level);

        void DecreaseKey(int key);

        void printh();


        bool hasLeft(int level);

        bool hasRight(int level);

};


// Heapify down과 Heapyifyup으로 나눠줘야한다.

// 특정 위치의 값을 삭제하기 위해서는  DecreaseKey가 필요하다.


bool Heap::hasLeft(int level)
{
    return level*2 + 1< tree.size();
}
bool Heap::hasRight(int level)
{
    return level*2 + 2< tree.size();
}
void Heap::DecreaseKey(int key )
{
    tree[key] = INT_MIN;
    while(key >= 0 && tree[key] < tree[key/2])
    {
        int temp = tree[key];
        tree[key] = tree[key/2];
        tree[key/2] = temp;
        key = key/2;
    }

}


void Heap::downheapify(int level)
{
    // int l = tree.size()-1;

    if(!hasLeft(level)) return;

    int smallest = level*2 +1;
    if(!hasRight(level)) {
        if(tree[smallest]  > tree[level*2+2]){
            smallest= level*2 + 2 ;
        }
    }
    if(tree[level] >tree[smallest]){
        int temp = tree[level];
        tree[level] = tree[smallest];
        tree[smallest] = temp;
        downheapify(smallest);
    }

    
}
void Heap::upheapify(int level)
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
void Heap::printh()
{
    for(auto c: tree){
        cout<<c<<" ";
    }
}

void Heap::remove()
// extract root
{
    // 1. swap last and root element. then pop back last
    int temp = tree.front();
    tree.front() = tree.back();
    tree.back() =tree.front();
    tree.pop_back();

    downheapify(0);
    
}
void Heap::remove(int key)
{
    // 1. swap last and root element. then pop back last
    DecreaseKey(key);
    int temp = tree.front();
    tree.front() = tree.back();
    tree.back() =tree.front();
    tree.pop_back();

    downheapify(0);
    
}

void Heap::insert(int data)
{

    tree.push_back(data);

    upheapify(tree.size()-1);
    
}


int main()
{

    Heap h;

    h.insert(4);

    h.insert(5);

    h.insert(30);
    h.insert(9);
    h.insert(7);
    h.remove(3);
    h.printh();
    return 0;
}