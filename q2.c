//Hikmet Terzioglu 161101071
//bos line kontrol edildi.
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
    char filename[100];
    players = malloc(numOfPlayers * sizeof *players);//array olusturuldu.
    printf("Please enter a file name and press enter\n");
    scanf("%s",filename);
    printf("Please enter an integer\n");
    int k;
    scanf("%d",&k);
    FILE *fp;
    int id=0;//lines

    if ((fp = fopen (filename, "r")) == NULL) {
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

    int scores[id-1];
    for(int ii=0;ii<id-1;ii++){
        scores[ii]=players[ii].point;
        
    }
    //sorting
    int number=0;
    for (int ilk = 0; ilk <id-1; ++ilk){ 
        
        for (int son = ilk + 1; son < id-1; ++son) 
        {
            if (scores[ilk] < scores[son]) 
            {
                number = scores[ilk];
                scores[ilk] = scores[son];
                scores[son] = number;
            }
        }
    }
    for(int ii=0;ii<k;ii++){
        for(int jj=0;jj<id-1;jj++){
            if(players[jj].point==scores[ii]){
                printf("%s\t%d\n",players[jj].firstname,scores[ii]);

            }
            
        }
    }





    
}