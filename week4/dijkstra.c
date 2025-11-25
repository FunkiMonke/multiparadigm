/**
 * FILE: DIJKSTRA.C
 * 
 * THIS FILE  CONTAINS EMPTY / DO-NOTHING IMPLEMENTATIONS
 * FOR THE FUNCTIONS REQUIRED OF DIJKSTRA'S ALGORITHM 
 *
 * DO NOT RENAME THESE FUNCTIONS OR CHANGE THEIR RETURN
 * TYPES OR INPUT PARAMETERS.
 *
 * YOU NEED TO COMPLETE THE IMPLEMENTATION OF THESE
 * FUNCTIONS. 
 *
 * THESE FUNCTIONS RECEIVE INPUT PARAMETERS THAT WILL
 * PROVIDE THEM WITH THE INFORMATION THAT THEY REQUIRE. 
 *
 * THE FUNCTIONS RETURN VALUES TO REPRESENT SUCCESS, ERROR,
 * OR, IN SOME CASES, DATA THAT HAS TO BE RETURNED. THE CALLER 
 * OF THESE FUNCTIONS WILL EXPECT TO RECEIVE THESE RETURN VALUES 
 * IN ORDER TO VERIFY THE OUTCOME OF THE FUNCTION CALL. 
 *
 * IF THERE ARE ANY FUNCTIONS THAT YOU DON'T HAVE TIME TO 
 * IMPLEMENT, PLEASE LEAVE THE EMPTY / DO-NOTHING IMPLEMENTATION
 * FOR THEM IN THIS FILE, OTHERWISE YOUR PROGRAM WON'T COMPILE
 * WHEN IT IS FED INTO OUR TESTER PROGRAM.
 * 
 */

/** 
 * ### INCLUDES
 */
#include <stddef.h>
#include "adj_matrix.h" // provides the definition of the 'Adjacency Matrix' struct which is required for one of the functions below
#include "dijkstra.h"   // provides the definition of structs and functions for the Dijkstra implementation

#include <stdio.h>
/** #### FUNCTION IMPLEMENTATIONS ## */

/**
 * This function should perform the Dijkstra algorithm. It expects to receive a 
 * ready-made graph to work with in the form of an AdjacencyMatrix. It 
 * also expects to receive an empty DijkstraTable which will be pre-initialised and 
 * ready to use. It also expects to receive the starting node on the graph to commence 
 * the algorithm from. 
 * 
 * This function should implement the algorithm, running it on the graph 
 * provided and updating the DijkstraTable with the outcome. After the function 
 * is called, the DijkstraTable will be inspected to determine whether the 
 * algorithm has been completed successfully. 
 * 
 * The function should return SUCCESS or a relevant error code.
 */
int runDijsktraAlgorithm(AdjacencyMatrix *pMatrix, DijkstraTable *pTable, int startNode)
{
    // void casts to prevent 'unused variable warning'
    // remove the following lines of code when you have 
    // implemented the function yourself

    //check within bounds
    if (startNode > 9 || startNode < 0)
    {
        return INVALID_INPUT_PARAMETER;
    }
    
    //make current the startnode, set distance to 0
    int curNode = startNode;
    pTable->table[startNode].distance = 0;
    int disCheck = 0;
    int breaker = 0;

    //loop until solved
    while (breaker !=NUMBER_OF_VERTICES)
    {
        //check every element in the row
        for (int i = 0; i < NUMBER_OF_VERTICES; i++) 
        {
            //edge exists if its greater than 1 in matrix
            if (pMatrix->matrix[curNode][i] > 0)
            {
                //add distance traveled so far
                disCheck = pTable->table[curNode].distance + pMatrix->matrix[curNode][i];

                //if total < current, make this the new table entry
                if (disCheck < pTable->table[i].distance)
                {
                    pTable->table[i].distance = disCheck;
                    pTable->table[i].predecessor = curNode;
                }
            }
        }

        for (int j = 0; j < NUMBER_OF_VERTICES; j++)
        {   //check if node's been visited, if not go through that node
            if (pTable->table[j].visited!=true)
            {
                pTable->table[curNode].visited = true;
                curNode = j;
                break;
            }
        }
        breaker++;
    }
    return SUCCESS;
}


/**
 * This function should determine the shortest path that exists on a graph 
 * from a given starting node (nodeFrom) to a given end node (nodeTo). 
 * The function expects to receive a pre-populated DijkstraTable which already 
 * contains the outcome of running the Dijkstra algorithm on a graph. It will 
 * also be provided with an array (pathFound) into which the shortest path should 
 * be recorded. The path should be recorded in reverse order; showing, from the 
 * end node, the predecessors that lead us there from the start node. 
 * For example, if the shortest path on graph from node 2 to node 8 was found 
 * to be 2 -> 4 -> 5 -> 8. The content that would be recorded in the ‘pathFound’ 
 * variable would be as follows: [8][5][4][2]. I.e., it shows the relevant nodes 
 * in the path, in reverse order. This includes the start and end node too. After the 
 * function is called, the 'pathFound' will be inspected to determine whether the 
 * algorithm has been completed successfully. 
 * 
 * The function should return SUCCESS or a relevant error code.
 */
int getShortestPathFrom(DijkstraTable *pTable, int nodeFrom, int nodeTo, int pathFound[])
{
    // void casts to prevent 'unused variable warning'
    // remove the following lines of code when you have 
    // implemented the function yourself

    //check its within table bounds
    if(nodeFrom > 9 || nodeTo > 9 || nodeFrom < 0 || nodeTo < 0)
    {
        return INVALID_INPUT_PARAMETER;
    }


    //set current to be the starting node, add it to path
    int curNode = nodeTo;
    pathFound[0] = curNode;
    int index = 1;

    //search until you find the destination
    while (curNode != -1)
    {
        //add predecessor to path, make current node the predecessor
        pathFound[index] = pTable->table[curNode].predecessor;
        curNode = pTable->table[curNode].predecessor;
        index++;
    }
    
    // returning NOT_IMPLEMENTED until your own implementation provided
    return SUCCESS;
}