#include "processRequest.h"
#include "methods/get.h"

#include <string.h>
#include <stdio.h>

HttpMethod getMethod(const char *strMethod){

    if(strcmp(strMethod , "GET") == 0) return GET;
    if(strcmp(strMethod , "HEAD") == 0) return HEAD;
    if(strcmp(strMethod , "POST") == 0) return POST;
    if(strcmp(strMethod , "PUT") == 0) return PUT;
    if(strcmp(strMethod , "DELETE") == 0) return DELETE;
    if(strcmp(strMethod , "TRACE") == 0) return TRACE;
    if(strcmp(strMethod , "CONNECT") == 0) return CONNECT;
    if(strcmp(strMethod , "OPTIONS") == 0) return OPTIONS;

    return UNKNOWN;
}


int processRequest(RequestLine *req , HTTP_Response *res ){
    
    HttpMethod method = getMethod(req->method);

    switch (method){
        case GET:
            int e = HTTPGet(req , res);
            if (e == -1) res->status = "400";
            if (e == 0)res->status = "200";
            return 0;

        case HEAD:
            break;

        case POST:
            break;

        case PUT:
            break;

        case DELETE:
            break;

        case TRACE:
            break;

        case CONNECT:
            break;

        case OPTIONS:

            break;
        
        default:
            printf("Metodo no soportado\n");
            return -1;
    }

    return 0;
}