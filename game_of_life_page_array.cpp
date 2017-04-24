#include <iostream>
#include <iomanip>
using namespace std;
#define PAGEWIDTH 72
#define ROWS 10
#define COLUMNS 10


//adds board to page page
void boardToPage(page[ROWS + 5][PAGEWIDTH], board[ROWS][COLUMNS], boardsOnPageSoFar){
  
  for (int y=0; y < ROWS +2; y++){
    for(int x=0; x < ROWS +2; x++){
      //top or bottom border
      if(y==0 || y++ ROWS +1){
        for(int i= 0; i< COLUMNS +2; i++){
          page[y][i+startingColumn] = '-';
        }
        page[y][startingColumn] = '+';
        page[y][startingColumn + COLUMNS +1] = '+';
      }
      else {
        //creates left and right borders
        if(x==0 || x== COLUMNS +1){
          page[y][x] = '|';
        }
        else {
          if(board[y-1][x-1] ==0){
            page[y][x + startingColumn] = ' ';
          }
          else {
            page[y][x] = 'X';
          }
        }
      }
    }
  }
}

/*
//adds the board to the page
void boardToPage(int board[ROWS][COLUMNS], char page[ROWS + 5][PAGEWIDTH], int startingColumn, int generationsSoFar) {
  
  
  //adds top border
  for(int i = 0; i < COLUMNS +1; i++){
    page[0][i + startingColumn] = '-';
  }
  page[0][startingColumn] = '+';
  page[0][startingColumn + COLUMNS+1] = '+';
  
  
  
  
  for (int y = 0; y < ROWS; ++y){
    for(int x = 0; x <= COLUMNS+2; ++x){

      //creates left and right borders   
      if(x==0 || x == COLUMNS +1){
        page[y+1][x + startingColumn]= '|';
      }
      
      // fills in the rest of the the columns, when x=1 actually looking at board column 0
      else {
        if(board[y][x-1] == 0){
          page[y+1][x + startingColumn] = ' ';
        }
        else {
        page[y+1][x + startingColumn] = 'X';
        cout << board[y][x-1] << "x:" << x <<  "y:" << y << endl;
        }
      }
    }
  }
  
  cout << page[ROWS+1][COLUMNS+1] << endl;
  
    int halfwayPoint = COLUMNS/2;
    int GenDigits[3] ={0};
    
    
    
    
    //gets last number first so has to start in GenDigits[2] and go backwards
    int digitStartingSpot = 2;
    int generationsSoFarCopy = generationsSoFar;
    int digit = 0;
    
    //puts the generation number in an array of size 3 by digit so we can convert to character for the character array
 
    for(int i = 0; i < 3; i++){
      digit = generationsSoFarCopy%10;
      generationsSoFarCopy = generationsSoFarCopy/10;
      GenDigits[digitStartingSpot] = digit;
      digitStartingSpot--;
    }
    
    GenDigits[digitStartingSpot] = digit;
    
    char GenDigitsChar[3] = {0};
    for(int z = 0; z<3; z++){
      if (z == 0 && GenDigits[0] == 0){
        GenDigitsChar[z] = ' ';
      }
      else if (z==1 && GenDigits[0] == 0 && GenDigits[1] == 0){
        GenDigitsChar[z] = ' ';
      }
        
      else{
        if (GenDigits[z] == 0){
          GenDigitsChar[z] = '0';
        }
        else if (GenDigits[z] == 1){
          GenDigitsChar[z] = '1';
        }
        else if (GenDigits[z] == 2){
          GenDigitsChar[z] = '2';
        }
        else if (GenDigits[z] == 3){
          GenDigitsChar[z] = '3';
        }
        else if (GenDigits[z] == 4){
          GenDigitsChar[z] = '4';
        }
        else if (GenDigits[z] == 5){
          GenDigitsChar[z] = '5';
        }
        else if (GenDigits[z] == 6){
          GenDigitsChar[z] = '6';
        }
        else if (GenDigits[z] == 7){
          GenDigitsChar[z] = '7';
        }
        else if (GenDigits[z] == 8){
          GenDigitsChar[z] = '8';
        }
        else {
          GenDigitsChar[z] = '9';
        }
      }
    }
    
      
      
      
      //now GenDigitsChar has the generation number in character form in a size 3 array
    
    
    
    // subtract 3 since using 7 total slots, 3 for "Gen" one for a space, and 3 for the number of generations
    for(int i = 0; i < COLUMNS +1; i++){
    page[ROWS + 1][i + startingColumn] = '-';
    }
  
    //adds the generation to the center of the bottom border
    page[ROWS + 1][startingColumn + halfwayPoint -3] = 'G';
    page[ROWS + 1][startingColumn + halfwayPoint -2] = 'e';
    page[ROWS + 1][startingColumn + halfwayPoint -1] = 'n';
    page[ROWS + 1][startingColumn + halfwayPoint] = ' ';
    page[ROWS + 1][startingColumn + halfwayPoint +1] = GenDigitsChar[0];
    page[ROWS + 1][startingColumn + halfwayPoint +2] = GenDigitsChar[1];
    page[ROWS + 1][startingColumn + halfwayPoint +3] = GenDigitsChar[2];
    page[ROWS + 1][startingColumn] = '+';
    page[ROWS + 1][startingColumn + COLUMNS+1] = '+';
    for(int i = 0; i < halfwayPoint - 3; i++){
      //adds second half of border after the gen number

    }
  
  }
  
  */


void printPage(char page[ROWS + 5][PAGEWIDTH]){
  for(int y = 0; y < ROWS +5; ++y){
    for(int x = 0; x < PAGEWIDTH; ++x){
      if(x == PAGEWIDTH -1){
        cout << endl;
      }
      else{
        cout << page[y][x];
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


//sets all values in page to ' '
void clearpage(char page[ROWS + 5][PAGEWIDTH]){
  for (int y = 0; y < ROWS+5; ++y){
    for(int x = 0; x < PAGEWIDTH; ++x){
      page[y][x] = ' ';
    }
  }
}





//iterates over multiple numOfGenerations
void runGenerations(int board[ROWS][COLUMNS], char page[ROWS + 5][PAGEWIDTH], int numOfGenerations){
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
  
  //the startingColumn will be the width of one board times the number of boards already placed
  int startingColumn = boardsOnPageSoFar * (COLUMNS + 5); 
  
  
  
  
  //add the starting board to page
  boardToPage(board, page, startingColumn, generationsSoFar);
  generationsSoFar ++; 
  boardsOnPageSoFar ++; 
  
  //flag to be used to see if the board changes
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
      printPage(page);
      cout << "This board has reached a static image." << endl;
      cout << "All future generations are identical." << endl << endl << endl << endl;
      break;
    }
    
    //if the page is full, print it, clear it, add the board to the page, and set counter of boards to 1
    else if (boardsOnPageSoFar == boardsPerPage) {
      printPage(page);
      clearpage(page);
      boardToPage(board, page, startingColumn, generationsSoFar);
      boardsOnPageSoFar = 1;
    }
    
    //add board to page
    else {
      boardToPage(board, page, startingColumn, generationsSoFar);
      boardsOnPageSoFar++;
    }
    
    //sets the last gen board to current board
    for (int y = 0; y < ROWS; ++y){
      for(int x = 0; x < COLUMNS; ++x){
        lastGenBoard[y][x] = board[y][x];
        }
      }
  }
  //have to print what is left on final page
  printPage(page);
  clearpage(page);
  
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
  char page[ROWS + 5][PAGEWIDTH] = {0};
  //use the clearpage function to make the page array all ' ' 
  clearpage(page);













  makeGlider(board);
  runGenerations(board, page, 36);
  clearBoard(board);
/*
  makeCheshireCat(board);
  runGenerations(board, page, 10);
  clearBoard(board);
  
  makePulsar(board);
  runGenerations(board, page, 10);
  clearBoard(board);
  
  
  // make sure the board is sufficiently large enough for the glider gun
  makeGliderGun(board);
  runGenerations(board, page, 55);
  clearBoard(board);
*/




  
}     

//http://www.cplusplus.com/doc/tutorial/files/ look here to figure out text file


/* how to get each digit in a number
  int a = 123;
  int digit = 0;
  
  while(a>=10){
    digit = a%10;
    a = a/10;
    cout << digit << endl;
  }
  digit = a;
  cout << digit << endl;  
*/

/*  RULES
    If cell is alive and has less than 2 alive neighbors, the cell dies.
    If cell is alive and has 2 or 3 live neighbors the cell stays alive.
    If cell is alive and cell has 4 or greater alive neighbors the cell dies.
    If dead cell has exactly 3 neighbors, the cell becomes alive.
*/
