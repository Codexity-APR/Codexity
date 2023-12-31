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
        printf("Unable to open directory %s\n", path);
        return;
    }

    // Read directory entries
    while ((entry = readdir(dir)) != NULL)
    {
        // Skip "." and ".." entries
        if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0)
            continue;

        // Create the file path by concatenating the directory path and the entry name
        snprintf(filepath, sizeof(filepath), "%s/%s", path, entry->d_name);

        // Get file information
        if (stat(filepath, &fileStat) < 0)
        {
            printf("Unable to retrieve file information for %s\n", filepath);
            continue;
        }

        // Check if the entry is a directory
        if (S_ISDIR(fileStat.st_mode))
        {
            // Recursively call search_dir for subdirectories
            search_dir(filepath);
        }
        else
        {
            // Process the file entry
            printf("Found file: %s\n", filepath);
        }
    }

    // Close the directory
    closedir(dir);
}