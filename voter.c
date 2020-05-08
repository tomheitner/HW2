/*

  File: voter.c

  Abstract:

    Voter handling implementation

*/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "voter.h"


/*
 * Types
 */
typedef struct _Voter
{
    char* pName;
    char* pParty;
    int ID;

    struct _Voter* pNext;
} Voter;


/*
 * Statics
 */
static Voter* VoterList = NULL;


/*

  Function: AddVoter

  Abstract:

    Adds a new voter to the database

  Parameters:

    pName    - The voter's name
    pSurname - The voter's surname
    ID		 - The voter's ID (assumed to be unique)
    pParty   - The voter's vote (assumed NOT to be changed)

  Returns: --

*/
void AddVoter(char* pName, char* pSurname, int ID, char* pParty)
{
    char *name = (char*) malloc(strlen(pName) + strlen(pSurname) + 1);
    char *cName = (char*)malloc(strlen(pName) + strlen(pSurname) + 1);

    if (name == NULL || cName == NULL) //check if any malloc failed
    {
        printf("malloc has failed in AddVoters");
        return;
    }

    strcpy(name, s1);
    strcat(name, s2);

    char chr;
    while (name[i]) 
    {
        chr = toupper(word[i]);
        strcat(cName, chr);
        i++;
    }

    Voter *newbie = { cName, pParty, ID, VoterList };
    VoterList = newbie;

    free(name);
    free(newbie);
}


/*

  Function: FreeVoters

  Abstract:

    Frees all memory in the voter data-base

*/
void FreeVoters()
{
    Voter *next = (Voter*) malloc(sizeof(Voter*));
    if (name == NULL) //check if malloc failed
    {
        printf("malloc has failed in FreeVoters");
        return;
    }
    while (VoterList != NULL)
    {
        next = VoterList->pNext;
        free(VoterList);
        VoterList = next;
    }
    free(next);
}


/*

  Function: PrintVoters

  Abstract:

    Prints all registered voters

*/
void PrintVoters()
{
    Voter* pVoter;

    printf("Registered Voters\n");
    printf("ID | Name | Vote\n");

    /*
     * Iterate the voter list and print the details of each voter
     */
    for (pVoter = VoterList; pVoter; pVoter = pVoter->pNext)
    {
        printf("%d %s %s\n", pVoter->ID, pVoter->pName, pVoter->pParty);
    }
    printf("\n");
}
