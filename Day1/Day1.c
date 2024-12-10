#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINES 1000  // Maximum number of lines

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
    char line[15];
    char sub_line[5];
    int line_count = 0;
    int output = 0;
    


    // Open the file
    file = fopen("input.txt", "r");
    if (file == NULL) {
        perror("Error opening file");
        return EXIT_FAILURE;
    }

    // Read lines from the file and store them in the array
    while (fgets(line,  15, file) != NULL) {
        // Divide line into two Integers
        getSubstring(line, sub_line, 0, 5);
        lines_left[line_count] = atoi(sub_line);
        
        getSubstring(line, sub_line, 8, 5);
        lines_right[line_count] = atoi(sub_line);

        line_count++;

    }

    fclose(file);
    
    qsort(lines_left, MAX_LINES, sizeof(int), comp);
    qsort(lines_right, MAX_LINES, sizeof(int), comp);


    /*  Part 1  */ 

    for (int i = 0; i < MAX_LINES; i++) {
        output = output + abs(lines_left[i] - lines_right[i]);
    }
    printf("Erste Antwort: %d\n", output);

    /*  Part 2  */

    output = 0;

    for (int i = 0; i < MAX_LINES; i++) {
        int frequency = 0;
        for (int j = 0; j < MAX_LINES; j++){
            if (lines_left[i] == lines_right[j]){
                frequency ++;
            }
        }
        output += frequency * lines_left[i];
    }
    printf("Zweite Antwort: %d\n", output);

}
