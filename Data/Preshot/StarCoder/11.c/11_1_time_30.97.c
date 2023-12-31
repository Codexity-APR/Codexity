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
    
    if(curl) {
        // Open file to write to
        fp = fopen("output.html", "wb");
        
        // Set URL to fetch
        curl_easy_setopt(curl, CURLOPT_URL, "http://www.example.com");
        
        // Set file to write to
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, fp);
        
        // Perform the request
        res = curl_easy_perform(curl);
        
        // Check for errors
        if(res != CURLE_OK)
            fprintf(stderr, "curl_easy_perform() failed: %s\n", curl_easy_strerror(res));
        
        // Cleanup
        curl_easy_cleanup(curl);
        
        // Close file
        fclose(fp);
    }

    return 0;
}