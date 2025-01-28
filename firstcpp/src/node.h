#pragma once

#include<string>

using namespace std;

class Node{

	public:
		string name;
		bool value;
		bool already_computed;

		Node(string inName);
		Node(string inName, bool inValue);

		void set_value(bool inValue);
		void show_value() const;
};

