#pragma once
#include <vector>
#include "Medikamente.h"
#include <utility>
#include <algorithm>
#include <string>

using std::vector;
using std::string;
class Repo
{
private:
	vector <Medikamente> med;
	std::vector< std::vector<Medikamente> > undo_list;
	int index = -1;
	int cap = -1;
	void Change();
public:
	
	vector <Medikamente> get_repo() { return med; }
	void add(Medikamente m);
	void remove(Medikamente m);
	void update(Medikamente m, Medikamente new_m);
	void undo();
	void redo();
	int Grosse();
};

