#ifndef GRAPH_H
#define GRAPH_H

#include <list>

template <typename V, typename E>
class Graph {
    public: 
        // I'm using these kind of like "prototypes," avoiding having to define
        // stuff in a weird order.
        class Vertex;
        class Edge;

        // A "position-like" object is just an `iterator` of some sort of `std::list`.
        typedef typename std::list<Vertex>::iterator VertexPosition;
        typedef typename std::list<Edge>::iterator EdgePosition;

        class Vertex {
            friend class Graph;
            public:
                V& operator*() {return value;}
                VertexPosition& get_position_in_vertex_list() {return position_in_vertex_list;}
            private:
                Vertex(V x) : value(x) {}
                VertexPosition& position_in_vertex_list;
                V value;
        };

        class Edge {
            friend class Graph;
            public:
                E& operator*() {return value;}
                EdgePosition& get_position_in_edge_list() {return position_in_edge_list;}
                VertexPosition get_end_vertices();
                Vertex& get_opposite_vertex_of(Graph::Vertex& v);
            private:
                Edge(Vertex& a, Vertex& b, E x) : value(x), first(a), second(b) {}
                E value;
                // Even though we use first and second, this is not a [[directed-edge]].
                // Or I guess it doesn't have to be one.
                Vertex& first;
                Vertex& second;
                EdgePosition& position_in_edge_list;
        };

    private: 
        std::list<Vertex> vertex_list;
        std::list<Edge> edge_list;
};

// This is just an absolute clusterfuck C++. What the hell.
template <typename V, typename E>
typename std::list<typename Graph<V, E>::Vertex>::iterator  Graph<V, E>::Edge::get_end_vertices() {
    std::list<Vertex> l;
    l.push_back(first);
    l.push_back(second);
    return l.begin();
}

template <typename V, typename E>
typename Graph<V, E>::Vertex& Graph<V, E>::Edge::get_opposite_vertex_of(Graph::Vertex& v) {
    for (VertexPosition temp = this->get_end_vertices();
         &(*temp) == &v;
         temp++);
}

#endif
