#include "response.h"

#include <stdio.h>
#include <stdlib.h>

static char *statusToString(HTTP_Status status){
    if(status == STATUS_200) return "200";
    if(status == STATUS_404) return "404";
    if(status == STATUS_400) return "400";
    if(status == STATUS_505) return "505";
    return "nadita";
}

void printResponse(HTTP_Response *res){
    printf("\n\n\n\n---------------Estos son los valores de la respuesta--------------\n");
    printf("Content: %s\n" , res->content);
    printf("Status: %s\n" , statusToString(res->status));
}

void freeResponse(HTTP_Response *res){
    if (res == NULL) return;

    free(res->content);
    free(res);
}

HTTP_Response *createHTTPResponse(){
    HTTP_Response *res = malloc(sizeof(HTTP_Response));
    res->content = NULL;
    res->status = STATUS_NULL;
    return res;
}