#include <stdio.h>
#include <string.h>

// Declare the states of the DFA
enum states {
  q0, q1, q2, q3
};

// Declare the transition function of the DFA
int transition(int state, char c) {
  switch (state) {
    case q0:
      if (c == 'a') return q1;
      else if (c == 'b') return q2;
      else return -1;
    case q1:
      if (c == 'a') return q1;
      else if (c == 'b') return q3;
      else return -1;
    case q2:
      if (c == 'a') return q2;
      else if (c == 'b') return q0;
      else return -1;
    case q3:
      if (c == 'a') return q3;
      else if (c == 'b') return q3;
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
  return (state == q3);
}

int main() {
  char str[100];
  printf("Enter the string: ");
  scanf("%s", str);

  if (isAccepted(str)) printf("The string is accepted.\n");
  else printf("The string is rejected.\n");

  return 0;
}
