#include "list.h"
#include <bits/stdc++.h>

using std::cout;
using std::endl;

template<typename E>
class AList: public List<E> {
    private:
        int maxArrSize;
        int listSize;
        int cursor;
        E *listArr;

    public:
        //CONSTRUCTOR
        AList(int size=10) {
            maxArrSize = size;
            listSize = cursor = 0;
            listArr = new E[maxArrSize]; //?????????
        }
        //DESTRUCTOR
        ~AList(){
            delete [] listArr;
        }

        void clear() {
            delete [] listArr;
            listSize = cursor = 0;
            listArr = new E[maxArrSize];
        }

        void insert(const E& element){
            if (listSize < maxArrSize){
                for(int i = listSize; i < cursor; i--){
                    listArr[i] = listArr[i-1];
                }
                listArr[cursor] = element;
                listSize++;
            } else {
                cout << "the list is full, cannot insert elements" << endl;
            }
        }

        void append(const E& element){
            if(listSize < maxArrSize){
                listArr[listSize++] = element;
            } else {
                cout << "the list is full, cannot append elements" << endl;
            }
        }

        E remove(){
            if( (cursor >=0) && (cursor < listSize) ){
                E element = listArr[cursor];

                for (int i = cursor; i<listSize-1; i++){
                    listArr[i] = listArr[i+1];
                }
                listSize--;
                return element;
            }
        }

        void moveToStart(){ cursor = 0; }
        void moveToEnd(){ cursor = listSize; }
        void prev(){ if (cursor > 0) cursor--; }
        void next(){ if (cursor < listSize) cursor++; }

        int length() const { return listSize; }

        int cursorPos() const { return cursor; }

        void moveToPos(int pos) {
            if ((pos>=0) && (pos<=listSize))    {
                cursor = pos;
            } else {
                cout << "position out of range" << endl;
            }
        }

        const E& getValue() const {
            if ((cursor>=0) && (cursor<listSize)) {
                return listArr[cursor];
            } else {
                cout << "No current element" << endl;
            }
        }

};
