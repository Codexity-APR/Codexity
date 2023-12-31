#include <stdio.h>
#include <stdlib.h>
#include <curl/curl.h>

int main(void)
{
    CURL *curl;
    FILE *fp;
    CURLcode res;
    
    // Initialize CURL
    curl = curl_easy_init();
    
    if (curl) {
        // Open file for writing
        fp = fopen("output.txt", "wb");
        if (fp == NULL) {
            printf("File cannot be opened.");
            return 1;
        }
        
        // Set URL to retrieve
        curl_easy_setopt(curl, CURLOPT_URL, "https://example.com");
        
        // Set file to write to
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, fp);
        
        // Perform the request
        res = curl_easy_perform(curl);
        
        // Check for errors
        if (res != CURLE_OK) {
            fprintf(stderr, "curl_easy_perform() failed: %s\n", curl_easy_strerror(res));
        }
        
        // Cleanup
        curl_easy_cleanup(curl);
        
        // Close file
        fclose(fp);
    }
    
    return 0;
}