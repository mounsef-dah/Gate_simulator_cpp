#include <string>
#include <iostream>
#include "GateNOT.h"

// Override calc_output method
void GateNOT::calc_output_self() {
    output.value = !inputs[0].value;
}

// Constructor using initializer list
GateNOT::GateNOT(const Node& input1, const Node& out)
    : Gate(out) {
    inputs.push_back(input1);
}
