#include "Node.h"

Define_Module(Node);

void Node::initialize()
{
    id=par("id");
    src=par("src");
    dst=par("dst");
    if(id==0)
    {
        LUT={{1,0}, {2,0}, {3,0}, {4,0}};
    }
    else if(id==1)
    {
        LUT={{0,0}, {2,1}, {3,2}, {4,1}};
    }
    else if(id==2)
    {
        LUT={{0,0}, {1,0}, {3,1}, {4,1}};
    }
    else if(id==3)
    {
        LUT={{0,0}, {1,0}, {2,1}, {4,1}};
    }
    else if(id==4)
    {
        LUT={{0,0}, {1,0}, {2,0}, {3,1}};
    }
    if(id==src)
    {
        cMessage *sfmsg=new cMessage();
        scheduleAt(0, sfmsg);
    }
}

void Node::handleMessage(cMessage *msg)
{
    if(msg -> isSelfMessage())
    {
        N_PDU *pkt=new N_PDU();
        pkt->setId(id);
        pkt->setSrc(src);
        pkt->setDst(dst);
        pkt->setStart(simTime());
        send(pkt, "out", LUT.at(dst));
    }
    else if(id==dst)
    {
        N_PDU *pkt=check_and_cast<N_PDU*>(msg);
        EV << "Delay of packet: " << (pkt->getArrivalTime()-pkt->getStart())*1000<<"ms";
        delete(pkt);
    }
    else
    {
        send(msg, "out", LUT.at(dst));
    }
}
