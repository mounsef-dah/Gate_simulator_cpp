
#include<string>
#include<iostream>
#include"circuit.h"


void circuit::show_gates() {

    for (Gate* gate : gates) {
        cout << typeid(*gate).name() << " << ";

        for (const Node& input : gate->inputs) {
            cout << input.name << " : ";
            input.show_value();
        }

        cout << ">> " << gate->output.name << " : ";
        gate->output.show_value();

        cout << endl;
    }
}


void circuit::inputs_to_gates() {

	for (Gate* gate : gates) {

		for (size_t i = 0; i < gate->inputs.size(); ++i) {

            for (size_t j = 0; j < inputs.size(); ++j) {
                if (gate->inputs[i].name == inputs[j].name) {

                	gate->inputs[i].value = inputs[j].value;
                    gate->inputs[i].already_computed = true;
                    break;
                }
            }
        }
    }
}

void circuit::internal_outputs_to_inputs() {

	for (Gate* gate : gates) {

    	for (Gate* otherGate : gates) {

        	if (gate == otherGate) continue;

            for (Node& input : otherGate->inputs) {

            	if (input.name == gate->output.name) {
                    input.value = gate->output.value;
                    input.already_computed = true;
                }
            }
        }
    }
}

bool circuit::are_all_outputs_computed() {

	for (Gate* gate : gates) {

		if (!gate->output.already_computed) {
            return false;
        }
    }

	return true;
}

void circuit::compute() {
    inputs_to_gates();

    while (!are_all_outputs_computed()) {

    	for (Gate* gate : gates) {
            if (!gate->output.already_computed) {
                gate->calc_output();
            }
        }

        internal_outputs_to_inputs();
    }
}

void circuit::gates_to_outputs() {
    for (Gate* gate : gates) {
        for (Node& output : outputs) {
            if (gate->output.name == output.name) {
                output.value = gate->output.value;
                output.already_computed=true;
                break;
            }
        }
    }
}

void circuit::reset() {

    for (Gate* gate : gates) {
        for (Node& input : gate->inputs) {
            input.already_computed = false;
        }
    }
    for (Gate* gate : gates) {
        gate->output.already_computed = false;
    }
}
