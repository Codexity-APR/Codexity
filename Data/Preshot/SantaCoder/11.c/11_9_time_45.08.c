#include <stdio.h>
#include <stdlib.h>
#include <curl/curl.h>

int main(void)
{
    CURL *curl;
    FILE *fp;
    CURLcode res;
    
    char *url = "https://www.example.com";
    char outfilename[FILENAME_MAX] = "output.txt";
    curl = curl_easy_init();
    
    if(curl)
    {
        fp = fopen(outfilename,"wb");
        curl_easy_setopt(curl, CURLOPT_URL, url);
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, NULL);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, fp);
        res = curl_easy_perform(curl);
        
        /* always cleanup */
        curl_easy_cleanup(curl);
        
        fclose(fp);
    }
    return 0;
}