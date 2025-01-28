#pragma once

#include<vector>
#include"Gate.h"


class GateNOT : public Gate{
public:
	GateNOT(const Node & input1 , const Node & out);

	void calc_output_self() override;


};

