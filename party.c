/*

  File: party.c

  Abstract:

    Party handling implementation

*/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "party.h"

#define MAX_PARTY_NAME      20


/*
 * Types
 */
typedef struct _Party
{
    char Party[MAX_PARTY_NAME];
    int NumVoters;

    struct _Party* pNext;
} Party;


/*
 * Prototypes
 */
void PrintError(char* pPartyName);


/*
 * Statics
 */
static Party* PartyList = NULL;


/*

  Function: AddVote

  Abstract:

    Records the chosen party of a voter

  Parameters:

    pPartyName - The party that received the vote

  Returns: A pointer to the party name that is guaranteed to stay constant until 'FreeParties'
           is called. If the party name is illegal, we fail the operation and return NULL.

*/
char* AddVote(char* pPartyName)
{
    Party* newParty; 
    Party* tmp;
    size_t i;

    tmp = PartyList;
    
    /* 
    iterating through the PartyList to see if the PartyName already in, and update number of voters if yes.
    */
    while (tmp != NULL) 
    {
        if (!strcmp(tmp->Party, pPartyName))
        {
            tmp->NumVoters++; 
            return tmp->Party;
        }
        tmp = tmp->pNext;
    }

    //checks if party name is leggal  
    for (i = 1; i < strlen(pPartyName); i++) {
        
        if ((pPartyName[i - 1] == '-') && (pPartyName[i] >= 'a') && (pPartyName[i] <= 'z')) //after '-' a lowercase letter
        {
            PrintError(pPartyName);
            return NULL;
        }  
    }
    
    newParty = malloc(sizeof(Party));
    if (newParty == NULL)
    {
        printf("malloc failed on newParty");
        exit(-1);
    }

    /* 
    adding new party to the list and changing head to point to this new party
    */
    newParty->NumVoters = 1;
    strcpy(newParty->Party,pPartyName);
    newParty->pNext = PartyList;
    PartyList = newParty;

    return newParty->Party;
}


/*

  Function: FreeParties

  Abstract:

    Frees all memory in the party database

*/
void FreeParties()
{
    Party* tmp;

    while (PartyList != NULL)
    {
        tmp = PartyList;
        PartyList = PartyList->pNext;
        free(tmp);
    }
}


/*

  Function: PrintResult

  Abstract:

    Reports the election result so far

*/
void PrintResult()
{
    Party* pParty;

    printf("Election Results\n");
    printf("Party | Num. of Voters\n");

    /*
     * Iterate the party list and print the current number of voters for each party
     */
    for (pParty = PartyList; pParty; pParty = pParty->pNext)
        printf("%s %d\n", pParty->Party, pParty->NumVoters);
    printf("\n");
}


void PrintError(char* pPartyName)
{
    printf("ERROR: '%s' is invalid\n", pPartyName);
}
