#ifndef NODE_H
#define NODE_H

#pragma once
#include <iostream>
using namespace std;

struct node {
	int data;
	node * next = NULL;
	node * prev = NULL;
};

#endif
