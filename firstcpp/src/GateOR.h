#pragma once

#include<vector>
#include"Gate.h"


class GateOR : public Gate{
public:

	GateOR(const Node & input1 , const Node & input2 , const Node & out);
	void calc_output_self() override;
};

