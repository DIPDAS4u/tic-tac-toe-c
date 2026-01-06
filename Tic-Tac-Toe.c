#include <stdio.h>
#include <stdlib.h>

    char board[3][3];

    void Boardbox(){
        printf("\nBOARD:");
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                board[i][j] = ' ';          // WARNING: This resets the board. Only call at the start of a game.
            }
        }
        int count = 7;
        int count2 = 4;
        int count3 = 1;
        printf("\n\n\t");
        for(int i = 0; i< 1; i++){
            for(int j =0; j< 3; j++){
                printf("%d", count++);
                if(j< 2){
                    printf("  |  ");
                }
            }
                if(i< 2){
                    printf("\n\t-------------\n\t");
                }
        }
        for(int i = 1; i< 2; i++){
            for(int j =0; j< 3; j++){
                printf("%d", count2++);
                if(j< 2){
                    printf("  |  ");
                }
            }
                if(i< 2){
                    printf("\n\t-------------\n\t");
                }
        }
        for(int i = 2; i< 3; i++){
            for(int j =0; j< 3; j++){
                printf("%d", count3++);
                if(j< 2){
                    printf("  |  ");
                }
            }
                if(i< 2){
                    printf("\n\t-------------\n\t");
                }
        }
        printf("\n\n");
    }

    void showBoard(){
        printf("\n\n\t");
        for(int i= 0; i< 3;i++){
            for(int j =0; j< 3; j++){
                printf(" %c", board[i][j]);
                if(j<2){
                    printf(" | ");
                }
            }
            if(i< 2){
                printf("\n\t------------\n\t");
            }
        }
        printf("\n\n");
    }
    int updateBoard(int cells, char playerSign){
        int rows = (9 - cells)/3;
        int columns = (cells - 1)%3;
        int isOk = 1;

        if(board[rows][columns] != ' '){
            printf("\n\t Invalid :: This cell has already been taken!\n Choose another Cell.  \n\t");
            isOk = 0;
        }else{
            board[rows][columns] = playerSign;
        }
        showBoard();
        return isOk;
    }

    int checkWinner(char sign){
        if((board[0][0] == sign && board[0][1] == sign && board[0][2] == sign)||
           (board[1][0] == sign && board[1][1] == sign && board[1][2] == sign)||
           (board[2][0] == sign && board[2][1] == sign && board[2][2] == sign)){
                return 1;
        }else if(
           (board[0][0] == sign && board[1][0] == sign && board[2][0] == sign)||
           (board[0][1] == sign && board[1][1] == sign && board[2][1] == sign)||
           (board[0][2] == sign && board[1][2] == sign && board[2][2] == sign)){
                return 1;
        }else if(
           (board[0][0] == sign && board[1][1] == sign && board[2][2] == sign)||
           (board[0][2] == sign && board[1][1] == sign && board[2][0] == sign)){
                return 1;
        }

        return 0;
    }

    int play_tictactoe();

    void Replay() {
    int choic;
    while (1) {
        printf("\n\n WANT TO CHALLENGE OTHER PLAYER FOR ANOTHER MATCH OR EXIT??\n");
        printf("\n\t (1)--CHALLENGE--");
        printf("\n\t (0)--EXIT!!--\n");
        printf("\n\tENTER YOUR CHOICE: ");
        scanf("%d", &choic);

            if (choic == 0) {
                printf("\n\t*Thank you for playing*\n");
                printf("\n\t  --*-- EXITED --*-- \n");
                break;
            } else if (choic == 1) {
                Boardbox();
                play_tictactoe();
            } else {
                printf("\nInvalid choice! Please enter 0 or 1.\n");
            }
        }
    }


    int play_tictactoe(){
        int game_result = 0;
        int playcount = 0;
        int cells = 0;
        int updateResult = 1;
        char playerSign;
        Boardbox();
        while(!game_result && playcount < 9){
           if(playcount % 2 == 0){
                playerSign = 'X';
                printf("\n PLAYER - 1 [ X ] : ");
           }else{
                playerSign = 'O';
                printf("\n PLAYER - 2 [ O ] : ");
           }
           scanf("%d", &cells);
           if(cells> 0 && cells< 10){
                updateResult = updateBoard( cells, playerSign);
                if(updateResult){
                    game_result = checkWinner(playerSign);
                    if(game_result){
                        printf("    *** PLAYER - %d WON.. ***\n", playerSign == 'X'? 1 : 2);
                        printf(" \n\t---- GAME OVER ---- \n");
                        return (playerSign == 'X') ? 1 : 2;
                    }
                    playcount++;
                }
           }else{
                printf("\nPlease Enter a valid cell value\n");
           }
        }
        printf("\n\t * DRAW * \n");
        return 0;
    }

    void rou() {
    int a = 0, b = 0;
    int rounds = 3;
    printf("-*-Three games, ONE WINNER!! Rack up your points to claim the first position-*-\n\n");
    for (int i = 1; i <= rounds; i++) {
        int winner = play_tictactoe();

        if (winner == 1)
            a += 3;
        else if (winner == 2)
            b += 3;
        else
            a++, b++;

        printf("\nAFTER ROUND %d: Player 1 = %d points, Player 2 = %d points\n", i, a, b);
    }

    printf("\n--- FINAL SCORES ---\nPlayer 1: %d\nPlayer 2: %d\n", a, b);

    if (a > b)
        printf("\n*** PLAYER 1 WINS THE TOURNAMENT! ***\n");
    else if (b > a)
        printf("\n*** PLAYER 2 WINS THE TOURNAMENT! ***\n");
    else
        printf("\n*** THE TOURNAMENT ENDED IN A DRAW! ***\n");
    }


    int emptyCells(int cells){
        int rows = (9 - cells)/3;
        int columns = (cells - 1)%3;
        return board[rows][columns] == ' ';
    }

    int ai_wins[8][3] = {{7,8,9},{4,5,6},{1,2,3},{7,4,1},{8,5,2},{9,6,3},{7,5,3},{9,5,1}};

    int aiMove(char ai, char player){

    for(int i = 0; i < 8; i++){
        int a = ai_wins[i][0];
        int b = ai_wins[i][1];
        int c = ai_wins[i][2];

        if(board[(9-a)/3][(a-1)%3] == ai && board[(9-b)/3][(b-1)%3] == ai && emptyCells(c))
            return c;

        if(board[(9-a)/3][(a-1)%3] == ai && board[(9-c)/3][(c-1)%3] == ai && emptyCells(b))
            return b;

        if(board[(9-c)/3][(c-1)%3] == ai && board[(9-b)/3][(b-1)%3] == ai && emptyCells(a))
            return a;
    }

    for(int i = 0; i < 8; i++){
        int a = ai_wins[i][0];
        int b = ai_wins[i][1];
        int c = ai_wins[i][2];

        if(board[(9-a)/3][(a-1)%3] == player && board[(9-b)/3][(b-1)%3] == player && emptyCells(c))
            return c;

        if(board[(9-a)/3][(a-1)%3] == player && board[(9-c)/3][(c-1)%3] == player && emptyCells(b))
            return b;

        if(board[(9-c)/3][(c-1)%3] == player && board[(9-b)/3][(b-1)%3] == player && emptyCells(a))
            return a;
    }

    if(emptyCells(5))
        return 5;

    int corners[4] = {1,3,7,9};
    for(int i = 0; i < 4; i++)
        if(emptyCells(corners[i]))
            return corners[i];

    int edges[4] = {2,4,6,8};
    for(int i = 0; i < 4; i++)
        if(emptyCells(edges[i]))
            return edges[i];

    return 0;
    }


    void play_withai(){

    int game_result = 0;
    int playcount = 0;
    int cells = 0;
    int updateResult = 1;

    char playerSign;
    char human, ai;
    int sign;

    printf("\n\t(1) - X");
    printf("\n\t(2) - O");
    printf("\n\tChoose your sign: ");
    scanf("%d", &sign);

    if(sign == 1){
        human = 'X';
        ai = 'O';
    }else{
        human = 'O';
        ai = 'X';
    }

    Boardbox();

    while(!game_result && playcount < 9){

        if(playcount % 2 == 0){
            if(human == 'X'){
                playerSign = human;
                printf("\n YOU [%c] : ", human);
                scanf("%d", &cells);
            }else{
                playerSign = ai;
                cells = aiMove(ai, human);
                printf("\n AI chose: %d\n", cells);
            }
        }else{
            if(human == 'O'){
                playerSign = human;
                printf("\n YOU [%c] : ", human);
                scanf("%d", &cells);
            }else{
                playerSign = ai;
                cells = aiMove(ai, human);
                printf("\n AI chose: %d\n", cells);
            }
        }

        if(cells > 0 && cells < 10){
            updateResult = updateBoard(cells, playerSign);
            if(updateResult){
                game_result = checkWinner(playerSign);
                if(game_result){
                    if(playerSign == human)
                        printf("\n\t-*- You Win! -*-\n");
                    else
                        printf("\n\t-*- AI Wins! -*-\n");
                    printf("\n ---- GAME OVER ---- \n");
                }
                playcount++;
            }
        }else{
            printf("\nInvalid cell! Try again.\n");
        }
    }
    if(!game_result && playcount == 9)
        printf("\n DRAW GAME\n");
    }

    void Replay_AI() {
    int choic;
    while (1) {
        printf("\n\n WANT TO CHALLENGE AI FOR ANOTHER MATCH OR EXIT??\n");
        printf("\n\t (1)--CHALLENGE--");
        printf("\n\t (0)--EXIT!!--\n");
        printf("\n\tENTER YOUR CHOICE: ");
        scanf("%d", &choic);

        if (choic == 0) {
            printf("\n\t*Thank you for playing*\n");
            printf("\n\t  --*-- EXITED --*-- \n");
            break;
        } else if (choic == 1) {
            Boardbox();
            play_withai();
        } else {
            printf("\nInvalid choice! Please enter 0 or 1.\n");
        }
    }
}



    int main(){
        srand(time(NULL));

        printf("---***---WELCOME PLAYERS TO THE GAME---***---\n\n");
        printf("------***----::TIC TAC TOE::----***------\n");
        printf("\n\t(1)---- QUICK MATCH");
        printf("\n\t(2)---- BEST OF 3(Tournament Style)");
        printf("\n\t(3)---- VS AI");
        printf("\n\t(0)---- EXIT\n");
        int choice;
        printf("\n\tEnter Your Choice:");
        scanf("%d", &choice);
        switch(choice){
        case 0:
            printf("\t :: Have a nice Day, PLAYERS!! :: \n\n\t--*-- EXITED --*--\n");
            return 0;
        case 1:
            printf("\n\n\t\t---** QUICK MATCH **---");
            printf("\n---Use your keypad (1-9) to place your mark on the matching grid cell.---\n\n");
            play_tictactoe();
            Replay();
            break;
        case 2:
            printf("\n\n\t\t---** BEST OF 3(Tournament Style) **---");
            printf("\n---Use your keypad (1-9) to place your mark on the matching grid cell.---\n\n");
            rou();
            break;
        case 3:
            printf("\n\n\t\t---** VS AI **---");
            printf("\n---Use your keypad (1-9) to place your mark on the matching grid cell.---\n\n");
            play_withai();
            Replay_AI();
            break;
        }

        return 0;
    }
