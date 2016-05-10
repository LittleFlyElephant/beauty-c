//
// Created by RayChen on 16/5/10.
//

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
    vector<long long> auids;
    vector<long long> afids;
    vector<long long> rids;
};


#endif //BEAUTY_C_ENTITY_H
