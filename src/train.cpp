// Copyright 2021 NNTU-CS
#include "train.h"

Train::Train() : first(nullptr), countOp(0) {}

int Train::getOpCount() {
  return countOp;
}

void Train::addCar(bool light) {
  Car *freshCar = new Car;
  freshCar->light = light;

  if (first == nullptr) {
    first = freshCar;
    freshCar->next = freshCar;
    freshCar->prev = freshCar;
    return;
  }

  Car *tail = first->prev;
  freshCar->next = first;
  freshCar->prev = tail;
  tail->next = freshCar;
  first->prev = freshCar;
}

int Train::getLength() {
  Car *current = first;
  current->light = true;

  while (true) {
    int distance = 0;

    do {
      current = current->next;
      countOp++;
      distance++;
    } while (!current->light);

    current->light = false;

    for (int i = 0; i < distance; i++) {
      current = current->prev;
      countOp++;
    }

    if (!current->light) {
      return distance;
    }
  }
}
