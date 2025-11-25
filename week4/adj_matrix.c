/**
 * FILE: ADJ_MATRIX.C
 * 
 * THIS FILE  CONTAINS EMPTY / DO-NOTHING IMPLEMENTATIONS
 * FOR THE FUNCTIONS REQUIRED FOR THE ADJACENCY MATRIX STRUCT. 
 *
 * DO NOT RENAME THESE FUNCTIONS OR CHANGE THEIR RETURN
 * TYPES OR INPUT PARAMETERS.
 *
 * YOU NEED TO COMPLETE THE IMPLEMENTATION OF THESE
 * FUNCTIONS. 
 *
 * THESE FUNCTIONS RECEIVE INPUT PARAMETERS THAT WILL
 * PROVIDE THEM WITH THE INFORMATION THEY REQUIRE. 
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
#include "my_malloc.h"          // gives access to memory allocation functions, including 'myMalloc'
#include <stdio.h>              // required for access to file input-output functions in C
#include "adj_matrix.h"         // required, to include the Adjacency Matrix data structures and function declarations
                                // that are being implemented in this file
#include <stdbool.h>            // required, to include the definition of the 


/** #### FUNCTION IMPLEMENTATIONS ## */

/**
 * Create a new, empty Adjacency Matrix, returning a pointer to the newly 
 * allocated matrix OR a value of NULL in the event of error. Ensure that 
 * the matrix is initialised to the defaultEdgeValue provided.
 * 
 * Remember to use myMalloc() to allocate memory instead of malloc(). 
 * In the event of memory allocation errors, return a value of NULL
 * for this function instead of the usual MEMORY_ALLOCATION_ERROR
 *
 */
AdjacencyMatrix* createAdjacencyMatrix(int defaultEdgeValue)
{
    // create
    AdjacencyMatrix* m = NULL;
    m = (AdjacencyMatrix*)myMalloc(sizeof(AdjacencyMatrix));
    if (m == NULL)
    {
        //return MEMORY_ALLOCATION_ERROR; commented out since it's a different return type
    }
    for (int i = 0; i < NUMBER_OF_VERTICES; i++)
    {
        for (int j = 0; j < NUMBER_OF_VERTICES; j++)
        {
            m->matrix[i][j] = defaultEdgeValue;
        }   
    }
    // returning NOT_IMPLEMENTED until your own implementation is provided
    return m;
}



/**
 * Add a new edge into an Adjacency Matrix using the details given
 * e.g., source node (src), destination node (dest), and weight
 * of the edge.
 * 
 * The function should return SUCCESS or a relevant error code.
 */
int addEdge(AdjacencyMatrix *pMatrix, int src, int dest, int weight)
{
    //check it's within bounds

    if (src >= 10 || dest >= 10 || src < 0|| dest < 0)
    {
        return INVALID_INPUT_PARAMETER;
    }
    pMatrix->matrix[src][dest] = weight;
    // returning NOT_IMPLEMENTED until your own implementation provided
    return SUCCESS;
}

/**
 * This function should add a collection of new edges into an 
 * AdjacencyMatrix using the input values given. In this case,
 * an array of Edges is provided, each one containing details of
 * a single Edge in the graph (src node, dest node, and weight).
 * 
 * You need to consider validation of the edges as you work your
 * way through them. The function should return SUCCESS if all
 * edges were processed successfully. It should return PARTIAL_SUCCESS
 * if only some of the edges were processed successfully. It should
 * return INVALID_INPUT_PARAMETER if all edges in the array were
 * found to be invalid. Your function should attempt to process all
 * edges before returning the result, ignoring any that are invalid,
 * but ensuring any valid edges are added to the graph successfully.
 * 
 */
int addEdges(AdjacencyMatrix *pMatrix, Edge edges[], int edgeNum)
{ 
    // void casts to prevent 'unused variable warning'
    // remove the following lines of code when you have 
    // implemented the function yourself

    int successCount = 0;

    for(int i = 0; i < edgeNum; i++) 
    {
        if (addEdge(pMatrix, edges[i].src, edges[i].dest, edges[i].weight) == SUCCESS)
        {
            successCount++;
        }
    }

    if (successCount < edgeNum && successCount != 0)
    {
        return PARTIAL_SUCCESS;
    }
    
    // returning NOT_IMPLEMENTED until your own implementation provided
    return SUCCESS;
}

/**
 * This function will receive the name of a file on disk which contains the 
 * data for a graph which has been stored in the form of an adjacency matrix. 
 * The function should read the content from the file and use it to populate 
 * the AdjacencyMatrix provided. The file will be formatted thus:
 * 
 * 0 0 0 0 0 0 0 0 0
 * 0 0 0 0 0 0 0 0 0
 * 0 0 0 0 0 0 0 0 0
 * 0 0 0 0 0 0 0 0 0
 * 0 0 0 0 0 0 0 0 0
 * 0 0 0 0 0 0 0 0 0
 * 0 0 0 0 0 0 0 0 0
 * 0 0 0 0 0 0 0 0 0
 * 0 0 0 0 0 0 0 0 0
 * 0 0 0 0 0 0 0 0 0
 * 
 * I.e., assuming a graph with 10 vertices, this will require a 10 x 10 matrix.
 * 
 * Each line in the file represents the next row in matrix, indexed from 0 to 9.
 * 
 * Each line will record the weight of the relevant edge in the graph. This will
 * be a value of zero (no edge) or a value of greater than zero (signifying that
 * an edge does exist, and the weight of that edge).
 * 
 * The function should return SUCCESS or a relevant error code.
 * 
 */
int loadMatrixFromFile(AdjacencyMatrix *pMatrix, char filename[])
{
    // void casts to prevent 'unused variable warning'
    // remove the following lines of code when you have 
    // implemented the function yourself
    FILE* fi = NULL;
    fi = (FILE*)myMalloc(sizeof(FILE));

    if (fi==NULL)
    {
        return MEMORY_ALLOCATION_ERROR;
    }
    

    fi = fopen(filename, "r");

    if (fi == NULL)
    {
        return FILE_IO_ERROR;
    }
    
    //make a buffer with a length as long as the lines + null/nl
    char val[22];
    while (fgets(val, 22, fi)!= NULL)                               //loop until no more lines
    {
        for(int i = 0; i<NUMBER_OF_VERTICES; i++)
        {
            for(int j = 0; j<=(NUMBER_OF_VERTICES*2)-1; j++)        //loop for each character, including whitespace
            {
                if (j%2 != 1)                                       //check every even iteration to skip whitspace
                {
                    pMatrix->matrix[i][j/2] = (int)val[j]-48;       //set the value in the matrix, shifting the ascii value to get the actual number
                }
            }
            fgets(val, 22, fi);                                     //scan next line
        }
    }
    fclose(fi);
    // returning NOT_IMPLEMENTED until your own implementation provided
    return SUCCESS;
}

int doDepthFirstTraversal(AdjacencyMatrix *pMatrix, int startingNode, int traversalOutput[])
{ 
    // void casts to prevent 'unused variable warning'
    // remove the following lines of code when you have 
    // implemented the function yourself

    //check within bounds
    if (startingNode>9||startingNode<0)
    {
        return INVALID_INPUT_PARAMETER;
    }
    
    //initialise variables
    int curNode = startingNode;
    int visited[NUMBER_OF_VERTICES];
    int stack[NUMBER_OF_VERTICES];
    int sTop = -1;
    int travInd = 1;

    for(int i = 0; i<NUMBER_OF_VERTICES; i++)
    {
        visited[i] = 0;
        stack[i] = 0;
    }
    visited[curNode] = 1;
    traversalOutput[0] = curNode;

    //loop until solved
    int breaker = 0;
    while (breaker != 1)
    {
        for (int i = 0; i < NUMBER_OF_VERTICES; i++)
        {
            if (pMatrix->matrix[curNode][i]>=1 && visited[i]!=1 )
            {
                sTop++;
                stack[sTop] = curNode;                  //add to stack             
                curNode = i;
                visited[i] = 1;                         //mark as visited
                traversalOutput[travInd] = curNode;
                travInd++;                              //add to output array
                i=-1;
                continue;
            }
        }

        breaker = 1;                                    //assume solved, check if stack is empty
        if (sTop >= 0)
        {
            curNode=stack[sTop];
            stack[sTop] = 0;
            sTop--;                                     //pop stack
            breaker = 0;                                //reset 
        }
    }
    // returning NOT_IMPLEMENTED until your own implementation provided
    return SUCCESS;
}