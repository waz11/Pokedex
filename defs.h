#ifndef DEFS_H_
#define DEFS_H_

typedef enum e_bool {true,false} bool;
typedef enum e_status{SUCCESS, FAILURE, NOT_FOUND} status;

//typedef void* element;
typedef void*(*copy)(void*);
typedef void(*freeElement)(void*);
typedef int(*compare)(void*,void*);
typedef char*(*printElement)(void*);

#endif /* DEFS_H_ */
