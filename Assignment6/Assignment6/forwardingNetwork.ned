network ForwardingNetwork
{
    parameters:
        int srcInput;
        int dstInput;

    submodules:
        N[5]: Node {
            id = index;
            src = srcInput;
            dst = dstInput;
        }
    connections allowunconnected:
        N[0].out[0] --> {  delay = 100ms; } --> N[1].in[0];
        N[1].out[0] --> {  delay = 100ms; } --> N[0].in[0];
        N[1].out[1] --> {  delay = 200ms; } --> N[2].in[0];
        N[2].out[0] --> {  delay = 200ms; } --> N[1].in[1];
        N[1].out[2] --> {  delay = 200ms; } --> N[3].in[0];
        N[3].out[0] --> {  delay = 200ms; } --> N[1].in[2];
        N[2].out[1] --> {  delay = 100ms; } --> N[4].in[0];
        N[4].out[0] --> {  delay = 100ms; } --> N[2].in[1];
        N[3].out[1] --> {  delay = 200ms; } --> N[4].in[1];
        N[4].out[1] --> {  delay = 200ms; } --> N[3].in[1];
}
