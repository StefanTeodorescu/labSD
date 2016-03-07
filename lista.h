//
// Created by Stefan Teodorescu on 07/03/16.
//

#ifndef LABSD_LISTA_H
#define LABSD_LISTA_H

template <class T>
class List {
private:
    T *first, *last;

    class Iterator {
        T* now;

        void operator++ ();
        void operator++ (Iterator);
        T* operator* (Iterator);
        T* operator-> ();
    };
public:
    typedef Iterator iterator;

    void insert (T element, int index);
    void remove (int index);
    void push_back (T element);
    void push_front (T element);

    Iterator begin ();
    Iterator end ();
};

#endif //LABSD_LISTA_H
