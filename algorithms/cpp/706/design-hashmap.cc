#include <iostream>

class MyHashMap {
public:
    /** Initialize your data structure here. */
    MyHashMap(int capacity_=29) {
        capacity = capacity_;
        size = 0;
        _rehash_cnt = 0;
        _freed = nullptr;
        mapped = new Node*[capacity]();
    }

    ~MyHashMap() {
        destroy_list(_freed);
        for (unsigned i = 0; i < capacity; i++)
            destroy_list(mapped[i]);
        delete[] mapped;
    }

    /** value will always be non-negative. */
    void put(int key, int value) {
        int h = hash(key);
        Node** list;
        for (list = &mapped[h]; *list; list = &(*list)->next) {
            if ((*list)->key == key)
                break;
        }
        if (!*list) {
            *list = create(key, value);
            ++size;
            if (size >= capacity)
                rehash();
        } else {
            (*list)->val = value;
        }
    }

    /** Returns the value to which the specified key is mapped,
     * or -1 if this map contains no mapping for the key */
    int get(int key) {
        int h = hash(key);
        for (Node* list = mapped[h]; list; list = list->next) {
            if (list->key == key)
                return list->val;
        }
        return -1;
    }

    /** Removes the mapping of the specified value key if
     * this map contains a mapping for the key */
    void remove(int key) {
        int h = hash(key);
        Node** list;
        for (list = &mapped[h]; *list; list = &(*list)->next) {
            if ((*list)->key == key)
                break;
        }
        if (!*list) return;
        Node* next = (*list)->next;
        free(*list);
        *list = next;
    }

private:
    unsigned hash(unsigned key) {
        key %= capacity;
        return key*(key + _rehash_cnt) % capacity;
    }

    struct Node {
        int key;
        int val;
        Node* next;
        Node(int key, int val) : key(key), val(val), next(nullptr) {
        }
    };

    Node* create(int key, int val) {
        Node* ret;
        if (_freed) {
            ret = _freed;
            _freed = _freed->next;
            ret->key = key;
            ret->val = val;
            ret->next = nullptr;
        } else {
            ret = new Node(key, val);
        }
        return ret;
    }

    void free(Node* node) {
        node->next = _freed;
        _freed = node;
    }

    void destroy_list(Node* list) {
        Node* next;
        while (list) {
            next = list->next;
            delete list;
            list = next;
        }
    }

    bool is_prime(int num) {
        for (int i = 2; i*i <= num; ++i)
            if (num%i == 0)
                return false;
        return true;
    }

    int next_prime(int num) {
        if ((num&0x1) == 0)
            num++;
        for (; !is_prime(num); num += 2)
            ;
        return num;
    }

    int _rehash_cnt;
    void rehash() {
        ++_rehash_cnt;
        int old_cap = capacity;
        Node** old_map = mapped;
        capacity = next_prime(capacity*2);
        mapped = new Node*[capacity]();
        for (int i = 0; i < old_cap; i++) {
            Node* next;
            for (; old_map[i]; old_map[i] = next) {
                next = old_map[i]->next;
                int h = hash(old_map[i]->key);
                old_map[i]->next = mapped[h];
                mapped[h] = old_map[i];
            }
        }
        delete[] old_map;
    }

    unsigned size;
    unsigned capacity;
    Node** mapped;
    Node* _freed;
};

int main()
{
    MyHashMap map;
    for (int i = 0; i < 1000000; i++)
        map.put(i, i);
    for (int i = 0; i < 1000000; i++)
        std::cout << map.get(i) << " ";
    std::cout << std::endl;
    for (int i = 0; i < 100; i += 1) {
        map.remove(i);
        std::cout << map.get(i) << " ";
    }

    return 0;
}
