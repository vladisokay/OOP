#include "../include/decimal.h"

Decimal::Decimal() : digits(nullptr), size(0) {}

Decimal::Decimal(const size_t& n, unsigned char value) : size(n) {
    digits = new unsigned char[size];
    for (size_t i = 0; i < size; ++i) {
        digits[i] = value;
    }
}

Decimal::Decimal(const std::initializer_list<unsigned char> &values) : size(values.size()) {
    digits = new unsigned char[size];
    size_t i = 0;
    for (const unsigned char& digit : values) { 
        digits[i++] = digit;
    }
}

Decimal::Decimal(const std::string& str) : size(str.length()) { 
    digits = new unsigned char[size];
    for (size_t i = 0; i < size; ++i) { 
        if (str[i] >= '0' && str[i] <= '9') {
            digits[i] = str[i] - '0';
        } else {
            throw std::invalid_argument("Invalid charapter in input");
        }
    }
    removeZeros();
}

Decimal::Decimal(const Decimal& other) : size(other.size) { 
    digits = new unsigned char[size];
    for (size_t i = 0; i < size; ++i) { 
        digits[i] = other.digits[i];
    }
}

Decimal::Decimal(Decimal&& move) noexcept : digits(nullptr), size(0){
    digits = move.digits;
    size = move.size;

    move.digits = nullptr;
    move.size = 0;
}

Decimal::~Decimal() noexcept {
    delete[] digits;
}

Decimal& Decimal::operator=(const Decimal& other) {
    if (this != &other) {
        delete[] digits;
        size = other.size;
        digits = new unsigned char[size];
        for (size_t i = 0; i < size; ++i) {
            digits[i] = other.digits[i];
        }
    }

    return *this;
}

Decimal Decimal::operator+(const Decimal& other) const {
    size_t maxSize = std::max(size, other.size);
    Decimal result;
    result.size = maxSize + 1;
    result.digits = new unsigned char[result.size];

    for (size_t i = 0; i < result.size; ++i) {
        result.digits[i] = 0;
    }


    int carry = 0;
    for (size_t i = 0; i < maxSize; ++i){
        int sum = carry;

        if (i < size) {
            sum += digits[size - 1 - i];
        }
        if (i < other.size) { 
            sum += other.digits[other.size - 1 - i];
        }

        result.digits[maxSize - 1 - i] = sum % 10;
        carry = sum / 10;
    }

    if (carry > 0) {
        result.digits[0] = carry;
    } else {
        result.size--;
        unsigned char* newData = new unsigned char[result.size];
        for (size_t i = 0; i < result.size; ++i) {
            newData[i] = result.digits[i + 1];
        }
    }
    return result;
}

Decimal Decimal::operator-(const Decimal& other) {
    if (*this < other) { 
        throw std::invalid_argument("Result is a negative or zero number");
    }

    size_t maxSize = size;
    Decimal result;
    result.size = maxSize;
    result.digits = new unsigned char[result.size];

    int hold = 0;
    unsigned char* resultPtr = result.digits + maxSize - 1;
    const unsigned char* thisPtr = digits + maxSize - 1;
    const unsigned char* otherPtr = other.digits + other.size - 1;

    while (resultPtr >= result.digits) {
        int diff = *thisPtr - hold;
        if (otherPtr >= other.digits) {
            diff -= *otherPtr;
            otherPtr--;
        }

        if (diff < 0) {
            diff += 10;
            hold = 1;
        } else {
            hold = 0;
        }

        *resultPtr = diff;

        resultPtr--;
        thisPtr--;
    }

    result.removeZeros();
    return result;
}



bool Decimal::operator<(const Decimal& other) const {
    if (size < other.size) { 
        return true;
    } else if (size > other.size) {
        return false;
    } else {
        for (size_t i = 0; i < size; ++i) {
            if (digits[i] < other.digits[i]) {
                return true;
            } else if (digits[i] > other.digits[i]) {
                return false;
            }
        }
        return false;
    }
}

bool Decimal::operator>(const Decimal& other) const {
    return !(*this < other) && !(*this == other);
}

bool Decimal::operator<=(const Decimal& other) const {
    if (*this == other || *this < other) {
        return true;
    } else {
        return false;
    }
}

bool Decimal::operator>=(const Decimal& other) const {
    if (*this == other || *this > other) {
        return true;
    } else {
        return false;
    }
}

bool Decimal::operator==(const Decimal& other) const {
    if (size != other.size) {
        return false;
    }
    for (size_t i = 0; i < size; ++i) {
        if (digits[i] != other.digits[i]) {
            return false;
        }
    }

    return true;
}

bool Decimal::operator!=(const Decimal& other) const {
    return !(*this == other);
}

Decimal& Decimal::operator+=(const Decimal& value) {
    return *this = (*this + value);
}
Decimal& Decimal::operator-=(const Decimal& value) {
    return *this = (*this - value);
}

Decimal& Decimal::operator++() {
    *this += Decimal("1");
    return *this;
}

Decimal Decimal::operator++(int) {
    Decimal temp = *this;
    *this += Decimal("1");
    return temp;
}

Decimal& Decimal::operator--() {
    *this -= Decimal("1");
    return *this;
}

Decimal Decimal::operator--(int) {
    Decimal temp = *this;
    *this -= Decimal("1");
    return temp;
}

std::ostream& operator<<(std::ostream& stream, const Decimal& digits) {
    for (size_t i = 0; i < digits.size; ++i) {
        stream << static_cast<int>(digits.digits[i]);
    }
    return stream;
}

void Decimal::removeZeros() {
    while (size > 1 && digits[0] == 0) {
        for (size_t i = 0; i < size; ++i) {
            digits[i] = digits[i + 1];
        }
        size--;
    }
}

void Decimal::print() const{
    for (size_t i = 0; i < size; ++i) {
        std::cout << static_cast<int>(digits[i]);
    }
    std::cout << std::endl;
}

size_t Decimal::getSize() const {
    return size;
}

std::string Decimal::toString() const {
    std::string result;
    for (size_t i = 0; i < size; ++i) {
        result += std::to_string(static_cast<int>(digits[i]));
    }
    return result;
}


