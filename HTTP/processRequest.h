#ifndef PROCESS_REQUEST_H
#define PROCESS_REQUEST_H

#include "structs/response.h"
#include "structs/requestLine.h"

typedef enum {
    GET,
    HEAD,
    POST,
    PUT,
    DELETE,
    TRACE,
    CONNECT,
    OPTIONS,
    UNKNOWN
} HttpMethod;


int  processRequest(RequestLine *req , HTTP_Response *res );
HttpMethod getMethod(const char *strMethod);

#endif