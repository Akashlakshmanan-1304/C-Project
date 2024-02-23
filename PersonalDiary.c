#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int i=0;
struct Title{
char titles[20];
}obj[100];
void Choice();
int ch;
char DicName[20],DicData[1000],DicDir[200],YesOrNo;
FILE *create;
//Basic Info
void Basic_Info(){
printf("Enter Diary Title(Can't Exceed 20):");
    getchar();
    scanf("%s",DicName);
    
    
}
//Create
void Create(){
    Basic_Info();
    strcat(obj[i].titles,DicName);
    i++;
    strcat(DicName,".txt");
    if(strlen(DicName)>20){
        printf("Name Exceeds Limit!Try Again........\n");
        Create();
    }
    else{
        create=fopen(DicName,"w");
        printf("Enter Data to be added :           ");
        getchar();
        fgets(DicData,sizeof(DicData),stdin);
        fprintf(create,"%s",DicData);
        printf("\n*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*\n");
        printf("Your Data Added Successfully!\n");
        printf("*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*\n");
        fclose(create);
    }
}
//Update
void Update(){
    Basic_Info();
    strcat(DicName,".txt");
        create=fopen(DicName,"a");
        printf("Enter Data to be updated          :");
        getchar();
        fgets(DicData,sizeof(DicData),stdin);
        fprintf(create,"%s",DicData);
        printf("\n*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*\n");
        printf("Your Data Updated Successfully!\n");
        printf("*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*\n");
        fclose(create);
    }
//Rewrite
void Rewrite(){
    Basic_Info();
    strcat(DicName,".txt");
        create=fopen(DicName,"w");
        printf("Are you sure to delete existing content!........\n");
         printf("[y for YES/n for NO]              :");
        getchar();
        scanf("%c",&YesOrNo);
        if(YesOrNo=='y'||YesOrNo=='Y'){
            printf("Enter Data to be rewrited         :");
            getchar();
            fgets(DicData,sizeof(DicData),stdin);
            fprintf(create,"%s",DicData);
            printf("\n*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*\n");
            printf("Your Data Rewrited Successfully!");
            printf("\n*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*\n");

            fclose(create);
        }
        else if(YesOrNo=='n'||YesOrNo=='N')
            exit(0);
        else{
            printf("Enter Correct Choice!");
            Choice();
        }
        
}
//Delete
void Delete(){
    Basic_Info();
    strcat(DicName,".txt");
    printf("\n---------------------------------------------------------\n");
    printf("\nAre you sure to delete the file!........\n");
    printf("[y for YES/n for NO]              :");
    getchar();
    scanf("%c",&YesOrNo);
    if(YesOrNo=='y'||YesOrNo=='Y'){
        if(remove(DicName)==0)
        {
        printf("\n*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*\n");
        printf("File Deletion Successfull!\n");
        printf("*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*\n");
        }
        else
        printf("\nFile Not Found!\n");
    }
    else if(YesOrNo=='n'||YesOrNo=='N')
            exit(0);
    else{
            printf("\nEnter Correct Choice!\n");
            Choice();
    }
}
//View
void View(){
    Basic_Info();
    strcat(DicName,".txt");
    create=fopen(DicName,"r");
    printf("\n");
    while (fgets(DicData, sizeof(DicData), create) != NULL) {
        // Process the data as needed
        printf("%s", DicData);
    }
    fclose(create);
    printf("\n---------------------------------------------------------\n");
    printf("\t\tEnd of File!");
    getchar();
}
//Loop
void Loop(){
    printf("\n---------------------------------------------------------\n");
    printf("\nDo you want to continue other operation........\n");
    printf("[y for YES/n for NO]              :");
    scanf("%c",&YesOrNo);
    if(YesOrNo=='y'||YesOrNo=='Y')
    Choice();
    else if(YesOrNo=='n'||YesOrNo=='N'){
            exit(0);
            printf("\n*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*\n");
            printf("Thank You .....Bye!");
            printf("\n*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*\n");
    }
        else{
            printf("\nEnter Correct Choice!\n");
            Choice();
        }
}
//Show
void Show(){
    int j;
    if(i==0)
        printf("No Diary Created yet.....!");
    else
    {
        printf("\n==========Available Diaries==========\n");
        for(j=0;j<i;j++)
        printf("%d. %s\n",j+1,obj[j].titles);
    }
}
void Choice(){
    printf("\n---------------------------------------------------------\n");
    printf("1.Create New Diary\n2.Update Data\n3.Rewrite\n4.Delete\n5.Read\n6.View Diaries\n7.Exit\n");
    printf("\n---------------------------------------------------------\n");
    printf("Enter your choice                 :");
    scanf("%d",&ch);
    switch(ch){
        case 1:
        Create();
        Loop();
        break;
        case 2:
        Update();
        Loop();
        break;
        case 3:
        Rewrite();
        Loop();
        break;
        case 4:
        Delete();
        Loop();
        break;
        case 5:
        View();
        Loop();
        break;
        case 6:
        Show();
        Loop();
        exit(0);
        break;
        case 7:
        exit(0);
        break;
        default:
        printf("\nEnter correct Choice!\n");
        Choice();

    }
}

int main(){
    printf("\n*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*\n");
    printf("\t\tHello!Welcome Back");
    printf("\n*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*\n");
    Choice();
}