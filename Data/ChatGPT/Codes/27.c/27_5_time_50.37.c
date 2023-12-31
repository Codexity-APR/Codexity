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
    struct stat info;

    // Open the directory
    dir = opendir(path);

    if (dir == NULL)
    {
        printf("Unable to open the directory %s\n", path);
        return;
    }

    // Loop through each entry in the directory
    while ((entry = readdir(dir)) != NULL)
    {
        char entry_path[256];
        snprintf(entry_path, sizeof(entry_path), "%s/%s", path, entry->d_name);

        // Get the file/directory information
        if (stat(entry_path, &info) == -1)
        {
            printf("Unable to get information about %s\n", entry_path);
            continue;
        }

        // Check if it is a directory
        if (S_ISDIR(info.st_mode))
        {
            // Ignore the current directory (.) and parent directory (..)
            if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0)
                continue;

            // Recursively search the subdirectory
            search_dir(entry_path);
        }
        else
        {
            // It is a file, do something with it
            printf("Found file: %s\n", entry_path);
        }
    }

    // Close the directory
    closedir(dir);
}