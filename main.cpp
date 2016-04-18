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
#include <TakeObject.h>
#include <PlaceObject.h>
#include <ReorderTable.h>
#include <Mmdp.h>
#include <c++/4.6/iosfwd>
#include <Wait.h>

using namespace std;

/*
 * 
 */


int main(int argc, char** argv) {
    //    WashLaundryFull wash;
    //    wash.createPomdp("wash_laundry_full",true);
    //    

    //    
    //    TakeObject take_object;
    //    take_object.name="take_object";
    //    //take_object.setParameters("human_take_glass");
    //   // take_object.create("take_object",false,true);
    //    
    //    PlaceObject place_object;
    //    place_object.name="place_object";
    //place_object.setParameters("human_place_glass_shelf");
    //place_object.create("place_object",true,true);
    //
    ReorderTable reorder_table1, reorder_table2;
    reorder_table1.name="agent0_reorder_table";
    reorder_table2.name="agent1_reorder_table";
    Mmdp reorder_table_mmdp;
    reorder_table_mmdp.agent_hmpd_["agent_0"] = &reorder_table1;
    reorder_table_mmdp.agent_hmpd_["agent_1"] = &reorder_table2;
    //    
//    vector<string> actions{"take", "place"};
//    for (string a : actions) {
//        for (int i = 0; i < 3; i++) {
//            string s_action =a+"_dish"+boost::lexical_cast<string>(i);
//            if (a=="place") {
//                s_action=s_action+"_counter";
//            }
//            string s_action1="agent0_"+s_action+"-agent1_wait";
//            string s_action2 ="agent0_wait-agent1_"+s_action;
//            Mmdp *sub_mmdp1=new Mmdp();
//            Mmdp *sub_mmdp2=new Mmdp();
//            if (a=="take") {
//                sub_mmdp1->agent_hmpd_["agent0"] = new TakeObject();               
//                sub_mmdp1->agent_hmpd_["agent1"] = new Wait();               
//                sub_mmdp2->agent_hmpd_["agent1"] = new TakeObject();               
//                sub_mmdp2->agent_hmpd_["agent0"] = new Wait();               
//            }
//            else {
//                sub_mmdp1->agent_hmpd_["agent0"] = new PlaceObject();
//                sub_mmdp1->agent_hmpd_["agent1"] = new Wait();
//                sub_mmdp2->agent_hmpd_["agent1"] = new PlaceObject();
//                sub_mmdp2->agent_hmpd_["agent0"] = new Wait();
//            }
//            reorder_table_mmdp.hierarchy_map_[s_action1] = sub_mmdp1;
//            reorder_table_mmdp.hierarchy_map_[s_action2] = sub_mmdp2;
//        }
//    }
//    for (int i = 0; i < 3; i++) {
//        for (int j = 0; j < 3; j++) {
//            for (string a1 : actions) {
//                for (string a2 : actions) {
//                    stringstream s_action;
//                    s_action << "agent0_" << a1 << "_dish" + boost::lexical_cast<string>(i);
//                    if (a1 == "place") {
//                        s_action << "_counter";
//                    }
//                    s_action << "-";
//                    s_action << "agent1_" << a2 << "_dish" + boost::lexical_cast<string>(j);
//                    if (a2 == "place") {
//                        s_action << "_counter";
//                    }
//                    Mmdp *sub_mmdp = new Mmdp();
//                    if (a1 == "take") {
//                        sub_mmdp->agent_hmpd_["agent0"] = new TakeObject();
//                    } else {
//                        sub_mmdp->agent_hmpd_["agent0"] = new PlaceObject();
//                    }
//                    if (a2 == "take") {
//                        sub_mmdp->agent_hmpd_["agent1"] = new TakeObject();
//                    } else {
//                        sub_mmdp->agent_hmpd_["agent1"] = new PlaceObject();
//                    }
//                    string astr = s_action.str();
//                    reorder_table_mmdp.hierarchy_map_[s_action.str()] = sub_mmdp;
//
//                }
//            }
//        }
//    }
    reorder_table_mmdp.create("human0_reorder_table-human1_reorder_table", true, true);
    //    Creating human1_place_dish0_counter-human2_place_dish1_counter
    //
    //    PlaceObject p1,p2;
    //    Mmdp place_object_mmdp;
    //    place_object_mmdp.agent_hmpd_["agent1"]=&p1;
    //    place_object_mmdp.agent_hmpd_["agent2"]=&p2;
    //    place_object_mmdp.create("human0_place_dish0_counter-human1_place_dish1_counter",true,true);
    //    place_object_mmdp.printTransitionFunction();

    //    
    //    TakeObject t1,t2;
    //    
    //    Mmdp take_object_mmdp;
    //    take_object_mmdp.agent_hmpd_["agent1"]=&t1;
    //    take_object_mmdp.agent_hmpd_["agent2"]=&t2;
    //    take_object_mmdp.create("human0_take_glass-human1_take_bottle",true,true);

    vector<pair<VariableSet, double> > belief;
    VariableSet vset;
    map<string, string> assignement;
    assignement["human0_isAt"] = "bed";
    assignement["human1_isAt"] = "bed";
    assignement["dish0_isAt"] = "bed";
    assignement["dish1_isAt"] = "counter";
    assignement["dish2_isAt"] = "counter";
    //    assignement["glass_isAt"] = "table";
    //    assignement["bottle_isAt"] = "counter";
    vset.set = assignement;

    
//    Hmdp* sub_mmdp=reorder_table_mmdp.hierarchy_map_["agent0_take_dish0-agent1_take_dish1"];
//    sub_mmdp->assignParametersFromActionName("human0_take_dish0-human1_take_dish1");
////    sub_mmdp->printQValues(vset);
//    PairStateAction p{sub_mmdp->mapStateEnum[sub_mmdp->convertToParametrizedState(vset)], "agent0_take_object0-agent1_move_table"};
//    VariableSet next_state=sub_mmdp->vecStateEnum[sub_mmdp->transition[p].begin()->first];
//    cout<<next_state.toString()<<"\n";
//    
//    p.first=sub_mmdp->mapStateEnum[next_state];
//    p.second="agent0_wait-agent1_take_object1";
//    next_state = sub_mmdp->vecStateEnum[sub_mmdp->transition[p].begin()->first];
//    cout<<next_state.toString()<<"\n";
//    sub_mmdp->printTransitionFunction();
    //    reorder_table_mmdp.printStates();
//        reorder_table_mmdp.printTransitionFunction();
//       reorder_table_mmdp.printRewardFunction();
    reorder_table_mmdp.printQValues(vset);
    reorder_table_mmdp.simulate(6, vset);

    return 0;
}

