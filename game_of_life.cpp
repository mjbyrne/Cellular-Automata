#include <iostream>
#include <iomanip>
using namespace std;
#define PAGEWIDTH 72
#define ROWS 30
#define COLUMNS 55


//prints everything but bottom border
void printBoard(int board[ROWS][COLUMNS]) {
  
  
  //prints top border
  cout << '+';
  for(int i = 0; i < COLUMNS; i++){
    cout << "-";
  }
  cout << '+' << endl;
  
  
  
  
  for (int y = 0; y < ROWS; ++y){
    for(int x = 0; x <= COLUMNS; ++x){

      //creates left border and first entry in line      
      if(x==0){
        cout << "|";
        if(board[y][x] ==0){
          cout << ' ';
        }
        else {
        cout << 'x';
        }
      }
      
      
      //creates right border and creates new line
      else if(x == COLUMNS){
        cout << '|' << endl;
      }
      
      
      // fills in the rest of the the columns
      else {
        if(board[y][x] ==0){
          cout << ' ';
        }
        else {
        cout << 'x';
        }
      }
    }
  }
}








void nextGeneration(int board[ROWS][COLUMNS]) {
  int neighbors[ROWS][COLUMNS] = {0};
  int neighborXPos = 0;
  int neighborYPos = 0;
  
  //Create new board called neighbors and set the value of each space equal to the number of alive neighbors it has
  for (int y = 0; y < ROWS; ++y){
    for(int x = 0; x < COLUMNS; ++x){
      for(int neighborNumber = 0; neighborNumber < 8; ++neighborNumber){
        //above and left
        if (neighborNumber == 0){ 
          if (y==0){
            neighborYPos = ROWS-1;
          }
          else {
            neighborYPos = y-1;
          }
          if (x==0){
            neighborXPos = COLUMNS-1;
          }
          else{
            neighborXPos = x-1;
          }
          neighbors[y][x] +=board[neighborYPos][neighborXPos];
        }
        
        //above  
        if (neighborNumber == 1){
          if(y==0){
            neighborYPos = ROWS-1;
          }
          else {
            neighborYPos = y-1;
          }
          neighborXPos = x;
          neighbors[y][x] +=board[neighborYPos][neighborXPos];
        }
        
        //above and right
        if (neighborNumber == 2){
          if(y==0){
            neighborYPos = ROWS-1;
          }
          else{
            neighborYPos = y-1;
          }
          if(x==COLUMNS-1){
            neighborXPos = 0;
          }
          else {
            neighborXPos = x+1;
          }
          neighbors[y][x] += board[neighborYPos][neighborXPos];
        }
        
        
        // left
        if (neighborNumber == 3){
          if(x==0){
            neighborXPos = COLUMNS-1;
          }
          else {
            neighborXPos = x-1;
          }
          neighborYPos = y;
          
          neighbors[y][x] += board[neighborYPos][neighborXPos];
        }
        
        // right
        if (neighborNumber == 4){
          if(x==COLUMNS-1){
            neighborXPos = 0;
          }
          else {
            neighborXPos = x+1;
          }
          
          neighborYPos = y;
          
          neighbors[y][x] += board[neighborYPos][neighborXPos];
          
        }
        
        //below and left
        if (neighborNumber == 5){
          if (y==ROWS-1){
            neighborYPos = 0;
          }
          else {
            neighborYPos = y+1;
          }
          if(x==0){
            neighborXPos = COLUMNS-1;
          }
          else{
            neighborXPos = x-1;
          }
          neighbors[y][x] += board[neighborYPos][neighborXPos];
          
        }
        
        // below
        if (neighborNumber == 6){
          if(y==ROWS-1){
            neighborYPos = 0;
          }
          else {
            neighborYPos = y+1;
          }
          neighborXPos = x;
          neighbors[y][x] +=board[neighborYPos][neighborXPos];
        }
        
        
        // below and right
        if (neighborNumber == 7){
          if(y==ROWS-1){
            neighborYPos = 0;
          }
          else {
            neighborYPos = y+1;
          }
          if(x==COLUMNS-1){
            neighborXPos = 0;
          }
          else {
            neighborXPos = x+1;
          }
          neighbors[y][x] +=board[neighborYPos][neighborXPos];
        }
        
      }
    }
  }

  for (int y = 0; y < ROWS; ++y){
    for(int x = 0; x <= COLUMNS; ++x){
      if(board[y][x] == 1 and neighbors[y][x] < 2){
        board[y][x] = 0;
      }
      if(board[y][x] == 1 and neighbors[y][x] == 2){
        board[y][x] = 1;
      }
      if(board[y][x] == 1 and neighbors[y][x] == 3){
        board[y][x] = 1;
      }
      if(board[y][x] == 1 and neighbors[y][x] > 3){
        board[y][x] = 0;
      }
      if(board[y][x] == 0 and neighbors[y][x] == 3){
        board[y][x] = 1;
      }
    }
  }
}






//sets all values in board to 0
void clearBoard(int board[ROWS][COLUMNS]){
  for (int y = 0; y < ROWS; ++y){
    for(int x = 0; x < COLUMNS; ++x){
      board[y][x] = 0;
    }
  }
}


//sets all values in pageArray to ' '
void clearPageArray(char pageArray[ROWS + 5][PAGEWIDTH]){
  for (int y = 0; y < ROWS+5; ++y){
    for(int x = 0; x < PAGEWIDTH; ++x){
      pageArray[y][x] = ' ';
    }
  }
}





//iterates over multiple numOfGenerations
void runGenerations(int board[ROWS][COLUMNS], char pageArray[ROWS + 5][PAGEWIDTH], int numOfGenerations){
  //create a secondary board and set it equal to the starting board
  int lastGenBoard[ROWS][COLUMNS] = {0};
  for (int y = 0; y < ROWS; ++y){
    for(int x = 0; x < COLUMNS; ++x){
      lastGenBoard[y][x] = board[y][x];
    }
  }
  //number of generations iterated so far
  int generationsSoFar = 0;
  
  //number of boards on the page array
  int boardsOnPageSoFar = 0;
  
  //number of full boards that can fit on one page, the +5 is because 2 are from the border and 3 will be the spaces in between boards
  int boardsPerPage = PAGEWIDTH / (COLUMNS+5);
  
  
  
  
  // print out the starting board as generation 0
  printBoard(board);
  
  //creates bottom border
    int halfwayPoint = COLUMNS/2;
    cout << '+';
    // subtract 3 since using 6 total slots, 3 for "Gen" one for a space, and two for the number of generations
    for(int i = 0; i < halfwayPoint - 3; i++){
      cout << "-";
    }
    cout << "Gen " << setw(3) << generationsSoFar; 
    for(int i = halfwayPoint + 3; i < COLUMNS-1; i++){
      cout << '-';
    }
    cout << '+' << endl;
    
  generationsSoFar++;
  
  bool areTheBoardsTheSame = true;
    
  for(generationsSoFar; generationsSoFar <= numOfGenerations; generationsSoFar ++){
    //advance one generation
    nextGeneration(board);
    
    //check to see if the current generation has changed at all
    areTheBoardsTheSame = true;
    for (int y = 0; y < ROWS; ++y){
      for(int x = 0; x < COLUMNS; ++x){
        if (lastGenBoard[y][x] != board[y][x]){
          areTheBoardsTheSame = false;
        }
      }
    }
    
    
    if (areTheBoardsTheSame == true){
      cout << "This board has reached a static image." << endl;
      cout << "All future generations are identical." << endl << endl << endl << endl;
      break;
    }
    else {
      printBoard(board);
      for (int y = 0; y < ROWS; ++y){
        for(int x = 0; x < COLUMNS; ++x){
          lastGenBoard[y][x] = board[y][x];
        }
      }
    }
    
    //creates bottom border
    int halfwayPoint = COLUMNS/2;
    cout << '+';
    // subtract 3 since using 6 total slots, 3 for "Gen" one for a space, and two for the number of generations
    for(int i = 0; i < halfwayPoint - 3; i++){
      cout << "-";
    }
    cout << "Gen " << setw(3) << generationsSoFar; 
    for(int i = halfwayPoint + 3; i < COLUMNS-1; i++){
      cout << '-';
    }
    cout << '+' << endl;
  }
  
  
}






//Glider
void makeGlider(int board[ROWS][COLUMNS]){
    board[0][1] = 1;
    board[1][2] = 1;
    board[2][0] = 1;
    board[2][1] = 1;
    board[2][2] = 1;
}  


//Cheshire cat
void makeCheshireCat(int board[ROWS][COLUMNS]){
  board[2][5] = 1;
  board[2][8] = 1;
  
  board[3][5] = 1;
  board[3][6] = 1;
  board[3][7] = 1;
  board[3][8] = 1;
  
  board[5][6] = 1;
  board[5][7] = 1;
  
  board[4][4] = 1;
  board[5][4] = 1;
  board[6][4] = 1;
  
  board[4][9] = 1;
  board[5][9] = 1;
  board[6][9] = 1;
  
  board[7][5] = 1;
  board[7][6] = 1;
  board[7][7] = 1;
  board[7][8] = 1;
}

void makePulsar(int board[ROWS][COLUMNS]){
  board[1][3] = 1;
  board[1][4] = 1;
  board[1][5] = 1;
  
  board[1][9] = 1;
  board[1][10] = 1;
  board[1][11] = 1;
 
  board[3][1] = 1;
  board[4][1] = 1;
  board[5][1] = 1;
  
  board[3][6] = 1;
  board[4][6] = 1;
  board[5][6] = 1;
 
  board[3][8] = 1;
  board[4][8] = 1;
  board[5][8] = 1;
  
  board[3][13] = 1;
  board[4][13] = 1;
  board[5][13] = 1;
  
  board[6][3] = 1;
  board[6][4] = 1;
  board[6][5] = 1;
  
  board[6][9] = 1;
  board[6][10] = 1;
  board[6][11] = 1;
  
  board[8][3] = 1;
  board[8][4] = 1;
  board[8][5] = 1;
  
  board[8][9] = 1;
  board[8][10] = 1;
  board[8][11] = 1;
  
  board[9][1] = 1;
  board[10][1] = 1;
  board[11][1] = 1;
  
  board[9][6] = 1;
  board[10][6] = 1;
  board[11][6] = 1;
 
  board[9][8] = 1;
  board[10][8] = 1;
  board[11][8] = 1;
  
  board[9][13] = 1;
  board[10][13] = 1;
  board[11][13] = 1;
  
  board[13][3] = 1;
  board[13][4] = 1;
  board[13][5] = 1;
  
  board[13][9] = 1;
  board[13][10] = 1;
  board[13][11] = 1;
}

//Gosper Glider Gun
void makeGliderGun(int board[ROWS][COLUMNS]){
  board[5][1] = 1;
  board[5][2] = 1;
  board[6][1] = 1;
  board[6][2] = 1;
  
  board[5][11] = 1;
  board[6][11] = 1;
  board[7][11] = 1;
  board[4][12] = 1;
  board[8][12] = 1;
  board[3][13] = 1;
  board[9][13] = 1;
  board[3][14] = 1;
  board[9][14] = 1;
  board[6][15] = 1;
  board[4][16] = 1;
  board[8][16] = 1;
  board[5][17] = 1;
  board[6][17] = 1;
  board[7][17] = 1;
  board[6][18] = 1;
  
  board[3][21] = 1;
  board[4][21] = 1;
  board[5][21] = 1;
  board[3][22] = 1;
  board[4][22] = 1;
  board[5][22] = 1;
  board[2][23] = 1;
  board[6][23] = 1;
  board[1][25] = 1;
  board[2][25] = 1;
  board[6][25] = 1;
  board[7][25] = 1;
  
  board[3][35] = 1;
  board[4][35] = 1;
  board[3][36] = 1;
  board[4][36] = 1;
}




int main(){
  //Creates board of just zeros
  int board[ROWS][COLUMNS] = {0};
  //creates the array that we will be printing out initializes every entry as null
  char pageArray[ROWS + 5][PAGEWIDTH] = {0};
  //use the clearPageArray function to make the page array all ' ' 
  clearPageArray(pageArray);













  makeGlider(board);
  runGenerations(board, pageArray, 12);
  clearBoard(board);

  makeCheshireCat(board);
  runGenerations(board, pageArray, 10);
  clearBoard(board);
  
  makePulsar(board);
  runGenerations(board, pageArray, 10);
  clearBoard(board);
  
  
  // make sure the board is sufficiently large enough for the glider gun
  makeGliderGun(board);
  runGenerations(board, pageArray, 55);
  clearBoard(board);





  
}     

//http://www.cplusplus.com/doc/tutorial/files/ look here to figure out text file
  


/*  RULES
    If cell is alive and has less than 2 alive neighbors, the cell dies.
    If cell is alive and has 2 or 3 live neighbors the cell stays alive.
    If cell is alive and cell has 4 or greater alive neighbors the cell dies.
    If dead cell has exactly 3 neighbors, the cell becomes alive.
*/
