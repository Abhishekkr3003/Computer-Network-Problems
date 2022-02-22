#ifndef __ASSIGNMENT6_NODE_H_
#define __ASSIGNMENT6_NODE_H_

#include <omnetpp.h>
#include <N_PDU_m.h>
#include <map>

using namespace omnetpp;
using namespace std;

class Node : public cSimpleModule
{
    map<int, int> LUT;
    int id;
    int src;
    int dst;
  protected:
    virtual void initialize();
    virtual void handleMessage(cMessage *msg);
};

#endif
