#include <iostream>
using namespace std;

int main()
{
  cout << "=== ARRAY and Pointer Basics ===" << endl;

  // 1. Tradional aRray declaration
  int numbers[5] = {10, 20, 30, 40, 50};

  cout << "\n1. Access using tradional access indexing: " << endl;
  for (int i = 0; i < 5; i++)
  {
    cout << "numbers[" << i << "] = " << numbers[i] << endl;
  }

  // 2. Array's point nature
  cout << "\n2. Arrray is actually a pointer: " << endl;
  cout << "numbers address: " << numbers << endl;
  cout << "&numbers[0] address: " << &numbers[0] << endl;
  cout << "Are these the same? " << (numbers == &numbers[0] ? "Yes" : "No") << endl;

  // 3. Access using pointer arithmetic
  cout << "\n3. Access using pointer arithmetic; " << endl;
  int *ptr = numbers; // Poinnter to the beginning of array

  for (int i = 0; i < 5; i++)
  {
    cout << "Method 1 - *(ptr + " << i << ") = " << *(ptr + i) << endl;
    cout << "Method 2 - ptr[" << i << "] = " << ptr[i] << endl;
    cout << "Address: " << (ptr + i) << endl;
    cout << "---" << endl;
  }

  // 4.Dynamic memory allocation
  int *dynamic_array = new int[5]; // Allocate space for 5 ints on heap

  // Assign values - using pointer arithmetic
  for (int i = 0; i < 5; i++)
  {
    *(dynamic_array + i) = (i + 1) * 10; // 10, 20, 30, 40, 50
  }

  // Print Values
  cout << "Dynamic array values: " << endl;
  for (int i = 0; i < 5; i++)
  {
    cout << "*(dynamic_array + )" << i << ") = " << *(dynamic_array + i) << endl;
  }

  // 5. Pointer arithmetic details
  cout << "\n5. How pointer arithmetic works: " << endl;
  cout << "dynamic_array address: " << dynamic_array << endl;
  cout << "Difference (bytes): " << (char *)(dynamic_array + 1) - (char *)dynamic_array;
  cout << "int size: " << sizeof(int) << " bytes" << endl;

  // Clean up memory
  delete[] dynamic_array;

  cout << "\n=== SUMMARY ===" << endl;
  cout << "• Array name = address of first element" << endl;
  cout << "• array[i] = *(array + i)" << endl;
  cout << "• ptr + i = ptr moved forward by i*sizeof(type) bytes" << endl;
  cout << "• Memory allocated with new[] must be freed with delete[]" << endl;

  return 0;
}
