#include <iostream>
using namespace std;

class ResourceManager
{
private:
  int *data;
  int size;

public:
  // Constructor - allocates memory
  ResourceManager(int s)
  {
    size = s;
    data = new int[size];
    cout << "Constructor: Allocated memory for " << size << " integers" << endl;

    // Initialize with some values
    for (int i = 0; i < size; i++)
    {
      *(data + i) = i * 10;
    }
  }

  // Destructor - cleans up memory
  ~ResourceManager()
  {
    cout << "Destructor: Freeing memory for " << size << " integers" << endl;
    delete[] data;  // CRITICAL: Free allocated memory
    data = nullptr; // Good practice
  }

  void print() const
  {
    cout << "Data: ";
    for (int i = 0; i < size; i++)
    {
      cout << *(data + i) << " ";
    }
    cout << endl;
  }
};

void test_automatic_cleanup()
{
  cout << "\n--- Function scope test ---" << endl;
  ResourceManager manager(5); // Constructor called
  manager.print();

  // When function ends, manager goes out of scope
  // Destructor is called AUTOMATICALLY
}

int main()
{
  cout << "=== DESTRUCTOR DEMONSTRATION ===" << endl;

  // Test 1: Automatic cleanup when object goes out of scope
  {
    cout << "Creating object in block scope..." << endl;
    ResourceManager rm1(3);
    rm1.print();
    cout << "End of block scope..." << endl;
    // Destructor called here automatically
  }
  cout << "After block scope" << endl;

  // Test 2: Function scope
  test_automatic_cleanup();
  cout << "After function call" << endl;

  // Test 3: Dynamic allocation
  cout << "\n--- Dynamic allocation test ---" << endl;
  ResourceManager *dynamic_rm = new ResourceManager(4);
  dynamic_rm->print();

  cout << "Manually deleting dynamic object..." << endl;
  delete dynamic_rm; // Destructor called here

  cout << "\n=== Program ending ===" << endl;
  return 0;
}
