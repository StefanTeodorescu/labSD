//
// Created by Stefan Teodorescu on 07/03/16.
//

#ifndef LABSD_LISTA_H
#define LABSD_LISTA_H

template <class T>
class List {
private:
    T *array;
    int size;
    int capacity;

    class Iterator {
    private:
        T* now;
    public:
        Iterator ();
        ~Iterator ();

        void operator ++ ();
        void operator ++ (Iterator);
        T& operator * (Iterator);
        T* operator -> ();
    };
public:
    List ();
    List (int capacity);
    ~List ();

    typedef Iterator iterator;

    void insert (const T& element, int index);
    void remove (int index);
    void push_back (const T& element);
    void push_front (const T& element);

    iterator begin ();
    iterator end ();
};

#endif //LABSD_LISTA_H