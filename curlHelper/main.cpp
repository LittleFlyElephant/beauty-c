//
// Created by RayChen on 16/5/12.
//

#include<iostream>
#include "curly.h"

using namespace std;

int main (int argc, const char * argv[])
{

    Curly curly;

    cout << "start" << endl;

    if (curly.Fetch("https://oxfordhk.azure-api.net/academic/v1.0/evaluate?expr=Id=2332023333&attributes=C.CId&subscription-key=f7cc29509a8443c5b3a5e56b0e38b5a6") == CURLE_OK){

        std::cout << "status: " << curly.HttpStatus() << std::endl;
        std::cout << "type: " << curly.Type() << std::endl;
        std::vector<string> headers = curly.Headers();

        for(std::vector<string>::iterator it = headers.begin();
            it != headers.end(); it++)
            std::cout << "Header: " << (*it) << std::endl;

        std::cout << "Content:\n" << curly.Content() << std::endl;
    }

    return 0;
}