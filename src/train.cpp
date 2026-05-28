// Copyright 2021 NNTU-CS
#include "train.h"

Train::Train() : head(nullptr), totalOps(0) {}

int Train::getOpCount() { 
    return totalOps; 
}

void Train::addCar(bool light) { 
    Car *freshCar = new Car;
    freshCar->light = light;
    
    if (head == nullptr) {
        head = freshCar;
        freshCar->next = freshCar;
        freshCar->prev = freshCar;
        return;
    }
    
    Car *tail = head->prev;
    freshCar->next = head;
    freshCar->prev = tail;
    tail->next = freshCar;
    head->prev = freshCar;
}

int Train::getLength() { 
    Car *current = head;
    current->light = true;
    
    while (true) {
        int distance = 0;
        
        do {
            current = current->next;
            totalOps++;
            distance++;
        } while (!current->light);
        
        current->light = false;
        
        for (int i = 0; i < distance; i++) {
            current = current->prev;
            totalOps++;
        }
        
        if (!current->light) {
            return distance;
        }
    }
}
