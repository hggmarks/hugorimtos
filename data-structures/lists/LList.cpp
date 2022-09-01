#include "list.h"
#include "bits/stdc++.h"

using std::cout;
using std::endl;

template <typename E>
class Node {
    public:
        E element;
        Node *next;
        
        Node(const E& elementVal, Node* nextNode = NULL) {
            element = elementVal;
            next = nextNode;
        }

        Node(Node* nextNode = NULL) {
            next = nextNode;
        }
};

template <typename E>
class LList: public List<E> {
    private:
        Node<E>* head;
        Node<E>* tail;
        Node<E>* cursor;
        int listSize;

        void init(){
            cursor = tail = head = new Node<E>;
            listSize = 0;
        }

        void removeAll() {
            while(head != NULL) {
                cursor = head;
                head = head->next;
                delete cursor;
            }
        }

    public:
        LList(int size = 10) {
            init();
        }

        ~LList() {
            removeAll();
        }

        //void print() const;
        void clear() {
            removeAll();
            init();
        }

        void insert(const E& element) {
            cursor->next = new Node<E>(element, cursor->next);
            if(tail == cursor) tail = cursor->next;
            listSize++;
        }

        void append(const E& element) {
            tail->next = new Node<E>(element, NULL);
            tail = tail->next;
            listSize++;
        }

        E remove() {
            if(cursor->next != NULL) {
                E element = cursor->next->element;
                Node<E> tempNode = cursor->next;
                if(tail == cursor->next) tail = cursor;
                cursor->next = cursor->next->next;
                delete tempNode;
                listSize--;
                return element;
            } else {
                cout << "No element" << endl;
            }
        }

        void moveToStart() { cursor = head; }
        void moveToEnd() {cursor = tail; }

        void prev(){
            if(cursor == head) return;

            Node<E> tempHead = head;

            while (tempHead.next != cursor){
                tempHead = tempHead.next;
            }
            cursor = tempHead;
        }

        void next(){
            if(cursor != tail) cursor = cursor->next;
        }

        int length() const { return listSize; }

        int cursorPos() const {
            Node<E> tempHead = head;

            for(int i=0; cursor != tempHead; i++){
                tempHead = tempHead.next;
            }
        }

        void moveToPos(int pos) {
            if((pos>=0) && (pos<=listSize)){
                cursor = head;
                for(int i=0; i<pos; i++){
                    cursor = cursor->next;
                }
            } else {
                cout << "Position out of range" << endl;
            }
        }

        const E& getValue() const {
            if(cursor->next != NULL){
                return cursor->next->element;
            } else {
                cout << "No value" << endl;
            }
        }
};

