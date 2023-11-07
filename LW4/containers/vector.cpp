#include "vector.hpp"

template <typename T>
Vector<T>::Vector() {
    size = 0;
    capacity = 1;
    data = reinterpret_cast<T*>(new int8_t[sizeof(T)]);
}

template <typename T>
Vector<T>::Vector(size_t cp) : capacity(cp), size(0){
    data = reinterpret_cast<T*>(new int8_t[(cp + 1) * sizeof(T)]);
}

template <typename T>
Vector<T>::Vector(const std::initializer_list<T>& other) {
    T* newData = reinterpret_cast<T*>(new int8_t[(other.size()) * sizeof(T)]);
    try {
        std::uninitialized_copy(other.begin(), other.end(), newData);
    } catch (...) {
        delete[] reinterpret_cast<char*>(newData);
        throw;
    }
    data = newData;
    capacity = other.size();
    size = other.size();
}

template <typename T>
Vector<T>::Vector(const Vector<T>& other) {
    size = other.size;
    capacity = other.capacity;
    T* newData = reinterpret_cast<T*>(new int8_t[(capacity + 1) * sizeof(T)]);

    try {
        std::uninitialized_copy(other.data, other.data + other.size, newData);
    } catch (...) {
        delete[] reinterpret_cast<T*>(newData);
        throw;
    }
    data = newData;
}

template <typename T>
Vector<T>::Vector(Vector<T>&& other) noexcept : capacity(other.capacity), size(other.size), data(other.data) {
    other.capacity = 0;
    other.size = 0;
    other.data = nullptr;
}

template <typename T>
Vector<T>& Vector<T>::operator = (const Vector<T>& other) {
    if (this == &other) {
        return *this;
    }

    size = other.size;
    capacity = other.capacity;
    data = reinterpret_cast<T*>(new int8_t[capacity * sizeof(T)]);
    std::copy(other.data, other.data + other.size, data);
    return *this;
}

template <typename T>
Vector<T>& Vector<T>::operator = (Vector<T>&& other) noexcept {
    this->capacity = other.capacity;
    this->size = other.size;
    this->data = other.data;

    other.data = nullptr;
    other.size = 0;
    other.capacity = 0;

    return *this;
}

template <typename T>
Vector<T>::~Vector() {
    for (size_t i = 0; i < size; ++i) {
        data[i].~T();
    }
    delete[] reinterpret_cast<int8_t*>(data);
}

template <typename T>
size_t Vector<T>::get_size() const {
    return size;
}

template <typename T>
size_t Vector<T>::get_capacity() const {
    return capacity;
}

template <typename T>
bool Vector<T>::empty() const{
    return size == 0;
}

template <typename T>
bool Vector<T>::operator == (const Vector<T>& other) const {
    if (size != other.size) {
        return false;
    }

    for (size_t i = 0; i < size; ++i) {
        if (data[i] != other.data[i]) {
            return false;
        }
    }

    return true;
}

template <typename T>
bool Vector<T>:: operator != (const Vector<T>& other) const {
    return !this->operator==(other);
}

template <typename T>
void Vector<T>::resize(size_t n, const T& value) {
    if (n > capacity) {
        expand(n);
    } 
    if (n > size) {
        for (size_t i = size; i != n; ++i) {
            new (data + i) T(value);
        }
    }
    if (n < size) {
        for (size_t i = n; i != size; ++i){
            data[i].~T();
        }
    }

    size = n;
}

template <typename T>
void Vector<T>::push_back(const T& value) {
    if (capacity - 1 == size) {
        expand(2 * size);
    }
    new(data + size)T(value);
    ++size;
}

template <typename T>
void Vector<T>::expand(size_t n) {
    if (n <= capacity) {
        return ;
    }

    T* newData = reinterpret_cast<T*>(new int8_t[n * sizeof(T)]);

    try {
        std::uninitialized_copy(data, data + size, newData);
    } catch(...) {
        delete[] reinterpret_cast<int8_t*>(newData);
        throw;
    }

    for (size_t i = 0; i < size; ++i) {
        data[i].~T();
    }

    delete[] reinterpret_cast<int8_t*>(data);
    data = newData;
    capacity = n;
}

template <typename T>
void Vector<T>::pop_back() {
    --size;
    data[size].~T();
}

template <typename T>
void Vector<T>::erase(size_t index) {
    if (index >= size) throw std::range_error("Index out of range");
    if (size == 0) return;

    if (index == size - 1) {
        pop_back();
        return;
    }

    data[index].~T();
    for (size_t i = index; i != size - 1; ++i) {
        data[i] = data[i + 1];
    }
    pop_back();
}

template <typename T>
T& Vector<T>::operator [] (size_t index) {
  return data[index];
}


template <typename T>
const T& Vector<T>::operator [] (size_t index) const {
  return data[index];
}

template <typename T>
T& Vector<T>::at(size_t index) {
    if (index >= size) {
        throw std::range_error("Out of range");
    }

    return data[index];
}

template <typename T>
const T& Vector<T>::at(size_t index) const {
    if (index >= size) {
        throw std::range_error("Out of range");
    }

    return data[index];
}

template <typename T>
const T& Vector<T>::front() const {
  if (size == 0) {
    throw std::range_error("Vector is empty");
  }

  return data[0];
}

template <typename T>
T& Vector<T>::front() {
  if (size == 0) {
    throw std::range_error("Vector is empty");
  }

  return data[0];
}

template <typename T>
const T& Vector<T>::back() const {
  if (size == 0) {
    throw std::range_error("Vector is empty");
  }

  return data[size - 1];
}

template <typename T>
T& Vector<T>::back() {
  if (size == 0) {
    throw std::range_error("Vector is empty");
  }

  return data[size - 1];
}

template<typename T>
std::ostream& operator<<(std::ostream& os, const Vector<T>& vector) {
    for (size_t i = 0; i < vector.size(); ++i) {
        os << vector[i] << " ";
    }
    return os;
}

template <typename T>
double Vector<T>::calculateTotalArea() const noexcept {
    double total_area = 0.0 ;
    for (size_t i = 0; i != this->get_size(); ++i) {
        total_area += (data[i]->area());
    }

    return total_area;
}