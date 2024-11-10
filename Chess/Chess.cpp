// Create ChessBoard
// Two palyer with alternate turns
// Chess Characters
// Assign movements rules for each indicidual chess characters

# include <iostream>
# include <string>
# include <algorithm>
# include <vector>
#include <cctype>

using namespace std;

// Bulid the characters for the chess
class ChessCharacters{
    public: 

    // Each set of chess pieces for the players 
    string ChessPieces[16] = {"K","Q","R","R","B","B","H","H","P","P","P","P","P","P","P","P"}; //Total Chess Pieces

    //Name of the characters
    string FindChessCharacter( char thischaracter){
        string thischaractername;
        switch (thischaracter){
          case 'K':
            thischaractername = "King";
            break;
          case 'Q' :
            thischaractername = "Queen";
            break;
          case 'R':
            thischaractername = "Rook";
            break;
          case 'B' :
            thischaractername = "Bishop";
            break;
          case 'H':
            thischaractername = "Knight";
            break;
          case 'P' :
            thischaractername = "Pawn";
            break;
        }
    return thischaractername; // return the value back 
    }
    
    // positions of the characters when the game is started
    string GetChessBoardPosition(int thisrow, int thiscol){
       string thischesscharacter;
        if (thisrow == 1){
           thischesscharacter = "BP";
        } else if(thisrow == 6){
            thischesscharacter = "WP";
        } else {
            switch (thiscol){
                case 7:
                  thischesscharacter = (thisrow == 0) ? "BR": "WR";
                  break;
                case 0:
                  thischesscharacter = (thisrow == 0) ? "BR": "WR";
                  break;
                case 6:
                  thischesscharacter = (thisrow == 0) ? "BH": "WH";
                  break;
                case 1:
                  thischesscharacter = (thisrow == 0) ? "BH": "WH";
                  break;
                case 5:
                  thischesscharacter = (thisrow == 0) ? "BB": "WB";
                  break;
                case 2:
                  thischesscharacter = (thisrow == 0) ? "BB": "WB";
                  break;
                case 3:
                  thischesscharacter = (thisrow == 0) ? "BQ": "WQ";
                  break;
                case 4:
                  thischesscharacter = (thisrow == 0) ? "BK": "WK";
                  break;
            }
        }
      return thischesscharacter;
    }
    
    //ChangeRowAlphabetToNumeric

    //In chess board (x,y) position is used as in graph. 
    //We have used matrix system to store the values of chessboard,
    //Hence, we have to change the chess board position to matrix based system.
    // This means we will have to swap the rows & column loaction & susbtract it by one
    // For example, (b2) position in chessboard will be (6,1) in our matrix storage system
    
    int GetColPositionFromInputChessLocation(string thisinputvalue){
        char thiscolchar = thisinputvalue[0]; // the second value in the chessboard represents the row in teh matrix.
          int thiscolvalue;
            switch (thiscolchar){
                case 'A':
                  thiscolvalue = 0 ;
                  break;
                case 'B':
                  thiscolvalue = 1;
                  break;
                case 'C':
                  thiscolvalue = 2;
                  break;
                case 'D':
                  thiscolvalue = 3;
                  break;
                case 'E':
                  thiscolvalue = 4;
                  break;
                case 'F':
                  thiscolvalue = 5;
                  break;
                case 'G':
                  thiscolvalue = 6;
                  break;
                case 'H':
                  thiscolvalue = 7;
                  break;
            }
          return thiscolvalue;  
        }

        // rows ar in alphabet so change that to numeric 
    int GetRowPositionFromInputChessLocation(string thisinputvalue){
        char thisrowchar = thisinputvalue[1]; // the second value in the chessboard represents the row in teh matrix.
          int thisrowvalue;
            switch (thisrowchar){
                case '8':
                  thisrowvalue = 0 ;
                  break;
                case '7':
                  thisrowvalue = 1;
                  break;
                case '6':
                  thisrowvalue = 2;
                  break;
                case '5':
                  thisrowvalue = 3;
                  break;
                case '4':
                  thisrowvalue = 4;
                  break;
                case '3':
                  thisrowvalue = 5;
                  break;
                case '2':
                  thisrowvalue = 6;
                  break;
                case '1':
                  thisrowvalue = 7;
                  break;
            }
          return thisrowvalue;  
        }
};

string ChessBoard[8][8] = {{"","","","","","","",""},
                          {"","","","","","","",""},
                          {"","","","","","","",""},
                          {"","","","","","","",""},
                          {"","","","","","","",""},
                          {"","","","","","","",""},
                          {"","","","","","","",""},
                          {"","","","","","","",""},};


string WChessCharacter[16]; //This will act as a container for white chessboard caharcters /. Idea is that as game go-on the chess pieces are removed & added accordingly. 
string BChessCharacter[16];  // This will act as a container for black chessboard characters


string UserPlayerName1; //User will input name && first user input will automatically be for white chess characters.
string UserPlayerName2; //PlayerB
string PlayerW = "W"; //Chess Player //PlayerW >> for whitechess board && PlayerB for black chess board
string PlayerB = "B";
string PlayerTurn;  //Always playerW will go first 
string UserMove;  //the move of the user like a1, b1 ,c2 
string OldUserMove;
string ChessPeiceSelect; // the chess peice the user wants to move
string GameWinner;
string ErrorMoveMessage;  // Will store the error message to output for any moves thats invalid



bool EndGame; // This will end the loop of the game // We could implement something like giving up the chess game as well. 
bool GameDrawn; // True game is drawn // False thereis winner

int row; // row will denote a,b,c,d,e,f,g,h
int col; // col will denote 1,2,3,4,5,6,7,8
int oldrow; // where the char was moved from
int oldcol; // where the char was moved from 


// This will be chessboard ouline.
ChessCharacters myObj;

void ChessBoardOutline(){
    for (int i = 0; i < 8; i++) {
      cout << "_________________________\n" ; 
        for (int j = 0 ; j < 8; j++) {
                cout << "| "  << ChessBoard[i][j] ;
        }       
      cout << "|" << endl;
    }
  cout << "_________________________\n" << endl;  
}


// Game has started assign the chess board to start the game. Used at the start of the game. 
void ArrangeChessBoard(){

  // Assign the chess characters to the indicidual chess containers
    for (int a = 0; a < 16; a++) {
        //ChessCharacters myObj;
        WChessCharacter[a] = "W" + myObj.ChessPieces[a];
    }
         
      // Assign the chess characters to the indicidual chess containers
    for (int a = 0; a < 16; a++) {
        //ChessCharacters myObj;
        BChessCharacter[a] = "B" + myObj.ChessPieces[a];
    }
                
  // Arrange the chess board
    for (int i = 0; i < 8; i++) {
        if (i == 1 || i == 6 || i == 7 ||i == 0){
            for (int j = 0 ; j < 8; j++) {
                  //ChessCharacters myObj; // OPen the class & look for what characters goes into the position. 
                  ChessBoard[i][j] = myObj.GetChessBoardPosition(i,j);
            } 
        }  
    }
}


//Assign player their turn. Could use simple turnary function but 
// keeping it separte for better understanding
void ChangePlayerTurn(){
    if (PlayerTurn == "W"){
      PlayerTurn = "B";
    } else { 
      PlayerTurn = "W";
    }
}

//After the selection of the chracter & move by user. FInd its location in the board so that it can be emptied out.
void FindCharacterPosition(string ThisChessPeiceSelect){
    for (int i = 0; i < 8; i++) {
        for (int j = 0 ; j < 8; j++) {
              string tmpchessboard = ChessBoard[i][j];
                if (tmpchessboard == ThisChessPeiceSelect){ //assign the old loaction 
                   oldrow = i;
                   oldcol = j;
                  break;
                }
        }  
    } 
}

int CountCharacterFromUserContainer(string thisselectedcharacter){
  int valuetoreturn;
  char thisplayer = thisselectedcharacter[0]; // First letter reperecents player
   if (thisplayer == 'W'){
      for ( int i = 0; i < 16; i++){
        string thischaracter = WChessCharacter[i];
            if (thischaracter == thisselectedcharacter){
                valuetoreturn = valuetoreturn + 1;
            }
      }
  } else {
      for ( int i = 0; i < 16; i++){
        string thischaracter = BChessCharacter[i];
           if (thischaracter == thisselectedcharacter) {
            valuetoreturn = valuetoreturn + 1; 
          }
      }
  }
  return valuetoreturn;  
}


// Using the location position of the user, get what the character is from the matrix chess board
// The input assumption is in format (a2) or from the user input.
string GetCharacterUsingLocation (string thischaracterlocation){ 
  //ChessCharacters myObj;
  int thisrows = myObj.GetRowPositionFromInputChessLocation(thischaracterlocation);
  int thiscols = myObj.GetColPositionFromInputChessLocation(thischaracterlocation);  
  
 string selectedcharacterlocation = ChessBoard[thisrows][thiscols];
  return selectedcharacterlocation;
}

//Check if the provided location is empty
bool IsTheSelectedLocationEmpty (string thischaracterlocation){
  bool valuetoreturn;
  //ChessCharacters myObj;
  int thisrows = myObj.GetRowPositionFromInputChessLocation(thischaracterlocation);
  //ChessCharacters myObj;
  int thiscols = myObj.GetColPositionFromInputChessLocation(thischaracterlocation); 
  
  string selectedcharacterlocation = ChessBoard[thisrows][thiscols];

    if (selectedcharacterlocation == "" || selectedcharacterlocation.empty()) {
      valuetoreturn = true;
    } 
  return valuetoreturn;
}


// Check if the provided location is empty using numeric row & column.
bool IsTheSelectedLocationEmptyUseRowAndColumn (int rowinfo, int colinfo){
  bool valuetoreturn;

  string selectedcharacterlocation = ChessBoard[rowinfo][colinfo];

    if (selectedcharacterlocation == "" || selectedcharacterlocation.empty()) {
      valuetoreturn = true;
    } 
  return valuetoreturn;
}


// After validating the move check if the selected location is empty or not. 
bool OkayToMakeTheMove (string MoveSelectedByUser, string CharacterSelectedByUser){
    bool valuetoreturn;
    // Now check if the new selected move is occupied or not. Can't move into same colour character space,
    string CharacterInNewMove = GetCharacterUsingLocation(MoveSelectedByUser);

    if (CharacterInNewMove != "" || !CharacterInNewMove.empty()) {
        // The location selected is occupied, now check if the location is occupied by opponent user.
        // If occupied by opponent then okay to make the move else. Can't make the move.
          if (CharacterSelectedByUser[0] == CharacterInNewMove[0]){
                valuetoreturn = false;
          } else {
                valuetoreturn = true;
          }
    } else {
      valuetoreturn = true;
    } 
  return valuetoreturn;
}


// check if there is any character between selected moves, keep the row constant & evaluate for changing column.
// Used for rook & Queen moves
bool CheckForCharacterBetweenColWithConstRow(int rowinfo, int colinfo, int targetcolinfo){
  bool valuetoreturn = true; // set the default to true if any box is filled then assign false and get out of the loop

  if (colinfo > targetcolinfo) {
      int i = colinfo - 1;
      for (i; i > targetcolinfo; i--){
            if (!IsTheSelectedLocationEmptyUseRowAndColumn(i,rowinfo)){
               valuetoreturn = false;
               break; 
            }
      }
  } else {
      int i = colinfo + 1;
      for (i; i < targetcolinfo; i++){
            if (!IsTheSelectedLocationEmptyUseRowAndColumn(i,rowinfo)){
               valuetoreturn = false;
               break; 
            }
      }
  }
  return valuetoreturn;
}

// Used for rook & Queen moves
// check if there is any character between selected moves, keep the col constant & evaluate for changing column.
bool CheckForCharacterBetweenRowWithConstCol(int rowinfo, int targetrowinfo , int colinfo){
  bool valuetoreturn = true; // set the default to true if any box is filled then assign false and get out of the loop

  if (rowinfo > targetrowinfo) {
      int i = rowinfo - 1;
      for (i; i > targetrowinfo; i--){
            if (!IsTheSelectedLocationEmptyUseRowAndColumn(i,colinfo)){
               valuetoreturn = false;
               break; 
            }
      }
  } else {
      int i = rowinfo + 1;
      for (i; i < targetrowinfo; i++){
            if (!IsTheSelectedLocationEmptyUseRowAndColumn(i,colinfo)){
               valuetoreturn = false;
               break; 
            }
      }
  }
  return valuetoreturn;
}

// check for Bishop style movement// seperated this as this will be useful for Queen movement as well. 
bool CheckForBishopStyleMovement(int rowinfo, int targetrowinfo , int colinfo, int targetcolinfo){
  bool valuetoreturn = true; // set the default to true if any box is filled then assign false and get out of the loop
  int newrow;
  int newcol;

    int j = (rowinfo < targetrowinfo) ? j = targetrowinfo - rowinfo : j = rowinfo -  targetrowinfo ;
    for (int i = 1; i < j; i++){
        newrow = (rowinfo < targetrowinfo) ? newrow = rowinfo + i : newrow = rowinfo - i;
        newcol = (colinfo < targetcolinfo) ? newcol = colinfo + i : newcol = colinfo - i;
            if (!IsTheSelectedLocationEmptyUseRowAndColumn(newrow,newcol)){
               valuetoreturn = false;
               break; 
            }
         }
  return valuetoreturn;
}


/// Implement the formula to make moves for the characters.
/// Idea is that after the move is selected the formula will check if the move is valid. 
// If not valid it will prompt to either change the selected location by user or change the character

//FORMULA FOR MOVES 

// These will check the move for the king
bool CheckTheMoveForKing (string MoveMadeByUser, string SelectedCharacter){
    // set default value to return to be false
    bool valuetoreturn = false;
    
    char PlayerSelected = SelectedCharacter[0];
    char CharacterSelected = SelectedCharacter[1];
    
    int thisrows = row;
    int thiscols = col; 

    int thisoldrows = oldrow;
    int thisoldcols = oldcol;

      if ((thisrows - thisoldrows) > 1 || (thisrows - thisoldrows) < -1 || (thiscols - thisoldcols) > 1 || (thiscols - thisoldcols) < -1){ //King can only move one position in either direction 
        ErrorMoveMessage = "Wrong move for King make next move";
      } else {
        // Check the intended loaction 
        if (OkayToMakeTheMove(MoveMadeByUser, SelectedCharacter)){
            valuetoreturn = true;
        }
      }
    return valuetoreturn;
}

// This move is for knight
bool CheckTheMoveForKnight(string MoveMadeByUser, string SelectedCharacter){
      // set default value to return to be false
    bool valuetoreturn = false;
    
    char PlayerSelected = SelectedCharacter[0];
    char CharacterSelected = SelectedCharacter[1];

    int thisrows = row;
    int thiscols = col; 

    int thisoldrows = oldrow;
    int thisoldcols = oldcol;

    // the move of the knight will always have move (x +- 2, y+- 1) or (x +- 1 , y +- 2). SO, if has to be within 2*2 square box everyhting else is false. 
      if ((thisrows - thisoldrows) > 2 || (thisrows - thisoldrows) < -2 || (thiscols - thisoldcols) > 2 || (thiscols - thisoldcols) < -2 ){ //King can only move one position in either direction 
        ErrorMoveMessage = "Wrong move for Knight make next move";
      } else {
          if ((thisrows - thisoldrows) == -2 || (thisrows - thisoldrows) == 2){
              if ((thiscols - thisoldcols) == -1 || (thiscols - thisoldcols) == 1){
                  // Now check if the new selected move is occupied or not. Can't move into same colour character space,
                  if (OkayToMakeTheMove(MoveMadeByUser, SelectedCharacter)){
                      valuetoreturn = true;
                  }
              }
          } else{
              if ((thiscols - thisoldcols) == -2 || (thiscols - thisoldcols) == 2){
                 // Now check if the new selected move is occupied or not. Can't move into same colour character space,
                  if (OkayToMakeTheMove(MoveMadeByUser, SelectedCharacter)){
                      valuetoreturn = true;
                  } 
              }      
          }
      }
    return valuetoreturn;
}


// These will check the move for the pawn
bool CheckTheMoveForPawn (string MoveMadeByUser, string SelectedCharacter){
    // set default value to return to be false
    bool valuetoreturn = false;
    
    char PlayerSelected = SelectedCharacter[0];
    char CharacterSelected = SelectedCharacter[1];

    int thisrows = row;
    int thiscols = col; 

    int thisoldrows = oldrow;
    int thisoldcols = oldcol;
    
     // Firstly, check for direction of movement of pawn. pawn move is unidirectional means can only move in one direction.
     bool CorrectDirectionalMove;
     if (PlayerSelected == 'B'){
     // Black pawn chess characters will start at (1) position in our matrix chess board.
       if (thisoldrows < thisrows){
          CorrectDirectionalMove = true; //moving forward assign true
       }
     } else {
       if (thisoldrows > thisrows){   // White pawn chess characters will strart at (6) position in our matrix chess board
          CorrectDirectionalMove = true; //moving forward assign true
       }
     }

      
      // Only Move ahead if direction is correct.
     if(!CorrectDirectionalMove){
        ErrorMoveMessage = "Make move in right direction";
     } else {

          if ((thisrows - thisoldrows) > 2 || (thisrows - thisoldrows) < -2 || (thiscols - thisoldcols) > 1 || (thiscols - thisoldcols) < -1) { //Pawn can only move one position in either direction 
            cout << "Wrong move make next move";
          } else {
            // First Make Sure the location infront of pawn is empty.
            // Get current location && check one step ahead.

            //Check for move where it attacks opponenet. 
            if (((thiscols - thisoldcols) == 1 || (thiscols - thisoldcols) == -1) && ((thisrows - thisoldrows) == 1 || (thisrows - thisoldrows) == -1)){
                // Can only make this move if there is opponent character. 
                if (IsTheSelectedLocationEmpty(MoveMadeByUser)){
                    ErrorMoveMessage = "Invalid Move for the pawn";
                } else {
                    // There is character now check if it is opponent character.
                    string thischaracter = GetCharacterUsingLocation(MoveMadeByUser);
                    //if the player selected & Opponent character is different. move is valid.
                    if (PlayerSelected != thischaracter[0]){
                        valuetoreturn = true;
                    } else {
                      ErrorMoveMessage = "Invalid Move for the pawn";
                    }   
                }

            } else {
               // here the move is either one step ahead or two step ahead,
               // Need to make sure the location ahead is empty.
                  bool thislocationvalue;
                  if (PlayerSelected == 'B'){
                    thislocationvalue = IsTheSelectedLocationEmptyUseRowAndColumn ((thisoldrows + 1) , thisoldcols);
                  } else {
                    thislocationvalue = IsTheSelectedLocationEmptyUseRowAndColumn ((thisoldrows - 1) , thisoldcols);
                  }
                  
                  if (!thislocationvalue){
                    ErrorMoveMessage = "Selected Move can't be made.";
                  } else {
                      if (((thisrows - thisoldrows) == 1 || (thisrows - thisoldrows) == -1)){
                          // as move is one step ahead its okey to make the move
                          valuetoreturn = true;  
                      } else {
                          // move is two step ahed check for that
                          if (IsTheSelectedLocationEmpty(MoveMadeByUser)){
                            valuetoreturn = true;
                          } else {
                            ErrorMoveMessage = "Invalid Move for the pawn";
                          }
                      
                      }
                  }    
            }
          }
      }
    return valuetoreturn;
}


// These will check the move for the Rook
bool CheckTheMoveForRook (string MoveMadeByUser, string SelectedCharacter){
    // set default value to return to be false
    bool valuetoreturn = false;
    
    char PlayerSelected = SelectedCharacter[0];
    char CharacterSelected = SelectedCharacter[1];

    int thisrows = row;
    int thiscols = col; 

    int thisoldrows = oldrow;
    int thisoldcols = oldcol;
    
      // rook can only travel acroos the column or rows. If not within that range than wrong move
      if (thisrows != thisoldrows && thiscols != thisoldcols) { 
        ErrorMoveMessage = "Wrong move for Rook ";
      } else {
         if (thisrows == thisoldrows){ //move is along the row
            if (CheckForCharacterBetweenColWithConstRow(thisrows, thisoldcols, thiscols) && OkayToMakeTheMove(MoveMadeByUser, SelectedCharacter)){
               // if the rows are empty & the selected row is empty make the move else invalid move.
               valuetoreturn = true;
            }

         } else {  //move is along the col
            if (CheckForCharacterBetweenRowWithConstCol(thisoldrows, thisrows, thiscols) && OkayToMakeTheMove(MoveMadeByUser, SelectedCharacter)){
               // if the cols are empty & the selected col is empty make the move else invalid move.
               valuetoreturn = true;
            }
         }
      }
    return valuetoreturn;
}


// These will check the move for the Bishop
bool CheckTheMoveForBishop (string MoveMadeByUser, string SelectedCharacter){
    // set default value to return to be false
    bool valuetoreturn = false;
    
    char PlayerSelected = SelectedCharacter[0];
    char CharacterSelected = SelectedCharacter[1];

    int thisrows = row;
    int thiscols = col; 

    int thisoldrows = oldrow;
    int thisoldcols = oldcol;

    int rowdiff = (thisrows < thisoldrows) ? rowdiff = thisoldrows - thisrows : rowdiff = thisrows - thisoldrows;
    int coldiff = (thiscols < thisoldcols) ? coldiff = thisoldcols - thiscols : coldiff = thiscols - thisoldcols;

    // bishop will always travel with (x +- n , y +- n). Hence, the difference in rows & col will always be same. 
    if (rowdiff != coldiff){
            ErrorMoveMessage = "Wrong move for bishop ";
    } else {
       if (CheckForBishopStyleMovement(thisoldrows, thisrows, thisoldcols, thiscols) && OkayToMakeTheMove(MoveMadeByUser, SelectedCharacter)){
          valuetoreturn = true;
       } 
    }
    return valuetoreturn;
}


// These will check the move for the Queen
// Queen movement is different as it can move like king, Bishop & rook. 
// So we will check accordingly, 
// Step 1: will check for move like king,
// Step 2: will check for move like Bishop,
// Step 3: will check for move like Rook,

bool CheckTheMoveForQueen (string MoveMadeByUser, string SelectedCharacter){
    // set default value to return to be false
    bool valuetoreturn = false;
    
    char PlayerSelected = SelectedCharacter[0];
    char CharacterSelected = SelectedCharacter[1];

    int thisrows = row;
    int thiscols = col; 

    int thisoldrows = oldrow;
    int thisoldcols = oldcol;
    
    int rowdiff = (thisrows < thisoldrows) ? rowdiff = thisoldrows - thisrows : rowdiff = thisrows - thisoldrows;
    int coldiff = (thiscols < thisoldcols) ? coldiff = thisoldcols - thiscols : coldiff = thiscols - thisoldcols;

    // First we will determine what kind of move it is//
    bool MoveLikeKing; bool MoveLikeRook; bool MoveLikeBishop;
      if (((thisrows - thisoldrows) <= 1 || (thisrows - thisoldrows) >= -1 ) && ((thiscols - thisoldcols) <= 1 || (thiscols - thisoldcols) >= -1 )) { //King can only move one position in either direction 
          // This move is like king, so as long as the selected location is empty or is of oponent character// can make a move
         if (OkayToMakeTheMove(MoveMadeByUser, SelectedCharacter)){
                valuetoreturn = true;
         }

      } else if (rowdiff == coldiff) {
         // Move like a bishop. So, check for the bishop move & check for individual location
         if (CheckForBishopStyleMovement(thisoldrows, thisrows, thisoldcols, thiscols) && OkayToMakeTheMove(MoveMadeByUser, SelectedCharacter)){
          valuetoreturn = true;
         }
          
      } else if(thisrows == thisoldrows || thiscols == thisoldcols){
         // MOve is like a rook. Check against it and output
         if (thisrows == thisoldrows){ //move is along the row
            if (CheckForCharacterBetweenColWithConstRow(thisrows, thisoldcols, thiscols) && OkayToMakeTheMove(MoveMadeByUser, SelectedCharacter)){
               // if the rows are empty & the selected row is empty make the move else invalid move.
               valuetoreturn = true;
            }

         } else {  //move is along the col
            if (CheckForCharacterBetweenRowWithConstCol(thisoldrows, thisrows, thiscols) && OkayToMakeTheMove(MoveMadeByUser, SelectedCharacter)){
               // if the cols are empty & the selected col is empty make the move else invalid move.
               valuetoreturn = true;
            }
         }
          
      } else {
         ErrorMoveMessage = "Wrong move for Queen ";
      }
    return valuetoreturn;
}

void UpdateChessBoard(int CharMovedToRow, int CharMovedToCol, string thischaracter, int CharMovedFromRow, int CharMovedFromCol ){
   // Everything is checked, Update the game
      //a) Character selected is correct
      //b) Move is selected
      //c) Character move is valid
      //d) Move is changed into individual row & col 
      //e) Also, check if the targeted position has opponenets character, if there is then remove it from the board & also from their container.
    
    bool okaytoproceed;

    if (IsTheSelectedLocationEmptyUseRowAndColumn(CharMovedToRow,CharMovedToCol)){
      okaytoproceed = true;
    } else {
      // there is character in the intended location so remove that piece
      string removethischaracter = ChessBoard[CharMovedToRow][CharMovedToCol];
      if (thischaracter[0] != PlayerTurn[0]){ // the character to be removed must be opposite to the current pl;ayer.
          okaytoproceed = true;
          if (PlayerTurn == "W"){
              for(int i = 0; i < 16; i++){
                if (WChessCharacter[i] == removethischaracter){
                    WChessCharacter[i] = ""; //Assign empty string
                }
              }
          } else {  
              for(int i = 0; i < 16; i++){
                if (BChessCharacter[i] == removethischaracter){
                    BChessCharacter[i] = ""; // Assign empty string
                }
              }
          }   
      }
    }
    
    if (okaytoproceed){
        ChessBoard[CharMovedToRow][CharMovedToCol] = thischaracter;
        ChessBoard[CharMovedFromRow][CharMovedFromCol] = "" ; // empty the position as the character was moved
        // switch the player turn  
        // switch the player//Determine player turn && switch play after every successful move
        ChangePlayerTurn(); 
    }
}

bool CheckForWin(){
  // Check if the king has moves left in the chess board
  // Check if the king is removed from the board
  // for now as long as the king is in the chess board the play will continue but change it to something else
  
  return false;
}

// Get the user input and check if it exists in the player character container
// Assumpiton is input character is correct
//
bool CheckCharacterFromUserInputInPlayerContainer(string thisusercharacterinput){
  bool valuetoreturn;
    
    if (thisusercharacterinput[0] != PlayerTurn[0]){
      cout << "Invalid character selection" << endl;
    } else {
      if (PlayerTurn == "W"){
          for ( int i = 0; i < 16; i++){
            string thischaracter = WChessCharacter[i];
                if (thischaracter == thisusercharacterinput){
                  valuetoreturn = true;
                  break; 
                }
          }
      } else {
          for ( int i = 0; i < 16; i++){
            string thischaracter = BChessCharacter[i];
              if (thischaracter == thisusercharacterinput) {
                valuetoreturn = true;
                break; 
              }
          }
      }
    }
  return valuetoreturn;
}

// move has to be made in format of actual chess. Like a1 to b5. b3 to h6. letter will run from a to h & number from 1 to 8.
bool CheckForTheMoveByUser(string thismovemade){

  bool valuetoreturn;
  string chessboardcolnumbering = "ABCDEFGH";
  char thisfirstletter = thismovemade[0];
  char thissecondletter = thismovemade[1];
  
  //check for second letter // has to be integer or digit
    if (isdigit(thissecondletter)){
        int thissecondletterint = thissecondletter - '0';
        if (thissecondletterint > 0 || thissecondletterint < 9){
                   // if true do second check 
                  //check for first letter// has to be string
                  size_t pos = chessboardcolnumbering.find(thisfirstletter);
                  if (pos != string::npos){
                    valuetoreturn = true;
                  } else {
                    valuetoreturn = false;
                  }
        }
    } 
  return valuetoreturn;
}

bool GetInputfromUser(){
   
   // a) First make sure the user seletcs only the peices that is avalible to them.
   // b) This will be user based.
   // NOTES
   // Maybe create a running record of the user chess pieces so that it is easier. 
   
   // Loop until correct character is selected //
   string thisplayerturn = PlayerTurn;
   string thisplayerselectedcharacter;
   string thisplayerselectedmove;
   bool MoveMadeIsValid;
    
    while(true){

        // first select the piece the user wants to move. Make sure it is the correct one
        while(true){
          string thisprint = (thisplayerturn == "W")? "WhiteCharacter":"BlackCharacter";
          cout << "Input the peice you want to move of " << thisprint << endl;
          cin >> thisplayerselectedcharacter;
          
            for (size_t i = 0; i < thisplayerselectedcharacter.length(); ++i) {
                thisplayerselectedcharacter[i] = toupper(thisplayerselectedcharacter[i]); // Modify the original string change to all CAP
            }
            
            if (CheckCharacterFromUserInputInPlayerContainer(thisplayerselectedcharacter)){
                break;  
            } else {  
                cout << "Invalid character selection" << endl;
            }
        }
        
        //If character is not King or queen. Check for poisiton in chessboard // or ask for input from user 
        // Check if the location provided by the user & character selection is correct.
        while(true){
          
          if (thisplayerselectedcharacter[1] == 'K' || thisplayerselectedcharacter[1] == 'Q'){
            break;
          } else {
            if (CountCharacterFromUserContainer(thisplayerselectedcharacter) > 1){
              // Ask for input from user to select which character
                string thismove;
                cout << "Input from where you want to move character" << endl;
                cin >> thismove;
                
                  for (size_t i = 0; i < thismove.length(); ++i) {
                      thismove[i] = toupper(thismove[i]); // Modify the original string change to all CAP
                  }

                    int thisrows = myObj.GetRowPositionFromInputChessLocation(thismove);
                    int thiscols = myObj.GetColPositionFromInputChessLocation(thismove);//second letter is column data. // this will be new col
                    string tmpcharacter = ChessBoard[thisrows][thiscols];
                    
                    if (tmpcharacter == thisplayerselectedcharacter){
                      // if move is valid this will store as the current location of the character
                      OldUserMove = thismove;
                      break;  
                    } else {  
                      cout << "Invalid location selection" << endl;
                    }
            }
          }
        }
        
        // after character input check the move user want to make
        // check for user move
        while(true){
          
          cout << "Input the move you want to make:" << endl;
          cin >> thisplayerselectedmove;

            // change the string to capital letters
            for (size_t i = 0; i < thisplayerselectedmove.length(); ++i) {
                thisplayerselectedmove[i] = toupper(thisplayerselectedmove[i]); // Modify the original string
            }
            
            if (CheckForTheMoveByUser(thisplayerselectedmove)){
              break;
            } else {
              cout << "Invalid move made" << endl;
            }
        }   
        
        // if movemadeisvalid is true then assign the golbal varaibles with the local varaiables to make changes to the chess board in next step.
        if (OldUserMove != ""){
            //ChessCharacters myObj;
            oldrow = myObj.GetRowPositionFromInputChessLocation(OldUserMove);//first letter is row data. // this will be new row
            //ChessCharacters myObj;
            oldcol = myObj.GetColPositionFromInputChessLocation(OldUserMove);//second letter is column data. // this will be new col
        } else {
            FindCharacterPosition(thisplayerselectedcharacter); // this function will check for currect location of the selected character then assigns that to global variable
        }
        
        // Assign new location as well. 
        //ChessCharacters myObj;
        row = myObj.GetRowPositionFromInputChessLocation(thisplayerselectedmove);//first letter is row data. // this will be new row
        //ChessCharacters myObj;
        col = myObj.GetColPositionFromInputChessLocation(thisplayerselectedmove);//second letter is column data. // this will be new col


        // MOve is checked & character is checked
        // Now the player is selcted, character is selected, 
        // check if the user move is valid or not.
        // If the selected characters are not king or queen then we need which characters is selected for the move
      char thisselectedcharacter = thisplayerselectedcharacter[1];

        switch (thisselectedcharacter){
              case 'K': //King check for king 
                MoveMadeIsValid = CheckTheMoveForKing(thisplayerselectedmove,thisplayerselectedcharacter);
                break;
              case 'Q' :
                MoveMadeIsValid = CheckTheMoveForQueen(thisplayerselectedmove,thisplayerselectedcharacter);
                break;
              case 'R':
                MoveMadeIsValid = CheckTheMoveForRook(thisplayerselectedmove,thisplayerselectedcharacter);
                break;
              case 'B' :
                MoveMadeIsValid = CheckTheMoveForBishop(thisplayerselectedmove,thisplayerselectedcharacter);
                break;
              case 'H':
                MoveMadeIsValid = CheckTheMoveForKnight(thisplayerselectedmove,thisplayerselectedcharacter);
                break;
              case 'P' :
                MoveMadeIsValid = CheckTheMoveForPawn(thisplayerselectedmove,thisplayerselectedcharacter);
                break;
        }
      
       if (MoveMadeIsValid){
         ChessPeiceSelect = thisplayerselectedcharacter; // character selection 
         break;
       } else {
        // Empty the global variables,, for loop 
          OldUserMove = ""; UserMove = ""; oldrow = 0; oldcol = 0; row = 0; col = 0;
          if (ErrorMoveMessage == "" || ErrorMoveMessage.empty()){
              ErrorMoveMessage = "Move was Invalid !!!. Try Again";
          }
          cout << ErrorMoveMessage << endl;
          // After display of error message smpty assign it be empty
          ErrorMoveMessage = "";
       }
    }
  return MoveMadeIsValid;     
}

int main (){

   //ChessBoardOutline();
   cout << "Welcome To Chess Game" << endl;
   // Here assign the characters to the chess board,
   // Assign the characters to the individual chess collection as well.
   // Maybe print chess board as well. 
   ArrangeChessBoard();
   PlayerTurn = "W"; // Assign player turn // white will go first 

    while(true){
     
      if (GetInputfromUser()){
        // Update the chessboard // use global variable as input
        UpdateChessBoard(row,col,ChessPeiceSelect,oldrow,oldcol);
        
        //Empty the string for new move 
        OldUserMove = "" ;
        UserMove = "";

        // CHeck for win /// if winner break out of the loop to go towards checking of winner.
        //continue on util the winner is selected
        if (CheckForWin()){
           break; // if true for check for win then break out of the loop.
        } else {
          ///Output the new chessboard & continue on .



        } 
      }
    }
    // Give the end result // print the winner & game  board

  if (GameDrawn){
     cout << "Game was a tie: " << endl;
  } else {
      cout << "Game winner is Player: "<< GameWinner << endl;
  }

  //Print the chess board1
  ChessBoardOutline();
  //cout << WChessCharacter[16]; //This will act as a container for white chessboard caharcters /. Idea is that as game go-on the chess pieces are removed & added accordingly. 
  //cout << BChessCharacter[16];
  //Check winnner & print the winner name & final chess board.

  return 0;
}