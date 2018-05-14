/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Node.h
 * Author: paulmelki
 *
 * Created on May 4, 2018, 9:37 PM
 */

#ifndef NODE_H
#define NODE_H

#include <iostream>
#include <string>

using namespace std;

typedef int nodeData;

class Node {
    
public:
    
    /**
     * No-arg constructor that creates a new node with data = 0 and pointer
     * "next" equal to null
     */
    Node();
    
    /**
     * Constructor that creates a new node having the given argument as data
     * and pointer "next" equal to null
     * @param data
     */
    Node(nodeData data);
    
    /**
     * Copy constructor that creates a new node having the same data and "next"
     * pointer as the node given as argument
     * @param orig
     */
    Node(const Node& orig);
    
    /**
     * Destructor that deletes the pointer "next"
     */
    virtual ~Node();
    
    /**
     * Setter that sets the "next" pointer equal to the given argument pointer
     * @param next
     */
    void setNext(Node * next);
    
    /**
     * Setter that sets the data equal to the given argument data
     * @param number
     */
    void setData(nodeData data);
    
    /**
     * Setter that sets the weight equal to the given weight
     * @param weight
     */
    void setWeight(double weight);
    
    /**
     * Getter that returns the pointer "next"
     * @return this->next
     */
    Node * getNext();
    
    /**
     * Getter that returns the value of the data in the node
     * @return this->data
     */
    nodeData getData();
    
    /**
     * Getter that returns the value of the weight of this node
     * @return this->weight
     */
    double getWeight();
    
private:
    
    // data contained in the node, representing the number of the node
    nodeData data;
    
    // a pointer to the next node
    Node * next;
    
    // double specifying the weight of this node
    double weight;

};


#endif /* NODE_H */

