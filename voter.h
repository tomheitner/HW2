/*

  File: voter.h

  Abstract:

    Voter handling interface

*/


#ifndef _VOTER_H_
#define _VOTER_H_


void AddVoter(char* pName, char* pSurname, int ID, char* pParty);
void FreeVoters();
void PrintVoters();

#endif /* _VOTER_H_ */
