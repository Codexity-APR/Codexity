#include <stdio.h>
#include <stdlib.h>
#include <curl/curl.h>

int main(void)
{
    CURL *curl;
    FILE *fp;
    CURLcode res;
    
    // Initialize curl
    curl = curl_easy_init();
    
    if (curl)
    {
        // Open file to write to
        fp = fopen("example.txt", "w");
        
        // Set URL to fetch
        curl_easy_setopt(curl, CURLOPT_URL, "https://example.com");
        
        // Set write function to write to file
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, fp);
        
        // Perform the request
        res = curl_easy_perform(curl);
        
        // Clean up
        curl_easy_cleanup(curl);
        
        // Close file
        fclose(fp);
    }
    
    return 0;
}