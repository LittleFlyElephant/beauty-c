//
// Created by cxworks on 16-5-11.
//

#ifndef _do_
#define _do_

#include "Method.h"
using  namespace std;
using namespace rapidjson;


bool id2id(Entity src,Entity dst){
    vector<ll> rid=src.rids;
    for (int i = 0; i < rid.size(); ++i) {
        if (rid[i]==dst.id)
            return true;
    }
    return false;
}
vector<ll> af2au(Entity src,Entity dst){
    vector<ll> ans=vector<ll>();
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
    vector<ll> ans=vector<ll>();
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
    vector<ll> ans=vector<ll>();
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
    vector<ll> ans=vector<ll>();
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
    vector<ll> ans=vector<ll>();
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


vector<ll> comp(Entity src,Entity dst);
void id2fcj2id(vector<Entity> ,vector<Ans>,Entity,ll);


//0-id,1-auid,2-afid,3-rid,4-jid,5-cid,6-fid
vector<Entity> getE(ll id,int type){
    return  getFromWeb(id,type);
}



string convert2json(vector<Ans> src){
   string ans;
    ans.append("[");
    for (int i = 0; i < src.size(); ++i) {
        int len=src[i].len;
        ans.append("[");
        for (int j = 0; j < len; ++j) {
            char t[20];
            sprintf(t,"%lld",src[i].ans[j]);
            ans.append(t);
            if (j<len-1)
                ans.append(",");
        }
        ans.append("]");
        if (i<src.size()-1)
            ans.append(",");
    }
    ans.append("]");
    return  ans;
}

vector<Ans> cx(ll id1,ll id2){
    vector<Ans> ans=*(new vector<Ans>);
    vector<Entity> start=getE(id1,0);
    vector<Entity> end=getE(id2,0);

    if (start.size()>1&&end.size()>1){
        //au -> au
        //au->af->au
        for (int i = 0; i < start.size(); ++i) {
            for (int j = 0; j < end.size(); ++j) {
                vector<ll> temp=af2au(start[i],end[j]);
                if (temp.size()>0){
                    for (int k = 0; k < temp.size(); ++k) {
                        Ans* ans1=new Ans();
                        ans1->ans[0]=id1;
                        ans1->ans[1]=temp[k];
                        ans1->ans[2]=id2;
                        ans1->len=3;
                        ans.push_back(*ans1);
                    }
                }
            }
        }
        //au->id->au
        for (int i = 0; i < start.size(); ++i) {
            for (int j = 0; j < end.size(); ++j) {
                if (id2au(start[i],end[j])){

                        Ans* ans1=new Ans();
                        ans1->ans[0]=id1;
                        ans1->ans[1]=start[i].id;
                        ans1->ans[2]=id2;
                        ans1->len=3;
                        ans.push_back(*ans1);
                }
            }
        }
        //au->id->id->au
        for (int i = 0; i < start.size(); ++i) {
            ll firid=start[i].id;
            for (int j = 0; j < end.size(); ++j) {
                ll secid=end[j].id;
                if(id2id(start[i],end[j])){
                    Ans* ans1=new Ans();
                    ans1->ans[0]=id1;
                    ans1->ans[1]=firid;
                    ans1->ans[2]=secid;
                    ans1->ans[3]=id2;
                    ans1->len=4;
                    ans.push_back(*ans1);
                }
            }

        }
    }
    else if(start.size()>1&&end.size()==1){
        //au->id
        Entity ende=end[0];
        //au->id
        for (int i = 0; i < start.size(); ++i) {
            if (au2id(start[i],ende)){
                Ans* ans1=new  Ans();
                ans1->ans[0]=id1;
                ans1->ans[1]=id2;
                ans1->len=2;
                ans.push_back(*ans1);
                break;
            }
        }
        //au->id->id
        for (int i = 0; i < start.size(); ++i) {

            if (id2id(start[i],ende)){
                ll firid=start[i].id;
                Ans* ans1=new Ans();
                ans1->ans[0]=id1;
                ans1->ans[1]=firid;
                ans1->ans[2]=id2;
                ans1->len=3;
                ans.push_back(*ans1);
            }
        }
        //au->af->au->id
        for (int i = 0; i < start.size(); ++i) {
            vector<ll> firafid=start[i].afids;
            for (int j = 0; j < firafid.size(); ++j) {
                vector<Entity> secauid=getE(firafid[j],2);

                for (int k = 0; k < secauid.size(); ++k) {
                    vector<ll> secau=au22id(secauid[k],ende);
                    if (!secau.empty()){
                        for (int l = 0; l < secau.size(); ++l) {
                            Ans * ans1=new Ans();
                            ans1->ans[0]=id1;
                            ans1->ans[1]=firafid[j];
                            ans1->ans[2]=secau[l];
                            ans1->ans[3]=id2;
                            ans1->len=4;
                            ans.push_back(*ans1);
                        }
                    }
                }
            }
        }
        //au->id->fcj->id
        id2fcj2id(start,ans,ende,id1);
        //au->id->id->id
        for (int i = 0; i < start.size(); ++i) {
            ll firid=start[i].id;
            vector<ll> rid=start[i].rids;
            for (int j = 0; j < rid.size(); ++j) {
                Entity temp=getE(rid[j],3)[0];
                if (id2id(temp,ende)){
                    Ans* ans1=new  Ans();
                    ans1->ans[0]=id1;
                    ans1->ans[1]=firid;
                    ans1->ans[2]=temp.id;
                    ans1->ans[3]=id2;
                    ans1->len=4;
                    ans.push_back(*ans1);
                }
            }
        }
        //au->id->au->id
        for (int i = 0; i < start.size(); ++i) {
            ll firid=start[i].id;
            vector<Entity> sec=getE(firid,0);
            for (int j = 0; j < sec.size(); ++j) {
                vector<ll> temp=au22id(sec[j],ende);
                if (!temp.empty()){
                    for (int k = 0; k < temp.size(); ++k) {
                        Ans* ans1=new Ans();
                        ans1->ans[0]=id1;
                        ans1->ans[1]=firid;
                        ans1->ans[2]=temp[k];
                        ans1->ans[3]=id2;
                        ans.push_back(*ans1);
                    }
                }
            }
        }
    } else if(start.size()==1&&end.size()>1){
        //id->au
        Entity starte=start[0];
        //id->au
        vector<ll> auid=starte.auids;
        for (int i = 0; i < auid.size(); ++i) {
            if (auid[i]==id2){
                Ans* ans1=new Ans();
                ans1->ans[0]=id1;
                ans1->ans[1]=id2;
                ans1->len=2;
                ans.push_back(*ans1);
            }
        }
        //id->id->au
        for (int i = 0; i < end.size(); ++i) {
            Entity now=end[i];
            if (id2id(starte,now)){
                Ans* ans1=new Ans();
                ans1->ans[0]=id1;
                ans1->ans[1]=now.id;
                ans1->ans[2]=id2;
                ans1->len=3;
                ans.push_back(*ans1);
            }
        }
        //id->fcj->id->au
        //fid
        for (int i = 0; i < end.size(); ++i) {
            Entity now=end[i];
            vector<ll> temp=fid2id(starte,now);
            if (temp.size()>0){
                for (int j = 0; j < temp.size(); ++j) {
                    Ans* ans1=new Ans();
                    ans1->ans[0]=id1;
                    ans1->ans[1]=temp[j];
                    ans1->ans[2]=now.id;
                    ans1->ans[3]=id2;
                    ans1->len=4;
                    ans.push_back(*ans1);
                }
            }
        }
        //jid
        for (int i = 0; i < end.size(); ++i) {
            Entity now=end[i];
            vector<ll> temp=jid2id(starte,now);
            if (temp.size()>0){
                for (int j = 0; j < temp.size(); ++j) {
                    Ans* ans1=new Ans();
                    ans1->ans[0]=id1;
                    ans1->ans[1]=temp[j];
                    ans1->ans[2]=now.id;
                    ans1->ans[3]=id2;
                    ans1->len=4;
                    ans.push_back(*ans1);
                }
            }
        }
        //cid
        for (int i = 0; i < end.size(); ++i) {
            Entity now=end[i];
            vector<ll> temp=cid2id(starte,now);
            if (temp.size()>0){
                for (int j = 0; j < temp.size(); ++j) {
                    Ans* ans1=new Ans();
                    ans1->ans[0]=id1;
                    ans1->ans[1]=temp[j];
                    ans1->ans[2]=now.id;
                    ans1->ans[3]=id2;
                    ans1->len=4;
                    ans.push_back(*ans1);
                }
            }
        }
        //id->id->id->au
        vector<ll> rid=starte.rids;
        for (int i = 0; i < rid.size(); ++i) {
            vector<Entity> temp=getE(rid[i],3);
            for (int j = 0; j < temp.size(); ++j) {
                for (int k = 0; k < end.size(); ++k) {
                    if (id2id(temp[j],end[k])){
                        Ans* ans1=new Ans();
                        ans1->ans[0]=id1;
                        ans1->ans[1]=temp[j].id;
                        ans1->ans[2]=end[k].id;
                        ans1->ans[3]=id2;
                        ans.push_back(*ans1);
                    }
                }
            }
        }
        //id->au->af->au
        for (int i = 0; i < auid.size(); ++i) {
            ll firau=auid[i];
            vector<Entity> sec=getE(firau,1);//auid
            for (int j = 0; j < sec.size(); ++j) {
                for (int k = 0; k < end.size(); ++k) {
                    vector<ll> secaf=af2au(sec[j],end[k]);
                    if (!secaf.empty()){
                        for (int l = 0; l < secaf.size(); ++l) {
                            Ans* ans1=new Ans();
                            ans1->ans[0]=id1;
                            ans1->ans[1]=firau;
                            ans1->ans[2]=secaf[l];
                            ans1->ans[3]=id2;
                            ans.push_back(*ans1);
                        }
                    }
                }
            }
        }
        //

    }
    else if(start.size()==1&&end.size()==1){
        //id->id
        Entity starte=start[0];
        Entity ende=end[0];
        //id->id
        if (id2id(starte,ende)){
            Ans* ans1=new Ans();
            ans1->ans[0]=id1;
            ans1->ans[1]=id2;
            ans1->len=2;
            ans.push_back(*ans1);
        }
        //id->id->id
        vector<ll> rid=starte.rids;
        for (int i = 0; i < rid.size(); ++i) {
            vector<Entity> firid=getE(rid[i],3);//rid
            for (int j = 0; j < firid.size(); ++j) {
                if (id2id(firid[j],ende)){
                    Ans* ans1=new Ans();
                    ans1->ans[0]=id1;
                    ans1->ans[1]=firid[j].id;
                    ans1->ans[2]=id2;
                    ans1->len=3;
                    ans.push_back(*ans1);
                }
            }
        }
        //id->au->id
        vector<ll> firau=au22id(starte,ende);
        if (!firau.empty()){
            for (int i = 0; i < firau.size(); ++i) {
                Ans* ans1=new Ans();
                ans1->ans[0]=id1;
                ans1->ans[1]=firau[i];
                ans1->ans[2]=id2;
                ans.push_back(*ans1);
            }
        }
        //id->fcj->id
        id2fcj2id(start,ans,ende,id1);
        //id->id->id->id
        for (int i = 0; i < starte.rids.size(); ++i) {
            vector<Entity> firid=getE(starte.rids[i],3);//rid
            for (int j = 0; j < ende.rids.size(); ++j) {
                vector<Entity> secrid=getE(ende.rids[j],3);
                for (int k = 0; k < firid.size(); ++k) {
                    for (int l = 0; l < secrid.size(); ++l) {
                        if (id2id(firid[k],secrid[l])){
                            Ans* ans1=new Ans();
                            ans1->ans[0]=id1;
                            ans1->ans[1]=firid[k].id;
                            ans1->ans[2]=secrid[l].id;
                            ans1->ans[3]=id2;
                            ans1->len=4;
                            ans.push_back(*ans1);
                        }
                    }
                }
            }
        }
        //id->au->id->id
        for (int i = 0; i < starte.auids.size(); ++i) {
            ll firau=starte.auids[i];
            vector<Entity> sec=getE(firau,1);//auid
            for (int j = 0; j < sec.size(); ++j) {
                if (id2id(sec[j],ende)){
                    Ans* ans1=new Ans();
                    ans1->ans[0]=id1;
                    ans1->ans[1]=firau;
                    ans1->ans[2]=sec[j].id;
                    ans1->ans[3]=id2;
                    ans.push_back(*ans1);
                }
            }
        }
        //id->id->au->id
        for (int i = 0; i < rid.size(); ++i) {
            vector<Entity> fir=getE(rid[i],3);
            for(int j = 0; j < fir.size(); ++j){
                vector<ll> secau=au22id(fir[j],ende);
                if (!secau.empty()){
                    for (int k = 0; k < secau.size(); ++k) {
                        Ans* ans1=new Ans();
                        ans1->ans[0]=id1;
                        ans1->ans[1]=fir[j].id;
                        ans1->ans[2]=secau[k];
                        ans1->ans[3]=id2;
                        ans.push_back(*ans1);

                    }

                }
            }
        }
        //id->id->fcj->id
        for (int i = 0; i < rid.size(); ++i) {
            vector<Entity> fir=getE(rid[i],3);
            id2fcj2id(fir,ans,ende,id1);
        }
        //id->fcj->id->id
        //fid
        vector<ll> fid=starte.fids;
        for (int i = 0; i < fid.size(); ++i) {
            vector<Entity> firid=getE(fid[i],6);//fid
            for (int j = 0; j < firid.size(); ++j) {
                if (id2id(firid[j],ende)){
                    Ans* ans1=new Ans();
                    ans1->ans[0]=id1;
                    ans1->ans[1]=fid[i];
                    ans1->ans[2]=firid[j].id;
                    ans1->ans[3]=id2;
                    ans.push_back(*ans1);
                }
            }
        }
        //jid
        vector<ll> jid=starte.jids;
        for (int i = 0; i < jid.size(); ++i) {
            vector<Entity> jirid=getE(jid[i],4);//cid
            for (int j = 0; j < jirid.size(); ++j) {
                if (id2id(jirid[j],ende)){
                    Ans* ans1=new Ans();
                    ans1->ans[0]=id1;
                    ans1->ans[1]=jid[i];
                    ans1->ans[2]=jirid[j].id;
                    ans1->ans[3]=id2;
                    ans.push_back(*ans1);
                }
            }
        }
        //fid
        vector<ll> cid=starte.cids;
        for (int i = 0; i < cid.size(); ++i) {
            vector<Entity> cirid=getE(cid[i],5);//cid
            for (int j = 0; j < cirid.size(); ++j) {
                if (id2id(cirid[j],ende)){
                    Ans* ans1=new Ans();
                    ans1->ans[0]=id1;
                    ans1->ans[1]=cid[i];
                    ans1->ans[2]=cirid[j].id;
                    ans1->ans[3]=id2;
                    ans.push_back(*ans1);
                }
            }
        }
    }


}





void id2fcj2id(vector<Entity> id,vector<Ans> ans,Entity tar,ll id1){
    //
    for (int i = 0; i < id.size(); ++i) {
        Entity now=id[i];
        //fid
        vector<ll> fid=now.fids;
        vector<ll> tarfid=tar.fids;
        set<ll> tarfidset;
        for (int j  = 0; j < tarfid.size(); ++j) {
            tarfidset.insert(tarfid[i]);
        }
        for (int j = 0; j < fid.size(); ++j) {
            if (tarfidset.find(fid[j])!=tarfidset.end()){
                Ans* ans1=new Ans();
                ans1->ans[0]=id1;
                ans1->ans[1]=now.id;
                ans1->ans[2]=fid[j];
                ans1->ans[3]=tar.id;
                ans.push_back(*ans1);
            }
        }
        //cid
        vector<ll> cid=now.cids;
        vector<ll> tarcid=tar.cids;
        set<ll> tarcidset;
        for (int j  = 0; j < tarcid.size(); ++j) {
            tarcidset.insert(tarcid[i]);
        }
        for (int j = 0; j < cid.size(); ++j) {
            if (tarcidset.find(cid[j])!=tarcidset.end()){
                Ans* ans1=new Ans();
                ans1->ans[0]=id1;
                ans1->ans[1]=now.id;
                ans1->ans[2]=cid[j];
                ans1->ans[3]=tar.id;
                ans.push_back(*ans1);
            }
        }
        //jid
        vector<ll> jid=now.jids;
        vector<ll> tarjid=tar.jids;
        set<ll> tarjidset;
        for (int j  = 0; j < tarjid.size(); ++j) {
            tarjidset.insert(tarjid[i]);
        }
        for (int j = 0; j < jid.size(); ++j) {
            if (tarjidset.find(jid[j])!=tarjidset.end()){
                Ans* ans1=new Ans();
                ans1->ans[0]=id1;
                ans1->ans[1]=now.id;
                ans1->ans[2]=jid[j];
                ans1->ans[3]=tar.id;
                ans.push_back(*ans1);
            }
        }
    }
}

#endif