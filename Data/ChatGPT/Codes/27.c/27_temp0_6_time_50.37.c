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
    path[strcspn(path, "\n")] = '\0'; // Remove trailing newline character

    // Call the search_dir function to start searching
    search_dir(path);

    return 0;
}

void search_dir(char *path)
{
    DIR *dir;
    struct dirent *entry;
    struct stat file_stat;
    char file_path[256];

    // Open the directory
    dir = opendir(path);
    if (dir == NULL)
    {
        printf("Unable to open directory: %s\n", path);
        return;
    }

    // Read directory entries
    while ((entry = readdir(dir)) != NULL)
    {
        // Ignore "." and ".." directories
        if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0)
            continue;

        // Construct the full path of the file/directory
        snprintf(file_path, sizeof(file_path), "%s/%s", path, entry->d_name);

        // Get file/directory information
        if (stat(file_path, &file_stat) == -1)
        {
            printf("Unable to get file/directory information: %s\n", file_path);
            continue;
        }

        // Check if it's a directory
        if (S_ISDIR(file_stat.st_mode))
        {
            // Recursively search the subdirectory
            search_dir(file_path);
        }
        else
        {
            // Process the file
            printf("Found file: %s\n", file_path);
        }
    }

    // Close the directory
    closedir(dir);
}