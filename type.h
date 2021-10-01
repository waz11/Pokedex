#ifndef TYPE_H_
#define TYPE_H_
#include "defs.h"

typedef struct Type* Type;

Type typeCreate(char* name);
status typeFree(Type type);
char* getTypeName(Type type);
//void* copyType(void* element);
status increase_cnt_instances(Type type);
status decrease_cnt_instances(Type type);

status addEffeciveAgainstMe(Type source, Type other);
void getEffectiveAgainstMe(Type type);
status deleteEffectiveAgainstMe(Type source, Type other);
int getEffectiveAgainstMeSize(Type type);

status addEffeciveAgainstOthers(Type source, Type other);
void getEffectiveAgainstOthers(Type type);
status deleteEffectiveAgainstOthers(Type source, char* other);
int getEffectiveAgainstOthersSize(Type type);

#endif /* TYPE_H_ */
