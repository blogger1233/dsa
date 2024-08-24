#include<stdio.h>
#include<stdbool.h>
#define ROW 9
bool isSafe(int row,int col,char sudoku[ROW][ROW],int value){
	char ch= value+'0';
	//check row and column
	for(int x=0;x<ROW;x++){
		if((sudoku[x][col]==ch&&x!=row)||(sudoku[row][x]==ch&&x!=col)){
			return false;
		}
	}
	//subgrid
	int subgrid_row = 3*(row/3);//mistake 
	int subgrid_col= 3*(col/3);//mistake 
	for(int i=0;i<3;i++){
		for(int j=0;j<3;j++){
			if(sudoku[subgrid_row+i][subgrid_col+j]==ch){
				return false;
			}
		}
	}
	return true;
}
bool solve(char sudoku[ROW][ROW]){
	//traverse sudoku

	for(int row=0;row<ROW;row++){
		for(int col=0;col<ROW;col++){
			if(sudoku[row][col]=='.'){
				//test each number
				for(int val = 1; val<=9;val++){
					//check safe
					if(isSafe(row,col,sudoku,val)){
						sudoku[row][col]=val+'0';
						bool future = solve(sudoku);
						if(future){
							return true;
						}else{
							sudoku[row][col]='.';
							
						}
					}
				}
				return false;
			}
		}
	}
	return true;
}

int main(){
	char sudoku[ROW][ROW]={
			{'1','.','7','.','.','6','4','5','.'},
			{'.','2','5','3','4','.','.','.','8'},
			{'.','6','.','.','.','1','.','7','.'},
			{'.','5','3','.','.','.','.','2','9'},
			{'6','1','.','.','.','9','8','.','.'},
			{'.','.','.','6','.','2','.','.','7'},
			{'.','.','1','.','9','3','2','.','.'},
			{'.','.','8','.','.','.','.','.','.'},
			{'.','4','.','.','7','8','5','9','1'}	
	};
	bool solved = solve(sudoku);
	if(solved){
		printf("sudoku solve\n");
		for(int i=0;i<ROW;i++){
			for(int j=0;j<ROW;j++){
				printf(" %c",sudoku[i][j]);
			}
			//new line
			printf("\n");
		}	
		printf("\n");
	}else{printf("sudoku cannot be solve\n");}
	return 0;
}
