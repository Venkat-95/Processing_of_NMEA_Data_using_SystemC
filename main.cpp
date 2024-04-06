#include <systemc.h>
#include "gps.h"
#include "tb.h"
#include "top.h"




int sc_main(int argc, char* argv[])
{
  top = new SYSTEM( "top" );// Assigning Memory to top module
  sc_start();
  return 0;
}

