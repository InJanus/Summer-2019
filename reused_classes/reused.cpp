#include <string>
#include <iostream>

void throwError(string message){
    try{
        throw runtime_error(message);
    }catch(exception& e){
        cerr << e.what() << endl;
    }
}