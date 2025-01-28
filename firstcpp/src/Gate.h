#pragma once

//#include<string>
#include<vector>
#include"node.h"

using namespace std;

class Gate{
	public:
		vector<Node> inputs;
		Node output;
		string name;

	    // Constructor to initialize the output node
	    Gate(Node out) : output(out) {}


	    void configure_for_two_inputs ( const Node & input1 , const Node & input2 , const Node & out);

	    virtual int calc_output();
	    virtual void calc_output_self() = 0;
		void show();
};

