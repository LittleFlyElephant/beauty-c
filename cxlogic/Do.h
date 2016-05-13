//
// Created by cxworks on 16-5-13.
//

#ifndef BEAUTY_C_DO_H
#define BEAUTY_C_DO_H

#include "Method.h"
#include <string>
bool id2id(Entity src,Entity dst);
vector<ll> af2au(Entity src,Entity dst);
bool inline id2au(Entity src,Entity dst);
vector<ll> fid2id(Entity src,Entity dst);
vector<ll> jid2id(Entity src,Entity dst);
vector<ll> cid2id(Entity src,Entity dst);
bool au2id(Entity src,Entity dst);
vector<ll> au22id(Entity src,Entity dst);
vector<ll> comp(Entity src,Entity dst);
void id2fcj2id(vector<Entity> ,vector<Ans>,Entity,ll);
vector<Entity> getE(ll id,int type);
string convert2json(vector<Ans> src);
vector<Ans> cx(ll id1,ll id2);

#endif //BEAUTY_C_DO_H
