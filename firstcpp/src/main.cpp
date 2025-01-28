#include<string>
#include<iostream>
#include<vector>
#include<math.h>
#include"node.h"
#include"gate.h"
#include"gateAND.h"
#include"gateOR.h"
#include"gateNOT.h"
#include"circuit.h"


using namespace std;

void show_truth_table(Gate* G) {
    int num_inputs = G->inputs.size();
    int num_combinations = pow(2, num_inputs);


    for (int i = 0; i < num_inputs; ++i) {
            std::cout << char('A' + i) << " ";
        }
    std::cout << "O" << std::endl;


    for (int i = 0; i < num_combinations; ++i) {

    	for (int j = 0; j < num_inputs; ++j) {
            bool input_value = (i >> (num_inputs - j - 1)) & 1;
            G->inputs[j].set_value(input_value);
            std::cout << input_value << " ";
        }

        G->calc_output();

        std::cout << G->output.value << std::endl;  // Output the result
    }
}


int main() {
/*	Node A("A"), B("B"), C("C",true);
	A.show_value();
	B.show_value();
	C.show_value();
	A.set_value(true);
	A.show_value();
	B.show_value();
	B.set_value(false);
	B.show_value();
*/

/*  Node A("A",true);
    Node B("B",false);
    Node O("O");

    Gate and_gate(O);
    and_gate.inputs.push_back(A);
    and_gate.inputs.push_back(B);
    and_gate.calc_output();
    and_gate.show();
    */

/*    GateAND G1( Node ("I1",true ),Node ("I2",true ),Node ("O"));
    GateOR G2( Node ("I1",true ),Node ("I2",false ),Node ("O"));
    GateOR G3( Node ("I1",false ),Node ("I2",true ),Node ("O"));
    GateAND G4( Node ("I1",false ),Node ("I2",false ),Node ("O"));
    GateNOT G5( Node ("I1",false ),Node ("O"));

    G1.calc_output();
    G2.calc_output();
    G3.calc_output();
    G4.calc_output();
    G5.calc_output();
*/
/*	G1.show();
    cout << endl;
    G2.show();
    cout << endl;
    G3.show();
    cout << endl;
    G4.show();
    cout << endl;
*/

    //show_truth_table(&G3);

	circuit Circ ;
    Circ.gates.push_back(new GateAND(Node("I1"), Node("I2"), Node("A")));
    Circ.gates.push_back(new GateOR(Node("I3"), Node("I4"), Node("B")));
    Circ.gates.push_back(new GateAND(Node("B"), Node("I5"), Node("C")));
    Circ.gates.push_back(new GateOR(Node("A"), Node("C"), Node("O1")));
    Circ.gates.push_back(new GateOR(Node("C"), Node("I6"), Node("O3")));
    Circ.gates.push_back(new GateNOT(Node("C"), Node("O2")));

    Circ.inputs.push_back(Node("I1", false));
    Circ.inputs.push_back(Node("I2", true));
    Circ.inputs.push_back(Node("I3", false));
    Circ.inputs.push_back(Node("I4", false));
    Circ.inputs.push_back(Node("I5", true));
    Circ.inputs.push_back(Node("I6", true));

    Circ.outputs.push_back(Node("O1"));
    Circ.outputs.push_back(Node("O2"));
    Circ.outputs.push_back(Node("O3"));

    Circ.compute();
    Circ.show_gates();
    Circ.gates_to_outputs();
    Circ.reset();
    Circ.show_gates();

	return 0;
}


