//
// Created by RayChen on 16/5/10.
//

#include "Entity.h"

#ifndef BEAUTY_C_APIHELPER_H
#define BEAUTY_C_APIHELPER_H

//0-id,1-auid,2-afid,3-rid,4-jid,5-cid,6-fid
vector<Entity> getEntities(long long id, int type);
vector<Entity> getFromWeb(long long id, int type);
void printEntities(vector<Entity> ve);

#endif //BEAUTY_C_APIHELPER_H
