/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Vertex.cpp
 * Author: paulmelki
 * 
 * Created on May 4, 2018, 9:39 PM
 */

#include "Vertex.h"

/**
 * No-arg constructor that creates a new vertex with its data equal to null
 * and its "first" pointer equal to null also
 */
Vertex::Vertex() {

    this->data = "";
    this->first = 0;
}

/**
 * Constructor that creates a new vertex with its data equal to the data of
 * the given parameter and its "first" pointer equal to null
 * @param data
 */
Vertex::Vertex(vertexData data) {

    this->data = data;
    this->first = 0;
}

/**
 * Copy-constructor that creates a new vertex that has the same data and
 * "first" pointer as the given argument vertex
 * @param orig
 */
Vertex::Vertex(const Vertex& orig) {

    if (&orig != 0) {
        this->data = orig.data;
        this->first = orig.first;
    }
}

/**
 * Destructor that deletes the "first" pointer
 */
Vertex::~Vertex() {
}

/**
 * Getter that returns the value of the data found in the vertex
 * @return this->data
 */
vertexData Vertex::getData() {

    return this->data;
}

/**
 * Getter that returns the pointer "first"
 * @return 
 */
Node * Vertex::getFirst() {

    return this->first;
}

/**
 * Setter that sets the value of data equal to the given parameter's data
 * @param data
 */
void Vertex::setData(vertexData data) {

    this->data = data;
}

/**
 * Setter that sets the "first" pointer of this vertex equal to the given
 * parameter pointer to node
 * @param node
 */
void Vertex::setFirst(Node* node) {

    this->first = node;
}

/**
 * Function that inserts a new node having the parameter "data" as its data 
 * in the linked list representing the vertices to which this vertex 
 * is connected
 * @param data
 * @param distance specifying the weight of the new node to be added
 * @return true if the insertion has occurred correctly
 */
bool Vertex::insert(nodeData data, double distance) {

    Node * pointer = this->first;
    Node * newNode = new Node(data);
    newNode->setWeight(distance);
    if (pointer == 0) {
        this->first = newNode;
        return true;
    }

    while (pointer->getNext() != 0) {
        pointer = pointer->getNext();
    }

    // Pointer.next is now null
    pointer->setNext(newNode);
    return true;


}

/**
 * Function that searches in the linked list representing the vertices to
 * which this vertex is connected, for the node having its data equal to the
 * given parameter "data". If such a node is found, it will be removed from
 * the list
 * @param data
 * @return true if the removal is successful, false if the node is not found
 */
bool Vertex::remove(nodeData data) {

    if (this->first == 0) {
        cout << "List is empty! Nothing to remove" << endl;
        return false;
    }

    Node * temp1 = this->first;
    Node * temp2 = this->first->getNext();

    if (temp2 == 0) {
        if (temp1->getData() != data)
            return false;
    }

    while (temp2 != 0) {
        if (temp2->getData() == data) {
            temp1->setNext(temp2->getNext());
            delete temp2;
        } else {
            temp1 = temp2;
            temp2 = temp2->getNext();
        }
    }
}
