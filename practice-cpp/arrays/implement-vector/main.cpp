#include <iostream>
#include <stdexcept>  // for std::out_of_range

class Vector {
 private:
  int* data;
  int size;
  int capacity;

  // Private resize method to allocate new memory and copy old elements
  void resize(int new_capacity) {
    int* new_data = new int[new_capacity];
    for (int i = 0; i < size; i++) {
      new_data[i] = data[i];
    }
    delete[] data;
    data = new_data;
    capacity = new_capacity;
  }

 public:
  // Constructor
  Vector() {
    capacity = 16;
    size = 0;
    data = new int[capacity];
  }

  // Destructor
  ~Vector() { delete[] data; }

  // Copy constructor (deep copy)
  Vector(const Vector& other) {
    capacity = other.capacity;
    size = other.size;
    data = new int[capacity];
    for (int i = 0; i < size; i++) {
      data[i] = other.data[i];
    }
  }

  // Copy assignment operator (deep copy)
  Vector& operator=(const Vector& other) {
    if (this == &other) return *this;  // handle self-assignment

    delete[] data;

    capacity = other.capacity;
    size = other.size;
    data = new int[capacity];
    for (int i = 0; i < size; i++) {
      data[i] = other.data[i];
    }

    return *this;
  }

  // Return the current number of elements
  int get_size() const { return size; }

  // Return the current capacity
  int get_capacity() const { return capacity; }

  // Check if the vector is empty
  bool is_empty() const { return size == 0; }

  // Return the element at a given index
  int at(int index) const {
    if (index < 0 || index >= size) {
      throw std::out_of_range("Index out of bounds");
    }
    return *(data + index);  // pointer arithmetic
  }

  // Add an item to the end
  void push(int item) {
    if (size == capacity) {
      resize(capacity * 2);
    }
    data[size++] = item;
  }

  // Insert an item at a specific index
  void insert(int index, int item) {
    if (index < 0 || index > size) {
      throw std::out_of_range("Index out of bounds");
    }
    if (size == capacity) {
      resize(capacity * 2);
    }
    for (int i = size; i > index; i--) {
      data[i] = data[i - 1];
    }
    data[index] = item;
    size++;
  }

  // Add an item to the beginning
  void prepend(int item) { insert(0, item); }

  // Remove and return the last item
  int pop() {
    if (size == 0) {
      throw std::out_of_range("Vector is empty");
    }
    int item = data[size - 1];
    size--;
    if (size > 0 && size == capacity / 4) {
      resize(capacity / 2);
    }
    return item;
  }

  // Delete the item at a given index
  void delete_at(int index) {
    if (index < 0 || index >= size) {
      throw std::out_of_range("Index out of bounds");
    }
    for (int i = index; i < size - 1; i++) {
      data[i] = data[i + 1];
    }
    size--;
    if (size > 0 && size == capacity / 4) {
      resize(capacity / 2);
    }
  }

  // Remove all occurrences of an item
  void remove(int item) {
    int i = 0;
    while (i < size) {
      if (data[i] == item) {
        delete_at(i);
      } else {
        i++;
      }
    }
  }

  // Find the first index of the item, or -1 if not found
  int find(int item) const {
    for (int i = 0; i < size; i++) {
      if (data[i] == item) return i;
    }
    return -1;
  }
};


int main() {
  Vector vec;

  // Add elements to the vector
  vec.push(10);
  vec.push(20);
  vec.push(30);

  // Insert an element at index 1
  vec.insert(1, 15);

  // Prepend an element
  vec.prepend(5);

  // Print all elements
  std::cout << "Vector elements: ";
  for (int i = 0; i < vec.get_size(); i++) {
    std::cout << vec.at(i) << " ";
  }
  std::cout << std::endl;

  // Remove and print last item
  std::cout << "Popped item: " << vec.pop() << std::endl;

  // Delete element at index 1
  vec.delete_at(1);

  // Remove all occurrences of 10
  vec.remove(10);

  // Print current state
  std::cout << "Current elements: ";
  for (int i = 0; i < vec.get_size(); i++) {
    std::cout << vec.at(i) << " ";
  }
  std::cout << std::endl;

  // Find element
  int index = vec.find(5);
  std::cout << "Index of 5: " << index << std::endl;

  return 0;
}
