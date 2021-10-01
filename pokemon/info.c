#include "info.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

struct Info{
	double heigh, weight;
	int attack;
};

Info infoCreate(double heigh, double weight, int attack){
	Info info = (Info)malloc(sizeof(struct Info));
	info->heigh = heigh;
	info->weight = weight;
	info->attack = attack;
	return info;
}

status infoDestory(Info info){
	free(info);
	info = NULL;
	return SUCCESS;
}

void infoDisplay(Info info){
	printf("Heigh: %.2f m    Weigth:%.2f kg    Attack:%d", info->heigh, info->weight, info->attack);
}

status setHeigh(Info info, double height){
	if(info==NULL)return FAILURE;
	info->heigh = height;
	return SUCCESS;
}

status setWeight(Info info, double weight){
	if(info==NULL)return FAILURE;
	info->weight = weight;
	return SUCCESS;
}

status setAttack(Info info, int attack){
	if(info==NULL)return FAILURE;
	info->attack = attack;
	return SUCCESS;
}


double getHeigh(Info info){
	return info->heigh;
}

double getWiehgt(Info info){
	return info->weight;
}

int getAttack(Info info){
	return info->attack;
}
