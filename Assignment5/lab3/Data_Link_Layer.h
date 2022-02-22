#ifndef __LAB2_DATA_LINK_LAYER_H_
#define __LAB2_DATA_LINK_LAYER_H_

#include <omnetpp.h>
#include <N_PDU_m.h>
#include <DL_PDU_m.h>

using namespace omnetpp;

class Data_Link_Layer : public cSimpleModule
{
  protected:
    cGate *fromNL;
    cGate *toNL;
    cGate *toNode;
    cGate *fromNode;
    int id;
    DL_PDU *copiedMsg;
    cMessage *timeOutEvent;
    virtual void initialize();
    virtual void handleMessage(cMessage *msg);
};

#endif
