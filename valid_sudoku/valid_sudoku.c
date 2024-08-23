//leet code 36 Valid Sudoku
#include<stdio.h>
#include<stdbool.h>
#define ROW 9
bool validate_sudoku(const char sudoku_board[ROW][ROW]){
		for(int row=0;row<ROW;row++){
			for(int column=0;column<ROW;column++){
				if(sudoku_board[row][column]!='.'){
					char temp = sudoku_board[row][column];
					for(int i=0;i<ROW;i++){
						if((sudoku_board[i][column]==temp&&i!=row)||(sudoku_board[row][i]==temp&&i!=column)){
							return false;
							}	
					}
				}	
			}
		}
		//
		for(int box_row=0;box_row<ROW;box_row+=3){
			for(int box_row=0;box_row<ROW;box_row+=3){
				bool seen[9]={false};
				for(int i=0;i<3;i++){
					for(int j=0;j<3;j++){
						if(sudoku_board[i+box_row][j+box_row]!='.'){
							int number = sudoku_board[i+box_row][j+box_row]-'0';
							if(seen[number-1]){
								return false;
							}else{
								seen[number-1]=true;
						
							}
						}
					}
				}
			}
		}
	return true;

}
int main(){
	const char sudoku_board[ROW][ROW]={	
						{'5','3','.','.','7','.','.','.','.'},
						{'6','.','.','1','9','5','.','.','.'},
						{'.','9','8','.','.','.','.','6','.'},
						{'8','.','.','.','6','.','.','.','3'},
						{'4','.','.','8','.','3','.','.','1'},
						{'7','.','.','.','2','.','.','.','6'},
						{'.','6','.','.','.','.','2','8','.'},
						{'.','.','.','4','1','9','.','.','5'},
						{'.','.','.','.','8','.','.','7','9'}
						};
	bool valid= validate_sudoku(sudoku_board);
	if(valid){
		printf("Sudoku board is valid\n");	
	}else{
		printf("Sudoku board is invalid\n");
	}
	return 0;
}
