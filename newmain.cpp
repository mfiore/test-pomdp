/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   newmain.cpp
 * Author: mfiore
 *
 * Created on June 14, 2016, 2:18 PM
 */

#include <cstdlib>
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

#include <MmdpManager.cpp>

#include "AssembleBracket.h"
#include "AttachBracket.h"
#include "GetObject.h"
#include "CleanSurface.h"
#include  "GlueSurface.h"

using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    cout << "Prova\n";

    map<string, Hmdp*> hmdp_map;
    hmdp_map["assemble"] = new AssembleBracket();
    hmdp_map["clean"] = new CleanSurface();
    hmdp_map["glue"] = new GlueSurface();
    hmdp_map["get"] = new GetObject();
    hmdp_map["apply"] = new AttachBracket();
    hmdp_map["wait"] = new Wait();
    MmdpManager manager(hmdp_map);


    Mmdp saphari_mmdp(&manager);
    saphari_mmdp.agent_hmpd_["agent0"] = new Saphari();
    saphari_mmdp.agent_hmpd_["agent1"] = new Saphari();
    //    

    saphari_mmdp.create("agent1_saphari-agent2_saphari", false, true);
    //    Saphari ab;
    //    ab.create("agent1_saphari",false,true);
    //    ab.assignParametersFromActionName("agent1_saphari");



    //    Mmdp reorder_table;
    //    reorder_table.agent_hmpd_["agent1"] = new ReorderTable();
    //    reorder_table.agent_hmpd_["agent2"] = new ReorderTable();
    //
    //    reorder_table.create("agent1_reorder_table-agent2_reorder_table", true, true);
    cout << "done\n";
    VariableSet initial_state;
    map<string, string> inital_set;
    inital_set["agent1_isAt"] = "table";
    inital_set["agent2_isAt"] = "table";
    inital_set["bracket1_isAt"] = "table";
    inital_set["bracket2_isAt"] = "table";
    inital_set["bracket3_isAt"] = "table";
    inital_set["gluebottle_isAt"] = "table";
    inital_set["surface1_status"] = "cleaned";
    inital_set["surface2_status"] = "cleaned";
    inital_set["surface3_status"] = "none";

    initial_state.set = inital_set;



    saphari_mmdp.printQValues(initial_state);
    //    saphari_mmdp.printRewardFunction();
    //    PairStateAction p;
    VariableSet para = saphari_mmdp.convertToParametrizedState(initial_state);

    int i = saphari_mmdp.mapStateEnum[para];
    //    
    //    p.first = saphari_mmdp.mapStateEnum.at(para);
    //    p.second = "agentp0_move_surfacep0-agentp1_wait";
    ////    pair<vector<string>, set<string> > r=saphari_mmdp.getSubMdpName(p.second);
    ////    Hmdp* h=saphari_mmdp.hierarchy_map_[r.first[0]];
    // 
    ////    map<VariableSet,double> stateprob = h->getHierarchicTransition(initial_state,&saphari_mmdp);
    //    StateProb stateprob=saphari_mmdp.transition[p];
    //
    //    for (auto s : stateprob) {
    ////        VariableSet v=s.first;
    //     
    //        VariableSet v=saphari_mmdp.vecStateEnum[s.first];
    //        cout<<v.toString();
    //    }
    //    saphari_mmdp.enumerateFunctions("prova.pomdp");
    //    saphari_mmdp.printTransitionFunction();
    saphari_mmdp.simulate(7, initial_state);

    //    
    return 0;
}
