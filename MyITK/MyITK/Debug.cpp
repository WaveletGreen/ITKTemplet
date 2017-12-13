#include "Debug.h"
void Debug(const char * outMsg){
	if (ctrl)
		printf("---------------%s-----------\n", outMsg);
}
