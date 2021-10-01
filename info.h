#ifndef INFO_H_
#define INFO_H_
#include "defs.h"

typedef struct Info* Info;

Info infoCreate(double heigh, double wight, int attack);
status infoDestory(Info info);
void infoDisplay(Info info);

#endif /* INFO_H_ */
