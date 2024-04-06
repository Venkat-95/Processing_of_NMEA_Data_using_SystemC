#include <systemc.h>

SC_MODULE (gps) {
  
sc_port<sc_fifo_in_if<char> > in_put;    //input fifo to read data from the test bench
sc_port<sc_fifo_out_if<char> > out_put;  //output fifo to send data from gps to test bench
 
void gps_main();    //gps function declaration

SC_CTOR (gps) {
    SC_THREAD(gps_main);  // calling thread
  }
};



