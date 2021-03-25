#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "list.h"

typedef struct Node Node;

struct Node {
    const void * data;
    Node * next;
    Node * prev;
};

struct List {
    Node * head;
    Node * tail;
    Node * current;
};

typedef List List;

Node * createNode(const void * data) {
    Node * new = (Node *)malloc(sizeof(Node));
    assert(new != NULL);
    new->data = data;
    new->prev = NULL;
    new->next = NULL;
    return new;
}

List * createList() {
    List * list = (List *) malloc(sizeof(List));
    list->head = NULL;
    list->tail = NULL;

    return list;
}

void * firstList(List * list) {
  if(!list->head) return NULL;
  list->current = list->head;

  return (void *) list->head->data;
}

void * nextList(List * list) {
  if(!list->current) return NULL;
  if(list->current == list->tail) return NULL;
  list->current = list->current->next;
  return (void *) list->current->data;
}

void * lastList(List * list) {
  if(!list->tail) return NULL;
  list->current = list->tail;
  
  return (void *) list->current->data;;
}

void * prevList(List * list) {
  if(!list->current) return NULL;
  if(list->current == list->head) return NULL;
  list->current = list->current->prev;

  return (void *) list->current->data;
}

void pushFront(List * list, const void * data) {
  Node *newFirst = createNode(data);
  if(list->head == NULL){ 
    list->head = newFirst;
    list->current = newFirst;
    list->tail = newFirst;
  }
  else{
  newFirst->next = list->head;
  list->head->prev = newFirst;
  list->head = newFirst;
  newFirst->prev = NULL;
  }
}

void pushBack(List * list, const void * data) {
    list->current = list->tail;
    pushCurrent(list,data);
}

void pushCurrent(List * list, const void * data) {
  Node *nuevo = createNode(data);
  
  
  if(list->current == list->tail)
  {
    nuevo->prev = list->current;
    list->current->next = nuevo->prev;
    nuevo->next = NULL;
    list->tail = nuevo;
    
  }
  else
  {
    nuevo->prev = list->current;
    nuevo->next = list->current->next;
    list->current->next = nuevo;

  }
}

void * popFront(List * list) {
    list->current = list->head;
    return popCurrent(list);
}

void * popBack(List * list) {
    list->current = list->tail;
    return popCurrent(list);
}

void * popCurrent(List * list) {
    return NULL;
}

void cleanList(List * list) {
    while (list->head != NULL) {
        popFront(list);
    }
}