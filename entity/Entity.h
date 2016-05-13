//
// Created by RayChen on 16/5/10.
//

#include "Author.h"
#include <vector>
using namespace std;

#ifndef BEAUTY_C_ENTITY_H
#define BEAUTY_C_ENTITY_H


class Entity {
public:
    long long id;
    vector<long long> fids;
    vector<long long> cids;
    vector<long long> jids;
    vector<Author> aas;
    vector<long long> rids;
    vector<long long> afids;
    vector<long long> auids;
    bool check(){
        return  fids.empty()&&cids.empty()&&jids.empty()&&rids.empty()&&afids.empty()&&auids.empty();
    }
};


#endif //BEAUTY_C_ENTITY_H
