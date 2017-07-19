/* -----------------------------------------------------------------------  */
/*                                                                          */
/*                   HW10_141044050_Lutfullah_Turker                        */
/*                                                                          */
/*                                                                          */
/* -----------------------------------------------------------------------  */
/*                Created on 02/05/2016 by Lutfullah_Turker                 */
/*                                                                          */
/* Description                                                              */
/* -----------------------------------------------------------------------  */
/* in this homework we have written simple database management system which */
/*  reads information about a department in a university such as students,  */
/*       lectures, and professors and outputs a file which includes some    */
/*                      summary information.                                */
/*                                                                          */
/*------------------------------------------------------------------------  */

/*--------------------------------------------------------------------------*/
/*                               Includes                                   */
/*--------------------------------------------------------------------------*/
#include <stdio.h>
#include <string.h>
typedef struct{
    int id;
    char name[30];
    char surname[30];
} student_t;
typedef struct{
    char degree[30];
    int lecId;
    char name[30];
    char surname[30];
} lecturer_t;
typedef struct{
    int code;
    char name[30];
    int lecturerId;
} lecture_t;
typedef struct{
    char classRoomName[30];
    char day[30];
    int start;
    int duration;
    int lecCode;
} schedule_t;
typedef struct{
    int stuId;
    int lecCode;
} takenCourse_t;
typedef struct{
    char lecName[25];
    char lecrName[25];
    char lecrSName[25];
    int count;
} lecture_lecturer_t;

/*---------------------------------------------------------------------------*/
/*                         Function Prototypes                               */
/*---------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------*/
void fillOutputFile(student_t *students,lecture_t *lectures,
lecturer_t *lecturers,schedule_t *schedules,takenCourse_t *takenCourses
,int stuNum,int lectureNum,int lecturerNum,int takenCNum,int scheduleNum);
/* output dosyasini doldurmak icin kullandigimiz fonksiyon prototipi. */
int main (void)
{/* struct arraylerimizi tanimliyoruz. */
    student_t students[30];
    lecture_t lectures[30];
    lecturer_t lecturers[30];
    schedule_t schedules[30];
    takenCourse_t takenCourses[30];
    int stuNum,lectureNum,lecturerNum,takenCNum,scheduleNum;
    /* arraylerde kacar eleman oldugunu aldigimiz eleman sayisi degiskenlerini
    tanimliyoruz ve file pointer ile input.dat dosyasini aciyoruz. */
    FILE *filep = fopen("input.dat","rb");
    if (filep==NULL)
    {/* dosya acilamazsa ekrana dosya acma hatasi seklinde bir hata basiyor.*/
        printf("input.dat file open error.\n");
        return 0;
    }/*ve input dosyasi acilmadiysa bos yere output dosyasi da olusturmamasi
    icin return yapip programdan cikiyoruz. */
    else
    {/* input acilirsa sirayla struct arrayinin alinacak eleman sayisini
        input dosyasindan alip tekrar fread fonksiyonuyla o eleman sayisi kadar
        struct okuyoruz ve struct arrayimizi dolduruyoruz. */
        fread(&stuNum,sizeof(int),1,filep);
        fread(students,sizeof(student_t),stuNum,filep);
        fread(&lecturerNum,sizeof(int),1,filep);
        fread(lecturers,sizeof(lecturer_t),lecturerNum,filep);
        fread(&lectureNum,sizeof(int),1,filep);
        fread(lectures,sizeof(lecture_t),lectureNum,filep);
        fread(&scheduleNum,sizeof(int),1,filep);
        fread(schedules,sizeof(schedule_t),scheduleNum,filep);
        fread(&takenCNum,sizeof(int),1,filep);
        fread(takenCourses,sizeof(takenCourse_t),takenCNum,filep);
        fclose(filep);
        /*tum arreylerimizi doldurduktan sonra input.dat in tamamini structlara
        aktardigimiz icin bu dosyayi kapatiyoruz. */
    }
    /* daha sonra doldurdugumuz structlari output.txt dosyasina uygun bir
 sekilde yerlestirmek icin output icin olusturdugumuz fonksiyonu cagiriyoruz.*/
    fillOutputFile(students,lectures,lecturers,schedules,takenCourses
                    ,stuNum,lectureNum,lecturerNum,takenCNum,scheduleNum);
    return 0;
}
void fillOutputFile(student_t *students,lecture_t *lectures,
lecturer_t *lecturers,schedule_t *schedules,takenCourse_t *takenCourses
,int stuNum,int lectureNum,int lecturerNum,int takenCNum,int scheduleNum)
{/* lecture-lecturer bolumunun sonundaki dersi alan ogrenci sayisini ve tum
    lecture-lecturer bolumunun satirlarini kaydetmek icin lecture_r struct
    arrayini olusturuyoruz. */
    int i,j,k,l,m,count;
    char dayArr[7][4];
    /*gunleri tuttugumuz arrayimiz en fazla 7 gun ve bir gun de 3 harfli 
    yazildigi icin ve sonu null olcagindan boyutlarini boyle yapiyoruz. */
    lecture_lecturer_t lecture_r[30];
    /*bu arrayin boyutu normalde lectureNum kadar olmasi gerekiyor fakat ISO
    C90 array boyutu variable oldugunda uyari veriyor.Bu yuzden boyutu en fazla
    olabilecek lectureNum kadar yani 30 kadar yapiyoruz.Fakat islemleri yine
    lectureNum  seklinde yapiyoruz. */
    FILE *filep2 = fopen("output.txt","w");
    for (i=0;i<lectureNum;i++)
        lecture_r[i].count=0;
        /*baslangicta her ders icin dersi alan ogrenci sayisinin 0 olmasini
        saglamak icin for dongusu ile hepsini 0 yapiyoruz. */
    if (filep2 == NULL)
        /* output.txt dosyasi olusturulamiyorsa hata mesaji verip islem
        yapmamasi icin bu if i koyuyoruz. */
        printf("output.txt file open error.\n");
    else
    {/*  eger dosya acilirsa yazma islemlerini yapmak icin else'e giriyor.*/
        for (i=0;i<takenCNum;i++)
        {/* bu for ile takenCourses arrayi geziliyor. */
            for (j=0;j<lectureNum;j++)
            {/* bu for ile de lecture array elemanlari geziliyor. */
            /* ve takenCourses arrayindeki ders kodu ile lecture'in code'si
            eslesirse dersi alan bir ogrenci bulunmus oluyor ve o dersin count
            degiskeni 1 artarak dersi alanlara bir ogrenci ekleniyor.Bu sekilde
         giderek her ders icin dersi alan ogrenciler tespit edilip yaziliyor.*/
                if (takenCourses[i].lecCode==lectures[j].code)
                    lecture_r[j].count++;
            }
        }
        for (i=0;i<lectureNum;i++)
        {/*bu dongude lecture_r arrayini dolduruyoruz. */
            strcpy(lecture_r[i].lecName,lectures[i].name);
            for (j=0;j<lecturerNum;j++)
                if(lecturers[j].lecId==lectures[i].lecturerId)
                {/* lecturers in id si ile lectures in id si eslestiginde
                    lecturer in name i lecture_r in namesine yaziliyor.Ayni
                    sekilde surname de yaziliyor. */
                    strcpy(lecture_r[i].lecrName,lecturers[j].name);
                    strcpy(lecture_r[i].lecrSName,lecturers[j].surname);
                }
        }
/*lecture-lecturer bolumunu arraye doldurma islemi bittikten sonra output.txt
   dosyamiza yazma islemine basliyoruz. */
        fprintf(filep2,"Lecture-Lecturer\n");
        for (i=0;i<lectureNum;i++)
        {
/*dongu ile elemanlari sirayla yazip alt satira gecip diger elemani yaziyoruz*/
            fprintf(filep2,"%s",lecture_r[i].lecName);
            fprintf(filep2," %s %s",lecture_r[i].lecrName,
            lecture_r[i].lecrSName);
            fprintf(filep2," %d\n",lecture_r[i].count);
        }
        fprintf(filep2,"\nStudent-Lecture\n");
/*lecture-Lecturer bolumu bittikten sonra student-Lecture bolumunu yaziyoruz.*/
        for (i=0;i<stuNum;i++)
        {/*ogrenci sayisi kadar satir olacagi icin bu sayi kadar donen dongu
            icinde output dosyasina yazdiriyoruz.*/
            count=0;
            fprintf(filep2,"%d %s ",students[i].id,students[i].name);
            fprintf(filep2,"%s ",students[i].surname);
            for (j=0;j<takenCNum;j++)
    /*bu dongude ogrencinin aldigi ders sayisini her alinan derste count 1
      arttirarak buluyoruz.ve output dosyasina yaziyoruz.  */
                if (takenCourses[j].stuId == students[i].id)
                    count++;
            fprintf(filep2,"%d\n",count);
        }
        fprintf(filep2,"\nStudent-Day\n");
        for (i=0;i<stuNum;i++)
        {/*ogrenci sayisi kadar satir olacagi icin bu sayi kadar donen dongu
            icinde output dosyasina yazdiriyoruz.*/
            fprintf(filep2,"%d %s ",students[i].id,students[i].name);
            fprintf(filep2,"%s ",students[i].surname);
    /*buraya kadar kolay bir sekilde ogrenci bilgilerini dosyaya yaziyoruz.
 asagidaki donguler tamamen bir ogrencinin ayni gun icinde iki dersi olursa
 output.txt dosyasina o gunun adinin iki kere yazilmasini engellemek icindir.*/
            m=0;
            for (j=0;j<7;j++)
            /*ders olan gunleri tuttugumuz dayArr arrayimizin her elemaninin
            ilk harfini null yapiyoruz.Cunku sonda bir sonraki eleman null ise
            virgul koyma seklinde bir if atayarak bunu kullanacagiz. */
                dayArr[j][0]='\0';
            for (j=0;j<takenCNum;j++)
            /* ogrencileri gezerken alinan tum dersleri de geziyor.ve ogrenci
    id siyle dersi alan ogrenci id si eslestiginde asagidaki donguye gidiyor.*/
                if (students[i].id==takenCourses[j].stuId)
                    for(k=0;k<scheduleNum;k++)
                /*bu dongude ise schedule arrayini  gezerek alinan dersin kodu
               ile schedule daki dersin kodunu eslestirip o dersin scheduledeki
                karsiligini buluyoruz . */
                        if (takenCourses[j].lecCode==schedules[k].lecCode)
                        {/*bulduktan sonra tekrar schedule kadarlik bir for
                        ile dayArr imizdaki gunler ile scheduledeki gunleri
                        karsilastiriyoruz.ve count tutarak bir ogrencinin ayni
                        gunde birden fazla dersi varsa o gunun output.txt
                        dosyasina iki kere yazilmasini engelliyoruz. */
                            count=0;
                            for (l=0;l<7;l++)
                                if(strcmp(dayArr[l],schedules[k].day)==0)
                                    count++;
                            if (count==0)
                                    strcpy(dayArr[m++],schedules[k].day);
                        }
            for (j=0;j<7;j++)
            {/*ayni gun iki kere yazilmayacak sekilde dayArra arrayimizi
                doldurduktan sonra sirayla gunlerimizi yaziyoruz ve sadece son
                yazilan gunden sonra virgul yazilmayacagi icin yazilan gun den
                sonraki elemanin ilk harfi null degil ise virgul koy diyoruz ve
                bu sekilde son gunden sonraki elemanin ilk harfini yukarda null
                yaptigimiz icin ona virgul koyulmuyor.*/
                if (dayArr[j][0] != '\0')
                    fprintf(filep2,"%s",dayArr[j]);
                if (dayArr[j+1][0] != '\0' && j+1 != 7)
                    fprintf(filep2,",");
            }
            fprintf(filep2,"\n");
        }/*yazma isi bittiginde dosyamizi kapatiyoruz. */
        fclose(filep2);
    }
}
/*---------------------------------------------------------------------------*/
/*                         End of HW10_141044050.c                            */
/*---------------------------------------------------------------------------*/
