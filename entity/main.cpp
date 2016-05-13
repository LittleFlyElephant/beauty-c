//
// Created by RayChen on 16/5/13.
//

#include <iostream>
#include "APIHelper.h"

using namespace std;

int main(){
    cout << "start:" << endl;//0-id,1-auid,2-afid,3-rid,4-jid,5-cid,6-fid
    vector<Entity> et = getFromWeb(33923547, 6);
}