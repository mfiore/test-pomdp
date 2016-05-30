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
#include "ReorderTable.h"

#include "Saphari.h"
using namespace std;

/*
 * 
 */


int main(int argc, char** argv) {
    cout << "Prova\n";
//        Mmdp saphari_mmdp;
//        saphari_mmdp.agent_hmpd_["agent1"]=new AssembleBracket();
//        saphari_mmdp.agent_hmpd_["agent2"]=new AssembleBracket();
    //    
//        saphari_mmdp.create("agent1_assemble_bracket1_surface1-agent2_assemble_bracket2_surface2",true,true);
    Saphari ab;
    ab.create("agent1_saphari",false,true);
    ab.assignParametersFromActionName("agent1_saphari");
    

    
//    Mmdp reorder_table;
//    reorder_table.agent_hmpd_["agent1"] = new ReorderTable();
//    reorder_table.agent_hmpd_["agent2"] = new ReorderTable();
//
//    reorder_table.create("agent1_reorder_table-agent2_reorder_table", true, true);
    cout<<"done\n";
        VariableSet initial_state;
        map<string, string> inital_set;
        inital_set["agent1_isAt"] = "table";
        inital_set["agent2_isAt"] = "table";
        inital_set["bracket1_isAt"] = "table";
        inital_set["bracket2_isAt"] = "table";
        inital_set["bracket3_isAt"] = "table";
        inital_set["gluebottle_isAt"] = "table";
        inital_set["surface1_status"] = "none";
        inital_set["surface2_status"] = "none";
        inital_set["surface3_status"] = "none";
    
        ab.printQValues(initial_state);
        initial_state.set = inital_set;
//        ab.rewardFunction(initial_state,"agent_assemble_bracket2_surface2");
        ab.simulate(30,initial_state);
    //    
    return 0;
}

