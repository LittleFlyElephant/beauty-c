//
// Created by cxworks on 16-5-11.
//

#ifndef _Method_cx
#define _Method_cx

#include <vector>
#include <set>
#include "../entity/Entity.h"
#define ll long long
using namespace std;

bool id2id(Entity src,Entity dst){
    vector<ll> rid=src.rids;
    for (int i = 0; i < rid.size(); ++i) {
        if (rid[i]==dst.id)
            return true;
    }
    return false;
}

vector<ll> af2au(Entity src,Entity dst){
    vector<ll> ans=*(new vector<ll>());
    vector<ll> afid=src.afids;
    set<ll> dstaf;
    for (int i = 0; i < dst.afids.size(); ++i) {
        dstaf.insert(dst.afids[i]);
    }
    //
    for (int i = 0; i < afid.size(); ++i) {
        if (dstaf.find(afid[i])!=dstaf.end()){
            ans.push_back(afid[i]);
        }
    }
    return  ans;
}

bool inline id2au(Entity src,Entity dst){
    return src.id==dst.id;
}

vector<ll> fid2id(Entity src,Entity dst){
    vector<ll> ans=*(new vector<ll>());
    vector<ll> srcfid=src.fids;
    set<ll> srcfidset;
    for (int i = 0; i < srcfid.size(); ++i) {
        srcfidset.insert(srcfid[i]);
    }
    for (int i = 0; i < dst.fids.size(); ++i) {
        if (srcfidset.find(dst.fids[i])!=srcfidset.end()){
            ans.push_back(dst.fids[i]);
        }
    }
    return  ans;
}

vector<ll> jid2id(Entity src,Entity dst){
    vector<ll> ans=*(new vector<ll>());
    vector<ll> srcjid=src.jids;
    set<ll> srcjidset;
    for (int i = 0; i < srcjid.size(); ++i) {
        srcjidset.insert(srcjid[i]);
    }
    for (int i = 0; i < dst.jids.size(); ++i) {
        if (srcjidset.find(dst.jids[i])!=srcjidset.end()){
            ans.push_back(dst.jids[i]);
        }
    }
    return  ans;
}

vector<ll> cid2id(Entity src,Entity dst){
    vector<ll> ans=*(new vector<ll>());
    vector<ll> srccid=src.cids;
    set<ll> srccidset;
    for (int i = 0; i < srccid.size(); ++i) {
        srccidset.insert(srccid[i]);
    }
    for (int i = 0; i < dst.cids.size(); ++i) {
        if (srccidset.find(dst.cids[i])!=srccidset.end()){
            ans.push_back(dst.cids[i]);
        }
    }
    return  ans;
}


bool au2id(Entity src,Entity dst){
    if (src.id==dst.id)
        return true;
    else
        return false;
}

vector<ll> au22id(Entity src,Entity dst){
    vector<ll> ans=*(new vector<ll>);
    vector<ll> dstau=dst.auids;
    set<ll> dstset;
    for (int i = 0; i < dstau.size(); ++i) {
        dstset.insert(dstau[i]);
    }
    //
    vector<ll> temp=src.auids;
    for (int i = 0; i < temp.size(); ++i) {
        if (dstset.find(temp[i])!=dstset.end()){
            ans.push_back(temp[i]);
        }
    }
    return  ans;
}




#endif