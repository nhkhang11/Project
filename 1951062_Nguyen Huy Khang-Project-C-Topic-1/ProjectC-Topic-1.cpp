// C PROHECT - TOPIC 1
// Write the program to manage stack of students of some basic information such as
// name, ID, age, scores with all operations such as push, pop, …. Use functions 
// and dynamic stack.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node
{
    int ID;
    char name[500];
    int age;
    float math,physics,chemistry;
    float GPA;
    struct node *link;
}*top = NULL;

void push(int i,int n,char string[],struct node *temp);
void display();
void check(int i,struct node *temp);
void remain(int i);
void del(struct node *temp);
void lowest(struct node *temp);

// the st_count func is used for counting the number of input into the stack
// so we can use this function to check the stack is full or not
int st_count()
{
    int count = 0;
    struct node *temp;
    temp = top;
    while (temp != NULL)
    {
        temp = temp->link;
        count++;
    }
    return count;
}

//change first character to capital and delete redudant space

void fix (char str[])
{   // the first one is used for change name to
    //standard format with capital letter of each word of name.
    int a,b;
    for ( a = 0; str[a] != '\0'; a++)
    {
        if (str[a] >= 'A' && str[a] <= 'Z') str[a] += 32;
        if (str[a - 1] == ' ' || a == 0)
        {
            if (str[a] >= 'a' && str[a] <= 'z')
                str[a] = str[a] - 32;
        }
    }
    // the second one is used for deleting
    //redundant blank between words.
    while(str[0] == ' ') strcpy(&str[0], &str[1]);
    
    for(b = 0; b < strlen(str) - 1; b++)
    {   if(str[b] == ' ' &&str[b+1] == ' ')
        {
            strcpy( &str[b], &str[b+1]);
            b--;
        }
    }
    while(str[strlen(str) - 1] == ' '){
            strcpy(&str[strlen(str) - 1], &str[strlen(str)]);
    }

}

// push infomation of student into stack

void push(int i,int n,char string[100],struct node *temp){
    int count;
// the function below is used for counting the number of input into the stack
    count = st_count();
// checking the stack is full or not.
// if the stack isn't full, we can input more.
    if (count <= n - 1)
    {
    printf("\n-----Enter info of the student-----\n");
    do{
    printf("\nID: ");
    scanf("%d",&(temp+i) -> ID);
    }while((temp) ->ID<=0);
    string[100]=getchar();
    printf("\nName: ");
    gets(string);
    fix(string);
    strcpy((temp+i)->name,string);
    do{
    printf("\nAge: ");
    scanf("%d",&(temp+i) ->age);
    }while((temp+i) ->age <= 0);
    do{
    printf("\nMath: ");
    scanf("%f",&(temp+i) -> math);
    }while((temp+i) ->math >10 || 0 > (temp+i) ->math );
    do{
    printf("\nPhysics: ");
    scanf("%f",&(temp+i) -> physics);
    }while((temp+i) ->physics >10 || 0 > (temp+i) ->physics );
    do{
    printf("\nChemistry: ");
    scanf("%f",&(temp+i) -> chemistry);
    }while((temp+i) ->chemistry >10 || 0 > (temp+i) ->chemistry );
// calculate the average of three subject = GPA = (math+physics+chemistry)/3

    (temp+i) ->GPA=(((temp+i) ->math)+((temp+i) ->physics)+((temp+i) ->chemistry))/3;
    
    (temp+i)->link = NULL;
    if (top == NULL)
    {
        top = (temp + i);
    }else
    {
        (temp + i)->link = top;
        top = (temp + i);
    }
    }
    else
        printf("SORRY! STACK FULL\n");
// if the stack is full, it will print this sentence "SORRY! STACK FULL".
}
 

// the info function helps to print out all the infomation of students
void info(int ID,char name[100],int age,float math,float physics,float chemistry,float GPA){
    printf("\nID: %d",ID);
    printf("\nName: %s",name);
    printf("\nAge: %d",age);
    printf("\nMath: %.2f",math);
    printf("\nPhysics: %.2f",physics);
    printf("\nChemistry: %.2f",chemistry);
    printf("\nGPA: %.2f\n",GPA);
}

// print out the list of students have been inputed 
void display(){
    struct node *ptr;
    printf("\n-----List-----\n\n");
    for(ptr=top; ptr!=NULL; ptr=ptr->link){
        info(ptr->ID, ptr->name,ptr->age,ptr->math,ptr->physics,ptr->chemistry,ptr->GPA);
        printf("\n--------------------------\n");
    }
    
}

// enter ID to find the infomation 
void check(int i,struct node *temp){
    struct node *ptr1;
    ptr1 = temp;
    int find;
    int count = 0;
    printf("\nInput ID to find info: "); // input the ID that you want to find
    scanf("%d",&find);
     
// we use loop to check each student until we find the same ID, if there is no similiar, ID not found
    for(ptr1=top; ptr1!=0; ptr1=ptr1->link)
    {
        if (find == ptr1->ID)
        {
            info(ptr1->ID, ptr1->name,ptr1->age,ptr1->math,ptr1->physics,ptr1->chemistry,ptr1->GPA);
            count ++; // this is used for avoid te case "Cannot find this ID."
        }
    }
    if (count==0)
        {
            printf("\nCannot find this ID.");
            
        }
    
}

// delete the student just input into the stack
void del(int i, struct node *temp){
    if (top == NULL)
        printf("**List is empty**\n");
    else
    {
        top = top->link;
        printf("\nDeleted.\n");
    }
}

// finding the academic ability of students
void lowest(struct node *temp){
    struct node *low;
    low=temp;
    
  for(low=top; low!=0; low=low->link)
    {   printf("\nID: %d\tName: %s\tGPA: %.2f\tAcademic ability: ",low ->ID,low -> name,low -> GPA);
        if(low -> GPA >= 8){ 
            printf("Excellent\n");
        }else if(low -> GPA >= 6.5){
            printf("Good\n");
        }else if(low -> GPA >= 4){
            printf("Average\n");
        }else printf("Below Average\n");
    }
    
}

// checking the stack is full or not and also checking number of student in the list

void stack_full(int n)
{
    int count;
 
    count = st_count();
    if (count == n)
    {   
        printf("\nList is full\n");
        printf("\nNumber of student in the list: %d/%d\n",count,n);
    }
    else
    {
        printf("\nList is not full.\n");
        printf("\nNumber of student in the list: %d/%d\n",count,n);
    }
    
}

int main()
{
    int n;
    char string[500];
    int choice;
    int i=0;
    struct node *temp;
    temp = (struct node*)malloc(sizeof(struct node));
    printf("\nEnter initial size for the list: "); // input the size of stack
	scanf("%d",&n);
   while(1)
    {
        printf("\n----MENU----\n\n");
        printf("1/ Insert info\n");
        printf("2/ Export List\n");
        printf("3/ Check if stack is full\n");
        printf("4/ Check info\n");
        printf("5/ Academic ability\n");
        printf("6/ Delete the student on the top list\n");
        printf("7/ Exit\n");
        printf("\nEnter the choice: ");
        scanf("%d", &choice);
        switch (choice)             // menu driven program
        {
        case 1:                     // Insert info
            push(i,n,string,temp);
            i++;
            break;
        case 2:                     // Export List
            display();
            break;
        case 3:                     // Check if stack is full
            stack_full(n);
            break;
        case 4:                     // Check the infomation
            check(i,temp);
            break;
        case 5:                     // Academic ability
            if (i>0)
            {
                lowest(temp);
            }else
            {
                printf("\n**List is empty**\n");
            }
            break;    
        case 6:                     // Delete the student on the top list
            if (i>0)
            {
                del(i,temp);
                i--;
            }else
            {
                printf("**List is empty**\n");
            }
            break;
        case 7:                     // Exit the program
            exit(0);
        default: 
            printf("Wrong choice\n");
            break;
        }
    }
}
