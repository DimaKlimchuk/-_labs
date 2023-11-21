#include <stdio.h>
#include <string.h>

#define MAX_LENGTH 1000

int main() {

    char input_string[MAX_LENGTH];

    // Enter data from keyboard
    printf("Enter a text: ");
    fgets(input_string, sizeof(input_string), stdin);

    // Enter Character 
    char char_to_remove;
    printf("Enter the character you want to remove: ");
    scanf_s(" %c", &char_to_remove);

    // Find and delete
    int length = strlen(input_string);
    for (int i = 0; i < length; i++) {
        if (input_string[i] == char_to_remove) {
            
            for (int j = i; j < length - 1; j++) {
                input_string[j] = input_string[j + 1];
            }
            
            length--;
            
            i--;
        }
    }

 
    printf("Result: %s\n", input_string);

    return 0;
}
