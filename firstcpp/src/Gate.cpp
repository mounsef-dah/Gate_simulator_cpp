#include<string>
#include<iostream>
#include"gate.h"

using namespace std;

void Gate::show() {
    for (Node input : inputs) {
        input.show_value();
    }
    cout << "| ";
    output.show_value();
}

int Gate::calc_output() {
	for (const Node& input : inputs) { // Use const reference for efficiency
	        if (!input.already_computed) return -1; // Ensure all inputs are computed
	    }

	    calc_output_self();
	    output.already_computed = true;
	    return 0;
}


void Gate :: configure_for_two_inputs ( const Node & input1 , const Node & input2 , const Node & out )
    {
    inputs.push_back(input1);
    inputs.push_back(input2);
}
