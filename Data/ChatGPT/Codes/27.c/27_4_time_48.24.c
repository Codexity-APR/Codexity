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
    path[strcspn(path, "\n")] = '\0'; // remove trailing newline character

    // Call the search_dir function
    search_dir(path);

    return 0;
}

void search_dir(char *path)
{
    DIR *dir;
    struct dirent *entry;
    struct stat fileStat;
    char filepath[256];

    // Open the directory
    dir = opendir(path);

    if (dir == NULL)
    {
        printf("Unable to open directory '%s'\n", path);
        return;
    }

    // Read directory entries
    while ((entry = readdir(dir)) != NULL)
    {
        // Ignore special entries . and ..
        if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0)
            continue;

        // Create the complete file path
        snprintf(filepath, sizeof(filepath), "%s/%s", path, entry->d_name);

        // Get file information
        if (stat(filepath, &fileStat) < 0)
        {
            printf("Unable to get file information for '%s'\n", filepath);
            continue;
        }

        // Perform operations on the file here

        // If the entry is a directory, recursively call search_dir
        if (S_ISDIR(fileStat.st_mode))
        {
            search_dir(filepath);
        }
    }

    // Close the directory
    closedir(dir);
}