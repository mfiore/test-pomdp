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
#include "WashLaundry.h"
#include "StartWashingMachine.h"
#include "GetLaundry.h"
#include <VariableSet.h>
#include "WashLaundryFull.h"
#include "StringOperations.h"

using namespace std;

/*
 * 
 */


int main(int argc, char** argv) {
    //    WashLaundryFull wash;
    //    wash.createPomdp("wash_laundry_full",true);
    //    
    GetLaundry get_laundry;
    WashLaundry wash_laundry;
    StartWashingMachine start_washing_machine;
    //    //    
   
    wash_laundry.hierarchy_map_["get_laundry"]=&get_laundry;
    wash_laundry.hierarchy_map_["start_washing_machine"]=&start_washing_machine;
    wash_laundry.create("wash_laundry", false, true);

    vector<pair<VariableSet, double> > belief;
    VariableSet vset;
    map<string, string> assignement;
    assignement["human_isAt"] = "bed";
    assignement["laundry1_isAt"] = "bed";
    assignement["laundry2_isAt"] = "box";
    assignement["laundry3_isAt"] = "box";
    assignement["box_isAt"] = "bed";
    assignement["washing_machine_state"] = "stopped";
    vset.set = assignement;
    //
    pair<VariableSet, double> var_prob{vset, 1.0};
    belief.push_back(var_prob);
   
//    cout<<wash_laundry.chooseHierarchicAction(vset)<<"\n";
    wash_laundry.simulate(3,vset);
//    

    return 0;
}

