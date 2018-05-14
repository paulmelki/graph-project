/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Graph.cpp
 * Author: paulmelki
 * 
 * Created on May 4, 2018, 9:40 PM
 */

#include "Graph.h"

/**
 * Default no-arg constructor that creates a graph having 5 unconnected
 * vertices
 */
Graph::Graph() {

    this->numberOfVertices = 5;
    this->vertices = new Vertex[this->numberOfVertices];
}

/**
 * Constructor that takes as parameter a certain number of vertices and 
 * creates a graph having this number of vertices, all unconnected
 * @param numberOfVertices
 */
Graph::Graph(int numberOfVertices) {

    this->numberOfVertices = numberOfVertices;
    this->vertices = new Vertex[this->numberOfVertices];
}

Graph::Graph(const Graph& orig) {
}

Graph::~Graph() {

}

/**
 * Getter that returns the number of vertices found in the graph
 * @return this->numberOfVertices
 */
int Graph::getNumberOfVertices() {

    return this->numberOfVertices;
}

/**
 * Getter that returns the array of vertices
 * @return this->vertices
 */
Vertex * Graph::getVertices() {

    return this->vertices;
}

/**
 * Function that takes a vector of strings and creates a vertex for every
 * name in the vector, then adds this new vertex to the graph
 * @param names, vector of strings
 * @return true if addition of elements is successful, false otherwise 
 */
bool Graph::addVertices(vector<string> names) {

    if (names.size() == 0) return false;

    for (int i = 0; i < names.size(); i++) {

        Vertex * newVertex = new Vertex(names[i]);
        vertices[i] = *newVertex;
    }

    return true;

}

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
bool Graph::addEdge(int numberOfVertex1, int numberOfVertex2, double distance) {

    // iterate through the graph
    for (int i = 0; i < this->numberOfVertices; i++) {

        // when the first vertex is found
        if (i == numberOfVertex1) {

            // insert the new vertex
            return this->vertices[i].insert(numberOfVertex2, distance);
        }
    }

    return false;
}

/**
 * Function that removes an edge, a connection, between 2 vertices in the
 * graph, if that edge is found
 * @param numberOfVertex1, the number representing the number of the first
 * vertex
 * @param numberOfVertex2, the number representing the number of the second
 * vertex
 * @return true if the operation is successful, false otherwise
 */
bool Graph::removeEdge(int numberOfVertex1, int numberOfVertex2) {

    // iterate through the graph
    for (int i = 0; i < this->numberOfVertices; i++) {

        // when the first vertex is found
        if (i == numberOfVertex1) {

            // remove the second vertex from the list of vertices to which
            // the first vertex is connected to
            return this->vertices[i].remove(numberOfVertex2);
        }

    }

    return false;
}

/**
 * Function that checks if there is an edge, a connection, between the 2 
 * specified edges
 * @param edge1
 * @param edge2
 * @return true if there is edge, false otherwise
 */
bool Graph::isEdge(nodeData vertex1, nodeData vertex2) {

    Vertex ver1 = this->vertices[vertex1];
    Node * neighbor = ver1.getFirst();

    while (neighbor != 0) {

        if (neighbor->getData() == vertex2) {
            return true;
        }

        neighbor = neighbor->getNext();
    }

    return false;
}

/**
 * Function that displays the graph in a specific format
 */
void Graph::display() {

    cout << "This is the graph that we read from the file: " << endl << endl;
    for (int i = 0; i < this->numberOfVertices; i++) {

        cout << i + 1 << ": " + this->vertices[i].getData() << endl
                << "connected to: " << endl;

        Node * neighbor = this->vertices[i].getFirst();
        cout << this->vertices[neighbor->getData()].getData() << " - ";
        neighbor = neighbor->getNext();

        while (neighbor != 0) {
            if (neighbor->getNext() != 0)
                cout << this->vertices[neighbor->getData()].getData() << " - ";
            else
                cout << this->vertices[neighbor->getData()].getData() << endl;
            neighbor = neighbor->getNext();
        }

        cout << endl;
        cout << endl;
    }
}

/**
 * Function that finds the shortest possible path between 2 specific
 * vertices
 * @param numberOfVertex1, the number representing the number of the first
 * vertex (source)
 * @param numberOfVertex2, the number representing the number of the second
 * vertex (destination)
 * @return an array containing the vertices that make up the path
 */
Vertex * Graph::findShortestPath(int numberOfVertex1, int numberOfVertex2) {

    /*
     * ALGORITHM AS GIVEN BY DR. JOUMANA
     * 1. bool temp[] that contains the vertices not visited
     *      set temp[i] = false
     * 
     * 2. create table calculate[][]
     *      set calculate[0][0] = 0
     *      set calculate[i][0] = infinity
     *      set calculate[i][1] = null
     * 
     * 3. for (i = 0 --> # of vertices) 
     *      find minimum element in calculate[i][0]
     *      final[min] = true; 
     *      temp[min] = true;
     *      current = min;
     *      loop over temp[i] for all nodes connected to current
     *          y is element connected to current
     *          if calculate[current][0] + weight(between current and y) < calculate[y][0]
     *              calculate[y][0] = calculate[current][0] + weight(between current and y)
     *              calculate[y][1] = current;
     */


    bool visited[this->numberOfVertices];

    for (int i = 0; i < this->numberOfVertices; i++) {

        visited[i] = false;
    }

    int calculate[this->numberOfVertices][2];
    for (int i = 0; i < this->numberOfVertices; i++) {
        calculate[i][0] = INT_MAX;
        calculate[i][1] = 0;
    }

    calculate[numberOfVertex1 - 1][0] = 0;

    for (int i = 0; i < this->numberOfVertices; i++) {

        int minimum = numberOfVertex2 - 1;

        for (int j = 1; j < this->numberOfVertices; j++)
            if (calculate[j][0] < calculate[minimum][0] && visited[j] == false)
                minimum = j;

        visited[minimum] = true;
        int current = minimum;

        Node * n = this->vertices[minimum].getFirst();

        while (n != 0) {


            if (calculate[n->getData() - 1][0] > n->getWeight() + calculate[current][0]) {

                calculate[n->getData() - 1][0] = n->getWeight() + calculate[current][0];
                calculate[n->getData() - 1][1] = current;
            }
            n = n->getNext();
        }
    }

    stack<int> tempoStack;
    int position = numberOfVertex2 - 1;

    while (calculate[position][1] != 0) {

        tempoStack.push(position);
        position = calculate[position][1];
    }

    tempoStack.push(numberOfVertex1 - 1);

    cout << endl << "The shortest path is: " << endl;

    while (!tempoStack.empty()) {

        cout << tempoStack.top() + 1 << " " <<
                vertices[tempoStack.top()].getData();
        if (tempoStack.top() + 1 != numberOfVertex2)
            cout << " --> ";

        tempoStack.pop();
    }
}

//    bool temp[this->numberOfVertices];
//    for (int i = 0; i < this->numberOfVertices; i++)
//        temp[i] = false;
//
//    int calculate[this->numberOfVertices][2];
//    for (int i = 0; i < this->numberOfVertices; i++) {
//        calculate[i][0] = 2147483647;
//        calculate[i][1] = NULL;
//    }
//    calculate[source - 1][0] = 0;
//
//    for (int i = 0; i < this->numberOfVertices; i++) {
//        int min = destination - 1;
//        for (int j = 1; j < this->numberOfVertices; j++)
//            if (calculate[j][0] < calculate[min][0] && temp[j] == false)
//                min = j;
//
//        temp[min] = true;
//        int current = min;
//
//        Node* n = vertices[min].getFirst();
//        while (n != NULL) {
//
//            if (calculate[n->getData() - 1][0] > n->getWeight() + calculate[current][0]) {
//                calculate[n->getData() - 1][0] = n->getWeight() + calculate[current][0];
//                calculate[n->getData() - 1][1] = current;
//            }
//            n = n->getNext();
//        }
//    }
//
//    stack<int> s;
//    int pos = destination - 1;
//    while (calculate[pos][1] != NULL) {
//        s.push(pos);
//        pos = calculate[pos][1];
//    }
//    s.push(source - 1);
//
//    cout << "\nShortest path is:\n" << endl;
//    while (!s.empty()) {
//        cout << s.top() + 1 << " " << vertices[s.top()].getData();
//        if (s.top() + 1 != destination)
//            cout << " -> ";
//        s.pop();
//    }

