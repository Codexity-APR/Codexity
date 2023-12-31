#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <sys/stat.h>
#include <string.h>

void search_dir(char *path);

int main()
{
    char path[100];

    // Prompt user for the drive path to search
    printf("Enter drive path to search: ");
    fgets(path, sizeof(path), stdin);

    // Remove the newline character from the input
    path[strcspn(path, "\n")] = '\0';

    // Call the search_dir function with the provided path
    search_dir(path);

    return 0;
}

void search_dir(char *path)
{
    DIR *dir;
    struct dirent *entry;
    struct stat file_info;
    char full_path[256];

    // Open the directory
    dir = opendir(path);

    if (dir == NULL) {
        printf("Unable to open directory: %s\n", path);
        return;
    }

    // Read directory entries
    while ((entry = readdir(dir)) != NULL) {
        // Ignore "." and ".." directories
        if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0) {
            continue;
        }

        // Create the full path by concatenating the directory path and the entry name
        snprintf(full_path, sizeof(full_path), "%s/%s", path, entry->d_name);

        // Retrieve file information
        if (stat(full_path, &file_info) == -1) {
            printf("Unable to retrieve file information for: %s\n", full_path);
            continue;
        }

        // Check if the entry is a directory
        if (S_ISDIR(file_info.st_mode)) {
            // Recursively search the subdirectory
            search_dir(full_path);
        }

        // Print the file/directory name
        printf("%s\n", entry->d_name);
    }

    // Close the directory
    closedir(dir);
}