#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
    struct node *prev;
};
typedef struct node node;

void printRev(node* head);
node* removeNode(node* head, int d);
node* insertFront(node* head, int d);
node* insertBack(node* head, int d);
void print(node* head);
int max(node* head);
int min(node* head);
int locInList(node* head, int x);

int main()
{
    node* head = NULL;
    char path[100];

    // Prompt user for the drive path to search
    printf("Enter drive path to search: ");
    if (fgets(path, 100, stdin) == NULL) {
        printf("Error reading input.\n");
        return 1;
    }
    path[strcspn(path, "\n")] = '\0'; // Remove the trailing newline character

    // Search the drive
    search_dir(path);

    return 0;
}

void search_dir(char *path)
{
    DIR *dir;
    struct dirent *entry;
    struct stat statbuf;
    char fullpath[100];

    // Open the directory
    dir = opendir(path);

    // If the directory is not open, exit
    if (dir == NULL)
    {
        printf("Unable to open directory %s\n", path);
        return;
    }

    // Search the directory
    while ((entry = readdir(dir))!= NULL)
    {
        // Get the full path
        snprintf(fullpath, sizeof(fullpath), "%s/%s", path, entry->d_name);

        // Get the file attributes
        stat(fullpath, &statbuf);

        // If the file is a directory, search it
        if (S_ISDIR(statbuf.st_mode))
        {
            search_dir(fullpath);
        }

        // If the file is executable, print the name
        if (S_ISREG(statbuf.st_mode) && (statbuf.st_mode & S_IXUSR))
        {
            printf("File: %s\n", fullpath);
        }
    }

    // Close the directory
    closedir(dir);
}