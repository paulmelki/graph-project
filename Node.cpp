/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Node.cpp
 * Author: paulmelki
 * 
 * Created on May 4, 2018, 9:37 PM
 */

#include "Node.h"

/**
 * No-arg constructor that creates a new node with data = 0 and pointer
 * "next" equal to null
 */
Node::Node() {

    this->data = 0;
    this->next = 0;

}

/**
 * Constructor that creates a new node having the given argument as data
 * and pointer "next" equal to null
 * @param data
 */
Node::Node(nodeData data) {

    this->data = data;
    this->next = 0;
    this->weight = 0;
}

/**
 * Copy constructor that creates a new node having the same data and "next"
 * pointer as the node given as argument
 * @param orig
 */
Node::Node(const Node& orig) {
}

/**
 * Destructor that deletes the pointer "next"
 */
Node::~Node() {

    delete this->next;
}

/**
 * Setter that sets the "next" pointer equal to the given argument pointer
 * @param next
 */
void Node::setNext(Node* next) {

    this->next = next;
}

/**
 * Setter that sets the data equal to the given argument data
 * @param number
 */
void Node::setData(nodeData data) {

    this->data = data;
}

/**
 * Setter that sets the weight equal to the given weight
 * @param weight
 */
void Node::setWeight(double weight) {

    this->weight = weight;
}

/**
 * Getter that returns the value of the data in the node
 * @return this->data
 */
nodeData Node::getData() {

    return this->data;
}

/**
 * Getter that returns the pointer "next"
 * @return this->next
 */
Node * Node::getNext() {

    return this->next;
}

/**
 * Getter that returns the value of the weight of this node
 * @return this->weight
 */
double Node::getWeight() {
    
    return this->weight;
}
