//Hikmet Terzioglu 161101071
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct{
    char firstname[50];
    int point;
 
}player;
int numOfPlayers=1000;//initial.
int main(){
    player* players;
    char filenameinput[100];
    char old_scores[1000];//max 100 olacagi varsayildi.
    char new_scores[1000];//max 100 olacagi varsayildi.
    
    char temp,temp1;
    players = malloc(numOfPlayers * sizeof *players);
    printf("Please enter a input file name and press enter:\n");//piazzada soylenen sekilde.
    scanf("%s",filenameinput);
    scanf("%c",&temp);
    printf("Please enter will be deleted scores:");//piazzada soylenen sekilde.
    fgets(old_scores,1000,stdin);
    
    
    
    int lengthold=strlen(old_scores);
    int lengthnew=strlen(new_scores);
    //skor sayisini bulmak.
    int skor_sayisi=0;
    for(int h=0;h<lengthold;h++){
        if(old_scores[h]==' '){
            skor_sayisi++;
        }
    }
    
    int old_scores_in[skor_sayisi+1];//bosluk sayisinin bir fazlasi.
    int new_scores_in[skor_sayisi+1];//bosluk sayisinin bir fazlasi.
    char sayio[100];
    int sayi_indexo=0;
    int array_old_index=0;
    for(int h1=0;h1<lengthold;h1++){
        if (old_scores[h1+1]=='\0'){
            sayio[sayi_indexo]=old_scores[h1];
            sayio[sayi_indexo+1]='\0';
            
            int deger=atoi(sayio);
            old_scores_in[array_old_index]=deger;
        
            break;
        }else if (old_scores[h1]!=' '){
            sayio[sayi_indexo]=old_scores[h1];
            sayi_indexo++;
        }else if(old_scores[h1]==' '){
            sayio[sayi_indexo]='\0';
            sayi_indexo=0;
            int deger=atoi(sayio);
            old_scores_in[array_old_index]=deger;
            array_old_index++;
        }
        

    }
   

    
    
    
    
    FILE *fp;
    int id=0;//lines

    if ((fp = fopen (filenameinput, "r")) == NULL) {
        printf("Dosya acma hatasi!");
        exit(1);
    }

    char a;
    char column[1000];
    int i=0;
    int arrayIndex=0;
    while(a=fgetc(fp)){
        
        if(a==EOF){
            if (column[0]=='\0')//bos satir kontrolu
            {
               break;
            }
            column[i]='\0';
            if(id!=0){
                if(id>=numOfPlayers){
                    numOfPlayers=numOfPlayers*2;
                    players = realloc(players,(numOfPlayers) *sizeof(*players));
                    //realloc
                }
                char name[50];
                int nameindex=0;
                char score[50];
                int scoreindex=0;
                
                int kontrol=0;
                for(int index=0;index<i;index++){
                    if(kontrol==0&&column[index]!='\t'){
                        name[nameindex]=column[index];
                        nameindex++;

                    }else if(kontrol==0&&column[index]=='\t'){
                        name[nameindex]='\0';
                        strcpy(players[arrayIndex].firstname,name);
                        kontrol++;
                        continue;
                    }else if(kontrol==1&&column[index+1]!='\0'){
                        score[scoreindex]=column[index];
                        scoreindex++;
                        
                    }else if (kontrol==1&&column[index+1]=='\0'){
                        score[scoreindex]=column[index];
                        scoreindex++;
                        score[scoreindex]='\0';
                        int point=atoi(score);
                        players[arrayIndex].point=point;
                    }
                    
                    

                } 
                arrayIndex++;
                
            }
            column[0]='\0';
            i=0;
            id++;
            break;
        
        }else if(a=='\n'){
            if (column[0]=='\0')//bos satir kontrolu
            {
               continue;
            }
            column[i]='\0';
            if(id!=0){
                if(id>=numOfPlayers){
                    numOfPlayers=numOfPlayers*2;
                    players = realloc(players,(numOfPlayers) *sizeof(*players));
                    //realloc
                }
                char name[50];
                int nameindex=0;
                char score[50];
                int scoreindex=0;
                
                int kontrol=0;
                for(int index=0;index<i;index++){
                    if(kontrol==0&&column[index]!='\t'){
                        name[nameindex]=column[index];
                        nameindex++;

                    }else if(kontrol==0&&column[index]=='\t'){
                        name[nameindex]='\0';
                        strcpy(players[arrayIndex].firstname,name);
                        kontrol++;
                        continue;
                    }else if(kontrol==1&&column[index+1]!='\0'){
                        score[scoreindex]=column[index];
                        scoreindex++;
                        
                    }else if (kontrol==1&&column[index+1]=='\0'){
                        score[scoreindex]=column[index];
                        scoreindex++;
                        score[scoreindex]='\0';
                        int point=atoi(score);
                        players[arrayIndex].point=point;
                    }
                    
                    

                } 
                arrayIndex++;
                
            }
            column[0]='\0';
            i=0;
            id++;
        }else{
            column[i]=a;
            i++;


        }
        
        

    }
    fclose(fp);
    
    //dosyaya yazdirma.
    if ((fp=fopen("updated_scores_q4.txt", "w+")) == NULL) {
      printf("Dosya açılamadı!\n");
      exit(1);
    }
    
    
    for(int ii=0;ii<skor_sayisi+1;ii++){
        for(int j=0;j<id-1;j++){
            if (players[j].point==old_scores_in[ii])
            {
                players[j].firstname[0]='\0';
                players[j].point=-100000;
            }
        
        }

 
    }
   
    
    
    
    fprintf(fp,"%s\t%s","Player","Score\n");
    fflush(fp);    
    for(int i=0;i<id-1;i++){
        if (players[i].firstname[0]!='\0')
        {
            fprintf (fp,"%s\t%d\n", players[i].firstname,players[i].point);
            fflush(fp);    
        }
        
        
    }

    fclose(fp);

    
}