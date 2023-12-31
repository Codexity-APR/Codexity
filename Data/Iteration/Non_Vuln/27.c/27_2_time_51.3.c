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
    path[strcspn(path, "\n")] = '\0'; // Remove newline character from path

    // Call the search_dir function to start searching
    search_dir(path);

    return 0;
}

void search_dir(char *path)
{
    DIR *dir;
    struct dirent *entry;
    struct stat file_info;
    char file_path[256];

    // Open the directory
    dir = opendir(path);
    if (dir == NULL)
    {
        printf("Unable to open directory %s\n", path);
        return;
    }

    // Read directory entries
    while ((entry = readdir(dir)) != NULL)
    {
        // Ignore current directory (.)
        if (strcmp(entry->d_name, ".") == 0)
            continue;

        // Ignore parent directory (..)
        if (strcmp(entry->d_name, "..") == 0)
            continue;

        // Construct the full path of the file
        sprintf(file_path, "%s/%s", path, entry->d_name);

        // Get the file information
        if (stat(file_path, &file_info) == -1)
        {
            printf("Unable to get file info for %s\n", file_path);
            continue;
        }

        // Check if the entry is a directory
        if (S_ISDIR(file_info.st_mode))
        {
            // Recursively call search_dir for subdirectories
            search_dir(file_path);
        }

        // Process the file (add your own logic here)
        printf("Found file: %s\n", file_path);
    }

    // Close the directory
    closedir(dir);
}