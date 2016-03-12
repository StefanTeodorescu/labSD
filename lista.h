//
// Created by Stefan Teodorescu on 07/03/16.
//
#include<iostream>
using namespace std;
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
        Iterator();
        ~Iterator();

        void operator ++ ();
        void operator ++ (Iterator);
        T& operator * (Iterator);
        T* operator -> ();
    };
public:
    List()
    {
        this->capacity = 1;
        this->size = 0;
        this->array = new T[capacity];
    }
    List(int capacity) {
        this -> capacity = capacity;
        this -> size = 0;
        this -> array = new T[capacity];
    }
    ~List()
    {
        delete[] array;
    }

    typedef Iterator iterator;
    
    int insert(const T& element, int index)
    {
        int i;

        if(index > size + 1)
        {
            cout<<"index out of bounds. Please try again!\n";
            return 0;
        }
        //vrem sa adaugam un element pe pozitia dorita
        if(size == capacity)
        {
            //in cazul in care elementul nu mai incape in vector, modificam dim vectorului
            
            T *new_array;
            new_array = new T[capacity+1];

            //elementele se gasesc in vector incepang cu array[0]
            //pozitia index se va gasi in vector la v[index-1]

            for( i = 0; i < index - 1 ; i++){
                new_array[i]=array[i];
            }
            
            new_array[i] = element;
            
            for( i = index; i <= size; i++)
            {
                new_array[i]=array[i-1];
            }

            delete[] array;
            array = new_array;
            capacity++;
        }
        else
        {
            for( i = index - 1; i < size; i++)
            {
                array[i+1] = array[i];
            }
            
            array[index-1] = element;
        }

        size++;
    }

    void remove(int index);

    void push_back(const T& element)
    {
        if (size == capacity)
        {
            T *new_array;
            new_array = new T[capacity+1];
        
            for(int i = 0; i < size; i++)
            {
                new_array[i] = array[i];
            }

            delete[] array;
            array = new_array;
            capacity = capacity + 1; 
        }
        
        //adaugam noul element

        array[size] = element;
        size ++;
    }
    void push_front(const T& element);

    T operator [] (int index) {
        return array[index];
    }

    int length() {
        return size;
    }

    iterator begin();
    iterator end();
};

#endif //LABSD_LISTA_H