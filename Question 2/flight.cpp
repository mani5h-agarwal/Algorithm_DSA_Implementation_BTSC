#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <stack>
using namespace std;
struct  User{
     string name="xyz";
     string seatNumber;
};
struct User user1;
int n1=21,m1=8;
vector<vector<string>>v( 21, vector<string> (8));
map<string,int>m;
stack<string>waitinglist;

void waitingList(){
    waitinglist.push(user1.name);
    int x=waitinglist.size();
    cout << endl;
    cout << "Zero Seats Available" << endl;
    cout << "In waiting list..." << x << ":20" << endl;
    cout << endl; 

}
void reserveSeat(){
    int i,j,x=0,y,f=0;
    string s;
    char c;
    cout << endl;
    cout << "Reserve your seat" << endl;
    cout << "Enter you preferences" << endl;
    cout << "Window/Middle/Aisle   :   ";
    cin >> s;
    if (s=="Window"){
        c='W';
    }
    else if (s=="Middle"){
        c='M';
    }
    else if (s=="Aisle"){
        c='A';
    }
    else{
        cout << "Enter correct Input" << endl;
        reserveSeat();
    }
    for (i=1;i<n1;i++){
        if (f==1) break;
        for (j=1;j<m1;j++){
          if (c=='W'){
            if (j==1  || j==7){
                if (m[v[i][j]]<2){
                    m[v[i][j]]++;
                    x=i;
                    f=1;
                    break;
                }
            }
          }  
          if (c=='M'){
            if (j==2 || j==6){
                if (m[v[i][j]]<2){
                    m[v[i][j]]++;
                    x=i;
                    f=1;
                    break;
                }
            }
          }
          if (c=='A'){
            if (j==3 || j==5){
                if (m[v[i][j]]<2){
                    m[v[i][j]]++;
                    x=i;
                    f=1;
                    break;
                }
            }
          }

        }
        
    }
    if (x==0){
        waitingList();
    }
    else{
        user1.seatNumber=to_string(x)+c;
        cout << endl << endl;
        cout << "Your Reservation has been completed" << endl;
        cout << "Your seat number is : " << x << c  << endl;
    }

}
void changeReservation(){
    m[user1.seatNumber]--;
    user1.seatNumber="";
    cout << "Changing Reservation..." << endl;
    reserveSeat();
    
}   
void cancelReservation(){
    m[user1.seatNumber]--;
    user1.seatNumber="";
    cout << "Reservation succesfully Cancelled" << endl;
}
void suggestOptimatSeat(){
    int i,j,x=0,y,f=0;
    string s;
    char c;
    cout << "Reserve your seat" << endl;
    cout << "Enter you preferences" << endl;
    cout << "Window/Middle/Aisle   :   ";
    cin >> s;
    if (s=="Window"){
        c='W';
    }
    else if (s=="Middle"){
        c='M';
    }
    else if (s=="Aisle"){
        c='A';
    }
    else{
        cout << "Enter correct Input" << endl;
        suggestOptimatSeat();
    }
    for (i=1;i<n1;i++){
        if (f==1) break;
        for (j=1;j<m1;j++){
            if (c=='W'){
            if (j==1  || j==7){
                if (m[v[i][j]]<2){
                    x=i;
                    f=1;
                    break;
                }
            }
          }  
          if (c=='M'){
            if (j==2 || j==6){
                if (m[v[i][j]]<2){
                    x=i;
                    f=1;
                    break;
                }
            }
          }
          if (c=='A'){
            if (j==3 || j==5){
                if (m[v[i][j]]<2){
                    x=i;
                    f=1;
                    break;
                }
            }
          }

        }
        
    }
    if (x!=0){
        cout << "You Optimal seat is" << x << c <<  endl;

    }
    else{
        cout << "Seat is not Available" << endl;
    }
}
void checkSeatAvailability(){
    int i,j,x=0,y,f=0;
    string s;
    char c;
    cout << "Reserve your seat" << endl;
    cout << "Enter you preferences" << endl;
    cout << "Window/Middle/Aisle   :   ";
    cin >> s;
    if (s=="Window"){
        c='W';
    }
    else if (s=="Middle"){
        c='M';
    }
    else if (s=="Aisle"){
        c='A';
    }
    else{
        cout << "Enter correct Input" << endl;
        checkSeatAvailability();
    }
    for (i=1;i<n1;i++){
        if (f==1) break;
        for (j=1;j<m1;j++){
            if (c=='W'){
            if (j==1  || j==7){
                if (m[v[i][j]]<2){
                    x=1;
                    f=1;
                    break;
                }
            }
          }  
          if (c=='M'){
            if (j==2 || j==6){
                if (m[v[i][j]]<2){
                    x=1;
                    f=1;
                    break;
                }
            }
          }
          if (c=='A'){
            if (j==3 || j==5){
                if (m[v[i][j]]<2){
                    x=1;
                    f=1;
                    break;
                }
            }
          }

        }
        
    }
    
    if (x==1){
        cout << "Seat is Available" << endl;

    }
    else{
        cout << "Seat is not Available" << endl;
    }


}

void initializeFlight(){   
    cout << endl;
    cout << "Flight Seat Map" << endl;
    cout << endl;
    int n,m,i,j;
    string r;
    n=21;
    m=8;  
    for (i=1;i<n;i++){
        v[i][0]=to_string(i);
    }
    v[0][0]="Row";
    v[0][1]="Window";
    v[0][2]="Middle";
    v[0][3]="Aisle";
    
        v[0][4]="Passage";
        v[0][5]="Aisle";
        v[0][6]="Middle";
        v[0][7]="Window";
    
    for (i=1;i<n;i++){
        for (j=1;j<m;j++){
            if (j==4) {
                v[i][j]="      ";
                continue;
            }
            r=v[0][j];
            v[i][j]=to_string(i)+r[0];
        }
    }
    for (i=0;i<m;i++){
        cout << v[0][i] << "      ";
    }
    cout << endl;
    for (i=1;i<n;i++){
        for (j=0;j<m;j++){
            cout << v[i][j];
             if (i<10){
                cout << "         ";
             }
             else{
                cout << "        ";
             }

        }
        cout << endl;
    }
   do{
       cout << endl << endl;
        cout << "---------------------------  Sky Wings ------------------------" << endl;
        cout << endl; 
        cout << endl;
       cout << "Enter 1 to Reserve Seat" << endl;
       cout << "Enter 2 to Check seat availability" << endl;
       cout << "Enter 3 to Suggest optimal seat" << endl;
       cout << "Enter 4 to Cancel Reservation" << endl;
       cout << "Enter 5 to Change Reservation" << endl;
       cout << "Enter 0 to Exit";
       cin >> j;
        if (j==1){
           reserveSeat();
       }
       else if (j==2){
        checkSeatAvailability();
       }
       else if (j==3){
        suggestOptimatSeat();
       }
       else if (j==4){
        cancelReservation();
       }
       else if (j==5){
        changeReservation();
       }

       if (j==0){
        exit(1);
       }
   }
   while(j);
   
       

  //  }
  //  while{

    }



    

    

int main(){
    cout << endl;
    cout << endl;
    cout << endl; 
    cout << "---------------------------  Welcome to sky wings ------------------------" << endl;
    cout << endl; 
    cout << endl;
    cout << endl;
    cout << "Enter y to initialize flight seats\n Enter n to exit"<< endl;
    string s;
    cin >> s;
    if (s=="y") initializeFlight();
    else if (s=="n") exit(0);
    else {
        cout << "Invalid input";
        main();
    }
    



    




}