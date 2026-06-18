class LRUCache {
public:

    int c;

    list<int> l;

    unordered_map<int,int> m; // key -> value

    unordered_map<int, list<int>::iterator> b; // key -> iterator

    LRUCache(int capacity) {
        c = capacity;
    }

    int get(int key) {

        if(m.count(key) == 0)
            return -1;

        l.erase(b[key]);

        l.push_back(key);

        b[key] = prev(l.end());

        return m[key];
    }

    void put(int key, int value) {

        if(m.count(key)) {

            l.erase(b[key]);

            l.push_back(key);

            b[key] = prev(l.end());

            m[key] = value;

            return;
        }

        if(l.size() == c) {

            int old = l.front();

            l.pop_front();

            m.erase(old);

            b.erase(old);
        }

        l.push_back(key);

        b[key] = prev(l.end());

        m[key] = value;
    }
};