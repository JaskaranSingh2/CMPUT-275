#include "intSet.h"
#include <algorithm>

// Default constructor
intSet::intSet() : size(0), capacity(4) {
    data = new int[capacity];
}

// Copy constructor
intSet::intSet(const intSet& is) : size(is.size), capacity(is.capacity) {
    data = new int[capacity];
    for (int i = 0; i < size; i++) {
        data[i] = is.data[i];
    }
}

// Move constructor
intSet::intSet(intSet&& is) : size(is.size), capacity(is.capacity), data(is.data) {
    is.data = nullptr;
    is.size = 0;
    is.capacity = 0;
}

// Copy assignment operator
intSet& intSet::operator=(const intSet& is) {
    if (this != &is) {
        // Delete current data
        delete[] data;
        
        // Copy data from other set
        size = is.size;
        capacity = is.capacity;
        data = new int[capacity];
        
        for (int i = 0; i < size; i++) {
            data[i] = is.data[i];
        }
    }
    return *this;
}

// Move assignment operator
intSet& intSet::operator=(intSet&& is) {
    if (this != &is) {
        // Delete current data
        delete[] data;
        
        // Move data from other set
        size = is.size;
        capacity = is.capacity;
        data = is.data;
        
        // Reset the source
        is.data = nullptr;
        is.size = 0;
        is.capacity = 0;
    }
    return *this;
}

// Destructor
intSet::~intSet() {
    delete[] data;
}

// Set union
intSet intSet::operator|(const intSet& other) const {
    intSet result(*this);
    
    // Add all elements from other set
    for (int i = 0; i < other.size; i++) {
        result.add(other.data[i]);
    }
    
    return result;
}

// Set intersection
intSet intSet::operator&(const intSet& other) const {
    intSet result;
    
    // Add elements that exist in both sets
    for (int i = 0; i < size; i++) {
        if (other.contains(data[i])) {
            result.add(data[i]);
        }
    }
    
    return result;
}

// Set equality
bool intSet::operator==(const intSet& other) const {
    if (size != other.size) {
        return false;
    }
    
    // Check if every element in this set is in the other set
    for (int i = 0; i < size; i++) {
        if (!other.contains(data[i])) {
            return false;
        }
    }
    
    return true;
}

// Check if s is a subset of *this
bool intSet::isSubset(const intSet& s) const {
    // For each element in s, check if it's in *this
    for (int i = 0; i < s.size; i++) {
        if (!contains(s.data[i])) {
            return false;
        }
    }
    
    return true;
}

// Check if *this contains element e
bool intSet::contains(int e) const {
    for (int i = 0; i < size; i++) {
        if (data[i] == e) {
            return true;
        }
    }
    
    return false;
}

// Add element e to the set
void intSet::add(int e) {
    // Don't add if element already exists
    if (contains(e)) {
        return;
    }
    
    // Check if we need to resize
    if (size == capacity) {
        // Double the capacity
        int newCapacity = capacity * 2;
        int* newData = new int[newCapacity];
        
        // Copy existing data
        for (int i = 0; i < size; i++) {
            newData[i] = data[i];
        }
        
        // Delete old data and update pointers
        delete[] data;
        data = newData;
        capacity = newCapacity;
    }
    
    // Add the new element
    data[size++] = e;
}

// Remove element e from the set
void intSet::remove(int e) {
    for (int i = 0; i < size; i++) {
        if (data[i] == e) {
            // Move all elements after this one back by one position
            for (int j = i; j < size - 1; j++) {
                data[j] = data[j + 1];
            }
            size--;
            return;
        }
    }
}

// Output operator for intSet
std::ostream& operator<<(std::ostream& out, const intSet& is) {
    out << "(";
    
    // Create a copy of the data for sorting
    int* sortedData = new int[is.size];
    for (int i = 0; i < is.size; i++) {
        sortedData[i] = is.data[i];
    }
    
    // Sort the data in ascending order
    std::sort(sortedData, sortedData + is.size);
    
    // Output elements
    for (int i = 0; i < is.size; i++) {
        out << sortedData[i];
        if (i < is.size - 1) {
            out << ", ";
        }
    }
    
    out << ")";
    
    delete[] sortedData;
    return out;
}