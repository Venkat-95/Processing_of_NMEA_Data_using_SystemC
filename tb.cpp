#include "tb.h"
void tb::source() {

//Send gps text file as an input o gps module
in_put->write('g');
wait(5,SC_NS);
in_put->write('p');
wait(5,SC_NS);
in_put->write('s');
wait(5,SC_NS);
in_put->write('D');
wait(5,SC_NS);
in_put->write('a');
wait(5,SC_NS);
in_put->write('t');
wait(5,SC_NS);
in_put->write('a');
wait(5,SC_NS);
in_put->write('.');
wait(5,SC_NS);
in_put->write('t');
wait(5,SC_NS);
in_put->write('x');
wait(5,SC_NS);
in_put->write('t');
wait(5,SC_NS);

}

void tb::sink() {

char inpdata;
int count=0;

//display the results from gps module
while(1){
    out_put->read(inpdata);
    cout<< inpdata;    
}
sc_stop();
}

