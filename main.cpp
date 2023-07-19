#include<iostream>
#include<iomanip>
#include<fstream>
#include<cctype>
#include <bits/stdc++.h> 


using namespace std;

// Bank_Account class
class Bank_Account{
    
    int account_number;
    string name;
    string type;
    int amount;
    
public:
    void create_account();
    void deposit_money();
    void withdraw_money();
    void display_account();
    void balance_enquiry();
    void close_account();
    void modify_account();
    void loan_enquiry();
    
};

// creating bank Account
void Bank_Account :: create_account(){

    cout<<" Enter Account Number : ";
    cin>>account_number;
    cout<<" Enter the name of the Account Holder : ";
    cin>>name;
    cout<<" Enter the type of Account (current/savings) : ";
    cin>>type;
    cout<<" Enter Deposit Amount : ";
    cin>> amount;
    cout<<endl;
    cout<<"Account Created.....";
    cout<<endl;
    
}

// Display Account Details
void Bank_Account :: display_account(){
    
    cout<<" Bank Account Number : "<<account_number<<endl;
    cout<<" Account Holder Name : "<<name<<endl;
    cout<<" Type of Account : "<<type<<endl;
    cout<<" Balance Amount : "<<amount<<endl;
    
}

// Deposit Money Function
void Bank_Account :: deposit_money(){
    
    int deposit;
    cout<<"\nEnter Deposit Amount : ";
    cin>>deposit;
    amount = amount + deposit;
    cout<<"Your Current Balance is : " <<amount<<endl;
}

// WithDraw Money Function
void Bank_Account :: withdraw_money(){
    
    int withdraw;
    cout<<"\nEnter Withdraw Amount : ";
    cin>>withdraw;
    amount = amount - withdraw;
    cout<<"Your Current Balance is : " <<amount<<endl;
    
}


// Function for to show balance
void Bank_Account :: balance_enquiry(){
    
    cout<<" Bank Account Number : "<<account_number<<endl;
    cout<<" Balance Amount : "<<amount<<endl;
    
}

// Function to Close Account
void Bank_Account :: close_account(){
    
    account_number = 0;
    name = "";
    type = "";
    amount = 0;
    
    cout<<"Account Deleted....."<<endl;
    cout<<endl;
}

// Function to Modify Account Details
void Bank_Account :: modify_account(){
    
    cout<<" Enter the name of the Account Holder : ";
   // cin.ignore();
    //cin.getline(name,50);
    cin >> name;
    cout<<" Enter the type of Account (current/savings) : ";
    cin>>type;
    cout<<"Account Modified....."<<endl;
    
}

void Bank_Account :: loan_enquiry(){
    int loan;
    int years;
    cout<<"Enter Amount for Loan : "<<endl;
    cin >> loan;
    cout<<"Enter Number of years : "<<endl;
    cin>> years;
    
    if(loan > amount*10){
        
        cout<<"Loan Amount can't be proceed!"<<endl;
        
    }else{
        // rate of interest is 12% 
        // per month roi is 1%
        // for month year = m*12
        double emi = ((loan)*(0.01)*((1)^(years*12)))/((1)^(years*12)-1);
        cout<<"Your EMI will be : "<<emi<<endl;
        
    }
    
    
}

//Function to validate password
void validate(string pass){
    
    if(pass.length()<8){
        cout << "Length is less than 8, retry with longer password! " <<endl;
        exit(1);
    }else{
        
    int n = pass.length();      
    bool hasLower = false, hasUpper = false, hasDigit = false; 
  
    for (int i = 0; i < n; i++) { 
        if (islower(pass[i])) 
            hasLower = true; 
        if (isupper(pass[i])) 
            hasUpper = true; 
        if (isdigit(pass[i])) 
            hasDigit = true; 
    } 
    
    cout << "Strength of password you have entered is :-"; 
    
    if ( hasUpper && hasDigit && hasLower && (n > 7)) // considering a strong must be of length 6 or more
        cout << "Strong" << endl; 
    else if ((hasLower || hasUpper) && hasDigit && (n > 7)) 
        //when at least a lower case or uppercase is used along with digit
        cout << "Moderate" << endl; 
    else
        cout << "Weak" << endl; 
        
    }
    
}


int main(){
    
    Bank_Account B;
    int ch;
    char option;
    string username;
    string password;
    string input_username;
    string input_password;
    
    cout<<"  ---------------------------------------"<<endl;
    cout<<" | Welcome to the Bank Management System |" << endl;
    cout<<"  ---------------------------------------"<<endl;
    
    // Signup Code
    cout<<"Set your Username : "<<endl;
    cin >> username;
    cout<<"Set your Password : "<<endl;
    cin >> password;
    validate(password);
    
    // Login Code
    cout<<"credential created!\nLogin Now..."<<endl;
    
    cout<<"Enter your username : "<<endl;
    cin>>input_username;
    cout<<"Enter your password : "<<endl;
    cin>>input_password;

    // checking for login credentitals
    if(input_username == username && input_password == password){
    
 do{
        
    cout<<" --- Main Menu ---"<<endl;
    cout<<" 1.Create Account"<<endl;
    cout<<" 2.Deposit Money"<<endl;
    cout<<" 3.Withdraw Money"<<endl;
    cout<<" 4.Balance Enquiry"<<endl;
    cout<<" 5.Loan Enquiry"<<endl;
    cout<<" 6.Modify Details"<<endl;
    cout<<" 7.Delete Account"<<endl;
    cout<<" 8.exit"<<endl;
    cout<<endl;
    
    
    cout<<" Enter Your Choice : ";
    cin>> ch;

    switch(ch){
        
        
        case 1:
                // create fn
                 B.create_account();
                 break;
                 
        
        case 2:
                
                //deposit fn
                B.deposit_money();
                break;
            
        case 3:
                
                //withdraw fn
                B.withdraw_money();
                break;
                
        case 4:
                //display_account();
                B.display_account();
                break;
                
        case 5:
                // loan enquiry
                B.loan_enquiry();
                break;
                 
                 
        case 6:
                
                // modify fn
                B.modify_account();
                break;
                
        case 7: 
                // delete function;
                 B.close_account();
                 break;
                
        case 8:
                
                    exit(1);
                
                
        default : 
                cout << "Try Again and Choose Correct Option!"<<endl;
                break;
        
    }
    
    cout<<"Do You Want to Exit?(y/n)" <<endl;
    cin >> option;
    cout<<endl;
    if(option == 'y'){
        exit(1);
    }
    
 }
 while(option == 'n');
    }
    else{
        cout<<"in valid credentitals";
    }
    return 0;
};