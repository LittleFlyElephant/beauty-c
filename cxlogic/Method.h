//
// Created by cxworks on 16-5-13.
//

#ifndef BEAUTY_C_METHOD_H
#define BEAUTY_C_METHOD_H
#define ll long long
#include "../entity/Entity.h"
#include "../entity/APIHelper.h"
#include "../rapidjson/document.h"
#include "../rapidjson/prettywriter.h"
#include "../rapidjson/filewritestream.h"
#include "../rapidjson/stringbuffer.h"
#include <stdio.h>
#include <set>
class Ans{
public:
    ll ans[4];
    int len;
    Ans(){
        len=0;
    }
};



#endif //BEAUTY_C_METHOD_H
