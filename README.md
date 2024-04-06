## Processing of NMEA Data using SystemC

### Introduction:

This repo hosts the code base for processing the NMEA data which is one type of format used in tracking the position of an automobile/cargo ship based on the GPS or
any other standard navigation system. 

In order to simulate the use case we create a test bench which basically takes the example text file and sends it as input to the GPS module. This in turn will read the NMEA data that was received and process it in such a way that the latitutes, longitudes and other information is seperated and 
sent to the memory module.

### Implementation:

The following steps are executed sequentially for simulating the usecase described above.

- The top module connects the test bench and the actual implementation module which is GPS in this case.
- The example NMEA data is read from the text file using the test bench module and passed to the GPS module using the top via signals.
- The processing of the GPS data is done in the gps.cpp.