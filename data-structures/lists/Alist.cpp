#include "list.h"


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

};