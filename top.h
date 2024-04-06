#include <systemc.h>



SC_MODULE(SYSTEM) { 

// Module declaration
tb     *tb0; //tb0 is instance for tb 
gps*gps0;//gps0 is instance for GPS

// local signal declaration
sc_fifo<char> in_put_sig;//input signal from test bench to gps module
sc_fifo<char> out_put_sig;//output signal to test bench to display the results

SC_CTOR(SYSTEM){
// Module instance signal connections

tb0 = new tb("tb0");// Assigning Memory for test bench
tb0->in_put( in_put_sig );    
tb0->out_put( out_put_sig );

gps0 = new gps("gps0");// Assigning Memory for gps 
gps0->in_put( in_put_sig );
gps0->out_put( out_put_sig );
}//check

~SYSTEM() {
//Destructor to remove them from simulation stack
delete tb0;
delete gps0;
}
};

SYSTEM *top = NULL;
