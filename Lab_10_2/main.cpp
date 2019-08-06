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
    int myyear;
    bool myresult;
    team inteam;
    while(flag){
        cout<< "1) Load the File\n2) Query by Team\n   Ex. Enter: Cincinnati_Reds"<<endl;
        if( option==1){
            //Do Task 1 which is Loading File
            myfile.open("C:\\Users\\mugip\\Desktop\\Summer_2019\\DataStructures\\Programming\\Greg_likes_tits\\Summer-2019\\Lab_10_2\\teams_worldseries.txt");		//this needs to be changed due to the relitive path
			if(myfile.is_open()){
				while(!myfile.eof()){
                    for( int i= 0; i <3;i++){
                        myfile >> myinfo;
                        if ( i==0){
                            inteam.name=myinfo;
                        }
                        else if( i ==1){
                            myyear=stoi(myinfo);
                            //the input the year
                        }
                        else if( i ==2){
                            if ( myinfo.compare("W")==0){
                                myresult = true;
                            }else{
                                myresult = false;
                            }
                            game temp;
                            temp.result = myresult;
                            temp.year = myyear;
                            inteam.resultyears.addItem(temp);
                            //inteam.
                            //input the true or false for that year
                        }
                        myfile>>myinfo;
                    }
                    //inteam added is sent to the hash and brian deals with the LL of length 1
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