#include "response.h"

#include <stdio.h>
#include <stdlib.h>

void printResponse(HTTP_Response *res){
    printf("\n\n\n\n---------------Estos son los valores de la respuesta--------------\n");
    printf("Content: %s\n" , res->content);
    printf("Status: %s\n" , res->status);
}

void freeResponse(HTTP_Response *res){
    free(res->content);
    free(res->status);
    res->content = NULL;
    res->status = NULL;
}

HTTP_Response *createHTTPResponse(){
    HTTP_Response *res = malloc(sizeof(HTTP_Response));
    res->content = NULL;
    res->status = NULL;
    return res;
}