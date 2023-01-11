
// survivor.cpp
// Implement any helper functions here. Do not modify the survivor.h file
// Your name:
// Your perm number: 
#include "survivor.h"
#include <iostream>
using namespace std;

int countVotes(Parchment *validVotes, string candidate)
{
     int count = 0;                     
         
     if(validVotes == NULL){
          return count;
     }
     if(validVotes->vote == candidate){
          count++;
     }
     count += countVotes(validVotes->next, candidate);
     return count;
     
}

string votedOut(Parchment *validVotes)
{
     string vOut = "";
     int totalVotes = 0;
     while(validVotes!=NULL){
          if(countVotes(validVotes, validVotes->vote) > totalVotes){
               totalVotes = countVotes(validVotes,validVotes->vote);
               vOut = validVotes->vote;
               cout << vOut << endl;
          }
          validVotes= validVotes->next;
     }
     return vOut;

}
Parchment *tallyTheVote(Parchment *votingUrn, HiddenImmunityIdol *idolUsed)
{
     
     if(votingUrn == NULL){
          return votingUrn;
     }
     if((votingUrn->vote) == (idolUsed->target)){
           Parchment* tmp = votingUrn;
           votingUrn=votingUrn->next;
           delete tmp;
           
     }else{
          return tallyTheVote(votingUrn->next, idolUsed);
     }


}