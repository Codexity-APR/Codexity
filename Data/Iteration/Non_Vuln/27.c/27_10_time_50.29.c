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
    path[strcspn(path, "\n")] = '\0'; // Remove the newline character from the input

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
        // Ignore "." and ".." directories
        if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0)
        {
            continue;
        }

        // Construct the full path of the entry
        snprintf(filepath, sizeof(filepath), "%s/%s", path, entry->d_name);

        // Get information about the entry
        if (lstat(filepath, &fileStat) < 0)
        {
            printf("Unable to get information about %s\n", filepath);
            continue;
        }

        // Check if the entry is a directory
        if (S_ISDIR(fileStat.st_mode))
        {
            // Recursive call to search_dir for subdirectory
            search_dir(filepath);
        }

        // Do something with the file or directory entry
        printf("Found: %s\n", filepath);
    }

    // Close the directory
    closedir(dir);
}