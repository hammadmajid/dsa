#include <ctype.h>
#include <stdio.h>

void print_interface() {
  printf("Select and option below:\n\n");
  printf("1. Add data to list\n");
  printf("2. Remove data from list\n");
  printf("3. Update data in list\n");
  printf("4. Print the list\n\n");
  printf("Enter your choice: ");
}

int main(int argc, char *argv[]) {
  int choice = 0;
  char state = 'y';

  while (tolower(state) != 'n') {
    print_interface();
    scanf(" %i", &choice);
    getchar();

    switch (choice) {
    case 1:
      break;

    case 2:
      break;

    case 3:
      break;

    case 4:
      break;

    default:
      printf("%d is a invalid choice \n", choice);
    }

    printf("\nContinue? (y/N): ");
    scanf(" %c", &state);
    getchar();
  }

  return 0;
}
