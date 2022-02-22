#include "Data_Link_Layer.h"

Define_Module(Data_Link_Layer);

void Data_Link_Layer::initialize()
{
    fromNL=gate("fromNL");
    toNL=gate("toNL");
    fromNode=gate("fromNode");
    toNode=gate("toNode");
    id=-1;
    timeOutEvent=new cMessage();
}

void Data_Link_Layer::handleMessage(cMessage *msg)
{
    if(msg==timeOutEvent)
    {
        send(copiedMsg, toNode);
        scheduleAt(simTime()+200, msg);
    }
    else if(msg -> getArrivalGate() == fromNL)
    {
        N_PDU *pkt=check_and_cast<N_PDU*>(msg);
        DL_PDU *frm=new DL_PDU();
        id++;
        id=id%2;
        frm->encapsulate(pkt);
        frm->setType("Data");
        frm->setPID(id);
        frm->setSrc(1);
        frm->setDest(2);
        copiedMsg=frm->dup();
        send(frm, toNode);
        scheduleAt(simTime()+200, timeOutEvent);
    }
    else if(msg -> getArrivalGate() == fromNode)
    {
        DL_PDU *frm=check_and_cast<DL_PDU*>(msg);
        if(strcmp(frm->getType(), "Data")==0)
        {
            if(uniform(0,1)<0.1)
            {
                bubble("pkt lost");
                delete(frm);
                //return;
            }
            else
            {
                DL_PDU *p=new DL_PDU();
                p->setPID(frm->getPID());
                p->setType("Ack");
                p->setSrc(2);
                p->setDest(1);
                send(p, toNode);
                send(frm->decapsulate(), toNL);
                delete(frm);
            }
        }
        else
        {
            cancelEvent(timeOutEvent);
            delete(msg);
        }
    }
}
