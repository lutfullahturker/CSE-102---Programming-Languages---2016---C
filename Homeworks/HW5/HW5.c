/* -----------------------------------------------------------------------  */
/*                                                                          */
/*                   HW05_141044050_Lütfullah_Türker                        */
/*                                                                          */
/*                                                                          */
/* -----------------------------------------------------------------------  */
/*                Created on 5/04/2016 by Lütfullah_Türker                  */
/*                                                                          */
/* Description                                                              */
/* -----------------------------------------------------------------------  */
/*    For the homework V, we have wrote chess program which will take       */
/* commands and arguments from the user, executes the commands              */
/*   and return the result.                                                 */
/*                                                                          */
/*------------------------------------------------------------------------  */


/*--------------------------------------------------------------------------*/
/*                               Includes                                   */
/*--------------------------------------------------------------------------*/
#include <stdio.h>
#include <math.h>

/*---------------------------------------------------------------------------*/
/*                         Function Prototypes                               */
/*---------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------*/
void emptyBuffer();
void initBoard(char *board);
int isPieceMovable(char *board);
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

void main()
{
	char board [64];
	int initComplete = 0;
	char empty;

	int command;
	scanf("%d", &command);

	while(command!=4)
	{
		switch(command)
		{
			case 1: initBoard(board);
				initComplete = 1;
				printf("OK\n");
				break;
			case 2:
				/*Read space character after command number*/
				scanf("%c", &empty);
				if (initComplete)
				{
					if(isPieceMovable(board))
						printf("YES\n");
					else
						printf("NO\n");
				}
				else
				{
					printf("Board is not initialized!\n");
					emptyBuffer();
				}
				break;
			case 3:
				if (initComplete)
					printBoard(board);
				else
					printf("Board is not initialized!\n");
					emptyBuffer();
				break;

			default: printf("Invalid command!\n"); emptyBuffer(); break;
		}
		scanf("%d", &command);
	}
}
void emptyBuffer()
{
	while ( getchar() != '\n' );
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
int isPieceMovable(char *board)
{
    char sourceCol,targetCol,empty;
    int sourceRow,targetRow,sourceIndex,isSuccessful;
    getPosition(&sourceCol,&sourceRow);
  /*degiskenlerimizi tanimladiktan sonra degerinin atanmasi icin "getPosition"
   fonksiyonuna gonderiyoruz.ve "isValidCell" fonksiyonu ile girilen degerlerin
   tabloda olup olmadigini kontrol ediyoruz ve tabloda yoksa '0' return
   ederek ekrana NO basmasini sagliyoruz.ve ayni islemi target col ve row icin
   gerceklestirmeden once kullanicinin girecegi bosluk karakterini okumasi icin
   empty degiskenini scanf ile yolluyor ve ayni islemleri gerceklestiriyoruz */
    if (!isValidCell(sourceCol,sourceRow))
    {   return 0;}
    scanf("%c", &empty);
    getPosition(&targetCol,&targetRow);
    if (!isValidCell(targetCol,targetRow))
    {   return 0;}
    sourceIndex=(8-sourceRow)*8+(sourceCol-'a');
    /* girilen Col ve Row  degiskenlerini tablomuzun hangi elemanina karsilik
    geldigini anlamak icin bir index degiskeni tanimliyoruz.ve bir denklemle
    girilen Col ve Row un tablodaki Indexini buluyoruz.Denklemde
    Col degiskenini char olarak aldigi icin Col u 'a' karakterinden cikariyoruz.
    ornegin Col c girildiyse (sourceCol-'a')=2 oluyor.*/
    switch (board[sourceIndex])
    {
    case 'r':
    case 'R':
        isSuccessful=isRookMovable(board ,sourceCol,sourceRow,targetCol,targetRow);
        if (isSuccessful==1)
            return 1;
        else
            return 0;
        break;
    case 'n':
    case 'N':
        isSuccessful=isKnightMovable(board ,sourceCol,sourceRow,targetCol,targetRow);
        if (isSuccessful==1)
            return 1;
        else
            return 0;
        break;
    case 'b':
    case 'B':
         isSuccessful=isBishopMovable(board ,sourceCol,sourceRow,targetCol,targetRow);
        if (isSuccessful==1)
            return 1;
        else
            return 0;
        break;
    case 'q':
    case 'Q':
        isSuccessful=isQueenMovable(board ,sourceCol,sourceRow,targetCol,targetRow);
        if (isSuccessful==1)
            return 1;
        else
            return 0;
        break;
    case 'k':
    case 'K':
        isSuccessful=isKingMovable(board ,sourceCol,sourceRow,targetCol,targetRow);
        if (isSuccessful==1)
            return 1;
        else
            return 0;
        break;
    case 'p':
    case 'P':
        isSuccessful=isPawnMovable(board ,sourceCol,sourceRow,targetCol,targetRow);
        if (isSuccessful==1)
            return 1;
        else
            return 0;
        break;
    default:
        return 0;
/*switch case de her tas icin kucuk veya buyuk harf girildiginde girilen harfe
 gore o tasin hareket edip edemeyecegini belirledigimiz fonksiyon cagriliyor ve
 bu fonksiyon hareket edemiyorsa 0  return edince ekrana NO basmasi icin if
 condition i ile bunu kontrol ediyoruz. */
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
    else
        return 0;
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

/*---------------------------------------------------------------------------*/
/*                         End of HW5_141044050.c                            */
/*---------------------------------------------------------------------------*/
