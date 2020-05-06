/*

  File: main.c

  Abstract:

    Election application entry point

*/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "voter.h"
#include "party.h"

#define MAX_LINE_LENGTH     256


int main()
{
    char Buf[MAX_LINE_LENGTH];
	char* delimiters = " \t\n";    
    char* pToken;
    char* pName;
    char* pSurName;
    char* pParty;
    char* pID;
    char* pListParty;
    int userQuit = 0;

    do
    {
    	
        if (!fgets(Buf,MAX_LINE_LENGTH,stdin)) 
                break; //EOF reached
        /*
         * Parse command
         */
        pToken = strtok(Buf, delimiters);
        switch (*pToken)
        {
        case 'A':
            // ADD <name> <surname> <ID> <party>
            pName = strtok(NULL, delimiters);
            pSurName = strtok(NULL, delimiters);
            pID = strtok(NULL, delimiters);
            pParty = strtok(NULL, delimiters);

            pListParty = AddVote(pParty);
			if (pListParty)
				AddVoter(pName, pSurName, atoi(pID), pListParty);
            break;

        case 'P':
            /*
             * PRINT (VOTERS or RESULT)
             */
            pToken = strtok(NULL, delimiters);
            if (*pToken == 'V')
            {
	            PrintVoters();
            }
            else
            {
	            PrintResult();
            }
            break;

        case 'Q':
            /*
             * QUIT
             */
            userQuit = 1;
            break;
        } 

    } while (!userQuit);

    FreeVoters();
    FreeParties();
    return 0;
}
