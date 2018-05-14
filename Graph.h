/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Graph.h
 * Author: paulmelki
 *
 * Created on May 4, 2018, 9:40 PM
 */

#ifndef GRAPH_H
#define GRAPH_H

#include "Vertex.h"
#include <climits>
#include <stack>
#include <vector>


class Graph {
public:

    /**
     * Default no-arg constructor that creates a graph having 5 unconnected
     * vertices
     */
    Graph();

    /**
     * Constructor that takes as parameter a certain number of vertices and 
     * creates a graph having this number of vertices, all unconnected
     * @param numberOfVertices
     */
    Graph(int numberOfVertices);

    Graph(const Graph& orig);
    virtual ~Graph();

    /**
     * Getter that returns the number of vertices found in the graph
     * @return this->numberOfVertices
     */
    int getNumberOfVertices();
    
    /**
     * Getter that returns the array of vertices
     * @return this->vertices
     */
    Vertex * getVertices();

    /**
     * Function that takes a vector of strings and creates a vertex for every
     * name in the vector, then adds this new vertex to the graph
     * @param names, vector of strings
     * @return true if addition of elements is successful, false otherwise 
     */
    bool addVertices(vector<string> names);

    /**
     * Function that adds an edge, a connection, between 2 vertices in the 
     * graph and sets the distance of this connection
     * @param numberOfVertex1, the number representing the number of the first
     * vertex
     * @param numberOfVertex2, the number representing the number of the second
     * vertex
     * @param distance, representing the distance between the 2 connected edges
     * @return true if the operation is successful, false otherwise
     */
    bool addEdge(int numberOfVertex1, int numberOfVertex2, double distance);

    /**
     * Function that removes an edge, a connection, between 2 vertices in the
     * graph, if that edge is found
     * @param numberOfVertex1, the number representing the number of the first
     * vertex
     * @param numberOfVertex2, the number representing the number of the second
     * vertex
     * @return true if the operation is successful, false otherwise
     */
    bool removeEdge(int numberOfVertex1, int numberOfVertex2);

    /**
     * Function that checks if there is an edge, a connection, between the 2 
     * specified edges
     * @param edge1
     * @param edge2
     * @return true if there is edge, false otherwise
     */
    bool isEdge(nodeData vertex1, nodeData vertex2);

    /**
     * Function that displays the graph in a specific format
     */
    void display();

    /**
     * Function that finds the shortest possible path between 2 specific
     * vertices
     * @param numberOfVertex1, the number representing the number of the first
     * vertex (source)
     * @param numberOfVertex2, the number representing the number of the second
     * vertex (destination)
     * @return an array containing the vertices that make up the path
     */
    Vertex * findShortestPath(int numberOfVertex1, int numberOfVertex2);


private:

    // number of vertices in the graph
    int numberOfVertices;

    // array of vertices containing the vertices that make up this graph
    Vertex * vertices;



};

#endif /* GRAPH_H */

