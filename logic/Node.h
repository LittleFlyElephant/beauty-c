//
// Created by RayChen on 16/5/10.
//

#include "../entity/Entity.h"

#ifndef BEAUTY_C_NODE_H
#define BEAUTY_C_NODE_H


class Node {
public:
    long long id;
    int type;
    Author aa;
    vector<Entity> hop1;
    Node(long long int id, int type) : id(id), type(type) { }
};


#endif //BEAUTY_C_NODE_H
