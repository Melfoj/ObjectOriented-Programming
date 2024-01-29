#include "Katren.h"


bool Katren::operator*()
{
	bool flag;
	tek = prvi->sled;
	flag = (prvi->stih ^ posl->stih && tek->stih ^ tek->sled->stih);
	return flag;
}
