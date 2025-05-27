#include <iostream>
using namespace std;

class SimpleArray
{
private:
  int *data;
  int size;

public:
  // Regular Constructor
  SimpleArray(int s) : size(s)
  {
    data = new int[size];
    cout << "Regular constructor: allocated memory for " << size << " elements" << endl;

    // Initialize with values
    for (int i = 0; i < size; i++)
    {
      *(data + i) = i + 1;
    }
  }

  // Copy Constructor - creates new object from existing one
  SimpleArray(const SimpleArray &other)
  {
    cout << "Copy constructor called!" << endl;

    // Copy the size
    size = other.size;

    // Allocate NEW memory (deep copy)
    data = new int[size];

    // Copy all elements using pointer arithmetic
    for (int i = 0; i < size; i++)
    {
      *(data + i) = *(other.data + i);
    }

    cout << "Deep copy completed - new object has its own memory" << endl;
  }

  // Destructor
  ~SimpleArray()
  {
    cout << "Destructor: freeing memory" << endl;
    delete[] data;
  }

  // Utility functions
  void print() const
  {
    cout << "Array [" << this << "]: ";
    for (int i = 0; i < size; i++)
    {
      cout << *(data + i) << " ";
    }
    cout << endl;
  }

  void modify(int index, int value)
  {
    if (index >= 0 && index < size)
    {
      *(data + index) = value;
    }
  }

  int *get_data_address() const
  {
    return data;
  }
};

// Function that takes parameter by VALUE (triggers copy constructor)
void function_by_value(SimpleArray arr)
{
  cout << "Inside function_by_value:" << endl;
  arr.print();
  arr.modify(0, 999); // Modify the copy
  cout << "Modified copy in function:" << endl;
  arr.print();
  // Copy destroyed when function ends
}

// Function that takes parameter by REFERENCE (no copy)
void function_by_reference(const SimpleArray &arr)
{
  cout << "Inside function_by_reference (no copy made):" << endl;
  arr.print();
}

int main()
{
  cout << "=== COPY CONSTRUCTOR DEMONSTRATION ===" << endl;

  // Create original object
  cout << "\n1. Creating original array:" << endl;
  SimpleArray original(4);
  original.print();
  cout << "Original data address: " << original.get_data_address() << endl;

  // Copy constructor called here
  cout << "\n2. Copy constructor (SimpleArray copy = original):" << endl;
  SimpleArray copy = original; // This calls copy constructor!
  copy.print();
  cout << "Copy data address: " << copy.get_data_address() << endl;

  // Verify they have different memory addresses
  cout << "\n3. Verifying deep copy (different memory addresses):" << endl;
  cout << "Original and copy have same address? "
       << (original.get_data_address() == copy.get_data_address() ? "YES (BAD!)" : "NO (GOOD!)") << endl;

  // Modify original, copy should remain unchanged
  cout << "\n4. Modifying original, copy should be unaffected:" << endl;
  original.modify(0, 777);
  cout << "Original after modification: ";
  original.print();
  cout << "Copy (should be unchanged): ";
  copy.print();

  // Function call by value (triggers copy constructor)
  cout << "\n5. Function call by value (creates temporary copy):" << endl;
  function_by_value(original);
  cout << "Original after function call (should be unchanged): ";
  original.print();

  // Function call by reference (no copy)
  cout << "\n6. Function call by reference (no copy made):" << endl;
  function_by_reference(original);

  cout << "\n=== Program ending - destructors will be called ===" << endl;
  return 0;
}
