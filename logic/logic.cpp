//
// Created by RayChen on 16/5/10.
//

#include <iostream>
#include "logic.h"
#include "Node.h"
#include "../entity/APIHelper.h"

void addToNodes(vector<long long> toAdd, int type, vector<Node> nodes){
    vector<long long>::iterator t;
    for (t = toAdd.begin(); t < toAdd.end(); t++) {
        long long l = *t;
        Node newNode(l, type);
        newNode.hop1 = getEntities(l, type);
        nodes.insert(nodes.end(), newNode);
    }
}

vector<Node> getFirstHop(long long id, int type){
    vector<Node> nodes;
    vector<Entity> data = getEntities(id, type);
    if (type == 0){//是 id
        vector<Entity>::iterator t;
        for (t = data.begin(); t < data.end(); t++) {
            Entity e = *t;
            addToNodes(e.rids, 3, nodes);
            addToNodes(e.auids, 1, nodes);
            addToNodes(e.fids, 6, nodes);
            addToNodes(e.cids, 5, nodes);
            addToNodes(e.jids, 4, nodes);
            vector<Author>::iterator aa_it;
            for (aa_it = e.aas.begin(); aa_it < e.aas.end(); ++aa_it) {

            }
        }
    }else {//是 auid
        vector<Entity>::iterator t;
        for (t = data.begin(); t < data.end(); t++) {
            Entity e = *t;
            Node newNode(e.id, 0);
            nodes.insert(nodes.end(), newNode);
            addToNodes(e.afids, 2, nodes);
        }
    }
    return nodes;
}

int getIdType(long long id){
    vector<Entity> ans = getEntities(id, 1);
    if (ans.size() == 0) return 0;
    return 1;
}

vector<vector<long long>> calculate(long long id1, long long id2){
    int id1_type = getIdType(id1);
    int id2_type = getIdType(id2);
    vector<Node> id1_hop1 = getFirstHop(id1, id1_type);
    vector<Node> id2_hop1 = getFirstHop(id2, id2_type);

    vector<vector<long long>> ans;


}