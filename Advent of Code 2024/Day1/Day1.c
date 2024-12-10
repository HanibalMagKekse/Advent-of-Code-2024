#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINES 1000  // Maximum number of lines
#define MAX_LENGTH 15 // Maximum length of each line

void getSubstring(const char *source, char *dest, int start, int length) {
    strncpy(dest, source + start, length);
    dest[length] = '\0'; // Null-terminate the destination string
}

int comp(const void* a,const void* b) {
      return *(int*)a - *(int*)b;
}

int main() {
    FILE *file;
    int lines_left[MAX_LINES];
    int lines_right[MAX_LINES];
    char line[MAX_LENGTH];
    char sub_line[5];
    int line_count = 0;
    int num;
    int output = 0;


    // Open the file
    file = fopen("input.txt", "r");
    if (file == NULL) {
        perror("Error opening file");
        return EXIT_FAILURE;
    }

    // Read lines from the file and store them in the array
    while (fgets(line,  15, file) != NULL) {
        // Remove newline character if present
        getSubstring(line, sub_line, 0, 5);
        num = atoi(sub_line);
        lines_left[line_count] = num;
        
        getSubstring(line, sub_line, 8, 5);
        num = atoi(sub_line);
        lines_right[line_count] = num;

        line_count++;

        // Check if the maximum number of lines is exceeded
        if (line_count >= MAX_LINES) {
            printf("Maximum number of lines exceeded!\n");
            break;
        }
    }

    fclose(file);
    
    qsort(lines_left, MAX_LINES, sizeof(int), comp);
    qsort(lines_right, MAX_LINES, sizeof(int), comp);

    // Print the stored lines
    printf("\nLines read from file:\n");
    for (int i = 0; i < MAX_LINES; i++) {
        printf("%d\n", abs(lines_left[i] - lines_right[i]));
        output = output + abs(lines_left[i] - lines_right[i]);
    }
    printf("%d\n", output);
    return EXIT_SUCCESS;
}
