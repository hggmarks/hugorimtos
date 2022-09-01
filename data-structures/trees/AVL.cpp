#include <bits/stdc++.h>
#include <iostream>

using std::cout;
using std::cin;

template <typename E>
class AVLnode {
    public:
        E key;
        AVLnode* left;
        AVLnode* right;
        int height;

        AVLnode(const E& item){
            key = item;
            left = NULL;
            right = NULL;
            height = 0;
        }
};

template <typename T>
class AVLTree {
    private:
        AVLnode<T>* root;
        int nodeCount;

        int h(AVLnode<T>* rt){
            if (rt == NULL) return -1;
            return rt->height;
        }

        int getBalance(AVLnode<T>*  rt){
            if (rt == NULL) return 0;
                return h(rt->left) - h(rt->right);
        }

        AVLnode<T>* leftRotate(AVLnode<T>* rt){
            AVLnode<T>* r = rt->right;
            AVLnode<T>* rl = r->left;
            r->left = rt;
            rt->right = rl;
            rt->height = 1 + std::max(h(rt->left), h(rt->right));
            r->height = 1 + std::max(h(r->left), h(r->right));

            return r;
        }

        AVLnode<T>* rightRotate(AVLnode<T>* rt){
            AVLnode<T>* l = rt->left;
            AVLnode<T>* lr = l->right;
            l->right = rt;
            rt->left = lr;
            rt->height = 1 + std::max(h(rt->left), h(rt->right));
            l->height = 1 + std::max(h(l->left), h(l->right));

            return l;
        }

        AVLnode<T>* insertHelp(AVLnode<T>* rt, T element){
            if (rt == NULL){
                AVLnode<T>* node = new AVLnode<T>(element);
                return node;
            } 

            if (element >= rt->key){
                rt->right = insertHelp(rt->right, element);
            } else {
                rt->left = insertHelp(rt->left, element);
            }

            rt->height = max(h(rt->left), h(rt->right));
            int balance = getBalance(rt);

            if ((balance < -1) && (element >= rt->right->key)) return leftRotate(rt);
            if ((balance > 1) && (element < rt->left->key)) return rightRotate(rt);

            if ((balance > 1) && (element >= rt->left->key)){
                rt->right = leftRotate(rt->left);
                return rightRotate(rt);
            }

            if ((balance < -1) && (element < rt->right->key)){
                rt->right = rightRotate(rt->right);
                return leftRotate(rt);
            }

            return rt;

            return root;
        }

        T findHelp(AVLnode<T>* rt, T k, int idx){
            if (rt == NULL) return -1;
            
            if (rt->key > k){
                return findHelp(rt->left, k);
            } else if (rt->key == k){
                return rt->key; 
            } else {
                return findHelp(rt->right, k);
            }
        }

    public:
        AVLTree(){
            root = NULL;
            nodeCount = 0;
        }

        void insert(AVLTree<T> avl, T element){
            avl.root = insertHelp(avl.root, element);
            nodeCount++;
        }

        T find(AVLTree<T> avl, T item){
            return findHelp(avl.root, item);
        }

        void preOrder(AVLnode<T>* rt){
            cout << rt->key << " ";
            preOrder(rt->left);
            preOrder(rt->right);         
        }

        void inOrder(AVLnode<T>* rt){
            inOrder(rt->left);
            cout << rt->key << " ";
            inOrder(rt->right);
        }

        void posOrder(AVLnode<T>* rt){
            posOrder(rt->left);
            posOrder(rt->right);
            cout << rt->key << " ";
        }
};
