#include <stdio.h>
#include <stdlib.h>
#include <curl/curl.h>

int main(void)
{
    CURL *curl;
    FILE *fp;
    CURLcode res;
    
    curl = curl_easy_init();
    
    if(curl)
    {
        // Set the URL to fetch
        curl_easy_setopt(curl, CURLOPT_URL, "https://example.com");
        
        // Set the write function
        fp = fopen("output.html", "wb");
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, fp);
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, fwrite);
        
        // Perform the request
        res = curl_easy_perform(curl);
        
        // Check for errors
        if(res != CURLE_OK)
            fprintf(stderr, "curl_easy_perform() failed: %s\n", curl_easy_strerror(res));
        
        // Cleanup
        curl_easy_cleanup(curl);
        fclose(fp);
    }
    
    return 0;
}