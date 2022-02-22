network LayerNetwork
{
    parameters:
        int src;
        int dest;
      
    submodules:
        SN: Node
        {
            address=src;
        }
        DN: Node
        {
            address=dest;
        }
        
    connections:
        SN.out --> {delay=100ms;} --> DN.in;
        DN.out --> {delay=100ms;} --> SN.in;
}
