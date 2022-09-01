#ifndef _LIST_H
#define _LIST_H

template <typename E>
class List {
    private:
        void operator = (const List&) {}
        List (const List&) {}

    public:
        List() {}
        virtual ~List() {}
        
        //removes all content of the list (making it empty)
        virtual void clear() = 0;

        //adds the "item" element at cursor right
        virtual void insert(const E &element) = 0;

        //adds the "item" element at the end of the list
        virtual void append(const E &element) = 0;

        //removes the element at the right of the cursor from the list
        virtual E remove() = 0;

        //moves the cursor to the start of the list
        virtual void moveToStart() = 0;

        //moves the cursor to the end of the list
        virtual void moveToEnd() = 0;

        //moves the cursor one step left, no change if at the start
        virtual void prev() = 0;

        //moves the cursor one step right, no change if at the end
        virtual void next() = 0;

        //return the lenght of the list (number of elements)
        virtual int length() = 0;

        //return the current position of the cursor
        virtual int cursorPos() const = 0;

        //moves the cursor to the "pos" position
        virtual void moveToPos(int pos) = 0;

        //return the element at the right of the cursor
        virtual const E& getValue() const = 0;
};
#endif
