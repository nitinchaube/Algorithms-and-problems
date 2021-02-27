/*
Given an array of names of candidates in an election. A candidate name in array represents a vote casted to the candidate. Print the name of candidates received Max vote. If there is tie, print lexicographically smaller name.

Examples:

Input :  votes[] = {"john", "johnny", "jackie",
                    "johnny", "john", "jackie",
                    "jamie", "jamie", "john",
                    "johnny", "jamie", "johnny",
                    "john"};
Output : John
We have four Candidates with name as 'John',
'Johnny', 'jamie', 'jackie'. The candidates
John and Johny get maximum votes. Since John
is alphabetically smaller, we print it.
*/
#include "bits/stdc++.h" 
using namespace std; 
  
    /* We have four Candidates with name as 'John', 
      'Johnny', 'jamie', 'jackie'. 
       The votes in String array are as per the 
       votes casted. Print the name of candidates 
       received Max vote. */
    void findWinner(vector<string>& votes) 
    { 
          
        // Insert all votes in a hashmap 
        map<string,int> mapObj ; 
        for (auto& str : votes) 
        { 
            mapObj[str]++; 
        } 
   
        // Traverse through map to find the candidate 
        // with maximum votes. 
        int maxValueInMap = 0; 
        string winner; 
        for (auto& entry : mapObj) 
        { 
            string key  = entry.first; 
            int val = entry.second; 
            if (val > maxValueInMap) 
            { 
                maxValueInMap = val; 
                winner = key; 
            } 
   
            // If there is a tie, pick lexicographically 
            // smaller. 
            else if (val == maxValueInMap && 
                winner>key) 
                winner = key; 
        } 
        cout << winner << endl; 
    } 
   
    // Driver code 
    int main() 
    { 
       vector<string> votes = { "john", "johnny", "jackie", 
                         "johnny", "john", "jackie", 
                         "jamie", "jamie", "john", 
                         "johnny", "jamie", "johnny", 
                         "john" }; 
   
       findWinner(votes); 
       return 0; 
    } 
     
