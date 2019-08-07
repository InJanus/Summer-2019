#include <iostream>
#include <fstream>
#include "..\\Lab_10_2\hash\hash.h"
#include <cstdio>
#include <cstdlib>
using namespace std;



int main (){
    bool flag = false;
    int option;
    ifstream myfile;
    string myinfo;
    int myyear;
    bool myresult;
    team inteam;
    HashTable mylist;
    while(!flag){
        cout<< "1) Load the File\n2) Query by Team\n   Ex. Enter: Cincinnati_Reds"<<endl;
        cin >> option;
        if( option==1){
            //Do Task 1 which is Loading File
            myfile.open("C:\\Users\\Brian Culberson\\Documents\\Code\\Summer-2019-1\\Lab_10_2\\teams_worldseries.txt");		//this needs to be changed due to the relitive path
			if(myfile.is_open()){
				while(!myfile.eof()){
                    for( int i= 0; i <=3;i++){
                        myfile >> myinfo;
                        //cout << myinfo << endl;
                        if ( i==0){
                            inteam.name=myinfo;
                        }
                        else if( i ==1){
                            myyear=stoi(myinfo);
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
                            //cout << temp.year << endl;
                            inteam.resultyears.addItem(temp);
                            mylist.addItem(inteam);
                            //inteam.
                            //input the true or false for that year
                        }else if(i == 3){
                            inteam.resultyears.removeAll();//do nothing
                        }
                    }
                    //inteam added is sent to the hash and brian deals with the LL of length 1
				}
			}
			// function here to get input from file to get data
			myfile.close();
        }
        else if( option ==2 ){
            //Do task 2 which is Query
        }else if(option == 3){
            mylist.print();
        }
    }
    return 0;
}