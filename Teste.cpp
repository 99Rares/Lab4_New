#include "Teste.h"
#include "Controller.h"
#include <cassert>
#include <iostream>
void Teste::test() {
	Repo r;
	Controller c = Controller(r);
	assert(r.Grosse() == 0);
	c.r.add(a);
	c.r.add(b);
	c.r.add(ce);
	c.r.add(e);
	c.r.add(aa);
	c.r.add(d);
	c.search("");
	assert(c.r.Grosse() == 6);

	c.r.remove(d);
	assert(c.r.Grosse() == 5);
	c.r.undo();
	assert(c.r.Grosse() == 6);
	c.r.redo();
	assert(c.r.Grosse() == 5);
	
	c.wenig_med(4);
	c.search("");
	c.search("a");
	c.grup();
	std::cout << '\n' << "Tests over" << '\n';
	

}