#include <iostream>
#include <memory>
#include <cstring>

template<typename T>

class Vector {
private:
    int size;
    int capacity;
    T* data = nullptr;
public:
    Vector();
    Vector(size_t n);
    Vector(const std::initializer_list<T>&);
    Vector(const Vector&);
    Vector(const Vector&&) noexcept;
    Vector& operator = (const Vector<T>&);
    Vector& operator = (const Vector<T>&&);

    ~Vector();

    size_t getSize() const;
    size_t getCapacity() const;

    bool empty() const;
    bool operator == (const Vector<T>&) const;
    bool operator != (const Vector<T>&) const;

    void resize(size_t, const T& = T());
    void push_back(const T&);
    void expand(size_t n);
    void pop_back();

    T& operator [](size_t);
    T& at(size_t);
    T& front();
    T& back();
    const T& operator [](size_t) const;
    const T& at(size_t) const;
    const T& back() const;
    const T& front() const;

    template<typename U>
    friend std::ostream& operator<<(std::ostream& os, const Vector<U>&);

};