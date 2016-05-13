//
// Created by RayChen on 16/5/10.
//

#include <iostream>
#include <string>
#include "APIHelper.h"
#include "../curlHelper/curly.h"
#include "../rapidjson/document.h"

using namespace std;
using namespace rapidjson;

string typeToString(int type){
    switch(type){
        case 1:
            return "AA.AuId";
        case 2:
            return "AA.AfId";
        case 3:
            return "R.RId";
        case 4:
            return "J.JId";
        case 5:
            return "C.CId";
        case 6:
            return "F.FId";
        default:
            return "";
    }
}

void printVector(vector<long long> v){
    vector<long long>::iterator it;
    for (it = v.begin(); it < v.end(); ++it) {
        long long l = *it;
        cout << l << " ";
    }
    cout << endl;
}

void printEntities(vector<Entity> ve){
    vector<Entity>::iterator it;
    for (it = ve.begin(); it < ve.end(); ++it) {
        Entity e = *it;
        cout << "Id: " << e.id << endl;
        cout << "AuIds: "; printVector(e.auids);
        cout << "AfIds: "; printVector(e.afids);
        cout << "RIds: "; printVector(e.rids);
        cout << "CIds: "; printVector(e.cids);
        cout << "FIds: "; printVector(e.fids);
        cout << "JIds: "; printVector(e.jids);
    }
}

//0-id,1-auid,2-afid,3-rid,4-jid,5-cid,6-fid
string buildString(long long id, int type){
    string my_id = to_string(id);
    string base = "Composite(";
    if (type > 0) {
        if (type != 3){
            base += typeToString(type);
            base += "=";
            base += my_id;
            base += ")";
        }else base = "RId="+my_id;
    } else base = "Id="+my_id;
    return base;
}

Entity valueToEntity(Value& value){
    Entity e;
    e.id = value["Id"].GetInt64();
    if (value.HasMember("RId")){
        Value& rid_array = value["RId"];
        for (size_t i = 0; i < rid_array.Size(); ++i) {
            e.rids.insert(e.rids.end(), rid_array[i].GetInt64());
        }
    }
    if (value.HasMember("AA")){
        Value& aa_array = value["AA"];
        for (size_t i = 0; i < aa_array.Size(); ++i) {
            Value& aa_value = aa_array[i];
            if (aa_value.HasMember("AuId")) e.auids.insert(e.auids.end(), aa_value["AuId"].GetInt64());
            if (aa_value.HasMember("AfId")) e.afids.insert(e.afids.end(), aa_value["AfId"].GetInt64());
        }
    }
    if (value.HasMember("F")){
        Value& f_array = value["F"];
        for (size_t i = 0; i < f_array.Size(); ++i) {
            Value& f_value = f_array[i];
            e.fids.insert(e.fids.end(), f_value["FId"].GetInt64());
        }
    }
    if (value.HasMember("C")){
        Value& c_value = value["C"];
        e.cids.insert(e.cids.end(), c_value["CId"].GetInt64());
    }
    if (value.HasMember("J")){
        Value& j_value = value["J"];
        e.jids.insert(e.jids.end(), j_value["JId"].GetInt64());
    }
    return e;
}

vector<Entity> jsonToEntities(string json){
    vector<Entity> entity_vectors;
    Document document;
    if(document.Parse<0>(json.c_str()).HasParseError()){
        cout << "error in parse json string" << endl;
    }
    if(!document.HasMember("entities")){
        cout << "no entities attr" << endl;
    }
    Value& entities = document["entities"];
    for (size_t i = 0; i < entities.Size(); ++i) {
        Value& entity = entities[i];
        entity_vectors.insert(entity_vectors.end(), valueToEntity(entity));
    }
    return entity_vectors;
}

vector<Entity> getEntities(long long id, int type) {
    return getFromWeb(id, type);
}

vector<Entity> getFromWeb(long long id, int type) {
    vector<Entity> ans;
    Curly curly;
    string attrs = "Id,RId,C.CId,J.JId,F.FId,AA.AuId,AA.AfId";
    string base = "https://oxfordhk.azure-api.net/academic/v1.0/evaluate?";
    base += "expr=";
    base += buildString(id, type);
    base += "&attributes=";
    base += attrs;
    base += "&count=10000";
    base += "&subscription-key=f7cc29509a8443c5b3a5e56b0e38b5a6";

    if (curly.Fetch(base) == CURLE_OK){
        ans = jsonToEntities(curly.Content());
    } else
        cout << "error in get from api" << endl;

//    printEntities(ans);
    return ans;
}

