/* 
 * File:   main.cpp
 * Author: mfiore
 *
 * Created on August 18, 2014, 9:42 AM
 */

#include <cstdlib>
#include <iostream>
#include<map>
#include <vector>
#include <Pomdp.h>
#include <fstream>
#include "PriorityQueue.h"
#include "Hmdp.h"
#include "Mmdp.h"

#include "Saphari.h"

using namespace std;

/*
 * 
 */


int main(int argc, char** argv) {
    cout<<"Prova\n";
    Mmdp saphari_mmdp;
    saphari_mmdp.agent_hmpd_["agent1"]=new Saphari();
    saphari_mmdp.agent_hmpd_["agent2"]=new Saphari();
    
    saphari_mmdp.create("saphari",false,true);
    
    VariableSet initial_state;
    map<string,string> inital_set;
    inital_set["agent1_isAt"]="table";
    inital_set["agent2_isAt"]="table";
    inital_set["bracket1_isAt"]="table";
    inital_set["bracket2_isAt"]="table";
    inital_set["bracket3_isAt"]="table";
    inital_set["gluebottle_isAt"]="table";
    inital_set["surfaced1_status"]="none";
    inital_set["surfaced2_status"]="none";
    inital_set["surfaced3_status"]="none";
    
    initial_state.set=inital_set;
//    take_object.simulate(2,initial_state);
//    
    return 0;
}

