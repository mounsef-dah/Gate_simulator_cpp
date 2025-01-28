# pragma once

#include<vector>
#include"Node.h"
#include"Gate.h"


class circuit {
public :
	vector <Node > inputs ;
	vector <Node > outputs ;
	vector < Gate *> gates ;

	void show_gates();
	void inputs_to_gates();
	void gates_to_outputs();
	void internal_outputs_to_inputs();
	bool are_all_outputs_computed();
	void reset();
	void clear_inputs();
	void compute();
};
