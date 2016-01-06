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
#include "Hmmdp.h"
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
    get_laundry.name = "get_laundry";
    start_washing_machine.name = "start_washing_machine";
    wash_laundry.name = "wash_laundry";
    wash_laundry.hierarchy_map_["start_washing_machine"] = &start_washing_machine;
    wash_laundry.hierarchy_map_["get_laundry"] = &get_laundry;
    wash_laundry.createPomdp("wash_laundry", false, true);
    //    wash_laundry.solveHierasrchical(true);
    //    start_washing_machine.createPomdp("start_washing_machine",false, false);
    //        get_laundry.createPomdp("get_laundry",false,false);
    //            get_laundry.createPomdp("get_laundry", true,);
    ////    get_laundry.printRewardFunction();
    //
    //    get_laundry.valueIteration(true);
    //    start_washing_machine.printRewardFunction();
    vector<pair<VariableSet, double> > belief;
    VariableSet vset;
    map<string, string> assignement;
    assignement["human_isAt"] = "bed";
    assignement["laundry1_isAt"] = "box";
    assignement["laundry2_isAt"] = "box";
    assignement["laundry3_isAt"] = "box";
    assignement["box_isAt"] = "bed";
    assignement["washing_machine_state"] = "stopped";
    vset.set = assignement;
    cout << "state number " << get_laundry.mapStateEnum[vset] << "\n";

    //
    pair<VariableSet, double> var_prob{vset, 1.0};
    belief.push_back(var_prob);
   
    wash_laundry.setInitialState(belief);
    cout<<wash_laundry.chooseHierarchicAction(vset)<<"\n";
//    
    map<VariableSet,double> ht=start_washing_machine.getHierarcicTransition(vset);
    map<int,double> a=wash_laundry.getMatchingStates(ht);
    //
     pair<int,string> t_input {wash_laundry.mapStateEnum[vset],"start_washing_machine"};

    std::map<int,double> future_states= wash_laundry.transition[t_input];
    for (auto b:future_states) {
        VariableSet set=wash_laundry.vecStateEnum[b.first];
        for (auto s:set.set) {
            cout<<s.first<<" "<<s.second<<"\n";
        }
        cout<<"\n";
        
    }


    return 0;
}

