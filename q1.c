//Hikmet Terzioglu 161101071
//iki isim&soyisim olmasi durumlari kontrol edildi.
//tek odaya rezervasyon olacagi varsayildi.
//realloc calisiyor
//piazzada bahsedildigi uzere struct arrayi global olusturuldu ve fonksiyonda  arraye alan acildi.
//ve pointeri(arrayi) return ediyor.
//denenmesi icin mainde yorum satirinda alindi.
//bos line kontrolu yapildi.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct{
int day; int month; int year;
} date;
typedef struct{
    int id;
    char firstname[50];
    char surname[50];
    date ind;
    date outd;
    int roomno;

}reservation;
reservation* readReservationFile();
int numOfReservations=4;
reservation* reservations;
int main(){


    //reservation* deneme;
    
    //deneme=readReservationFile();
    //printf("A\n");
    /*for(int i=0;i<numOfReservations;i++){
        
        printf("%d\n",deneme[i].id);            
        printf("%s-%s\n",deneme[i].firstname,deneme[i].surname);            
        printf("%d %d %d\n",deneme[i].ind.day,deneme[i].ind.month,deneme[i].ind.year);
        printf("%d %d %d\n",deneme[i].outd.day,deneme[i].outd.month,deneme[i].outd.year);
        printf("%d\n",deneme[i].roomno);
        printf("*************************\n");

    }*/
    
    
    
}

reservation* readReservationFile(){
    reservations = malloc(numOfReservations * sizeof *reservations);
    FILE *fp;
    int id=0;

    if ((fp = fopen ("reservations.txt", "r")) == NULL) {
        printf("Dosya acma hatasi!");
        exit(1);
    }

    char a;
    int i=0;
    char column[1000];
    int numberOfColumn=0;
    int arrayIndex=0;
    char idc[50];
    int idcf=0;
    
    char firstname[50];
    int indexf=0;
    char surname[50];
    int surnamef=0;

    char datei[50];
    int dateif=0;

    char dateo[50];
    int dateof=0;


    char roomno[50];
    int roomnof=0;

    while((a=fgetc(fp))){
        if(a==EOF){
            if (column[0]=='\0')//bos satir kontrolu
            {
               break;
            }
            
            column[i]='\0';
            
            if(id!=0){
                if(id>=numOfReservations){
                    numOfReservations=numOfReservations*2;
                    reservations = realloc(reservations,(numOfReservations) *sizeof(*reservations));
                    //realloc
                }    
                for(int index=0;index<i;index++){
                    if(column[index]!='\t'){
                        if(numberOfColumn==0){
                            idc[idcf]=column[index];
                            idcf++;
                        
                        }else if(numberOfColumn==1){
                            firstname[indexf]=column[index];
                            indexf++;
                        }else if(numberOfColumn==2){
                            surname[surnamef]=column[index];
                            surnamef++;
                        
                        }else if(numberOfColumn==3){
                            datei[dateif]=column[index];
                            dateif++;
                        
                        }else if(numberOfColumn==4){
                            dateo[dateof]=column[index];
                            dateof++;
                        }else if(numberOfColumn==5){
                            roomno[roomnof]=column[index];
                            roomnof++;
                        
                        }
                        if(column[index+1]=='\0'&&numberOfColumn==5){
                            roomno[roomnof]='\0';
                            int roomnoi=atoi(roomno);
                            reservations[arrayIndex].roomno=roomnoi;
                            roomnof=0;
                            roomno[0]='\0';
                            numberOfColumn=0;
                        }
                    }   
                    else{
                        if(numberOfColumn==0){
                            idc[idcf]='\0';
                            int idres=atoi(idc);
                            reservations[arrayIndex].id=idres;
                            idcf=0;
                            idc[0]='\0';
                            numberOfColumn++;
                            continue;
                        
                        }else if(numberOfColumn==1){
                            firstname[indexf]='\0';
                            strcpy(reservations[arrayIndex].firstname,firstname);
                            indexf=0;
                            firstname[0]='\0';
                            numberOfColumn++;
                            continue;
                        }else if(numberOfColumn==2){
                            surname[surnamef]='\0';
                            strcpy(reservations[arrayIndex].surname,surname);
                            surnamef=0;
                            surname[0]='\0';
                            numberOfColumn++;
                            continue;
                        }else if(numberOfColumn==3){
                            datei[dateif]='\0';
                            char dateday[10];
                            int di=0;
                            char datemonth[10];
                            int mi=0;
                            char dateyear[10];
                            int yi=0;
                            int bosluk=0;
                            
                            for(int index1=0;index1<dateif;index1++){
                                if(bosluk==0&&datei[index1]!=' '){
                                    dateday[di]=datei[index1];
                                    di++;
                                }else if(bosluk==0 && datei[index1]==' '){
                                    bosluk++;
                                    dateday[di]='\0';
                                    int day=atoi(dateday);
                                    reservations[arrayIndex].ind.day=day;   
                                    continue;
                                }else if(bosluk==1 && datei[index1]!=' '){
                                    datemonth[mi]=datei[index1];
                                    mi++;
                                }else if(bosluk==1 && datei[index1]==' '){
                                    bosluk++;
                                    datemonth[mi]='\0';
                                    int month=atoi(datemonth);
                                    reservations[arrayIndex].ind.month=month;
                                    continue;
                                }else if(bosluk==2 && datei[index1+1]!='\0'){
                                    dateyear[yi]=datei[index1];
                                    yi++;
                                }else if(bosluk==2 && datei[index1+1]=='\0'){
                                    dateyear[yi]=datei[index1];
                                    yi++;
                                    dateyear[yi]='\0';
                                    int year=atoi(dateyear);
                                    reservations[arrayIndex].ind.year=year;
                                    break;
                                }

                            }
                            
                            dateif=0;
                            datei[0]='\0';
                            numberOfColumn++;
                            continue;
                            
                            
                        }else if(numberOfColumn==4){
                            dateo[dateof]='\0';
                            char dateday[10];
                            int di=0;
                            char datemonth[10];
                            int mi=0;
                            char dateyear[10];
                            int yi=0;
                            int bosluk=0;
                            
                            for(int index1=0;index1<dateof;index1++){
                                if(bosluk==0&&dateo[index1]!=' '){
                                    dateday[di]=dateo[index1];
                                    di++;
                                }else if(bosluk==0 && dateo[index1]==' '){
                                    bosluk++;
                                    dateday[di]='\0';
                                    int day=atoi(dateday);
                                    reservations[arrayIndex].outd.day=day;   
                                    continue;
                                }else if(bosluk==1 && dateo[index1]!=' '){
                                    datemonth[mi]=dateo[index1];
                                    mi++;
                                }else if(bosluk==1 && dateo[index1]==' '){
                                    bosluk++;
                                    datemonth[mi]='\0';
                                    int month=atoi(datemonth);
                                    reservations[arrayIndex].outd.month=month;
                                    continue;
                                }else if(bosluk==2 && dateo[index1+1]!='\0'){
                                    dateyear[yi]=dateo[index1];
                                    yi++;
                                }else if(bosluk==2 && dateo[index1+1]=='\0'){
                                    dateyear[yi]=dateo[index1];
                                    yi++;
                                    dateyear[yi]='\0';
                                    int year=atoi(dateyear);
                                    reservations[arrayIndex].outd.year=year;
                                    break;
                                }

                            }
                            
                            dateof=0;
                            dateo[0]='\0';
                            numberOfColumn++;
                            continue;
                            
                            
                        }
                    } 
                    


                }
                   
                arrayIndex++;            
                    
            }
            column[0]='\0';
            i=0;
            id++;
            break;    
        }else if(a=='\n'){
            column[i]='\0';
            if (column[0]=='\0')//bos satir kontrolu
            {
               continue;
            }
            if(id!=0){
                
                if(id>=numOfReservations){
                    numOfReservations=numOfReservations*2;
                    reservations = realloc(reservations,(numOfReservations) *sizeof(*reservations));
                    //realloc
                }
                for(int index=0;index<i;index++){
                    if(column[index]!='\t'){
                        
                        if(numberOfColumn==0){
                            idc[idcf]=column[index];
                            idcf++;
                        
                        }else if(numberOfColumn==1){
                            firstname[indexf]=column[index];
                            indexf++;
                        }else if(numberOfColumn==2){
                            surname[surnamef]=column[index];
                            surnamef++;
                        
                        }else if(numberOfColumn==3){
                            datei[dateif]=column[index];
                            dateif++;
                        
                        }else if(numberOfColumn==4){
                            dateo[dateof]=column[index];
                            dateof++;
                        }else if(numberOfColumn==5){
                            roomno[roomnof]=column[index];
                            roomnof++;
                        
                        }
                        if(column[index+1]=='\0'&&numberOfColumn==5){
                            roomno[roomnof]='\0';
                            int roomnoi=atoi(roomno);
                            reservations[arrayIndex].roomno=roomnoi;
                            roomnof=0;
                            roomno[0]='\0';
                            numberOfColumn=0;
                            break;
                        }
                    }   
                    else if(column[index]=='\t'){
                        
                        
                        if(numberOfColumn==0){
                            idc[idcf]='\0';
                            int idres=atoi(idc);
                            reservations[arrayIndex].id=idres;
                            idcf=0;
                            idc[0]='\0';
                            numberOfColumn++;
                            continue;
                        
                        }else if(numberOfColumn==1){
                            firstname[indexf]='\0';
                            strcpy(reservations[arrayIndex].firstname,firstname);
                            indexf=0;
                            firstname[0]='\0';
                            numberOfColumn++;
                            continue;
                        }else if(numberOfColumn==2){
                            surname[surnamef]='\0';
                            strcpy(reservations[arrayIndex].surname,surname);
                            surnamef=0;
                            surname[0]='\0';
                            numberOfColumn++;
                            continue;
                        }else if(numberOfColumn==3){
                            datei[dateif]='\0';
                            char dateday[10];
                            int di=0;
                            char datemonth[10];
                            int mi=0;
                            char dateyear[10];
                            int yi=0;
                            int bosluk=0;
                            
                            for(int index1=0;index1<dateif;index1++){
                                if(bosluk==0&&datei[index1]!=' '){
                                    dateday[di]=datei[index1];
                                    di++;
                                }else if(bosluk==0 && datei[index1]==' '){
                                    bosluk++;
                                    dateday[di]='\0';
                                    int day=atoi(dateday);
                                    reservations[arrayIndex].ind.day=day;   
                                    continue;
                                }else if(bosluk==1 && datei[index1]!=' '){
                                    datemonth[mi]=datei[index1];
                                    mi++;
                                }else if(bosluk==1 && datei[index1]==' '){
                                    bosluk++;
                                    datemonth[mi]='\0';
                                    int month=atoi(datemonth);
                                    reservations[arrayIndex].ind.month=month;
                                    continue;
                                }else if(bosluk==2 && datei[index1+1]!='\0'){
                                    dateyear[yi]=datei[index1];
                                    yi++;
                                }else if(bosluk==2 && datei[index1+1]=='\0'){
                                    dateyear[yi]=datei[index1];
                                    yi++;
                                    dateyear[yi]='\0';
                                    int year=atoi(dateyear);
                                    reservations[arrayIndex].ind.year=year;
                                    break;
                                }

                            }
                            
                            dateif=0;
                            datei[0]='\0';
                            numberOfColumn++;
                            continue;
                            
                            
                        }else if(numberOfColumn==4){
                            dateo[dateof]='\0';
                            char dateday[10];
                            int di=0;
                            char datemonth[10];
                            int mi=0;
                            char dateyear[10];
                            int yi=0;
                            int bosluk=0;
                            
                            for(int index1=0;index1<dateof;index1++){
                                if(bosluk==0&&dateo[index1]!=' '){
                                    dateday[di]=dateo[index1];
                                    di++;
                                }else if(bosluk==0 && dateo[index1]==' '){
                                    bosluk++;
                                    dateday[di]='\0';
                                    int day=atoi(dateday);
                                    reservations[arrayIndex].outd.day=day;   
                                    continue;
                                }else if(bosluk==1 && dateo[index1]!=' '){
                                    datemonth[mi]=dateo[index1];
                                    mi++;
                                }else if(bosluk==1 && dateo[index1]==' '){
                                    bosluk++;
                                    datemonth[mi]='\0';
                                    int month=atoi(datemonth);
                                    reservations[arrayIndex].outd.month=month;
                                    continue;
                                }else if(bosluk==2 && dateo[index1+1]!='\0'){
                                    dateyear[yi]=dateo[index1];
                                    yi++;
                                }else if(bosluk==2 && dateo[index1+1]=='\0'){
                                    dateyear[yi]=dateo[index1];
                                    yi++;
                                    dateyear[yi]='\0';
                                    int year=atoi(dateyear);
                                    reservations[arrayIndex].outd.year=year;
                                    break;
                                }

                            }
                            
                            dateof=0;
                            dateo[0]='\0';
                            numberOfColumn++;
                            continue;
                            
                            
                        }
                    } 
                    


                }
                   
                arrayIndex++;            
                    
            }
            column[0]='\0';
            i=0;
            id++;
            numberOfColumn=0;
            

        }else{
            column[i]=a;
            i++;    
        }
        
    }
    
    
    
    fclose(fp);
    

   return reservations;




}
