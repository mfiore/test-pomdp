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
#include "Handover.h"

using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    cout << "Prova\n";

    map<string, Hmdp*> hmdp_map_1, hmdp_map_2;
    MmdpManager manager;
    hmdp_map_1["assemble"] = new AssembleBracket();
    //    hmdp_map_1["clean"] = new CleanSurface();
    //    hmdp_map_1["glue"] = new GlueSurface();
    hmdp_map_1["get"] = new GetObject();
    //    hmdp_map_1["apply"] = new AttachBracket();
    hmdp_map_1["wait"] = new Wait();
    hmdp_map_1["handover"] = new Handover();
    hmdp_map_1["saphari"] = new Saphari();

    hmdp_map_2["assemble"] = new AssembleBracket();
    //    hmdp_map_2["clean"] = new CleanSurface();
    //    hmdp_map_2["glue"] = new GlueSurface();
    hmdp_map_2["get"] = new GetObject();
    //    hmdp_map_2["apply"] = new AttachBracket();
    hmdp_map_2["wait"] = new Wait();
    hmdp_map_2["saphari"] = new Saphari();


    vector<map<string, Hmdp* > > v_hmdp{hmdp_map_1, hmdp_map_2};
    manager.hmdp_map_ = v_hmdp;


    vector<string> forbidden_actions;

    //same bracket can't be assigned to two different places
    for (int i = 1; i < 4; i++) {
        for (int j = 1; j < 4; j++) {
            for (int k = 1; k < 4; k++) {
                if (j == k) continue;
                forbidden_actions.push_back("agentp0_assemble_bracket" + to_string(i) + "_" + "surface" + to_string(j) +
                        "-agentp1_assemble_bracket" + to_string(i) + "_surface" + to_string(k));
            }
        }
    }
    //two brackets can't be assigned to the same place
    for (int i = 1; i < 4; i++) {
        for (int j = 1; j < 4; j++) {
            if (i == j) continue;
            for (int k = 1; k < 4; k++) {
                forbidden_actions.push_back("agentp0_assemble_bracket" + to_string(i) + "_" + "surface" + to_string(k) +
                        "-agentp1_assemble_bracket" + to_string(j) + "_surface" + to_string(k));
            }
        }
    }
    Mmdp saphari_mmdp(&manager);
    saphari_mmdp.agent_hmpd_["agent0"] = new Saphari();
    saphari_mmdp.agent_hmpd_["agent1"] = new Saphari();
    saphari_mmdp.forbidden_actions_ = forbidden_actions;

    //    saphari_mmdp.create("agent1_saphari-agent2_saphari", false, true);
    saphari_mmdp.create("agent1_saphari-agent2_saphari", false, true);

    //    Handover h;
    //    h.create("agent2_handover_gluebottle_agent1",true, true);

    cout << "done\n";
    VariableSet initial_state;
    map<string, string> inital_set;
    inital_set["agent1_isAt"] = "table";
    inital_set["agent2_isAt"] = "table";
    inital_set["bracket1_isAt"] = "agent2";
    inital_set["bracket2_isAt"] = "table";
    inital_set["bracket3_isAt"] = "table";
    inital_set["gluebottle_isAt"] = "agent2";
    inital_set["surface1_status"] = "none";
    inital_set["surface2_status"] = "cleaned";
    inital_set["surface3_status"] = "glued";

    initial_state.set = inital_set;

    VariableSet para = saphari_mmdp.convertToParametrizedState(initial_state);
    int s = saphari_mmdp.mapStateEnum[para];


    saphari_mmdp.printQValues(initial_state);

     int r = saphari_mmdp.getReward(para, "agentp0_assemble_bracket1_surface1-agentp1_assemble_bracket2_surface2");
    //    VarStateProb v_succ = saphari_mmdp.getFutureStates(para, "agentp0_handover_gluebottle_agentp1");
    //    for (auto s : v_succ) {
    //        int i = saphari_mmdp.mapStateEnum[s.first];
    //    }
    //    cout << "";

    //    cout << para.toString() << "\n";


    //    saphari_mmdp.testEnumerate(s, "agentp0_handover_gluebottle_agentp1");

    //            Mmdp *h = (Mmdp*) saphari_mmdp.hierarchy_map_["agent_handover_object_agent"];
    //    set<string> changed_mdps = {"agent0", "agent1"};
    //
    //    Mmdp *h = (Mmdp*) saphari_mmdp.hierarchy_map_["agent_assemble_bracketcc_surfacecc-agent_assemble_bracketcc_surfacecc"];
    //    h->assignParametersFromActionName("agent1_assemble_bracket2_surface2-agent2_assemble_bracket2_surface2", changed_mdps,map<string,string>());
    //    Mmdp *h2 = (Mmdp*) h->hierarchy_map_["agent_assemble_bracketc_surface-agent_get_objectc"];
    //    h2->assignParametersFromActionName("agent1_assemble_bracket2_surface2-agent2_get_bracket2",changed_mdps,map<string,string>());

    //    h->assignParametersFromActionName("agent1_handover_gluebottle_agent2");

    //    VariableSet parak = h->convertToParametrizedState(initial_state);

    //    int k = h->mapStateEnum[parak];
    //    h2->testEnumerate(1446, "agentp0_move_surfacep0-agentp1_move_table");
    //    h->loadHierarchicInCache();
    //    h->emptyHierarchicCache();
    //    VarStateProb v_succ = h->getFutureStates(parak, "agent1_give_object_agent2-agent2_receive_object_agent1");
    //    for (auto s : v_succ) {
    //        int i = h->mapStateEnum[s.first];
    //        if (h->isGoalState(h->vecStateEnum[i])) {
    //            cout<<"";
    //
    //        }
    //    }
    //    cout << "";


    //
    //    h->calculateHierarchicTransition();
    //    map<int, double> f = h->getHierarchicTransition(k);
    //    cout << "";


    saphari_mmdp.simulate(25, initial_state);

    //    
    return 0;
}

