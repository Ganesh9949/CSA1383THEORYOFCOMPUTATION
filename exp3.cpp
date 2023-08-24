#include <iostream>
#include <string>

using namespace std;

// Declare the variables
string str;
string *productions[] = {"S ? 0A1", "A ? 0A", "A ? 1A", "A ? e"};

// Function to check if the given string belongs to the language
bool isAccepted(string str) {
  // Initialize the stack
  stack<char> stack;
  stack.push('S');

  // Iterate over the characters of the string
  for (int i = 0; str[i] != '\0'; i++) {
    // Pop the top symbol from the stack
    char symbol = stack.top();
    stack.pop();

    // Check if the symbol is in the language
    for (int j = 0; productions[j][0] != '\0'; j++) {
      if (symbol == productions[j][0]) {
        // If yes, then push the next symbol from the production onto the stack
        if (productions[j][2] != '\0') {
          stack.push(productions[j][2]);
        }
        break;
      }
    }

    // If the symbol is not in the language, then the string is not accepted
    if (productions[j][0] == '\0') {
      return false;
    }
  }

  // If the stack is empty after reading the entire string, then the string is accepted
  if (stack.empty()) {
    return true;
  }

  return false;
}

int main() {
  cout << "Enter the string: ";
  cin >> str;

  if (isAccepted(str)) {
    cout << "The string is accepted.\n";
  } else {
    cout << "The string is rejected.\n";
  }

  return 0;
}
