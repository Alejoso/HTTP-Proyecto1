#include "get.h"
#include "../utils/readFile.h"

#include <string.h>
#include <stdlib.h>

int HTTPGet(RequestLine *req , HTTP_Response *res){

    // Sacar la ruta por defecto (/index.html)
    if(strcmp(req->requestURI , "/") == 0){
        char *defaultURI = "/index.html";

        req-> requestURI = realloc(req->requestURI , strlen(defaultURI) + 1);
        strcpy(req->requestURI, defaultURI);
    }

    char *content = readFile(req->requestURI);
    if (content == NULL) return -1;

    res->content = content; 

    return 0;

}