#ifndef VERTEX_H 
#define VERTEX_H

template <typename T>
class Vertex {
    public:
        Vertex();
        T operator*();
    private:
        T* value;
};

template <typename T>
Vertex<T>::Vertex() {
    value = nullptr;
}

template <typename T>
T Vertex<T>::operator*() {
    return *value;
}

#endif
