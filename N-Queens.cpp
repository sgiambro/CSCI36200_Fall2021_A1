//N-Queens.cpp

#include <iostream>
#include <sstream>
#include <stack>

using namespace std;

int main(){
		
	stack<pair<int , int> >  queens;
	bool conflict = false;
	bool moved = false;
	int numQueens = 0;
	int queensPlaced = 0;
	int temp1 = 0;
	int temp2 = 0;
	string userNum = "";
	
	
	//get number of queens from user
	while(numQueens < 4){
		
		cout << "Enter number of queens on the board:  ";
		getline(cin , userNum);
		
		stringstream ss;
		ss << userNum;
		ss >> numQueens;
	
		if (numQueens < 4 ){
			cout << "ERROR! Number has to be 4 or more. ";
		}
	
	}
	
	
	//Places all the queens in the correct positions
	int columns[numQueens];
	queens.push({1,1});
	columns[0] = 1;
	while (numQueens != queensPlaced) {
		
		conflict = false;
		moved = false;
		
		//testing for conflicts with other queens
		for(int i=0; i<queensPlaced ; i++){
			if(queens.top().second == (columns[i] - ((queens.top().first) - (i+1)))  ||  queens.top().second == (columns[i] + (queens.top().first) - (i+1))  ||  queens.top().second == columns[i]){
				conflict = true;
			}
		}
		
		//if no conflicts place queen and add another one row up
		if(conflict == false){
			columns[(queens.top().first) - 1] = queens.top().second;
			queensPlaced++;
			if((queens.top().first) + 1  <=  numQueens){
				queens.push({(queens.top().first) + 1, 1});
				columns[(queens.top().first) - 1] = queens.top().second;
			}
		}
		
		//if theres a conflict move the queen or pop the top queen to a previous queen 
		else if(conflict == true){
			if((queens.top().second) + 1  <= numQueens){
				temp1 = queens.top().first;
				temp2 = queens.top().second;
				queens.pop();
				queens.push({ temp1 , temp2 + 1 });
				columns[temp1 - 1] = temp2 + 1;
			}
			
			else if((queens.top().second) + 1  > numQueens){
				queens.pop();
				while(!moved){
					
					if((queens.top().second) + 1  > numQueens){
						queens.pop();
						queensPlaced--;
					}
					
					else if((queens.top().second) + 1  <= numQueens){
						temp1 = queens.top().first;
						temp2 = queens.top().second;
						queens.pop();
						queens.push({ temp1 , temp2 + 1 });
						columns[temp1 - 1] = temp2 + 1;
						queens.push({(queens.top().first) + 1, 1});
						columns[(queens.top().first) - 1] = queens.top().second;
						moved = true;
					}
					
				}
				
			}
			
		}
		
		
	}
	
	
	//shows all final queen positions
	cout << "All queen positions: ";
	while (!queens.empty()){
	
		cout << "("  <<  queens.top().first  <<  ","  <<  queens.top().second  <<  ")";
		queens.pop();
	
	}
	
	cout << "\n";

}