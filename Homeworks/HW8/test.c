printf("whiteKingRow  %d  whiteKingCol  %c  blackKingRow    %d  blackKingCol  %c \n",whiteKingRow,whiteKingCol,blackKingRow,blackKingCol);

int isInCheck(char* board)
{
    int whiteIndexes[16],blackIndexes[16];
    int blackKingRow,whiteKingRow,pieceRow,i,j;
    char blackKingCol,whiteKingCol,pieceCol;
    findPieces(board ,whiteIndexes ,blackIndexes);
    for (i=0;i<BOARD_SIZE*BOARD_SIZE && board[i] != 'k';i++){}
    for (j=0;j<BOARD_SIZE*BOARD_SIZE && board[j] != 'K';j++){}
    findColAndRow(j,&whiteKingCol,&whiteKingRow);
    findColAndRow(i,&blackKingCol,&blackKingRow);
    for (i=0;i<16;i++)
    {
        findColAndRow(whiteIndexes[i],&pieceCol,&pieceRow);
        if(isPieceMovable(board,pieceCol,pieceRow,blackKingCol,blackKingRow))
            return 2;
        findColAndRow(blackIndexes[i],&pieceCol,&pieceRow);
        if(isPieceMovable(board,pieceCol,pieceRow,whiteKingCol,whiteKingRow))
            return 1;
    }
    return 0;
}

void findPieces(char* board ,int* whiteIndexes ,int* blackIndexes)
{
    int i=0,k=0,j;
    for(j=0;j<64;j++)
    {
        if ((board[j]>='a' && board[j]<='z') && i<16)
             blackIndexes[i++]=j;
        if ((board[j]>='A' && board[j]<='Z') && k<16)
            whiteIndexes[k++]=j;
    }
}


int isInCheck(char* board)
{
    int blackKingRow,whiteKingRow,pieceRow,i,j;
    char blackKingCol,whiteKingCol,pieceCol;
    for (i=0;i<BOARD_SIZE*BOARD_SIZE && board[i] != 'k';i++){}
    for (j=0;j<BOARD_SIZE*BOARD_SIZE && board[j] != 'K';j++){}
    findColAndRow(j,&whiteKingCol,&whiteKingRow);
    findColAndRow(i,&blackKingCol,&blackKingRow);
    for (i=0;i<BOARD_SIZE*BOARD_SIZE;i++)
    {
        if ( isWhite(board[i]))
        findColAndRow(IIIIIIIIIIIIII,&pieceCol,&pieceRow);
        if(isPieceMovable(board,pieceCol,pieceRow,blackKingCol,blackKingRow))
            return 2;
        findColAndRow(blackIndexes[i],&pieceCol,&pieceRow);
        if(isPieceMovable(board,pieceCol,pieceRow,whiteKingCol,whiteKingRow))
            return 1;
    }
    return 0;
}
