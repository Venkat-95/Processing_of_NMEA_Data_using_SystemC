 #include <systemc.h>
SC_MODULE(tb)
{

sc_port<sc_fifo_out_if<char> > in_put;   
sc_port<sc_fifo_in_if<char> >  out_put;

void source();
void sink();

SC_CTOR(tb) {
SC_THREAD(source); // Output characters are produced
SC_THREAD(sink);// Input characters are read
}
};
