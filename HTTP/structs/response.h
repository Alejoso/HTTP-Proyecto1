#ifndef RESPONSE_H
#define RESPONSE_H

typedef enum {
    STATUS_200,
    STATUS_400,
    STATUS_404,
    STATUS_505,
    STATUS_NULL,
} HTTP_Status;

typedef struct {
    HTTP_Status status;
    char *content;
} HTTP_Response;

void printResponse( HTTP_Response *res);
void freeResponse(HTTP_Response *res);
HTTP_Response *createHTTPResponse();

#endif