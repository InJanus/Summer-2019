#include <string>


int hash::hashfunction(string inVal){
    int retVal;
    for ( int i =0; i <inVal.length();i++){
        retVal += int(inVal.at(i));
    }
    return retVal;
}
