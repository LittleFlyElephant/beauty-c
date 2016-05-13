//
// Created by cxworks on 16-5-13.
//

#ifndef BEAUTY_C_METHOD_H
#define BEAUTY_C_METHOD_H
#define ll long long
#include "../entity/Entity.h"
#include "../entity/APIHelper.h"
#include <stdio.h>

#include <set>
class Ans{
public:
    ll ans[4];
    int len;
    Ans(){
        len=0;
    }

    bool  operator<(const Ans& b) const {
        if (this->len<b.len)
            return  true;
        if (this->len>b.len)
            return false;
        else
            return this->ans[1]<b.ans[1];
    }
    bool operator==(const Ans& b){
        if (b.len!=this->len)
            return false;
        for (int i = 1; i < this->len-1; ++i) {
            if (this->ans[i]!=b.ans[i])
                return  false;
        }
        return true;
    }
};



#endif //BEAUTY_C_METHOD_H
