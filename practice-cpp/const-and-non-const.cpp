#include <iostream>
using namespace std;

class SimpleVector
{
private:
  int *data;
  int size_;

public:
  SimpleVector() : data(new int[10]), size_(0) {}
  ~SimpleVector() { delete[] data; }

  // CONST function - promises not to modify member variables
  int get_size() const
  {
    return size_; // OK - just reading
                  // size_ = 5;  // ERROR! Cannot modify in const function
  }

  // CONST function - can only call other const functions
  bool is_empty() const
  {
    return get_size() == 0; // OK - calling another const function
                            // return non_const_function(); // ERROR! Cannot call non-const function
  }

  // NON-CONST function - can modify member variables
  void add_item(int item)
  {
    *(data + size_) = item;
    size_++; // OK - can modify
  }

  // NON-CONST function
  void non_const_function()
  {
    size_ = 0; // OK - can modify
  }
};

int main()
{
  SimpleVector vec;

  // Regular object - can call both const and non-const functions
  cout << "Size: " << vec.get_size() << endl; // const function
  vec.add_item(10);                           // non-const function

  // CONST object - can ONLY call const functions
  const SimpleVector const_vec;
  cout << "Const vec size: " << const_vec.get_size() << endl; // OK
  cout << "Is empty: " << const_vec.is_empty() << endl;       // OK
  // const_vec.add_item(20);  // ERROR! Cannot call non-const function on const object

  return 0;
}
