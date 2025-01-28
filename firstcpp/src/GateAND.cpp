#include <string>
#include <iostream>
#include "GateAND.h"


void GateAND::calc_output_self() {
    output.value = inputs[0].value && inputs[1].value;
}


GateAND::GateAND(const Node& input1, const Node& input2, const Node& out) : Gate(out) {
    configure_for_two_inputs(input1, input2, out);
}
