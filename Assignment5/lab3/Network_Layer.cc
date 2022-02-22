#include "Network_Layer.h"

Define_Module(Network_Layer);

void Network_Layer::initialize()
{
    address=par("id");
    counter=10;
    id=-1;
    countOfSend=0;
    in=gate("fromDLL");
    out=gate("toDLL");

    WATCH(counter);

    if(address==1)
    {
        cMessage *sfmsg=new cMessage();
        scheduleAt(0, sfmsg);
    }
}

void Network_Layer::handleMessage(cMessage *msg)
{
    if(msg -> isSelfMessage())
    {
        N_PDU *pkt=new N_PDU();
        pkt -> setType("Data");
        send(pkt, out);
        std::string s = std::to_string(++countOfSend);
        s=s+" sent";
        char const *pchar = s.c_str();
        bubble(pchar);
        delete(msg);
        counter--;
        if(!counter)
            return;
        cMessage *sfmsg=new cMessage();
        scheduleAt(simTime()+600, sfmsg);
    }
    else
    {
        delete(msg);
    }
}
