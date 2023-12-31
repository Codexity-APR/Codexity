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
    scanf("%s", path);

    // Call the search_dir function to start searching the directory
    search_dir(path);

    return 0;
}

void search_dir(char *path)
{
    DIR *dir;
    struct dirent *entry;
    struct stat info;

    // Open the directory
    dir = opendir(path);

    // Check if the directory exists
    if (dir == NULL)
    {
        perror("Unable to open directory");
        exit(EXIT_FAILURE);
    }

    // Loop through each directory entry
    while ((entry = readdir(dir)) != NULL)
    {
        char full_path[256];

        // Ignore . and .. directories
        if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0)
            continue;

        // Create the full path to the entry
        snprintf(full_path, sizeof(full_path), "%s/%s", path, entry->d_name);

        // Get information about the entry
        if (stat(full_path, &info) == -1)
        {
            perror("Unable to get file info");
            exit(EXIT_FAILURE);
        }

        // Check if the entry is a directory
        if (S_ISDIR(info.st_mode))
        {
            // Recursively call search_dir for subdirectories
            search_dir(full_path);
        }
        else
        {
            // Print the path of the file
            printf("%s\n", full_path);
        }
    }

    // Close the directory
    closedir(dir);
}