/*PRE-PROCESS SPECIFICATIONS */
#include "mesinkata.h"
#include <stdio.h>
#include <assert.h>

/*-------------------------------------------------------------------------------------------------------------*/
/*TYPE DECLARATION */
typedef Kata MatriksKata [100][10];
typedef char boardstate[10];
typedef struct {
	boardstate state;
} StateArray[10];

/*-------------------------------------------------------------------------------------------------------------*/
/*FUNCTIONS & PROCEDURES DECLARATION */
void printBoard(boardstate board);
void printBoard(boardstate board){
    printf("------- CURRENT BOARD STATE --------\n");
    printf("|                                  |\n|");
    for(int i=0; i<=8 ; i++){
        printf("     %c     ", board[i]);
        if (i == 2 || i== 5)
            printf(" |\n|                                  |\n|");
    }
    printf(" |\n|                                  |");
    printf("\n");
    printf("------- CURRENT BOARD STATE --------\n");
    printf("\n");
}

/*
void ChangeBoardH (boardstate* board, int input);
void ChangeBoardH (boardstate* board, int input){
    *board[input] = 'X';
}


void ChangeBoardC (boardstate* board, MatriksKata DFA, int input, int inputc);
void ChangeBoardC (boardstate* board, MatriksKata DFA, int input, int inputc){
   /* printf("CHANGE COMP BOARD ------\n");
    printf("i : %d, j : %d\n", inputc, input);
    for (int k =0; k<=8 ; k++){
        /*printf("%c", DFA[inputc][input].TabKata[k]);
        *board[k] = DFA[inputc][input].TabKata[k];
    }

    printf("NEW BOARD \n");
    printBoard(*board);
    printf("\n");
}*/

int SearchState (boardstate board, MatriksKata DFA);
int SearchState (boardstate board, MatriksKata DFA){
    /* DEBUGGER :   printf("SEARCH STATE --- \n");*/
    int i,j,k;
    boolean found = false;
    boolean match;
    j=0;

    for (i=0; i<=32 && (!found) ; i++){
        /* DEBUGGER :  printf("PASS ROW : %d",i); */

        match = true;
        for(k=0; k<=8 && match ; k++){
            /* DEBUGGER : printf("board = %c DFA = %c\n", board[k], DFA[i][j].TabKata[k]); );*/
            match = board[k] == DFA[i][j].TabKata[k];
        }
        found = match;
    }
    /* DEBUGGER : printf("index gotten from search = %d\n", i-1);*/
    if (found)
        return i-1;
    else
        return -999;
}

void CheckGameState( MatriksKata DFA, int input, int inputc, boolean* Endgame, char *Endstate);
void CheckGameState( MatriksKata DFA, int input, int inputc, boolean* Endgame, char *Endstate){
    /* DEBUGGER :     printf("CHECK GAME STATE %c\n", DFA[inputc][input].TabKata[9]);*/

    if ( input <1 || input >9){
        printf("<SYSTEM MESSAGE> Board placement location doesn't exist or out of range!\n");
        *Endstate = 'E';
    }
    else {
        char cond = DFA[inputc][input].TabKata[9];
        *Endstate = cond;
        /* DEBUGGER :   printf("ENDSTATE IS : %c\n", *Endstate);*/
        if (cond == 'C' )
            *Endgame = true;
        else if (cond == 'D')
            *Endgame = true;}


}

int DFADecree (boardstate board, MatriksKata DFA, int move, boolean* Endgame, char* Endstate );
int DFADecree (boardstate board, MatriksKata DFA, int move, boolean* Endgame, char* Endstate){
    int idx = SearchState(board, DFA);
    if (idx == -999)
        printf("<SYSTEM MESSAGE> INPUT ERROR!!! \n");
    else
        /* UNUSED : ChangeBoardC(board, DFA, move, idx);*/
        CheckGameState(DFA, move, idx, Endgame, Endstate);
    return idx;
}

/*
void CopyTab (boardstate Tin, boardstate* Tout){
    for (int i=0; i<= 8; i++){
            *Tout[i] = Tin[i];
            printf("Tin :%c  Tout :%c", Tin[i], *Tout[i] );
        }
    /*WHY WON'T IT WORK LIKE THIS?
}*/



/*-------------------------------------------------------------------------------------------------------------*/
/*MAIN PROGRAM*/
int main(){
    /*MAIN MENU INTERFACE */
printf(" \n");
printf("TTTTTTTTTTTTTTTTTTTTTTTIIIIIIIIII        CCCCCCCCCCCCC \n");
printf("T:::::::::::::::::::::TI::::::::I     CCC::::::::::::C \n");
printf("T:::::::::::::::::::::TI::::::::I   CC:::::::::::::::C \n");
printf("T:::::TT:::::::TT:::::TII::::::II  C:::::CCCCCCCC::::C \n");
printf("TTTTTT  T:::::T  TTTTTT  I::::I   C:::::C       CCCCCC \n");
printf("        T:::::T          I::::I  C:::::C               \n");
printf("        T:::::T          I::::I  C:::::C               \n");
printf("        T:::::T          I::::I  C:::::C               \n");
printf("        T:::::T          I::::I  C:::::C               \n");
printf("        T:::::T          I::::I  C:::::C               \n");
printf("        T:::::T          I::::I  C:::::C               \n");
printf("        T:::::T          I::::I   C:::::C       CCCCCC \n");
printf("      TT:::::::TT      II::::::II  C:::::CCCCCCCC::::C \n");
printf("      T:::::::::T      I::::::::I   CC:::::::::::::::C \n");
printf("      T:::::::::T      I::::::::I     CCC::::::::::::C \n");
printf("      TTTTTTTTTTT      IIIIIIIIII        CCCCCCCCCCCCC to the \n");
printf("                                                       \n");
printf(" \n");
printf("         tttt                                                 \n");
printf("      ttt:::t                                                 \n");
printf("      t:::::t                                                 \n");
printf("      t:::::t                                                 \n");
printf("ttttttt:::::ttttttt      aaaaaaaaaaaaa       cccccccccccccccc \n");
printf("t:::::::::::::::::t      a::::::::::::a    cc:::::::::::::::c \n");
printf("t:::::::::::::::::t      aaaaaaaaa:::::a  c:::::::::::::::::c \n");
printf("tttttt:::::::tttttt               a::::a c:::::::cccccc:::::c \n");
printf("      t:::::t              aaaaaaa:::::a c::::::c     ccccccc \n");
printf("      t:::::t            aa::::::::::::a c:::::c              \n");
printf("      t:::::t           a::::aaaa::::::a c:::::c              \n");
printf("      t:::::t    tttttta::::a    a:::::a c::::::c     ccccccc \n");
printf("      t::::::tttt:::::ta::::a    a:::::a c:::::::cccccc:::::c \n");
printf("      tt::::::::::::::ta:::::aaaa::::::a  c:::::::::::::::::c \n");
printf("        tt:::::::::::tt a::::::::::aa:::a  cc:::::::::::::::c \n");
printf("          ttttttttttt    aaaaaaaaaa  aaaa    cccccccccccccccc  to the\n");
printf("                                                              \n");
printf("                                                                                                          \n");
printf("TTTTTTTTTTTTTTTTTTTTTTT                 EEEEEEEEEEEEEEEEEEEEEE \n");
printf("T:::::::::::::::::::::T                 E::::::::::::::::::::E \n");
printf("T:::::::::::::::::::::T                 E::::::::::::::::::::E \n");
printf("T:::::TT:::::::TT:::::T                 EE::::::EEEEEEEEE::::E \n");
printf("TTTTTT  T:::::T  TTTTTT   ooooooooooo     E:::::E       EEEEEE \n");
printf("        T:::::T         oo:::::::::::oo   E:::::E              \n");
printf("        T:::::T        o:::::::::::::::o  E::::::EEEEEEEEEE    \n");
printf("        T:::::T        o:::::ooooo:::::o  E:::::::::::::::E    \n");
printf("        T:::::T        o::::o     o::::o  E:::::::::::::::E    \n");
printf("        T:::::T        o::::o     o::::o  E::::::EEEEEEEEEE    \n");
printf("        T:::::T        o::::o     o::::o  E:::::E              \n");
printf("        T:::::T        o::::o     o::::o  E:::::E       EEEEEE \n");
printf("      TT:::::::TT      o:::::ooooo:::::oEE::::::EEEEEEEE:::::E \n");\\\
printf("      T:::::::::T      o:::::::::::::::oE::::::::::::::::::::E \n");
printf("      T:::::::::T       oo:::::::::::oo E::::::::::::::::::::E \n");
printf("      TTTTTTTTTTT         ooooooooooo   EEEEEEEEEEEEEEEEEEEEEE \n");
printf("                                                               \n");

printf(" \n");
	BEGIN: //LOOP START POINT//
    printf("~~~~~WELCOME TO THE-TIC-TO-THE-TAC-TO-THE-TOE~~~~~~\n");
    printf("~A FANTASTIC GAME WHERE YOU CAN\'T WIN AT ALL~\n");
    printf("\n");
    boardstate board = {'1','2','3','4','5','6','7','8','9'};
    printBoard(board);

    /*
    board[4] ='X';
    printBoard(board);
    printf("\n");

    boardstate dummy2;
    for (int i=0; i<= 8; i++){
            dummy2[i] = board[i];
            printf("Tin :%c  Tout :%c", board[i], dummy2[i] );
        }
    printBoard(dummy2);
    printf("\n");*/

    printf("<SYSTEM MESSAGE> : WHO SHALL GO FIRST?\n");
    printf("input options : H or C (H means U first, C means computer first)\n");
    char firstTurn;
    scanf(" %c", &firstTurn);
    MatriksKata DFA;
    StateArray statelist;
    int neff= 0;

    if (firstTurn == 'H' || firstTurn == 'h' ){
            char* filename = "HFIRST.txt";
            STARTKATA(filename);
            /*read file into matrix*/
            for (int i =0 ; i<50 && (!EndKata) ; i++){
                for (int j =0; j<=9 ; j++){
                    DFA[i][j] = CKata;
                    /* DEBUGGER : for (int k =1; k<=10 ; k++){
                                    printf("%c", CKata.TabKata[k]);}
                                printf("\n");*/
                    ADVKATA();
                    }
                }

            printf("<SYSTEM MESSAGE> INITIATING HUMAN-GOES-FIRST MODULE. SIT BACK TIGHT!\n");
            int move,idx;
            boolean Endgame = false;
            char Endstate;
            boardstate dummy;
			
			
			// MAIN GAME LOOP :
            while(!Endgame) {
                /*printBoard(board);*/
                printf("\n");
				
				//LOOP TO EVALUATE INPUT
                do {
                        /*Copying current board state to dummy*/
                        for (int i=0; i<= 8; i++){
                                dummy[i] = board[i];
                            }

                        /* Copying dummy board to list of state */
                        for (int i=0; i<= 8; i++){
                                statelist[neff].state[i]  =  dummy[i];
                            }

                        /*Asking for user move */
                        printf("<SYSTEM MESSAGE> Select a spot on the board...\n");
                        scanf("%d", &move);
                        while(getchar() != '\n'); /*SCANF IS SO FUCKING FLAWED, NEED THIS TO DISCARD BUFFER CLUTTERS*/

                        /*Consultates to DFA */

                        printf("<SYSTEM MESSAGE> COMPUTER IS CONSULTING TO DFA  ...\n");
                        idx = DFADecree(dummy, DFA, move, &Endgame, &Endstate);
                        /*DEBUGGER : printf("%d\n",idx); */
                        if (idx == -999 || Endstate == 'E') {
                            /* DEBUGGER : printf("idx = %d, endstate = %c", idx, Endstate);*/
                            printf("<SYSTEM MESSAGE> INPUT ERROR, REINPUT! \n");
                        }
                        else {
                                /*copying boardstate from DFA to dummy */
                                for (int k =0; k<=8 ; k++){
                                    /*DEBUGGER : printf("%c", DFA[idx][move].TabKata[k]);*/
                                    dummy[k] = DFA[idx][move].TabKata[k];
                                }
                                /*dummy[move-1] = 'X';*/
                        }

                    } while (Endstate == 'E' || idx == -999); /*Asking user for input until dummy board state is acceptable */

       /*Status : User input already accepted. */
       neff++; /* neff of states-passed list is incremented */

       /*Dummy is in acceptable condition. Dummy is copied to real board */
       for (int i=0; i<= 8; i++){
            board[i] = dummy[i];
        }

        /*printing the board */
       printf("<SYSTEM MESSAGE> RESULT : \n");
       printBoard(board);
       printf("\n");

        /*Final state check */
        if (Endgame){
            if (Endstate == 'C'){
                        printf(" ___________.._______\n");
                        printf("| .__________))______|\n");
                        printf("| | / /      ||\n");
                        printf("| |/ /       ||\n");
                        printf("| | /        ||.-''.\n");
                        printf("| |/         |/  _  \ \n");
                        printf("| |          ||  `/,|\n");
                        printf("| |          (\\`_.'\n");
                        printf("| |         .-`--'.\n");
                        printf("| |        /Y . . Y\ \n");
                        printf("| |       // |   | \\\n");
                        printf("| |      //  | . |  \\\n");
                        printf("| |     ')   |   |   (`\n");
                        printf("| |          ||'||\n");
                        printf("| |          || ||\n");
                        printf("| |          || ||\n");
                        printf("| |          || ||\n");
                        printf("| |         / | | \"\n");
                        printf("~~~~~~~~~~|_`-' `-' |~~~~~~\n");
                        printf("|~|~~~~~~~\ \       '~~\n");
                        printf("| |        \ \        | \n");
                        printf(": :         \ \       : :  \n");
                        printf(". .          `'       . .\n");
                        printf("<VERDICT> YOU HAVE BEEN EXECUTED (FIGURATIVELY) BY COMPUTER!(YOU LOSE) \n");
                }
                else if (Endstate == 'D'){
                    printf("~~~Congratulations~~~\n");
                    printf("<VERDICT> DRAWWWWWWW!!! \n");
                    printf("YOU THOUGHT U COULD WIN? \n");
                    printf("KEEP DREAMING! \n");                    }
                }
        }
    }

    /*COMP GOES FIRST MODULE */
    else if (firstTurn== 'C' || firstTurn == 'c'){
            /*DFA file is read and stored in matrikskata */
            char* filename = "CFIRST.txt";
                STARTKATA(filename);
                for (int i =0 ; i<100 && (!EndKata) ; i++){
                    for (int j =0; j<=9 ; j++){
                        DFA[i][j] = CKata;
                        /*DEBUGGER   for (int k =1; k<=10 ; k++){
                                        printf("%c", CKata.TabKata[k]);}
                                    printf("\n");*/
                        ADVKATA();
                        }
                    }

            /*variable initializations */
            printf("<SYSTEM MESSAGE> INITIALIZING COMP-GOES-FIRST MODULE \n");
            int move,idx;
            boolean Endgame = false;
            char Endstate;
            boardstate dummy;

            /*Computer takes the first move */
            printf("<SYSTEM MESSAGE> COMPUTER MAKES THE FIRST MOVE...\n");
            board[4] = 'O';
            printBoard(board);
            printf("\n");

            /*Copying current board to states-passed list */
            for (int i=0; i<= 8; i++){
                statelist[neff].state[i]  =  dummy[i];
            }

            /*INPUT LOOP*/
            while(!Endgame) {
                do {
                    /*copy current board state to dummy */
                    for (int i=0; i<= 8; i++){
                            dummy[i] = board[i];
                        }

                    /*copying current board state to states-passed list */
                    for (int i=0; i<= 8; i++){
                        statelist[neff].state[i]  =  dummy[i];
                    }

                    /*asking for user input */
                    printf("<SYSTEM MESSAGE> Select a spot on the board...\n");
                    scanf("%d", &move);
                    while(getchar() != '\n'); /*SCANF IS SO FRICKIN' FLAWED, NEED THIS TO DISCARD BUFFER CLUTTERS*/


                    /*Computer Consultates to DFA*/
                    printf("<SYSTEM MESSAGE> COMPUTER IS CONSULTING TO DFA ...\n");
                    idx = DFADecree(dummy, DFA, move, &Endgame, &Endstate); // returns index of appropriate next state from DFA

                    if (idx == -999 || Endstate == 'E') {
                            printf("<SYSTEM MESSAGE> INPUT ERROR, REINPUT! \n");
                        }
                        else {
                                /*copying boardstate from DFA to dummy */
                                for (int k =0; k<=8 ; k++){
                                    /*DEBUGGER : printf("%c", DFA[idx][move].TabKata[k]);*/
                                    dummy[k] = DFA[idx][move].TabKata[k];
                                }
                        }

                } while (Endstate == 'E' || idx == -999);

       /*Status : User input already accepted. */
       neff++; /* neff of states-passed list is incremented */

       /*Dummy is in acceptable condition. Dummy is copied to real board */
       for (int i=0; i<= 8; i++){
            board[i] = dummy[i];
        }

        /*printing the board */
       printf("<SYSTEM MESSAGE> RESULT : \n");
       printBoard(board);
       printf("\n");

        /*Final state check */
            if (Endgame){
                if (Endstate == 'C'){ // COMPUTER WINS
                        printf(" ___________.._______\n");
                        printf("| .__________))______|\n");
                        printf("| | / /      ||\n");
                        printf("| |/ /       ||\n");
                        printf("| | /        ||.-''.\n");
                        printf("| |/         |/  _  \ \n");
                        printf("| |          ||  `/,|\n");
                        printf("| |          (\\`_.'\n");
                        printf("| |         .-`--'.\n");
                        printf("| |        /Y . . Y\ \n");
                        printf("| |       // |   | \\\n");
                        printf("| |      //  | . |  \\\n");
                        printf("| |     ')   |   |   (`\n");
                        printf("| |          ||'||\n");
                        printf("| |          || ||\n");
                        printf("| |          || ||\n");
                        printf("| |          || ||\n");
                        printf("| |         / | | \"\n");
                        printf("~~~~~~~~~~|_`-' `-' |~~~~~~\n");
                        printf("|~|~~~~~~~\ \       '~~\n");
                        printf("| |        \ \        | \n");
                        printf(": :         \ \       : :  \n");
                        printf(". .          `'       . . \n");
                        printf("<VERDICT> YOU HAVE BEEN EXECUTED (FIGURATIVELY) BY COMPUTER!(YOU LOSE) \n");
                }
                else if (Endstate == 'D'){ // IT IS A DRAW
                    printf("~~~Congratulations~~~\n");
                    printf("<VERDICT> DRAWWWWWWW!!! \n");
                    printf("YOU THOUGHT U COULD WIN? \n");
                    printf("KEEP DREAMING!\n\n");
                    }
                }
            }
        }
    else{ /*TURN INPUT IS WRONG */
        printf("<SYSTEM ERROR MESSAGE> INPUT IS NOT VALID! PLEASE READ CAREFULLY!!! -_-\n");}

    /*Copying current board state to states-passed list */
    for (int i=0; i<= 8; i++){
        statelist[neff].state[i]  =  board[i];
    }

    /*IF Turn Input is wrong, offensive comment ensues ...*/
    if(neff ==0 ) {
    printf("Seriously?\n");
    printf("      ,\n");
    printf("(`-.-/(           .:::::.,\n");
    printf(" `-.__)          /  ``:\:: .               /7_.-,\n");
    printf("     '. -.       -  - `:::'           .- (  `_.=\n");
    printf("      \\  `--._  |/   _?'`      ___.-'   -`~\n");
    printf("       \\         -  / )----'''' -    .-'\n");
    printf("         `--..   `--' ,'           .-'\n");
    printf("              `\   --'       )---''\n");
    printf("                )           )\n");
    printf("                |          _|\n");
    printf("                (           \ \n");
    printf("                 L          /\n");
    printf("                 |          \\ \n");
    printf("                 )__     _   \\ \n");
    printf("                 \\ `---' `--'\n");
    printf("                   L         |\n");
    printf("                   |   \\      |\n");
    printf("                   \\   L     ) \\ \n");
    printf("                     L_ (     / \n");
    printf("                     |   \\ .   \\ \n");
    printf("       ...             |    `.  \\ \n");
    printf("                  _.-`--='  \    )\n");
    printf("                 (   _-'     `--'\\ \n");
    printf("                  '~'        . ' |  \n");
    printf("                            (,_./\n");
    printf("JANGAN SENGAJA BIKIN ERROR...!!!\n ");}

    else {
            /*Print States-passed list */
            printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
            printf("STATES PASSED : \n");
            for (int i=0; i<= neff; i++){
                printf("[%d]. ",i+1);
                for (int j=0; j<= 8; j++){
                    printf("%c",statelist[i].state[j]);
                    }
                printf("\n");
            }
    }
    goto BEGIN;
}

