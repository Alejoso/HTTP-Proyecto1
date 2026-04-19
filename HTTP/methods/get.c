#include "get.h"
#include "../utils/readFile.h"

#include <string.h>
#include <stdlib.h>

HTTP_Status HTTPGet(RequestLine *req , HTTP_Response *res){

    // Sacar la ruta por defecto (/index.html)
    if(strcmp(req->requestURI , "/") == 0){
        char *defaultURI = "/index.html";

        req->requestURI = realloc(req->requestURI , strlen(defaultURI) + 1);
        strcpy(req->requestURI, defaultURI);
    }

    char *content = readFile(req->requestURI);
    
    // El archivo no existe
    if (content == NULL) return STATUS_404 ;

    // El archivo existe
    res->content = content; 
    return STATUS_200;
    
}