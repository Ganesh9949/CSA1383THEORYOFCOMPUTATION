#include <stdio.h>
#include <string.h>

// Declare the states of the DFA
enum states {
  q0, q1
};

// Declare the transition function of the DFA
int transition(int state, char c) {
  switch (state) {
    case q0:
      if (c == '0') return q1;
      else return -1;
    case q1:
      if (c == '1') return q1;
      else return -1;
    default:
      return -1;
  }
}

// Function to check if the given string is accepted by the DFA
int isAccepted(char *str) {
  int state = q0;
  for (int i = 0; str[i] != '\0'; i++) {
    state = transition(state, str[i]);
    if (state == -1) return 0;
  }
  return (state == q1);
}

int main() {
  char str[100];
  printf("Enter the string: ");
  scanf("%s", str);

  if (isAccepted(str)) printf("The string is accepted.\n");
  else printf("The string is rejected.\n");

  return 0;
}
