#ifndef EDGE_H
#define EDGE_H

#include <list>

#include "vertex.hpp"

template <typename Tedge, typename Tvertex>
class Edge {
    public: 
        Edge(Vertex<Tvertex> a, Vertex<Tvertex> b, Tedge* v);

        Tedge get_value();

        typename std::list<Vertex<Tvertex>>::iterator get_end_vertices();
        typename std::list<Vertex<Tvertex>>::iterator get_opposite_vertex_of(typename std::list<Vertex<Tvertex>>::iterator v);

    private:
        Tedge* value;
        std::list<Vertex<Tvertex>> vertices;
};

template <typename Tedge, typename Tvertex>
Edge<Tedge, Tvertex>::Edge(Vertex<Tvertex> a, Vertex<Tvertex> b, Tedge* v) {
    vertices.push_back(a);
    vertices.push_back(b);
    value = v;
}

template <typename Tedge, typename Tvertex>
Tedge Edge<Tedge, Tvertex>::get_value() {
    return *value;
}

template <typename Tedge, typename Tvertex>
typename std::list<Vertex<Tvertex>>::iterator Edge<Tedge, Tvertex>::get_end_vertices() {
    return vertices.begin();
}

template <typename Tedge, typename Tvertex>
typename std::list<Vertex<Tvertex>>::iterator Edge<Tedge, Tvertex>::get_opposite_vertex_of(typename std::list<Vertex<Tvertex>>::iterator v) {
    for (typename std::list<Vertex<Tvertex>>::iterator temp = vertices.begin();
         temp != vertices.end();
         temp++) {
    
        
    }
}

#endif
