
#include "gps.h"
#define FIFO_LEN 64 
;
void gps::gps_main(void) // Scoping operator(::) means that the thread gps_main belongs to Module GPS
{


while(1){
char var;
std::string x;
std::string y;

for(int i=0; i<=FIFO_LEN; i++)
{
        in_put->read(var);
        x+=var;

        std::ifstream ifile(x);
        std::string delimiter = ",";
        std::string line; // we read the full line here
        
        while (std::getline(ifile, line)) // read the current line
            {   
            std::string data = line.substr(0,line.find(delimiter));
            std::string cmp = "$GPGGA";
            line.erase(0,line.find(delimiter)+1);
            
            if(data == cmp){                       // Comparing the Data in the text file whether it is $GPGGA or not
                
                // seperating TIME-STAMP
                std::string ts = line.substr(0,line.find(delimiter));
                double tsp = std::stod(ts);
                int tsi = std::stoi(ts);            
                int sec = tsi%100;
                tsi = tsi/100;
                int min = tsi%100;
                int hr = tsi/100;

                //seperating Lattitude
                line.erase(0,line.find(delimiter)+1);
                std::string lattitude = line.substr(0,line.find(delimiter));
                double lat = std::stod(lattitude);
                int lati=lat/100;
                double latr=lat-lati*100;

                // seperating Longitude
                line.erase(0,line.find(delimiter)+1);
                std::string direc = line.substr(0,line.find(delimiter));
                line.erase(0,line.find(delimiter)+1);
                std::string longitude=line.substr(0,line.find(delimiter));
                double lon = std::stod(longitude);
                int loni=lon/100;
                double lonr=lon-loni*100;
                line.erase(0,line.find(delimiter)+1);
                std::string direc1=line.substr(0,line.find(delimiter));
                y+=data;
                y+="    ";
                y+=std::to_string(hr)+":"+std::to_string(min)+":"+std::to_string(sec);     // converting time stamp into UTC
                y+="    ";
                y+=std::to_string(lati)+"Degrees "+std::to_string(latr)+" "+direc;          // converting lattitude into degrees
                y+="    ";
                y+=std::to_string(loni)+"Degrees "+std::to_string(lonr)+" "+direc1;         // converting longitude into degrees
                y+="\n";

        }
        }
        for(int k=0;k<=y.length();k++){
                out_put->write(y[k]);
                        
        }
      
}

}
}
