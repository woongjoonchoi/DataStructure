#include <vector>
#include <utility>
#include <iostream>
#include <algorithm>
using namespace std;
bool cmp(vector<int> a , vector<int> b){
    if (a[1] != b[1]) return a[1]  > b[1] ;
    
    else return a[0] < b[0];
    
}

class Node{
    private:
        pair<int , vector<int>>  data; 

    // left,right 가필요   
    public:
        Node * left = NULL;
        Node * right = NULL;
        Node(int num , int x , int y);
        int get_data();
        int get_num();
};

Node::Node(int num , int x , int y){
    vector<int> temp;
    temp.push_back(x);temp.push_back(y);
    this->data =  make_pair(num , temp);
    
}
// x좌표 리턴
int Node::get_data(){
    return this->data.second[0];
}

int Node::get_num(){
    return this->data.first;
}

class BST{
    private :
        Node *root=NULL;
        vector<int> trav;
    public :
        BST(Node *root);

        void insert(Node *root,Node *node);

        void search(int data);

        void postorder(Node *node) ;

        void preorder(Node *node);

        void print_t();

        Node *get_root();
};

void BST::print_t(){
    for(auto c: this->trav){
        cout<<c<<endl;
    }
}
Node* BST::get_root(){
    return this->root;
}
BST::BST(Node *root){
    this->root = root;
}
void BST::insert(Node *root , Node *node)
{
    // Node node (k->get_num(),k->get_data(),k->get_1());
    if(this->root == NULL) {
        this->root = node;
        return;
    }
    if(node->get_data() > root->get_data() ){
        if(root->right == NULL) {
            root->right = node;
            return;
        }else{
            insert((root->right) , node);
        }
    }else if(node->get_data() < this->root->get_data()){
        if(root->left == NULL) {
            root->left = node;
            return;
        }else{
            insert((root->left) , node);
        }
    }
}
// why 포인터? 삽입할때마다 node의
void BST::postorder(Node *node){
    trav.push_back(node->get_num());
    if(node->left!=NULL)postorder(node->left);
    if(node->right!=NULL)postorder(node->right);
}

void BST::preorder(Node *node){
    if(node->left!=NULL)preorder(node->left);
    if(node->right!=NULL)preorder(node->right);
    trav.push_back(node->get_num());
}

void BST::search(int data)
{

}

int main()
{
    vector<vector<int>> nodeinfo ;
    int arr[][2] = {{5, 3}, {11, 5}, {13, 3}, {3, 5}, {6, 1}, {1, 3}, {8, 6}, {7, 2}, {2, 2}} ;

    for(int i  = 0 ; i<9;i++){

        vector<int> a;
        for(int k = 0 ;k<2;k++){ 
            a.push_back(arr[i][k]);
        }

        a.push_back(i+1);
        nodeinfo.push_back(a);
    }
    sort(nodeinfo.begin(),nodeinfo.end(),cmp);
    Node *a =  new Node(nodeinfo[0][2],nodeinfo[0][0],nodeinfo[0][2]) ;
    BST b(a);
    for(int i = 1;i<nodeinfo.size();i++){
        Node *c = new Node(nodeinfo[i][2],nodeinfo[i][0],nodeinfo[i][2]);
        // cout<<&c<<endl;
        b.insert(b.get_root(),c );
    }
    // Node a()

    b.postorder((b.get_root()));
    b.print_t();
    return 0;
}