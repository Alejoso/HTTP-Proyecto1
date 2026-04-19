#include "response.h"
#include "../utils/enumToString.h"

#include <stdio.h>
#include <stdlib.h>

void printResponse(HTTP_Response *res){
    char headerBuffer[4096];
    snprintf(headerBuffer, sizeof(headerBuffer) , 
        "%s %s %s\r\n"
        "Content-Length: %zu\r\n"
        "\r\n",
        versionToString(res->httpVersion),
        statusToString(res->status),
        statusToReasonPhrase(res->status),
        res->contentLength
    );

    printf("\n\n%s%s" , headerBuffer , res->content);
}

void freeResponse(HTTP_Response *res){
    if (res == NULL) return;

    free(res->content);
    free(res);
}

HTTP_Response *createHTTPResponse(){
    HTTP_Response *res = malloc(sizeof(HTTP_Response));

    res->status = STATUS_NULL;
    res->httpVersion = VERSION_HTTP1;
    
    res->content = NULL;
    res->contentLength = 0;
    
    return res;
}