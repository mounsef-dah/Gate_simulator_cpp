#include<string>
#include<iostream>
#include"node.h"

using namespace std;


Node::Node(string inName){
	name = inName;
	already_computed = false;
}

Node::Node(string inName, bool inValue){
	name = inName;
	value = inValue;
	already_computed = true;
}

void Node::set_value(bool inValue){
	value = inValue;
	already_computed = true;
}

void Node::show_value() const{
	if(!already_computed){
		cout << "? ";
	}
	else{
		cout << (value ? "1 ":"0 ");
	}
}



