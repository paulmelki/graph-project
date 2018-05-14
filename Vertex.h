/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Vertex.h
 * Author: paulmelki
 *
 * Created on May 4, 2018, 9:39 PM
 */

#ifndef VERTEX_H
#define VERTEX_H

#include "Node.h"

typedef string vertexData;

class Vertex {
    
public:
    
    /**
     * No-arg constructor that creates a new vertex with its data equal to null
     * and its "first" pointer equal to null also
     */
    Vertex();
    
    /**
     * Constructor that creates a new vertex with its data equal to the data of
     * the given parameter and its "first" pointer equal to null
     * @param data
     */
    Vertex(vertexData data);
    
    /**
     * Copy-constructor that creates a new vertex that has the same data and
     * "first" pointer as the given argument vertex
     * @param orig
     */
    Vertex(const Vertex& orig);
    
    /**
     * Destructor that deletes the "first" pointer
     */
    virtual ~Vertex();

    /**
     * Setter that sets the value of data equal to the given parameter's data
     * @param data
     */
    void setData(vertexData data);
    
    /**
     * Setter that sets the "first" pointer of this vertex equal to the given
     * parameter pointer to node
     * @param node
     */
    void setFirst(Node * node);
    
    /**
     * Getter that returns the value of the data found in the vertex
     * @return this->data
     */
    vertexData getData();
    
    /**
     * Getter that returns the pointer "first"
     * @return 
     */
    Node * getFirst();

    /**
     * Function that inserts a new node having the parameter "data" as its data 
     * in the linked list representing the vertices to which this vertex 
     * is connected
     * @param data
     * @param distance specifying the weight of the new node to be added
     * @return true if the insertion has occurred correctly
     */
    bool insert(nodeData data, double distance);
    
    /**
     * Function that searches in the linked list representing the vertices to
     * which this vertex is connected, for the node having its data equal to the
     * given parameter "data". If such a node is found, it will be removed from
     * the list
     * @param data
     * @return true if the removal is successful, false if the node is not found
     */
    bool remove(nodeData data);

private:

    // data that the vertex holds
    vertexData data;
    
    // pointer to the first node in the linked list representing the vertices
    // to which this vertex is connected
    Node * first;



};

#endif /* VERTEX_H */

