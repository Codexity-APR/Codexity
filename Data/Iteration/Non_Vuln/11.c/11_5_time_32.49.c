#include <stdio.h>
#include <stdlib.h>
#include <curl/curl.h>

int main(void)
{
    CURL *curl;
    FILE *fp;
    CURLcode res;

    // Initialize curl
    curl_global_init(CURL_GLOBAL_DEFAULT);

    // Create a curl handle
    curl = curl_easy_init();
    if (curl) {
        // Open file for writing
        fp = fopen("output.txt", "w");
        if (fp == NULL) {
            fprintf(stderr, "Error opening output.txt\n");
            return 1;
        }

        // Set URL to download
        curl_easy_setopt(curl, CURLOPT_URL, "https://www.example.com");

        // Set file to write to
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, fp);

        // Perform the request
        res = curl_easy_perform(curl);
        if (res != CURLE_OK)
            fprintf(stderr, "curl_easy_perform() failed: %s\n", curl_easy_strerror(res));

        // Clean up
        curl_easy_cleanup(curl);

        // Close the file
        fclose(fp);
    }

    // Cleanup curl
    curl_global_cleanup();

    return 0;
}