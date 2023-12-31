
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ROWS 1000
#define MAX_COLS 10
#define MAX_LINE_LEN 1024

// Define a structure to hold each row of the CSV file
struct csv_row {
    char *cols[MAX_COLS];
};

// Define a helper function to parse a CSV row into a struct
void parse_csv_row(char *line, struct csv_row *row) {
    char *token;
    int i = 0;
    token = strtok(line, ",");
    while (token != NULL && i < MAX_COLS) {
        row->cols[i] = token;
        token = strtok(NULL, ",");
        i++;
    }
}

// Define a comparison function for sorting rows based on the value in the 4th column
int compare_rows(const void *a, const void *b) {
    struct csv_row *row_a = (struct csv_row *) a;
    struct csv_row *row_b = (struct csv_row *) b;
    float val_a = atof(row_a->cols[3]);
    float val_b = atof(row_b->cols[3]);
    if (val_a < val_b) {
        return -1;
    } else if (val_a > val_b) {
        return 1;
    } else {
        return 0;
    }
}

int main() {
    // Open the input file
    FILE *fp = fopen("input.csv", "r");
    if (fp == NULL) {
        printf("Error opening input file\n");
        return 1;
    }

    // Read each line of the input file and parse it into a csv_row
    struct csv_row rows[MAX_ROWS];
    char line[MAX_LINE_LEN];
    int num_rows = 0;
    while (fgets(line, MAX_LINE_LEN, fp) != NULL && num_rows < MAX_ROWS) {
        parse_csv_row(line, &rows[num_rows]);
        num_rows++;
    }

    // Sort the rows based on the value in the 4th column
