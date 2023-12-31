#include <stdio.h>
#include <stdlib.h>
#include <curl/curl.h>

int main(void)
{
    CURL *curl;
    FILE *fp;
    CURLcode res;
   
    curl = curl_easy_init();
    if (curl) {
        fp = fopen("example.txt", "w");
        curl_easy_setopt(curl, CURLOPT_URL, "http://www.example.com");
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, fp);
        res = curl_easy_perform(curl);
        
        /* Check for errors */
        if(res != CURLE_OK) {
            fprintf(stderr, "Error: %s\n", curl_easy_strerror(res));
        }
        /* Cleanup curl and close the file */
        curl_easy_cleanup(curl);
        fclose(fp);
    }
    return 0;
}