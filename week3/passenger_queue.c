#include <stdlib.h> // required for some memory allocation functions such as 'malloc()' and 'free()'
#include <string.h> // you will need this if you use the string helper functions in C
#include "passenger_queue.h" // required, to include the Passenger Queue data structures, #defines, and function declarations
#include <stdio.h> // for displaying items in the queue

/*** ### FUNCTION IMPLEMENTATIONS ### ***/

/**
 * Create a new, empty queue, returning a pointer to the newly allocated
 * queue OR a value of NULL in the event of error.
 */
PassengerQueue *createQueue()
{
   PassengerQueue* q = NULL;
   q = (PassengerQueue*)malloc(sizeof(PassengerQueue));
   q->head = NULL;
   q->tail = NULL;
   return q;
}

int addPassenger(PassengerQueue *qPtr, int passengerID, char *passengerName, int isPriority)
{
   Passenger* p = NULL;
   p = (Passenger*)malloc(sizeof(Passenger));
   p->ID = passengerID;
   strcpy(p->name, passengerName);
   p->next = NULL;

   if (qPtr->head == NULL)
   {
      qPtr->head = p;
      qPtr->head->next = NULL;
      qPtr->tail = p;
   }

   else if(isPriority == 0)
   {
      qPtr->tail->next = p;
      qPtr->tail = p;
   }

   else
   {
      p->next = qPtr->head;
      qPtr->head = p;
   }
   return SUCCESS;
}


/** 
 * Get the count of / number of passengers in the queue
 */
int getPassengerCount(PassengerQueue *qPtr)
{
   Passenger* p = NULL;
   p = (Passenger*)malloc(sizeof(Passenger));
   p = qPtr->head;
   int count = 0;
   while (p!=NULL)
   {
      count++;
      p = p->next;
   }
   
   return count;
}


/**
 * Remove the next passenger from the HEAD of the  queue, copying the removed passenger's
 * information into the fields of the input variable provided (*p)
 */
int removePassengerAtHead(PassengerQueue *qPtr, Passenger *p)
{
   Passenger* temp = qPtr->head;
   int tID = temp->ID;
   char tName[MAX_PASSENGER_NAME_LENGTH];
   strcpy(tName, temp->name);
   qPtr->head = temp->next;
   free(temp);
   return SUCCESS;
}


/**
 * Peek at the HEAD passenger in the queue.
 */
int peekAtHeadPassenger(PassengerQueue *qPtr, Passenger *p)
{
   p->ID = qPtr->head->ID;
   strcpy(p->name, qPtr->head->name);
   p->next = qPtr->head->next;
   return SUCCESS;
}

                           //0----0----0----0----0   o

                                             //0
/**
 * Remove the next passenger from the TAIL of the  queue, copying the removed passenger's
 * information into the fields of the input variable provided (*p)
 * NOTE: THIS ISN'T AS STRAIGHT FORWARD AS REMOVING FROM THE HEAD!
 */
int removePassengerAtTail(PassengerQueue *qPtr, Passenger *p)
{
   Passenger* temp = NULL;
   temp = (Passenger*)malloc(sizeof(Passenger));
   temp = qPtr->head;


   Passenger* copy = NULL;
   copy = (Passenger*)malloc(sizeof(Passenger));
   copy = qPtr->head;

   while (temp->next != NULL)
   {
      copy = temp;
      temp = temp->next;
   }

   copy->next = NULL;
   qPtr->tail = copy;
   temp = NULL;
   copy = NULL;

   free(temp);
   free(copy);
   return SUCCESS;
}


/**
 * Clear the content of the queue, freeing the memory for each passenger in the queue and
 * the queue itself. 
 */
int clearQueue(PassengerQueue *qPtr)
{
   Passenger* copy = NULL;
   copy = (Passenger*)malloc(sizeof(Passenger));

   while (qPtr->head != NULL)
   {
      copy = qPtr->head;
      qPtr->head = copy->next;
      free(copy);
   }
   free(qPtr);
   return SUCCESS;
}


/** 
 * ADDED EXTRAS. If you want something extra to do, try implementing a function which
 * will re-order the passengers in the queue based on their ID value, making sure they
 * occur in order from lowest to highest.
 */
int sortQueue(PassengerQueue *qPtr);


/** 
 * Add any other functions you want too, e.g., a function to add an item into the middle of the queue, 
 * in between two passengers, or even remove a passenger from the middle of the queue. Implement a function 
 * to find / locate a specific passenger in the queue based on their ID value. 
 */

// add implementations of other functions here too, e.g., addPassenger(), removePassenger(), etc.