#ifndef VECTOR_BASED_COMPLETE_BINARY_TREE_H
#define VECTOR_BASED_COMPLETE_BINARY_TREE_H

#include <vector>

template <typename T>
class CompleteBT {
    public:
        typedef typename std::vector<T>::iterator Position;

        CompleteBT() : v(1) {}

        int size() const {return v.size();}
        
        // We cannot make this const, since that would make the `Position` it returns const.
        Position get_root() { return get_position_from_index(1); }
        Position get_last() { return get_position_from_index(size()); }

        // We use the rule that a left is `2*index_parent`, and a right is `2*index_parent + 1`
        Position get_position_left(const Position p) { return get_position_from_index(2 * get_index_from_position(p)); }
        Position get_position_right(const Position p) { return get_position_from_index(2 * get_index_from_position(p) + 1); }
        Position get_position_parent(const Position p) { return get_position_from_index(get_index_from_position(p) / 2); }

        bool position_has_left(const Position p) { return 2 * get_index_from_position(p) <= size(); }
        bool position_has_right(const Position p) { return 2 * get_index_from_position(p) + 1 <= size(); }

        bool position_is_root(const Position p) { return get_index_from_position(p) == 1; }

        void add_last(const T v) { v.push_back(v); }
        void remove_last() { v.pop_back(); }

        void swap(const Position first, const Position second) {T temp = *first; *first = *second; *second = temp; }

    private:
        std::vector<T> v;

    protected:
        // We cannot make this const, since that would make the `Position` it returns const.
        Position get_position_from_index(const int &i) { return v.begin() + i;}
        int get_index_from_position(Position p) const { return p - v.begin();}
};



#endif
