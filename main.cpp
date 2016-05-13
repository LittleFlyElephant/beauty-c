#include <iostream>
#include <cstring>


#include "web/mongoose.h"
#include "cxlogic/Do.cpp"
using namespace std;
#define ll long long
static const char *s_http_port = "8000";

static void ev_handler(struct mg_connection *c, int ev, void *p) {
    if (ev == MG_EV_HTTP_REQUEST) {
        struct http_message *hm = (struct http_message *) p;
        const  char * query=hm->query_string.p;
        int  len=hm->query_string.len;
        char * q=new char(len);
        memcpy(q,query,len);
        int loc=0;
        for (;loc<len;loc++){
            if (q[loc]=='&')
                break;
        }
        char fir[loc-3]={'\0'};
        char sec[len-loc-5+1]={'\0'};

        memcpy(fir,&q[4],loc-4);
        memcpy(sec,&q[loc+5],len-loc-5);
        ll id1=strtol(fir,NULL,10);
        ll id2=strtol(sec,NULL,10);
        //
        string ans=convert2json(cx(id1,id2));

        /* Send the reply */
        mg_printf(c, "HTTP/1.1 200 OK\r\n"
                          "Content-Type: application/json\r\n"
                          "Content-Length: %d\r\n"
                          "\r\n"
                          "%s",
                  (int) ans.length(), ans.c_str());


    }
}

int main(void) {
    struct mg_mgr mgr;
    struct mg_connection *nc;

    mg_mgr_init(&mgr, NULL);
    nc = mg_bind(&mgr, s_http_port, ev_handler);
    mg_set_protocol_http_websocket(nc);


    printf("Starting multi-threaded server on port %s\n", s_http_port);
    for (;;) {
        mg_mgr_poll(&mgr, 3000);
    }
    mg_mgr_free(&mgr);

    return 0;
}
