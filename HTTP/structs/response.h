#ifndef RESPONSE_H
#define RESPONSE_H

typedef struct {
    char *status;
    char *content;
} HTTP_Response;

void printResponse( HTTP_Response *res);
void freeResponse(HTTP_Response *res);
HTTP_Response *createHTTPResponse();
#endif