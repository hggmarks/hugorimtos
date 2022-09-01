#include <bits/stdc++.h>
#include <iostream>

#define endl '\n'

using std::cout;
using std::cin;


template <typename E>
class BSTnode {
    public:
        E key;
        BSTnode<E>* left;
        BSTnode<E>* right;
    
        BSTnode(const E& item){
            key = item;
            left = NULL;
            right = NULL;
        }
};

template <typename E>
class BSTree {
    private:
        
        BSTnode<E>* root;
        int nodeCount;

        BSTnode<E>* insertHelp(BSTnode<E>* root, E element){
            if (root == NULL){
                BSTnode<E>* node = new BSTnode<E>(element);
                return node;
            } 

            if (element >= root->key){
                root->right = insertHelp(root->right, element);
            } else {
                root->left = insertHelp(root->left, element);
            }

            return root;
        }

    public:

        BSTree(){
            root = NULL;
            nodeCount = 0;
        }

        void insert(BSTree<E> bst, E element){
            bst.root = insertHelp(bst.root, element);
            nodeCount++;
        }

        void preOrder(BSTnode<E>* rt){
            cout << rt->key << endl;
            preOrder(rt->left);
            preOrder(rt->right);         
        }

        void inOrder(BSTnode<E>* rt){
            inOrder(rt->left);
            cout << rt->key << endl;
            inOrder(rt->right);
        }

        void posOrder(BSTnode<E>* rt){
            posOrder(rt->left);
            posOrder(rt->right);
            cout << rt->key << endl;
        }
};


int main(){

    cin.tie(nullptr);
    std::ios_base::sync_with_stdio(false);
    
    int num_inputs, input;
    cin >> num_inputs;
    BSTree<int> tree{};
    
    for (int i=0; i<num_inputs; i++){
        cin >> input;
        tree.insert(tree, input);
    }

    cout << tree.root->key << endl;

    return 0;
}