#ifndef HASH_MAP_H
#define HASH_MAP_H

#include <list>
#include <vector>

// K for type of the keys 
// V for type of the values
template <typename K, typename V>
class Entry {
    public:
        // The default values of `_key` and `value` are just empty instances of the classes specified in the typename.
        Entry(const K& k = K(), const V& v() = V()) :
            _key(k),
            _value(v) { }

        // Just getters and setters, really.
        const K& get_key() {return _key;}
        const V& get_value() {return _value;}
        void set_key(const K& k) {_key = k;}
        void set_key(const V& v) {_key = v;}

    private:
        K _key;
        V _value;
};

// K for type of the keys 
// V for type of the values
// H for the type of the hashing function
template <typename K, typename V, typename H>
class HashMap {
    public:
        typedef Entry<const K, V> Entry;
        class Iterator;

    public:
        HashMap(int capacity = 100);

        int size() const;
        bool empty() const;

        Iterator find(const K& k);
        Iterator put(const K& k, const V& v);

        void erase(const K& k);
        void erase(const Iterator& p); 

        Iterator get_begin_iter();
        Iterator get_end_iter();

    protected:
        typedef std::list<Entry> Bucket;
        typedef std::vector<Bucket> BucketArray;

    protected:
        // We declare some utilities here:
        Iterator finder(const K& k);
        Iterator inserter(const Iterator& p, const Entry& e);
        void eraser(const Iterator& p);
        
        typedef typename BucketArray::iterator BIter;
        typedef typename Bucket::iterator EIter;

        static void next_entry(Iterator& p) {++ p.ent; }
        static bool end_of_bucket(const Iterator& p) {
            return p.ent == p.bkt->end();     
        }

    private:
        int n;
        H hash_function;
        BucketArray B;

    public:
        class Iterator {
            private:
                EIter ent;
                BIter bkt;
                const BucketArray* ba;
            
            public:
                Iterator(const BucketArray& a, const BIter& b, const EIter& q = EIter())
                    : ent(q), bkt(b), ba(&a) {}
                Entry& operator*() const;
                bool operator==(const Iterator& p) const;
                Iterator& operator++();
                friend class HashMap;

        };
};

template <typename K, typename V, typename H>
typename HashMap<K, V, H>::Entry& HashMap<K, V, H>::Iterator::operator*() const {
    return *ent;
}

template <typename K, typename V, typename H>
bool HashMap<K, V, H>::Iterator::operator==(const HashMap<K, V, H>::Iterator& p) const {
    if (ba != p.ba || bkt != p.bkt) return false;
    else if (bkt == ba->end()) return true;
    else return (ent == p.ent);
}

template 

#endif
