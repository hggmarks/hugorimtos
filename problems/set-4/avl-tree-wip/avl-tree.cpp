#include <bits/stdc++.h>

//template <typename E>
class AVLnode {
    public:
        int key;
        AVLnode* left;
        AVLnode* right;
        int leftNodes;
        int rightNodes;
        int height;

        AVLnode(int item){
            key = item;
            left = right = NULL;
            leftNodes = rightNodes = height = 0;
        }
};

//template <typename T>
class AVLTree {
    private:

        int h(AVLnode* rt){
            if (rt == NULL) return -1;
            return rt->height;
        }

        int max(int x, int y){
            return (x>y) ? x : y;
        }

        int getBalance(AVLnode*  rt){
            if (rt == NULL) return 0;
                return h(rt->left) - h(rt->right);
        }

        AVLnode* leftRotate(AVLnode* rt){

            AVLnode* r = rt->right;
            AVLnode* rl = r->left;
            r->left = rt;
            rt->right = rl;

            rl == NULL ? rt->rightNodes = 0 : rt->rightNodes = rl->rightNodes + rl->leftNodes + 1;

            rt == NULL ? r->leftNodes = 0 : r->leftNodes = rt->leftNodes + rt->rightNodes + 1;

            rt->height = 1 + max(h(rt->left), h(rt->right));
            r->height = 1 + max(h(r->left), h(r->right));

            return r;
        }

        AVLnode* rightRotate(AVLnode* rt){
            AVLnode* l = rt->left;
            AVLnode* lr = l->right;
            l->right = rt;
            rt->left = lr;

            lr == NULL ? rt->leftNodes = 0 : rt->leftNodes = lr->leftNodes + lr->rightNodes + 1;

            rt == NULL ? l->rightNodes = 0 : l->rightNodes = rt->leftNodes + rt->rightNodes + 1;

            rt->height = 1 + max(h(rt->left), h(rt->right));
            l->height = 1 + max(h(l->left), h(l->right));

            return l;
        }

        AVLnode* insertHelp(AVLnode* rt, int element){
            if (rt == NULL){
                return new AVLnode(element);
            } 

            if (element >= rt->key){
                rt->right = insertHelp(rt->right, element);
                rt->rightNodes++;
            } else {
                rt->left = insertHelp(rt->left, element);
                rt->leftNodes++;
            }

            rt->height = 1 + max(h(rt->left), h(rt->right));
            int balance = getBalance(rt);

            if ((balance < -1) && (element >= rt->right->key)) return leftRotate(rt);
            if ((balance > 1) && (element < rt->left->key)) return rightRotate(rt);
            
            if ((balance > 1) && (element >= rt->left->key)){
                rt->left = leftRotate(rt->left);
                return rightRotate(rt);
            } 
            
            if ((balance < -1) && (element < rt->right->key)){
                rt->right = rightRotate(rt->right);
                return leftRotate(rt);
            }

            return rt;

        }

        int findHelp(AVLnode* rt, int k, int idx){
            if (rt == NULL) return -1; 
            
            while(rt != NULL){

                if (rt->key < k){
                    idx += rt->leftNodes + 1;
                    rt = rt->right;
                } else if ( rt->key == k ){
                    return idx + rt->leftNodes + 1;
                } else {
                    rt = rt->left;
                }

                

            }

            return -1;


            // if (rt->key > k){
            //     return findHelp(rt->left, k, idx);
            // } else if (rt->key == k){
            //     return rt->leftNodes + idx + 1; 
            // } else {
                
            //     rt->left == NULL ? idx += 1 : idx += rt->left->leftNodes + rt->right->rightNodes + 2;
                
            // }
            //     return findHelp(rt->right, k, idx);
        }

    public:

        AVLnode* root;
        int nodeCount;

        AVLTree(){
            root = NULL;
            nodeCount = 0;
        }

        void insert(int element){
            root = insertHelp(root, element);
            nodeCount++;
        }

        int find(int item){
            return findHelp(root, item, 0);
        }
};


int main() {
    AVLTree avl;
    int q;
    int op, num, r;
    scanf("%d", &q);

    for (int i = 0; i < q; i++){
        scanf("%d %d", &op, &num);

        if (op == 1){
            avl.insert(num);
        } else {
            r = avl.find(num);

            r == -1 ? printf("Data tidak ada\n") : printf("%d\n", r);
        }
    }

    return 0;
}
