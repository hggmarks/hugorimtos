#include <bits/stdc++.h>
#include <iostream>

using std::cout;
using std::cin;

template <typename E>
class BSTnode {
    public:
        E key;
        BSTnode* left;
        BSTnode* right;
    
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

        void preOrder(BSTnode<E>* root){
            cout << root->key << " ";
            preOrder(root->left);
            preOrder(root->right);         
        }

        void inOrder(BSTnode<E>* root){
            inOrder(root->left);
            cout << root->key;
            inOrder(root->right);
        }

        void posOrder(){}
};
