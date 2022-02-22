module Node
{
    parameters:
        int address;
        
        gates:
            input in;
            output out;
   		
   		submodules:
   		    NL: Network_Layer
   		    {
   		        id=address;
   		    }
   		    
   		    DLL: Data_Link_Layer
   		    {
   		        id=address;
   		    }
   	connections:
   	    NL.toDLL --> DLL.fromNL;
   	    DLL.toNL --> NL.fromDLL;
   	    DLL.toNode --> out;
   	    in --> DLL.fromNode;
}
