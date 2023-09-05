#include<string.h>
#include<stdio.h>
#include<ctype.h>
int i;
char buffer[20],alpha[10],beta[10];
char obeta[10];
int bindex=0;
//Formula : B->Bc|d   d is beta and c is alpha
    //      B->dB'    
    //      B'->cB'|E
void main(){

    void FilterBeta(char *p,char *beta){
        if(beta[strlen(beta)-1] == p[0]){
            printf("Right Recursive production %s\n",beta);
        }
        else{
           char o_beta[20];
           int oid=0;
            for(int i=0;i<strlen(beta);i++){
                //printf("beta is %s \n",beta);
                if(!isupper(beta[i])){
                    o_beta[oid]=beta[i];
                    oid++;
                    //printf("I am in \n");
                }
            }
            o_beta[oid]='\0';
            printf("\nbeta is %s \n",o_beta);
            oid=0;

        }
    }

    void checkBeta(char *p,int index){
        while(p[index] != '|' && p[index] != '\0'){
            beta[bindex]=p[index];
            bindex++;
            index++;
        }
        beta[index++]='\0';
        index=bindex=0;
        FilterBeta(p,beta);
        
    }

    void findAlpha(char *p,int index){
        while(p[index] != '|' && index<strlen(p)){
            alpha[bindex]=p[index];
            bindex++;
            index++;
        }
        alpha[bindex]='\0';
        printf("\nAplha is %s\n",buffer); 
        index=0;
        bindex=0;
        
    }

    void checkLeftRecursion(char *p,int index){
        if(p[0] == p[index]){
            printf("Left Recursion Exist at index %d \n",index);
            if(p[index+1] == '|' || index+1==strlen(p)){
                printf("No Alpha Found Production with null Alpha\n");
                
            }     
            else{
                i=index+1;  
                findAlpha(p,i);
            }
        }  
        else{
            printf("not Recursion at %d\n",index);
            checkBeta(p,i+1);
        }
    }

    void returnIndex(char *p){
        int len;
        len=strlen(p);
        for(i=0;i<len;i++){
            if(p[i] == '>'){
                checkLeftRecursion(p,i+1);
            }
            else if(p[i] == '|'){
                checkLeftRecursion(p,i+1);
            }
        }
    }

    //Ask user to enter the production
    int n;
    printf("Enter the n number of production you want to enter:\n");
    scanf("%d",&n);
    char p1[30];
    for(int i=0;i<n;i++){
        printf("\nEnter the production format(A->Abb|ba): ");
        scanf("%s",&p1);
        returnIndex(p1);
        printf("****Output***\n");
        printf(" %s \n A->%sA' \n A'->%sA'|E",p1,beta,alpha);

    }
}