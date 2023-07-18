#pragma once

// A class to hold pointers to items, automatically frees elements when calling remove or set
template<typename T>
class ItemsList {
public:
    const int maxSize;
    int length = 0;

    void pushBack(T item);
    void set(int idx, T item);
    void remove(int idx);
    void remove(T item);
    void clear();

    ItemsList(int maxSize)
        : maxSize(maxSize),
        items(new T[maxSize]())
    {};

    T& operator[](int idx) const {
        return items[idx];
    }

    ~ItemsList() {
        delete[] items;
    }
private:
    T* items;
};

template<typename T>
void ItemsList<T>::pushBack(T item) {
    if (length == maxSize) {
        return;
    }

    items[length++] = item;
}

template<typename T>
void ItemsList<T>::set(int idx, T item) {
    if (idx >= length) {
        return;
    }

    if (items[idx]) {
        delete items[idx];
    }

    items[idx] = item;
}

template<typename T>
void ItemsList<T>::remove(int idx) {
    delete items[idx];

    for (int i = idx; i < length; i++) {
        items[i] = items[i + 1];
    }

    --length;
}

template<typename T>
void ItemsList<T>::remove(T item) {
    bool found = false;

    for (int i = 0; i < length; i++) {
        if (items[i] == item) {
            found = true;
            delete items[i];
        }

        if (found) {
            items[i] = items[i + 1];
        }
    }

    if (found) {
        --length;
    }
}

template<typename T>
void ItemsList<T>::clear() {
    for (int i = 0; i < length; i++) {
        delete items[i];
    }

    length = 0;
}