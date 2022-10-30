//Chloe Marton
//Dr. Steinberg
//COP3223C Section 004
//Small Program 5

#include <stdio.h>
void change(double * ptd, double * ptp);//1
void resterauntReceipt();//2
void gradeDistribution();//3
int incrementUpdate(int * ptrv);//4



int main()
{

    
    double due;
    double *ptd;
    //collects input for amount due
    printf("Amount Due: ");
    scanf("%lf", &due);
    //assigns address to pointer
    ptd = &due;

    double paid;
    double *ptp;
    //collects input for amount paid 
    printf("Amount Paid: ");
    scanf("%lf", &paid);
    //assigns address to pointer
    ptp = &paid;

    change(&due, &paid);//calls change function


    resterauntReceipt();//calls resteraunt receipt function
    gradeDistribution();//calls grade distribution function 




    /*---------------------------------------------*/
    printf("Before calling incrementUpdate\n");
    //declares val and assigns its pointer
    int val = 0;
    int *ptrv;
    ptrv = &val;
    printf("val = 0\n");
    int option;

    //do-while loop to keep output running until user decides
    do
    {
        printf("Updating val now...\n");

        //calls increment function to add to val 
        val = incrementUpdate(&val);

        printf("Would you like to update ...\n");
        printf("Enter 0 if you would like to update again. Anything else will exit the update.\n");

        
        printf("Option: ");
        scanf("%d", &option);


    }while(option == 0);

    //loop ends, print statements are printed
    printf("val is now done updating...\n");
    printf("After calling incrementUpdate\n");
    //result of val is printed
    printf("val = %d", val);
 /*---------------------------------------------*/
    return 0;
}






//1----------------------------------------
void change(double * ptd, double * ptp)
{
    //amount of change is calculated 
    double change = *ptp - *ptd;
    //to account for rounding error 
    change = change + 0.0000025;

    int dollar = change / 1; //dollar = amount of change  
    change = change - dollar; // change is updated - dollar

    int quarter = change / 0.25; // quarter = 1/4th of change 
    change = change - quarter * 0.25; // change is subtracted by 0.25 

    int dime = change / 0.1; // dime = 1/10th of change 
    change = change - dime * 0.10;//change is subtracted by 0.10

    int nickel = change / 0.05;//nickel is 1/20th of change 
    change = change - nickel * 0.05;//change - 0.05

    int penny = change / 0.01;//penny is 1/100th of change 
    change = change - penny * 0.01;//change - 0.01
        
    
    //print statements to print results
    printf("Change\n");
    printf("%d dollars\n", dollar);
    printf("%d quarters\n", quarter);
    printf("%d dimes\n", dime);
    printf("%d nickels\n", nickel);
    printf("%d pennies\n", penny);
    



}


//2----------------------------
void resterauntReceipt()
{
    //greeting
    printf("Welcome to Bob's Burgers! Our burger of the day is Say Cheese Burger!\n");

    //initialize order, price, menu items 
    int order;
    double price;
    int r = 0;
    int s = 0;
    int c = 0;
    int f = 0;
    int sal = 0;
    int sd = 0;

    //open receipt file to write in 
    FILE *receipt; 
    receipt = fopen("myreceipt.txt", "w");
    
    //loop to ask for order until user wants to print receipt 
    while( order != 0 )
    {

        //menu is printed
        printf("Please enter your order by selecting the option number. Otherwise type 0 and your order receipt will be printed.\n");

        printf("-----------------------\n");
        printf("1: Regular\t$5.00\n");
        printf("2: Special\t$5.95\n");
        printf("3: Cheese\t$5.50\n");
        printf("4: Fries\t$2.00\n");
        printf("5: Salad\t$2.50\n");
        printf("6: Soft Drink\t$2.00\n");
        printf("-----------------------\n");

        //collects input for the users order
        printf("What will you add to your order: ");
        scanf("%d", &order);

        //switch statement for each menu item output
        switch(order)
        {
            case 1: 
                //REGULAR
                printf("Adding regular to your order.\n");
                price += 5;//adds menu price to total 
                r += 1;//counts regulars
                break;
            
            case 2:
                //SPECIAL 
                printf("Adding special to your order.\n");
                price += 5.95;//adds menu price to total
                s += 1;//counts specials
                break;
            
            case 3:
                //CHEESE
                printf("Adding cheese to your order.\n");
                price += 5.50;//adds menu price to total 
                c += 1;//counts cheese
               
                break;

            case 4:
                //FRIES
                printf("Adding fries to your order.\n");
                price += 2.00;//adds menu price to total
                f += 1;//counts fries
                
                break;

            case 5:
                //SALAD
                printf("Adding salad to your order.\n");
                price += 2.50;//adds menu price to total 
                sal += 1;//counts salads
                break;

            case 6:
                //SOFT DRINK
                printf("Adding soft drink to your order.\n");
                price += 2.00;//adds menu price to total
                sd += 1;//counts soft drinks 
                break;

            default:
                //PRINT RECEIPT
                printf("Order is now placed. Printing receipt.\n");
                break;

        }

        
    }
    //prints receipt to text file 
    fprintf(receipt, "Bob's Burgers Restaurant Receipt Order\n");
    fprintf(receipt,"-----------------------\n");
    fprintf(receipt, "%d Regular(s)\n", r);
    fprintf(receipt, "%d Special(s)\n", s);
    fprintf(receipt, "%d Cheese(s)\n", c);
    fprintf(receipt, "%d Fries\n", f);
    fprintf(receipt, "%d Salad(s)\n", sal);
    fprintf(receipt, "%d Soft Drink(s)\n", sd);
    fprintf(receipt, "-----------------------\n");
    fprintf(receipt, "Total: $%.2lf\n", price);//total price 
    fprintf(receipt, "Thank you and come again!");

    fclose(receipt);//closes text file 

    
}


//3-------------------------------------
void gradeDistribution()
{
    //opens file for reading grades
    FILE * grades;
    grades = fopen("grades.txt", "r");

    //initializes variable for grades inside file, initializes count for each grade
    char grd;
    int a = 0;
    int b = 0;
    int c = 0;
    int d = 0;
    int f = 0;

    //if file doesnt open print statement 
    if(grades == NULL)
    {
        printf("File did not open");
    }
    else
    {
        //loop to read grades in file 
        while(fscanf(grades, "%c", &grd) == 1 )
        {
            if(grd == 'A')
            {
                a += 1;//counts As in file 
            }
            else if(grd == 'B')
            {
                b += 1;//counts Bs in file 
            }
            else if(grd == 'C')
            {
                c += 1;//counts Cs in file
            }
            else if(grd == 'D')
            {
                d += 1;//counts Ds in file 
            }
            else if(grd == 'F')
            {
                f += 1;//counts Fs in file 
            }
        
        }
    }
    
    //prints number of each grade in file 
    printf("Here is the grade distribution.\n");
    printf("A: %d\n", a);
    printf("B: %d\n", b);
    printf("C: %d\n", c);
    printf("D: %d\n", d);
    printf("F: %d\n", f);

    fclose(grades);
}

//4----------------------------------------
int incrementUpdate(int * ptrv)
{
    //adds 1 to value of val using pointer
    *ptrv += 1;

    return *ptrv;//returns value to the main function 
        
}
