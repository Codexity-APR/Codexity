#include <stdio.h>
#include <stdlib.h>
#include <curl/curl.h>

int main(void)
{
    CURL *curl;
    FILE *fp;
    CURLcode res;
    
    curl = curl_easy_init(); // initialize curl
    if (curl) {
        fp = fopen("example.txt","wb"); // open file to write data
        
        // set url to download data from
        curl_easy_setopt(curl, CURLOPT_URL, "https://www.example.com");
        
        // write data to file
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, fp);
        
        res = curl_easy_perform(curl); // perform the download
        if (res != CURLE_OK) {
            fprintf(stderr, "Error: %s\n", curl_easy_strerror(res)); // print error message
        }
        
        curl_easy_cleanup(curl); // cleanup curl
        fclose(fp); // close file
    }
    
    return 0;
}