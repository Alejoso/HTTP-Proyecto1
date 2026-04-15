#include "HTTP/requestParser.h"
#include "HTTP/processRequest.h"

int main(){

    RequestLine *req = createRequestLine();
    HTTP_Response *res = createHTTPResponse();

    int parse = parseRequestLine("GET /index.html HTTP1/1\r\n" , req);

    if(parse == -1) printf("Pailas, se nos jodio el parser\n");

    printRequestLine(req);

    int p = processRequest(req , res);

    if(p == -1) printf("Se nos pailametro el procesamiento de la request\n");

    printResponse(res);

    return 0;
}