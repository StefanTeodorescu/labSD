//
// Created by Stefan Teodorescu on 07/03/16.
//
#ifndef LABSD_LISTA_H
#define LABSD_LISTA_H

using namespace std;

template <class T>
class List {
private:
    T* array;
    int size;
    int capacity;

    class Iterator {
        friend class List; //ca sa pot sa fac constructorii private
    private:
        int where;
        T* array;

        //am nevoie de referinte catre array ca sa pot returna un element din lista
        explicit Iterator(const List& L, int where = 0)
                : array(L.array), where(where)
        { }
        explicit Iterator(T* const array, int where = 0)
                : array(array), where(where)
        { }

    public:
        Iterator() {
            where = 0;
        }

        Iterator operator ++ () {
            where ++;
            return Iterator(array, where);
        }

        Iterator operator ++ (int) {
            const Iterator now = Iterator(array, where);
            where ++;
            return now;
        }

        Iterator operator -- () {
            const Iterator now = Iterator(array, where);
            where --;
            return now;
        }

        Iterator operator -- (int) {
            where --;
            return Iterator(array, where);
        }

        T& operator * () {
            return array[where];
        }

        T* operator -> () {
            return &array[where];
        }

        void operator = (const Iterator& it) {
            where = it.where;
            array = it.array;
        }

        bool operator != (const Iterator& it) {
            return array != it.array || where != it.where;
        }

        bool operator == (const Iterator& it) {
            return array == it.array && where == it.where;
        }
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
    
    void insert(const T& element, int index)
    {
        int i;

        if(index > size + 1)
        {
            cout<<"index out of bounds. Please try again!\n";
            return;
        }
        //vrem sa adaugam un element pe pozitia dorita
        if(size == capacity)
        {
            //in cazul in care elementul nu mai incape in vector, modificam dim vectorului
            
            T *new_array;
            new_array = new T[capacity * 2];

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
            capacity *= 2;
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

    void remove(const T& element, unsigned index)
    {
        int i;

        if(index > size)
        {
            cout<<"Index out of bounds. Please try again!\n";
            return;
        }



        size --;
    }


    void push_back(const T& element)
    {
        if (size == capacity)
        {
            T *new_array;
            new_array = new T[capacity * 2];
        
            for(int i = 0; i < size; i++)
            {
                new_array[i] = array[i];
            }

            delete[] array;
            array = new_array;
            capacity = capacity * 2;
        }
        
        //adaugam noul element

        array[size] = element;
        size ++;
    }
    void push_front(const T& element)
    {
        if( size == capacity)
        {
            T *new_array;
            new_array = new T[capacity * 2];

            //Copiem toate elementele in noul vector, decalate cu o pozitie
            for(int i = 1; i <= size; i++)
            {
                new_array[i] = array[i - 1];
            }

            delete[] array;
            array = new_array;
            capacity = capacity * 2;
        }

        //Adaugam noul element pe pozitia 0
        array[0] = element;
        size ++;
    }

    T& operator [] (int index) {
        return array[index];
    }

    int length() {
        return size;
    }

    iterator begin() {
        return Iterator(*this);
    }
    iterator end() {
        return Iterator(*this, size);
    }
};

#endif //LABSD_LISTA_H
