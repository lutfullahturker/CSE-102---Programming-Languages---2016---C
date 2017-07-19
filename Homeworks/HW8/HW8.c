/* -----------------------------------------------------------------------  */
/*                                                                          */
/*                   HW08_141044050_Lutfullah_Turker                        */
/*                                                                          */
/*                                                                          */
/* -----------------------------------------------------------------------  */
/*                Created on 18/04/2016 by Lutfullah_Turker                 */
/*                                                                          */
/* Aciklama                                                                 */
/* -----------------------------------------------------------------------  */
/*    8.odevde 5. odevimizi tamamlayarak sah cekerek tam anlamiyla          */
/*          satranc oynanabilen satranc programi yaziyoruz.                 */
/*                                                                          */
/*                                                                          */
/*------------------------------------------------------------------------  */


/*--------------------------------------------------------------------------*/
/*                               Includes                                   */
/*--------------------------------------------------------------------------*/
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#define BOARD_SIZE 8
/*---------------------------------------------------------------------------*/
/*                         Function Prototypes                               */
/*---------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------*/
/*-----------------------------------  NEW  ---------------------------------*/

int isInCheck(char* board);
int makeMove(char *board, char sc, int sr, char tc, int tr);
char getPlayer(char* board,char sc,int sr);
int isBlack(char currPlayer);
int isWhite(char currPlayer);
int isPieceMovable(char *board, char sc, int sr, char tc, int tr);
void findColAndRow(int index,char* col,int* row);
/*--------------------------------  In HW5  ---------------------------------*/
void initBoard(char *board);
void printBoard(char *board);
void getPosition(char *col, int *row);
int isValidCell(char col, int row);
int isRookMovable(char *board , char sourceCol, int sourceRow, char targetCol,
int targetRow);
int isKnightMovable(char *board, char sourceCol, int sourceRow, char targetCol,
int targetRow);
int isBishopMovable(char *board, char sourceCol, int sourceRow, char targetCol,
int targetRow);
int isQueenMovable(char *board, char sourceCol, int sourceRow, char targetCol,
int targetRow);
int isKingMovable(char *board, char sourceCol, int sourceRow, char targetCol,
int targetRow);
int isPawnMovable(char *board, char sourceCol, int sourceRow, char targetCol,
int targetRow);


int main() {
    char board [BOARD_SIZE*BOARD_SIZE], empty;
    int player = 1; /* 1 white, 0 black */
    char sc,tc;
    int sr,tr;
    int moveStatus = 0;
    int checkStatus = 0;
    char currPlayer;
    initBoard(board);
    isInCheck(board);
    do {
        printBoard(board);
        printf("%s player move > ", player ? "White" : "Black");
        getPosition(&sc,&sr);
        scanf("%c", &empty);
        getPosition(&tc,&tr);
        scanf("%c", &empty);
        currPlayer = getPlayer(board, sc,sr);
        if(!isValidCell(sc,sr)) {
            printf("Source position is invalid\n");
            continue;
        }
        if(!isValidCell(tc,tr)) {
            printf("Target position is invalid\n");
            continue;
        }
        if((isBlack(currPlayer) && player) ||
           (isWhite(currPlayer) && !player)) {
            printf("Illegal piece. \n");
            continue;
        }

        moveStatus = makeMove(board,sc,sr,tc,tr);
        switch(moveStatus) {
            case 0:
                printf("Invalid move!\n");
                break;
            case 1:
                printf("Your king is in check!\n");
                ++checkStatus;
                break;
            case 3:
                printf("Check!\n");
            case 2:
                player = !player;
                checkStatus = 0;
                break;
        }
    } while(checkStatus < 2);
    printf("%s player WINS!\n", player ? "Black" : "White");
    return 0;
}

void initBoard(char *board)
{
    char temp[64]={'r','n','b','q','k','b','n','r','p','p','p','p','p','p','p',
    'p',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',
    ' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','P','P','P',
    'P','P','P','P','P','R','N','B','Q','K','B','N','R'};
/* C dilinde char arrayler tanimlandigi yer disinda yukaridaki gibi
tanimlanamadigi icin biz de baska bir degiskende arrayimizi tanimliyoruz.
ve asagidaki for dongusuyle ana Board dongumuzdeki her elemana esitliyoruz.*/
    int i;
    for(i=0;i<64;i++)
    {
        board[i]=temp[i];
    }
}

void printBoard(char *board)
{
    int i,k,tablo=0;
    char a='a';
/* sutunlarimiz a dan h ye kadar oldugu icin bunu donguyle basacagimizdan bir
a degiskeni tanimliyoruz ve a yi artirarak h ye kadar olan harfleri ekrana
    bastiriyoruz.*/
    printf(" ");
    for(i=0;i<8;i++)
    {
        printf(" %c",a++);
    }
    /* donguler bitince satir atlasin diye \n bastiriyoruz.*/
    printf("\n ");
    /* donguyle harflerin altindaki '-' sembollerini bastiriyoruz.*/
    for(i=0;i<8;i++)
    {
        printf(" -");
    }
    printf("\n");
    for(i=8;i!=0;i--)
    {
        /*tablonun elemanlarini basmak icin bir dongu olusturuyoruz
        ve son elemandan sonra bosluk olmayacagi icin for dongusunun icine
        son eleman degilse bosluklu ,son elemansa bosluksuz tablo elemani
        basmasi icin if else koyuyoruz.Icerdeki dongude bir satiri bastiriyor
        ve dis dongude de 8 satir olusturuyoruz.*/
            printf("%d|",i);
            for(k=0;k<8;k++)
            {
                if (k==7)
                    printf("%c",board[tablo++]);
                else
                    printf("%c ",board[tablo++]);
            }
            printf("|\n");
    }
    printf("  - - - - - - - - \n");
}

void getPosition(char *col, int *row)
{/* source ve target Col ve rowlarimizi kullanicidan aldigimiz fonksiyon */
    scanf(" %c%d",col,row);
}

int isValidCell(char col, int row)
{/* girilen col ve rowlarin tabloda bulunup bulunmadigini anlamak icin
Col a ile h arasinda mi ve row da 1 ile 8 arasinda mi diye kontrol ediyoruz.*/
    if (col<='h' && col>='a' && row<=8 && row>=1)
    {
        return 1;
    }
    else
        return 0;
}

int isRookMovable(char *board , char sourceCol, int sourceRow, char targetCol,
                   int targetRow)
{
    int sourceIndex,targetIndex,i,temp;
    sourceIndex=(8-sourceRow)*8+(sourceCol-'a');
    targetIndex=(8-targetRow)*8+(targetCol-'a');
    temp =sourceIndex;
    /* tablodaki indexi tespit etmek icin index bulma denklemini yaziyoruz.
    dongude sourceIndex degisecegi icin bunu temp e atayip temp ile islem
    yapiyoruz .*/
    if (targetCol==sourceCol || targetRow == sourceRow)
    {/* kale'nin hareketinde Col veya Row her zaman sabit kalmak zorunda!*/
        if (targetCol==sourceCol)
        {/* Col sabitse Row degisir ve Row sabitse Col degisir.Ikisi icin
            ayri ayri ifler olusturuyoruz.*/
              for (i=0;i<abs(sourceRow-targetRow);i++)
              {/* Col sabitken kac satir hareket edilmek istendigini bulmak
                  icin sourceRow-targetRow ile bunu buluyoruz.Birbirinden
                  buyuk olma ihtimaline karsi bu islemin mutlak degerini
                  aliyoruz ve kac satir gidiliyorsa her satiri tek tek
                  kontrol ediyoruz.*/
                  if (sourceRow>=targetRow)
                    temp += 8;
                    /* gitmek istedigimiz satir bulunulan satirdan kucukse veya
                    buyukse index birinde azalip birinde artacagi icin
                    hangisini yapacagimizi if else ile tespit ediyoruz. */
                    else
                        temp-=8;
                  if (board[temp]!=board[targetIndex])
                  {
                      if (board[temp] !=' ')
                        return 0;
                  }
                  /*son elemana kadar bosluk karakteri olmak zorunda oldugu
                      icin ve son elemanda rakip tas da olabilecegi icin
                    if ile  son elemana ayri islem yapiyoruz.*/
                  else
                  {
                      if (board[sourceIndex]=='r' && (board[temp]==' ' || (board[temp]>='A' && board[temp]<='Z')))
                            return 1;
                            /*hareket ettirmek istedigimiz kale tasi kucuk olan
                            ise buyuk taslarin yerine gidebilir.Eger kucuk olan
                            ise kucuk taslarin yerine gidebilir diye ikisine
                            farkli if yapiyoruz.*/
                      else if (board[sourceIndex]=='R' && (board[temp]==' ' || (board[temp]>='a' && board[temp]<='z')))
                          return 1;
                      else
                        return 0;
                  }
              }
        }
        else
        {/* Col lar degil de Row lar esit ise buradaki islemleri uyguluyoruz.*/
            for (i=0;i<abs(sourceCol-targetCol);i++)
          {/* ayni sekilde gidilen sutun kadar dongu calisacagi icin
              sourceCol-targetCol ile kac sutun gidildigini buluyor ve
              o kadar sayida donguyu calistiriyoruz. */
              if(sourceCol>=targetCol)
                temp --;/* bu sefer Col lar arasýnda hareket yapilacagindan
                indeximizi 1 artirip veya 1 azaltiyoruz. */
            else
                temp++;

              if (board[temp]!=board[targetIndex])
              {
                  if (board[temp] !=' ')
                    return 0;
              }
              else
              {/*yukaridaki islemlerin aynilarini Rowlar esit halde yapiyoruz.*/
                  if (board[sourceIndex]=='r' && (board[temp]==' ' || (board[temp]>='A' && board[temp]<='Z')))
                        return 1;
                  else if (board[sourceIndex]=='R' && (board[temp]==' ' || (board[temp]>='a' && board[temp]<='z')))
                      return 1;
                  else
                    return 0;
              }
          }
        }
    }
    else/* hicbiri degilse 0 return ederek hareketin mumkun olmadigini
        belirtiyoruz.*/
        return 0;
     return 0;
}
int isKnightMovable(char *board, char sourceCol, int sourceRow, char targetCol, int targetRow)
{
    int sourceIndex,targetIndex;
    sourceIndex=(8-sourceRow)*8+(sourceCol-'a');
    targetIndex=(8-targetRow)*8+(targetCol-'a');
/*Atin hareketinde her zaman ya Sutun 2 hareket ettiginde Satir 1 hareket eder
Ya da Sutun 1 hareket ettiginde Satir 2 hareket eder.buna gore sartlarimiz::*/
    if (((targetCol==sourceCol+2 || targetCol==sourceCol-2) &&
         (targetRow==sourceRow+1 || targetRow==sourceRow-1)) ||
        ((targetCol==sourceCol+1 || targetCol==sourceCol-1) &&
         (targetRow==sourceRow+2 || targetRow==sourceRow-2)))
    {/* Hedef konumda rakip mi yoksa kendi takim elemanimiz mi olup olmadigini
        kontrol ederek islem yapiyoruz.*/
        if (board[sourceIndex]=='n' && (board[targetIndex]==' ' ||(board[targetIndex]<='Z' && board[targetIndex]>='A')))
            return 1;
        else if (board[sourceIndex]=='N' && (board[targetIndex]==' ' || (board[targetIndex]<='z' && board[targetIndex]>='a')))
            return 1;
        else
            return 0;
    }
    else
        return 0;
     return 0;
}

int isBishopMovable(char *board, char sourceCol, int sourceRow, char targetCol, int targetRow)
{
    int sourceIndex,targetIndex,i,temp;
    sourceIndex=(8-sourceRow)*8+(sourceCol-'a');
    targetIndex=(8-targetRow)*8+(targetCol-'a');
    temp =sourceIndex;
    if (abs(targetCol-sourceCol)==abs(targetRow-sourceRow))
    {/*cikarmanin sonucu - bir sayi ciktiginda da sayinin pozitif haliyle islem
        yapacagimizdan mutlak deger fonksiyonu icinde yaziyoruz.*/
        for (i=0;i<abs(sourceRow-targetRow);i++)
          {/*asagi dogru capraz gidildiginde saga dogruysa index olarak 9 index
              fazla veya sola dogruysa 7 index fazla ve ayni sekilde yukari
              giderken de bu sayilarin cikartilmis hali olacagi icin hepsini
              if lerle degistiriyoruz. */
              if(targetCol>sourceCol && targetRow<sourceRow)
                temp += 9;
              if(targetCol<sourceCol && targetRow>sourceRow)
                temp -=9;
              if(targetCol>sourceCol && targetRow>sourceRow)
                temp -=7;
              if (targetCol<sourceCol && targetRow<sourceRow)
                temp +=7;
              if (board[temp]!=board[targetIndex])
              {
                  if (board[temp] !=' ')
                    return 0;
              }
              /*yine hedef konuma kadar bosluk olma sarti ve sadece hedef
                  konumda rakip tas olabilme sarti oldugundan ikisini ayri ayri
                  yaziyoruz .*/
              else
              {
                  if (board[sourceIndex]=='b' && (board[temp]==' ' || (board[temp]>='A' && board[temp]<='Z')))
                        return 1;
                  else if (board[sourceIndex]=='B' && (board[temp]==' ' || (board[temp]>='a' && board[temp]<='z')))
                      return 1;
                  else
                    return 0;
              }
          }
    }
    else
        return 0;
     return 0;
}

int isQueenMovable(char *board, char sourceCol, int sourceRow, char targetCol, int targetRow)
{
    int sourceIndex,targetIndex,i,temp;
    sourceIndex=(8-sourceRow)*8+(sourceCol-'a');
    targetIndex=(8-targetRow)*8+(targetCol-'a');
    temp =sourceIndex;
    /* Queen , Rook (kale) un tum sartlari ve Bishop(fil) un tum sartlari
        ile hareket ettiginden dolayi isRookMovable ve isBishopMovable
        fonksiyonlarimizin icerigini ayri if ler seklinde buraya yazdik.
     Ve ikisinin de sartini saglamiyorsa basarisiz olacagindan return 0 dedik*/
    if (abs(targetCol-sourceCol)==abs(targetRow-sourceRow))
    {
        for (i=0;i<abs(sourceRow-targetRow);i++)
          {
              if(targetCol>sourceCol && targetRow<sourceRow)
                temp += 9;
              if(targetCol<sourceCol && targetRow>sourceRow)
                temp -=9;
              if(targetCol>sourceCol && targetRow>sourceRow)
                temp -=7;
              if (targetCol<sourceCol && targetRow<sourceRow)
                temp +=7;
              if (board[temp]!=board[targetIndex])
              {
                  if (board[temp] !=' ')
                    return 0;
              }
              else
              {
                  if (board[sourceIndex]=='q' && (board[temp]==' ' || (board[temp]>='A' && board[temp]<='Z')))
                        return 1;
                  else if (board[sourceIndex]=='Q' && (board[temp]==' ' || (board[temp]>='a' && board[temp]<='z')))
                      return 1;
                  else
                    return 0;
              }
          }
    }
    else if (targetCol==sourceCol || targetRow == sourceRow)
    {
        if (targetCol==sourceCol)
        {
              for (i=0;i<abs(sourceRow-targetRow);i++)
              {
                  if (sourceRow>=targetRow)
                    temp += 8;
                    else
                        temp-=8;
                  if (board[temp]!=board[targetIndex])
                  {
                      if (board[temp] !=' ')
                        return 0;
                  }
                  else
                  {
                      if (board[sourceIndex]=='q' && (board[temp]==' ' || (board[temp]>='A' && board[temp]<='Z')))
                            return 1;
                      else if (board[sourceIndex]=='Q' && (board[temp]==' ' || (board[temp]>='a' && board[temp]<='z')))
                          return 1;
                      else
                        return 0;
                  }
              }
        }
        else
        {
            for (i=0;i<abs(sourceCol-targetCol);i++)
          {
              if(sourceCol>=targetCol)
                temp --;
            else
                temp++;

              if (board[temp]!=board[targetIndex])
              {
                  if (board[temp] !=' ')
                    return 0;
              }
              else
              {
                  if (board[sourceIndex]=='q' && (board[temp]==' ' ||
                        (board[temp]>='A' && board[temp]<='Z')))
                        return 1;
                  else if (board[sourceIndex]=='Q' && (board[temp]==' ' ||
                                (board[temp]>='a' && board[temp]<='z')))
                      return 1;
                  else
                    return 0;
              }
          }
        }
    }
    else
        return 0;
    return 0;
}

int isKingMovable(char *board, char sourceCol, int sourceRow, char targetCol, int targetRow)
{
    int sourceIndex,targetIndex;
    sourceIndex=(8-sourceRow)*8+(sourceCol-'a');
    targetIndex=(8-targetRow)*8+(targetCol-'a');
    if((sourceCol==targetCol-1|| sourceCol==targetCol+1|| sourceCol==targetCol)
        && (targetRow==sourceRow+1 || targetRow==sourceRow-1
            || targetRow==sourceRow))
    {/*King(sah) her yone sadece 1 birim gidebildigi icin Row veya Col en fazla
        1 artip 1 azalabilir veya degismez.*/
        if (board[sourceIndex]=='k' && (board[targetIndex]==' ' ||
            (board[targetIndex]>='A' && board[targetIndex]<='Z')))
                return 1;
            /* her zamanki gibi rakip eleman varsa gidebilmesi icin hareket
            ettirdigimiz tasa gore rakibe de gidebilsin diye ayri if ler
                koyuyoruz.*/
          else if (board[sourceIndex]=='K' && (board[targetIndex]==' ' ||
                    (board[targetIndex]>='a' && board[targetIndex]<='z')))
              return 1;
          else
            return 0;
    }
    return 0;
}

int isPawnMovable(char *board, char sourceCol, int sourceRow, char targetCol, int targetRow)
{
    int sourceIndex,targetIndex;
    sourceIndex=(8-sourceRow)*8+(sourceCol-'a');
    targetIndex=(8-targetRow)*8+(targetCol-'a');
/*pawn(piyon) onu bosken her seferinde sadece 1 kare ilerleyebilir.Ve geri
 gidemez.Buda her seferinde 8 index ilerleyebilir demek oluyor.Ve gidecegi yer
bos olmak zorunda .Asagidaki if ile bu sarti sagliyorsa 1 return ediyoruz.*/
    if (board[sourceIndex]=='p' && targetIndex==sourceIndex+8 &&
        board[targetIndex]==' ')
            return 1;
    /* Veya caprazinda rakibe ait bir tas varsa bir kare capraz da gidebildigi
    ihtimalini de goze aliyoruz.*/
    else if (board[sourceIndex]=='P' && targetIndex==sourceIndex-8 &&
        board[targetIndex]==' ')
            return 1;
    else if ((board[sourceIndex]=='p' && (targetIndex==sourceIndex+9 ||
                targetIndex==sourceIndex+7) &&
             (board[targetIndex]>='A' && board[targetIndex]<='Z'))
              || (board[sourceIndex]=='P' && (targetIndex==sourceIndex-9 ||
                targetIndex==sourceIndex-7)&&
             (board[targetIndex]>='a' && board[targetIndex]<='z')))
            return 1;
    else
        return 0;
return 0;
}

int isPieceMovable(char *board, char sc, int sr, char tc, int tr)
{
    int isSuccessful=0;
    switch (getPlayer(board, sc,sr))
    {
    case 'r':
    case 'R':
        isSuccessful=isRookMovable(board ,sc,sr,tc,tr);
        if (isSuccessful==1)
            return 1;
        else
            return 0;
        break;
    case 'n':
    case 'N':
        isSuccessful=isKnightMovable(board ,sc,sr,tc,tr);
        if (isSuccessful==1)
            return 1;
        else
            return 0;
        break;
    case 'b':
    case 'B':
         isSuccessful=isBishopMovable(board ,sc,sr,tc,tr);
        if (isSuccessful==1)
            return 1;
        else
            return 0;
        break;
    case 'q':
    case 'Q':
        isSuccessful=isQueenMovable(board ,sc,sr,tc,tr);
        if (isSuccessful==1)
            return 1;
        else
            return 0;
        break;
    case 'k':
    case 'K':
        isSuccessful=isKingMovable(board ,sc,sr,tc,tr);
        if (isSuccessful==1)
            return 1;
        else
            return 0;
        break;
    case 'p':
    case 'P':
        isSuccessful=isPawnMovable(board ,sc,sr,tc,tr);
        if (isSuccessful==1)
            return 1;
        else
            return 0;
        break;
    default:
        return 0;
/*switch case de her tas icin kucuk veya buyuk harf girildiginde girilen harfe
 gore o tasin hareket edip edemeyecegini belirledigimiz fonksiyon cagriliyor ve
bu fonksiyon hareket edemiyorsa 0 return ederek hareket edemedigini belirtiyor.
  if condition i ile bunu kontrol ediyoruz. */
    }

}
int isBlack(char currPlayer)
{
    /* eger currPlayer kucuk bir harfse oynanan tas black tir ve bu yuzden
    return 1 yapiyoruz eger kucuk harf degilse black degildir ve return 0 */
    if(currPlayer>='a' && currPlayer<='z')
        return 1;
    return 0;
}

int isWhite(char currPlayer)
{
    /* eger currPlayer buyuk bir harfse oynanan tas white tir ve bu yuzden
    return 1 yapiyoruz eger buyuk harf degilse white degildir ve return 0 */
    if(currPlayer>='A' && currPlayer<='Z')
        return 1;
    return 0;
}

char getPlayer(char* board,char sc,int sr)
{
    int sourceIndex;
    sourceIndex=(8-sr)*8+(sc-'a');
    /* girilen Col ve Row  degiskenlerini tablomuzun hangi elemanina karsilik
    geldigini anlamak icin bir index degiskeni tanimliyoruz.ve bir denklemle
    girilen Col ve Row un tablodaki Indexini buluyoruz.Denklemde
    Col degiskenini char olarak aldigi icin Col u 'a' karakterinden cikariyoruz.
    ornegin Col c girildiyse (sourceCol-'a')=2 oluyor.Ve board[sourceIndex] ile
    o indexdeki harfi return ediyoruz. */
    return board[sourceIndex];
}

int makeMove(char *board, char sc, int sr, char tc, int tr)
{
    int sourceIndex,targetIndex;
    char temp;
    /*black ve white oyuncularinin Kinglerinin index i gerekli oldugu icin
    2 tane for dongusuyle Kinglerin indexlerini buluyoruz. */
    int blackKingRow,whiteKingRow,i,j;
    char blackKingCol,whiteKingCol;
    for (i=0;i<BOARD_SIZE*BOARD_SIZE && board[i] != 'k';i++){}
    for (j=0;j<BOARD_SIZE*BOARD_SIZE && board[j] != 'K';j++){}
    /*indexleri bulduktan sonra bunlari isPieceMovable fonksiyonunda Col ve Row
olarak gonderecegimiz icin Col ve Row a ceviren fonksiyonumuzla ceviriyoruz.*/
    findColAndRow(j,&whiteKingCol,&whiteKingRow);
    findColAndRow(i,&blackKingCol,&blackKingRow);
   /*yine index gerekli oldugu icin index denklemimizi burada da kullaniyoruz*/
    sourceIndex=(8-sr)*8+(sc-'a');
    targetIndex=(8-tr)*8+(tc-'a');
    if (!isPieceMovable(board,sc,sr,tc,tr))
        /* eger hareket normal sartlarda mumkun degilse yani ornegin duz giden
        kale capraz goturmeye calisiliyorsa direk bunun kontrolu yapilip
        eger gidemiyorsa 0 return ediyoruz. */
        return 0;
    if(isWhite(getPlayer(board,sc,sr)))
    {/* eger White yani buyuk harfler oynuyorsa*/
        if(isInCheck(board)==1)
        {/*eger white in kendisi sahdaysa hamleden once targeti temp e atiyoruz
        cunku hamle sonrasi yine sah olursa hamleyi yapmamamiz yani hamleyi geri
         almamiz gerekiyor. */
            temp = board[targetIndex];
            board[targetIndex]=board[sourceIndex];
            board[sourceIndex]=' ';
            if (isInCheck(board)==1)
            {/*yer degisimi sonrasi tekrar ısIncheck fonksiyonunu cagriyoruz ve
                hareket sonucu hala kendisi sahdaysa hareketi yapamamasi
                gerektigi icin hamleyi geri aliyor ve 1 return ediyoruz. */
                board[sourceIndex]=board[targetIndex];
                board[targetIndex]=temp;
                return 1;
            }
            else if (board[targetIndex]=='K' &&
                     isPieceMovable(board,tc,tr,blackKingCol,blackKingRow))
            {/*board[targetIndex] ile oynanan tas King mi diye bakiyoruz ve
            King oynaniyorsa ve hamleden sonra rakip kingi yiyebilir duruma
           geliyorsa hamleyi geri alarak 1 return ediyoruz.Cunku hamleden sonra
          bizim kingimiz rakip kingi yiyebiliyorsa sira rakipteyken de rakip de
            bizim kingimizi yiyebilir demektir.Yani kendimizi sah yapiyoruz.*/
                board[sourceIndex]=board[targetIndex];
                board[targetIndex]=temp;
                return 1;
            }
            else if (isInCheck(board)==0)
            /* hareket sonrasi sahdan kendini sah dan kurtariyorsa return 2. */
                return 2;
            else
            /*hareket sonrasi sahdan kurtulupta rakibe sah cekiyorsa return 3*/
                return 3;
        }
        else
        {/* eger kendisi sahda degilse hamleyi yap */
            temp = board[targetIndex];
            board[targetIndex]=board[sourceIndex];
            board[sourceIndex]=' ';
            if (isInCheck(board)==1)
            {/* hamle sonucu kendi kendini sah yapiyorsa hamleyi geri al ve
                kendini sah yaptigi icin 1 return et. */
                board[sourceIndex]=board[targetIndex];
                board[targetIndex]=temp;
                return 1;
            }
            else if (board[targetIndex]=='K' &&
                     isPieceMovable(board,tc,tr,blackKingCol,blackKingRow))
            {/*board[targetIndex] ile oynanan tas King mi diye bakiyoruz ve
            King oynaniyorsa ve hamleden sonra rakip kingi yiyebilir duruma
           geliyorsa hamleyi geri alarak 1 return ediyoruz.Cunku hamleden sonra
          bizim kingimiz rakip kingi yiyebiliyorsa sira rakipteyken de rakip de
            bizim kingimizi yiyebilir demektir.Yani kendimizi sah yapiyoruz.*/
                board[sourceIndex]=board[targetIndex];
                board[targetIndex]=temp;
                return 1;
            }
            else if (isInCheck(board)==2)
            /* hareket sonrasi rakibi sah yapiyorsa 3 return et. */
                return 3;
            else
            /* hareket normal bi sekilde gerceklesiyorsa return 2. */
                return 2;
        }
    }
    if(isBlack(getPlayer(board,sc,sr)))
    {/* ayni ihtimalleri kucuk harfler yani Black oynarken de yaziyoruz. */
        if(isInCheck(board)==2)
        {/*eger black in kendisi sahdaysa hamleden once targeti temp e atiyoruz
       cunku hamle sonrasi yine sah olursa hamleyi yapmamamiz yani hamleyi geri
         almamiz gerekiyor. */
            temp = board[targetIndex];
            board[targetIndex]=board[sourceIndex];
            board[sourceIndex]=' ';
            if (isInCheck(board)==2)
            {/*yer degisimi sonrasi tekrar ısIncheck fonksiyonunu cagriyoruz ve
            hareket sonucu hala kendisi sahdaysa hareketi yapamamasi
            gerektigi icin hamleyi temp ile geri aliyor ve 1 return ediyoruz.*/
                board[sourceIndex]=board[targetIndex];
                board[targetIndex]=temp;
                return 1;
            }
            else if (board[targetIndex]=='k' &&
                     isPieceMovable(board,tc,tr,whiteKingCol,whiteKingRow))
            {/*board[targetIndex] ile oynanan tas King mi diye bakiyoruz ve
            King oynaniyorsa ve hamleden sonra rakip kingi yiyebilir duruma
           geliyorsa hamleyi geri alarak 1 return ediyoruz.Cunku hamleden sonra
          bizim kingimiz rakip kingi yiyebiliyorsa sira rakipteyken de rakip de
            bizim kingimizi yiyebilir demektir.Yani kendimizi sah yapiyoruz.*/
                board[sourceIndex]=board[targetIndex];
                board[targetIndex]=temp;
                return 1;
            }
            else if (isInCheck(board)==0)
            /* hareket sonrasi sahdan kendini sah dan kurtariyorsa return 2. */
                return 2;
            else
            /*hareket sonrasi sahdan kurtulupta rakibe sah cekiyorsa return 3*/
                return 3;
        }
        else
        {/* eger kendisi sahda degilse hamleyi yap */
            temp = board[targetIndex];
            board[targetIndex]=board[sourceIndex];
            board[sourceIndex]=' ';
            if (isInCheck(board)==2)
            {/* hamle sonucu kendi kendini sah yapiyorsa hamleyi geri al ve
                kendini sah yaptigi icin 1 return et. */
                board[sourceIndex]=board[targetIndex];
                board[targetIndex]=temp;
                return 1;
            }
            else if (board[targetIndex]=='k' && isPieceMovable(board,tc,tr,whiteKingCol,whiteKingRow))
            {/*board[targetIndex] ile oynanan tas King mi diye bakiyoruz ve
            King oynaniyorsa ve hamleden sonra rakip kingi yiyebilir duruma
           geliyorsa hamleyi geri alarak 1 return ediyoruz.Cunku hamleden sonra
          bizim kingimiz rakip kingi yiyebiliyorsa sira rakipteyken de rakip de
            bizim kingimizi yiyebilir demektir.Yani kendimizi sah yapiyoruz.*/
                board[sourceIndex]=board[targetIndex];
                board[targetIndex]=temp;
                return 1;
            }
            else if (isInCheck(board)==1)
            /* hareket sonrasi rakibi sah yapiyorsa 3 return et. */
                return 3;
            else
            /* hareket normal bi sekilde gerceklesiyorsa return 2. */
                return 2;
        }
    }
    return 0;
}

int isInCheck(char* board)
{/*black ve white oyuncularinin Kinglerinin index i gerekli oldugu icin
    2 tane for dongusuyle Kinglerin indexlerini buluyoruz. */
    int blackKingRow,whiteKingRow,pieceRow,i,j;
    char blackKingCol,whiteKingCol,pieceCol;
    for (i=0;i<BOARD_SIZE*BOARD_SIZE && board[i] != 'k';i++){}
    for (j=0;j<BOARD_SIZE*BOARD_SIZE && board[j] != 'K';j++){}
    /*indexleri bulduktan sonra bunlari isPieceMovable fonksiyonunda Col ve Row
olarak gonderecegimiz icin Col ve Row a ceviren fonksiyonumuzla ceviriyoruz.*/
    findColAndRow(j,&whiteKingCol,&whiteKingRow);
    findColAndRow(i,&blackKingCol,&blackKingRow);
    for (i=0;i<BOARD_SIZE*BOARD_SIZE;i++)
    {/* i 0 dan 64 e kadar tum tabloyu dolasirken bulunan her buyuk harfte
asagidaki ife ve her kucuk harfte de bi asagidaki if e girerek islem yapiyor.*/
        if (isWhite(board[i]) && board[i]!='K')
        {/* Buyuk harfler icin index bulundugunda bu if e giriyor ve asagidaki
            fonksiyonla bu indexi Col ve Row a ceviriyoruz.*/
            findColAndRow(i,&pieceCol,&pieceRow);
            if(isPieceMovable(board,pieceCol,pieceRow,blackKingCol,blackKingRow))
                /* sonra da isPieceMovable da sc sr yerine bulunan buyuk harfi
                ve tc tr yerine de her zaman rakip King tasini yolluyoruz.
                yani bu donguyle herhangi bir tas rakip Kingi yiyebiliyor mu
                diye bakiyoruz ve bir tas dahi rakip King i yiyebiliyorsa
                2 return ederek Black in sah da oldugunu belirtiyoruz. */
                return 2;
        }
        if (isBlack(board[i]) && board[i]!='k')
        {/* Kucuk harfler icin index bulundugunda bu if e giriyor ve asagidaki
            fonksiyonla bu indexi Col ve Row a ceviriyoruz.*/
            findColAndRow(i,&pieceCol,&pieceRow);
            if(isPieceMovable(board,pieceCol,pieceRow,whiteKingCol,whiteKingRow))
                /* sonra da isPieceMovable da sc sr yerine bulunan kucuk harfi
                ve tc tr yerine de her zaman rakip King tasini yolluyoruz.
                yani bu donguyle herhangi bir tas rakip Kingi yiyebiliyor mu
                diye bakiyoruz ve bir tas dahi rakip King i yiyebiliyorsa
                1 return ederek White in sah da oldugunu belirtiyoruz. */
                return 1;
        }
    }
    /* kimse sah da degilse icerdeki hicbir returne takilmadan buraya geliyor
    ve kimse sahda olmadigi icin 0 return ediliyor.Ayrica kingler yanyana gelip
    birbirlerine sah cekiyorlarsa da 0 return ediyoruz cunku bu durumu makeMove
    fonksiyonunda inceliyoruz. */
    return 0;
}
void findColAndRow(int index,char* col,int* row)
{
    /* verilen indexi pointer ile Col ve Row a cevirip return ediyoruz. */
    *col=index%8 + 'a';
    *row=8-(index/8);
}
/*---------------------------------------------------------------------------*/
/*                         End of HW8_141044050.c                            */
/*---------------------------------------------------------------------------*/
