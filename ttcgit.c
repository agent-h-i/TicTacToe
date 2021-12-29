

#include<stdio.h>
#include<stdlib.h>
#include<time.h>


//declaring all the functions that will be used//
void welcomeMessage();//function to print welcome message
void printgameBoard(char *gameBoard);//prints the initial stage of the board on the screen
int randMove(int move, char update, char *gameBoard);//gets the move from the compuetr
void updateBoard(int move, char update, char *gameBoard);//updates the board with the players move
void resetBoard(char *board);//this function resets the playBoard to its original state
int win_draw(char *gameBoard);//determines if the game is won or drawn
int AiMove(char *gameBoard);//returns the best ai move to be used to update board
int minimax(char *gameBoard, int isMaximizing);//this is  the minimax function to be called recursively to get the best possible move for the computer

int main( ){
    char gameBoard[100] = {'0','1','2','3','4','5','6','7','8','9'};
    //storing the rows and columns of the game board in an array;acts as a reference for the player
    //allocating large amount of memory for the array
    //declaring variables
    int i;
    int move;//initializing the players move as a variable
    //setting up the players characters
    char update1 = 'X';//human player mark
    char update2 = 'O';//ai player mark




    welcomeMessage();
    printgameBoard(gameBoard);//printing this board for the player reference
    resetBoard(gameBoard);
    printf("\nHuman Plays X, and Computer Plays O\n\n");


    printf("Do you want to play against a Human(1), Random AI(2), or Smart AI(3)?\n");
    int choice;
    scanf("%d",&choice);


    if (choice==1){
        for(i=0;i<10;i++){
        ///this series of codes gets the move from the first player, and updates the board
        printf("Player %c Enter a number: ",update1);
        scanf("%d",&move);//getting input from first player
        updateBoard(move,update1, gameBoard);//updating the board
        printgameBoard(gameBoard);//printing the updated boards
        ///this series of codes checks for a winner after the player has inputted their move
        //if the conditions of the if statement is met, player is broken out of the loop
        win_draw(gameBoard);
        if (win_draw(gameBoard)==-1){
            printf("Player X you have won the game!\n");
            break;
        }
        else if(win_draw(gameBoard)==0){
        printf("DRAW!\n");
        break;
        }


        ///this series of codes gets the move from the second player, and updates the board
        printf("Player %c Enter a number: ",update2);
        scanf("%d",&move);//getting input from second plaeyr
        updateBoard(move,update2,gameBoard);//updating the board
        printgameBoard(gameBoard);
        ///this series of codes checks for a winner after the player has inputted their move
        //if the conditions of the if statement is met, player is broken out of the loop
        win_draw(gameBoard);
        if (win_draw(gameBoard)==1){
            printf("Player O you have won the game!\n");
            break;
        }
        else if(win_draw(gameBoard)==0){
        printf("DRAW!\n");
        break;
        }
      }
    }


    else if (choice==2){

    for(i=0;i<10;i++){
    
    ///this series of codes gets the move from the first player, and updates the board
    printf("Player %c Enter a number: ",update1);
    scanf("%d",&move);//getting input from first player
    updateBoard(move,update1,gameBoard);
    printgameBoard(gameBoard);
    ///this series of codes checks for a winner after the player has inputted their move
    //if the conditions of the if statement is met, player is broken out of the loop
    win_draw(gameBoard);
    if (win_draw(gameBoard)==-1){
        printf("Human has won the game!\n");
        break;
    }
    else if(win_draw(gameBoard)==0){
        printf("DRAW!\n");
        break;
    }

    printf("Random Computer Move:\n");
    randMove(move, update2, gameBoard);
    printgameBoard(gameBoard);
    win_draw(gameBoard);
    if (win_draw(gameBoard)==1){
        printf("Random Computer has won the game!\n");
        break;
    }
        else if(win_draw(gameBoard)==0){
        printf(" DRAW!");
        break;
    }
     }
    }


    else if (choice==3){
    
    for(i=0;i<10;i++){
    
    ///this series of codes gets the move from the first player, and updates the board
    printf("Player %c Enter a number: ",update1);
    scanf("%d",&move);//getting input from first player
    updateBoard(move,update1,gameBoard);
    printgameBoard(gameBoard);
    ///this series of codes checks for a winner after the player has inputted their move
    //if the conditions of the if statement is met, player is broken out of the loop
    win_draw(gameBoard);
    if (win_draw(gameBoard)==-1){
        printf("Human has won the game!\n");
        break;
    }
    else if(win_draw(gameBoard)==0){
        printf("DRAW!\n");
        break;
    }

    printf("Smart Computer Move:\n");
    move = AiMove(gameBoard);
    updateBoard(move, update2, gameBoard);
    printgameBoard(gameBoard);
    win_draw(gameBoard);
    if (win_draw(gameBoard) == 1){
        printf("Smart Computer has won the game!\n");
        break;
        }
    else if(win_draw(gameBoard)==0){
        printf(" DRAW!\n");
        break;
        }
    
      }
      }
  printf("\nTHANK YOU FOR PLAYING!\n");
 }






void welcomeMessage(){
    printf("\n\tWelcome to TIC TAC TOE\t\n");
    printf("\n");
    printf("\n\tTHIS GAME IS ONLY FOR HUMAN AND COMPUTER PLAYERS\t\n");
    printf("Preparing your board\n");
    printf("\n");
    printf(".\n");
    printf("..\n");
    printf("...\n");
    printf("\n");
    printf("Board generated!\n\n");
}


void printgameBoard(char *gameBoard){
   
    printf("\n");
    printf("  %c  |  %c  |  %c  \n",gameBoard[1],gameBoard[2],gameBoard[3]);//six spaces between the each line
    printf("-----------------\n");//splitting the board
    printf("  %c  |  %c  |  %c  \n",gameBoard[4],gameBoard[5],gameBoard[6]);
    printf("-----------------\n");
    printf("  %c  |  %c  |  %c  \n",gameBoard[7],gameBoard[8],gameBoard[9]);
    printf("\n");
}



void updateBoard(int move, char update, char *gameBoard){
    //in this series of statements, we are taking the input(move) from the user and using it to update the board with their choice
    //if the users move is 1, and the value printed on th board is one, the gameboard[1]
    //the concept repeats for the rest of the statemens

    if (move == 1 && gameBoard[1] == ' '){
    gameBoard[1]= update;
    }
    else if ( gameBoard[move] == ' '){
        gameBoard[move]= update;
    }
    else {printf("Invalid input :[");}
}



int win_draw( char *gameBoard){
  //this function checks for the players win
  //if the place on the gameboard is not empty and the characters, horizontally, vertically, diagonally match, then a value is returned

  //checking for win in the horizontal row
    if (gameBoard[1] != ' ' && gameBoard[1] == gameBoard[2] && gameBoard[2] == gameBoard[3]){
        if(gameBoard[1]=='X'){return -1;}
        else if(gameBoard[1]=='O'){return 1;}
    }

    else if (gameBoard[4] != ' ' && gameBoard[4] == gameBoard[5] && gameBoard[5] == gameBoard[6]){
        if(gameBoard[4]=='X'){return -1;}
        else if(gameBoard[4]=='O'){return 1;}
    }

    else if(gameBoard[7]!= ' ' && gameBoard[7]==gameBoard[8] && gameBoard[8]==gameBoard[9]){
        if(gameBoard[7]=='X'){return -1;}
        else if(gameBoard[7]=='O'){return 1;}
    }

    //checking for win in vertical row
    else if(gameBoard[1] != ' ' && gameBoard[1]==gameBoard[4] && gameBoard[4]==gameBoard[7]){
        if(gameBoard[1]=='X'){return -1;}
        else if(gameBoard[1]=='O'){return 1;}
    }
    else if (gameBoard[2] != ' ' && gameBoard[2] == gameBoard[5] && gameBoard[5]==gameBoard[8]){
        if(gameBoard[2]=='X'){return -1;}
        else if(gameBoard[2]=='O'){return 1;}
    }   
    else if (gameBoard[3] != ' ' && gameBoard[3]==gameBoard[6] &&gameBoard[6]==gameBoard[9]){
        if(gameBoard[3]=='X'){return -1;}
        else if(gameBoard[3]=='O'){return 1;}
    }

    //checking for win in diagonal row

    else if(gameBoard[1] != ' ' && gameBoard[1]==gameBoard[5] && gameBoard[5]==gameBoard[9]){
        if(gameBoard[1]=='X'){return -1;}
        else if(gameBoard[1]=='O'){return 1;}
    }
    else if(gameBoard[3] != ' ' && gameBoard[3]==gameBoard[5] && gameBoard[5]==gameBoard[7]){
        if(gameBoard[3]=='X'){return -1;}
        else if(gameBoard[3]=='O'){return 1;}
    }

//checking if here is no match for any of the values
//if all the places on the gameboard are not empty a value is returned
//if the conditions of this statement is satisfied, 0 is returned
else if(gameBoard[1]!=' '&&gameBoard[2]!=' '&&gameBoard[3]!=' '&&gameBoard[4]!=' '&&gameBoard[5]!=' '&&gameBoard[6]!=' '&&gameBoard[7]!=' '&&gameBoard[8]!=' '&&gameBoard[9]!=' '){
    return 0;
}

//this statement returns 3 if all the conditions of the above statements are not met
else{
    return 3;
}

}




int randMove(int move, char update, char *gameBoard){


    while(1){//this serves are a loop to make sure board is only choosing legal moves
    ///this part of the code generates a random number to be used as the computers move
    move = 1+(10.0*rand())/(RAND_MAX+1.0);
    
    if(gameBoard[move] != ' '){
        continue;}//tells the computer to jump back to the top of the loop  if the generated move has already been taken up on the board
    //this part fo the function is simialr to the update board function
    else if (move == 1 && gameBoard[1] == ' '){
    gameBoard[1]= update;
    break;
    }
    else if(move == 2 && gameBoard[2] == ' '){
    gameBoard[2]=update;
    break;
    }
    else if(move == 3 && gameBoard[3] == ' '){
    gameBoard[3]=update;
    break;
    }
    else if(move == 4 && gameBoard[4] == ' '){
    gameBoard[4]=update;
    break;
    }
    else if(move == 5 && gameBoard[5] == ' '){
    gameBoard[5]=update;
    break;
    }
    else if(move == 6 && gameBoard[6] == ' '){
    gameBoard[6]=update;
    break;
    }
    else if(move == 7 && gameBoard[7] == ' '){
    gameBoard[7]=update;
    break;
    }
    else if(move == 8 && gameBoard[8] == ' '){
    gameBoard[8]=update;
    break;
    }
    else if(move == 9 && gameBoard[9] == ' '){
    gameBoard[9]=update;
    break;
    }
   }
   
}



void resetBoard(char *gameBoard){
//resetting the board by looping through each spaces on the board and replacing it with an empty character
    int j;
    for (j=0;j<11;j++){
        gameBoard[j] = ' ';
    }

}



int AiMove(char *gameBoard){
  int bestScore = -1000; 
  int bestaiMove=0;//initial move of the ai
  int score;//score of the move

  for(int i=1;i<10;i++){//lopping over the arrays
    if (gameBoard[i] == ' '){//checking cell if empty
      gameBoard[i] = 'O';//if the board at this position of the loop is empty, th board should be fileld with this move
      score = minimax(gameBoard, 0 );//calling the minimax function recursively to return a score for the move made
      gameBoard[i]=' ';//setting this position to its initial state again
      if(score > bestScore){//if the conditions of this statement is met,
        bestScore = score;//the current score is set to the best score 
        bestaiMove = i;//and the current move is set to the best move
      }
    }
  }
  return bestaiMove;//this returns the bets ai move to be used in the update baord function later on
}




/*//////////MINIMAX GAME THEORY EXPLANATION//////////
In this game, the minimax algorithm is used to generate moves for the opponent player which will prevent the human player from winning.
When the minimax function is called, it will check for a winning move (terminal state) in the current game and assign a score accordingly.
In order for the AI to win, it should gain the highest possible score hence, making the best move accordingly.
When the minmax function is called, the computer will play the tictactoegame against itself(based on the current board state) to obtain the highest score possible.
In the game that the computer plays against itself(based on the current board state), there is a Maximising player (which aims to score the highest possible score) and a Minimizing player (the opponent, which aims to score the lowest possible score), and both these players play to win.
Based on the game it plays, it will return the score of the Maximizing player which will be converted into the best move for the computer to make.
//////////////////////////////////////////////////*/



int minimax(char *gameBoard, int isMaximizing){
  int score;
  int bestScore;
  int i;


  /////CHECKING FOR TERMINAL STATE////////
  score = win_draw(gameBoard);
    if(score == -1){
        return score;//returns a low value if the human player has won
      }
    else if (score == 1){//if 'O' wins, 2 is returned form the win_draw function and the score returned is 1
        return score;//returns a high value if the ai player ahs won the game
      }
    else if (score==0){
        return score;//returns 0 if the game is draw
      }
  //////////////////////////////////////

////////////////FOR THE MAXIMIZING PLAYER TO WIN////////////////////////////////////
///the value returned from this series of codes will be used as the best move for the AI to win
    
///this series of codes are to check if the ai  has won or in a position to win and returns a high number so the ai can use it later on
  if(isMaximizing==1){//checking if the ai is currently the maximizing player who will get the highest score,
    bestScore = -100;//setting the best score to -100, a low number
    
    for(i=1;i<10;i++){// looping through the gameBoard array 
      if (gameBoard[i] == ' '){//checking if this cell is empty
        gameBoard[i] = 'O';//placing this spot as the computer move 
        score = minimax(gameBoard, 0);//calling the minimax function to return a score for the move made
        gameBoard[i]=' ';//setting this position to its initial empty state again
        if(score > bestScore){//if the conditions of this statement is met, the current score is set to the best score and the current move is set tot eh best move
          bestScore = score;
        }
      }
    }
  return bestScore;
  }

//////////////////////////FOR THE MINMIZING PLAYER TO WIN/////////////////////////////////////////////////////////////
//the value returned from this series of codes is used by the maximzing player to block the opponents move

 else{//if the minimizing player is playing
  bestScore = 100;//setting the best score to 100, a high number
  
  for(i=1;i<10;i++){//only looping throught the empty cells
    if (gameBoard[i] == ' '){//checking cell if its empty
      gameBoard[i] = 'X';//placing this spot as the computer
      score = minimax(gameBoard, 1);//calling the minimax function to return a score for the move made
      gameBoard[i]=' ';//setting this position to its initial empty state again
      if(score < bestScore){//if the conditions of this statement is met, the current score is set to the best score and the current move is set tot eh best move
        bestScore = score;
        }
      }
    }
  return bestScore;
 }

 
}
