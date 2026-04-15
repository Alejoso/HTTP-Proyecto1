#include "requestLine.h"

#include <stdio.h>
#include <stdlib.h>

void printRequestLine( RequestLine *req){
    printf("\n\n\n\n\n\n--------------Estos son los datos que se parsearon a la request---------------------\n");
    printf("Metodo: %s\n" , req->method);
    printf("requestURI: %s\n" , req->requestURI);
    printf("Version de HTTP: %s\n" , req->httpVersion);
}

RequestLine *createRequestLine(){
    RequestLine *req = malloc(sizeof(RequestLine));

    req->method = NULL;
    req->requestURI = NULL;
    req->httpVersion = NULL;

    return req;
}

void freeRequestLine (RequestLine *req){
    free(req->method);
    free(req->requestURI);
    free(req->httpVersion);

    req->method = NULL;
    req->requestURI = NULL;
    req->httpVersion = NULL;
}
