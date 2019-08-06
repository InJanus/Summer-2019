#include <iostream>
#include <fstream>
#include "..\\Lab_10_2\hash\hash.h"
#include <cstdio>
#include <cstdlib>
using namespace std;



int main (){
    bool flag;
    int option;
    ifstream myfile;
    string myinfo;
    Team inteam;
    while(flag){
        cout<< "1) Load the File\n2) Query by Team\n   Ex. Enter: Cincinnati_Reds"<<endl;
        if( option==1){
            //Do Task 1 which is Loading File
            myfile.open("C:\\Users\\culbe\\Documents\\Code\\Summer-2019-1\\Lab_9\\states.txt");		//this needs to be changed due to the relitive path
			if(myfile.is_open()){
				while(!myfile.eof()){
                    for( int i= 0; i <3;i++){
                        myfile >> myinfo;
                        if ( i==0){
                            inteam.name=myinfo;
                        }
                        else if( i ==1){
                            //inteam.
                            //the input the year
                        }
                        else if( i ==2){
                            //inteam.
                            //input the true or false for that year
                        }
                    }
                    //inteam added is sent to the hash and brian deals with the LL of length 1
                    //
					myfile>>myinfo;
				}
			}
			// function here to get input from file to get data
			myfile.close();
        }
        else if( option ==2 ){
            //Do task 2 which is Query
        }
    }
    return 0;
}