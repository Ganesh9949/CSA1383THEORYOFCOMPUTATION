#include <stdio.h>
#include <string.h>

// Declare the variables
char str[100];
char *productions[] = {"S ? 0S0", "S ? 1S1", "S ? 0", "S ? 1", "S ? e"};

// Function to check if the given string belongs to the language
int isAccepted(char *str) {
  // Initialize the stack
  char stack[100];
  int top = -1;

  // Push the start symbol onto the stack
  stack[++top] = 'S';

  // Iterate over the characters of the string
  for (int i = 0; str[i] != '\0'; i++) {
    // Pop the top symbol from the stack
    char symbol = stack[top--];

    // Check if the symbol is in the language
    for (int j = 0; productions[j][0] != '\0'; j++) {
      if (symbol == productions[j][0]) {
        // If yes, then push the next symbol from the production onto the stack
        if (productions[j][2] != '\0') {
          stack[++top] = productions[j][2];
        }
        break;
      }
    }

    // If the symbol is not in the language, then the string is not accepted
    if (productions[j][0] == '\0') {
      return 0;
    }
  }

  // If the stack is empty after reading the entire string, then the string is accepted
  if (top == -1) {
    return 1;
  }

  return 0;
}

int main() {
  char str[100];
  printf("Enter the string: ");
  scanf("%s", str);

  if (isAccepted(str)) printf("The string is accepted.\n");
  else printf("The string is rejected.\n");

  return 0;
}
