#ifndef __LAB2_NETWORK_LAYER_H_
#define __LAB2_NETWORK_LAYER_H_

#include <omnetpp.h>
#include <N_PDU_m.h>

using namespace omnetpp;

class Network_Layer : public cSimpleModule
{
  private:
    int counter;
  protected:
    int address;
    int id;
    cGate *in;
    cGate *out;
    int countOfSend;
    virtual void initialize();
    virtual void handleMessage(cMessage *msg);
};

#endif
