/*
  gpx to cvs converter created by Sumit Das
  version 2.0
  last modification May 26, 2021
*/
#include <iostream>
#include <cstring>
#include <string>
#include <sstream>
#include <fstream>
#include <conio.h>

using namespace std;

// copy array elements array1 to array2
//arr_size is copy array size & curArr_size is m_arr array size
void copyArr(char main_arr[], char blank_arr[], int curArr_size, int index){
  //terget main_arr and blank_arr elements 1->n
  int j=index+1;//main_arr first elements index
  //terget blank_arr index 1..n
  for(int i=0;i<curArr_size;i++){
    blank_arr[i]=main_arr[j];//copy array
    j++;
  }
}

// get array size
//[x]  {[1], [2], [3],....[n]}  [y]
//return n array size between [x] to [y] elements
int sizearr(char arr[],int index){
  int count=0; // count variable
  
  int i=index+1; //terget next element [1]

  while (arr[i]!='"'){
    count++;//update 1 in contuer variable
    i++;//increment index
  }
  return count;// return array size
}

// array to string convert
// converts character array to string and returns it 
string ArrToStr(char* a, int size) { 
    int i;  
    string s = ""; 
    for (i = 0; i < size; i++) { 
        s = s + a[i]; 
    } 
    return s; 
} 

// string to array converted
int strToArr(char arr[], string str, int size){
  // copying the contents of the
  // string to char array
  strcpy(arr, str.c_str());
  return size;
}

// get array current size
int currArrSize(int currArr, int cutArr){
  return (currArr+1)+cutArr;
}

// get array size
//[x]  {[1], [2], [3],....[n]}  [y]
//return n array size between [x] to [y] elements
int sizearr2(char arr[],int index){
  int count=0; // count variable
  
  int i=index+1; //terget next element [1]

  while (arr[i]!='<'){
    count++;//update 1 in contuer variable
    i++;//increment index
  }
  return count;// return array size
}

void massage(){
    cout<<"       <<= INDICODE4YOU =>>"<<endl;
    cout<<"<<= welcome to gpx to csv convertors =>>"<<endl;
}

void convert();
void about();
void helps();

int main(){
  bool termi= true;
  char ch;
  while(termi){
    start:
    system ("cls");
    massage();
    cout<<endl;
    cout<<"[0] Exit"<<endl;
    cout<<"[1] Convertors gpx to csv"<<endl;
    cout<<"[2] About me"<<endl;
    cout<<"[3] Helps"<<endl;
    cout<<endl; 
    
    cout<<"Please enter your choice /> ";
    ch=getch();
    
    if(ch=='0'||ch=='E'||ch=='e'){
      exit(0);
    }
    else if(ch=='1'||ch=='C'||ch=='c'){
      termi=false;
      convert();
    }
    else if(ch=='2'||ch=='A'||ch=='a'){
      termi=false;
      about();
    }
    else if(ch=='3'||ch=='H'||ch=='h'){
      termi=false;
      helps();
    }
    else{
      cout<<"\n\nOpps! your choice is invalid :-("<<endl;
      cout<<"Please try agen........"<<endl;
      cout<<"\nDo you want some help? Hits [Y]/[N]"<<endl;
      char ch=getch();
      if(ch=='y'||ch=='Y')
        helps();
      goto start;
    }
  }
  getch();
  return 0;
}

void convert(){
  // Creation of fstream class object
  fstream fin, fout;
  
  // file name string variable
  string filName;
  
  // make string variable output of line by file
  string line;
  
  // main array and copy array
  char m_arr[300],c_arr[300];
  
  // array size store variable
  int n,n2;
  
  // Mein Array size according to Copy Array size
  int curArr;
  //latitude,longitude,elevation,speed variable
  string lat="0",lon="0",ele="0",speed="0"; // file input string
  string temlat="",temlon=""; // file input temporary string
  int id=0,id2=0,id3=0; // codinat id/point
  
  start:
  system("cls");
  massage();
  cout<<endl;
  
  cout<<"Enter Your GPX file name: ";
  cin>>filName;
  
  // Open a gpx file
  fin.open(filName, ios::in);
  
  // Opens an existing csv file or creates a new file.
  fout.open("points.csv", ios::out);
  
 // file header title write
 fout << "x, " << "y, "<< "z, " << "Points, "<<"Speed"<<"\n";
 
 // check all files is opened or not opened
  if(fin.is_open()&&fout.is_open())
  {
    
    // get all line into the files
    while (getline(fin, line) ) { 
      // converted line string to char array and get array size
      n= strToArr(m_arr, line, line.length());
      
      // terget all array elements 
      for (int i = 0; i < n; i++){
        // chack array index find [l],[a],[t] elements and get latitude
        if(m_arr[i]=='l'&&m_arr[i+1]=='a'&&m_arr[i+2]=='t'){
          n2=sizearr(m_arr,i+4); //get copy array size
          curArr=currArrSize(i+4, sizearr(m_arr,i+4));// Mein Array size according to Copy Array size
           
          // copy m_arr[] to c_arr[] array 
          copyArr(m_arr, c_arr, curArr, i+4);
          
          //array to string converted
          lat=ArrToStr(c_arr,n2);
        }
        // check Array index find [l],[o],[n] elements and get longitude
        else if(m_arr[i]=='l'&&m_arr[i+1]=='o'&&m_arr[i+2]=='n'){
          n2=sizearr(m_arr,i+4); //get copy array size
          curArr=currArrSize(i+4, sizearr(m_arr,i+4));// Mein Array size according to Copy Array size
           
          //copy m_arr[] to c_arr[] array
          copyArr(m_arr, c_arr, curArr, i+4);
          
          //array to string converted
          lon=ArrToStr(c_arr,n2);
        }
        
        // check Array index find [<],[e],[l] elements and get elevation
        else if(m_arr[i]=='<'&&m_arr[i+1]=='e'&&m_arr[i+2]=='l'){
          n2=sizearr2(m_arr,i+4); //get copy array size
          curArr=currArrSize(i+4, sizearr(m_arr,i+4));// Mein Array size according to Copy Array size
           
          // copy m_arr[] to c_arr[] array
          copyArr(m_arr, c_arr, curArr, i+4);
          
          // array to string converted
          ele=ArrToStr(c_arr,n2);
        }
        
        // check Array index find [<],[s],[p],[e],[e] elements and get speed
        else if(m_arr[i]=='<'&&m_arr[i+1]=='s'&&m_arr[i+2]=='p'&&m_arr[i+3]=='e'&&m_arr[i+4]=='e'){
          n2=sizearr2(m_arr,i+6); //get copy array size
          curArr=currArrSize(i+6, sizearr(m_arr,i+6));// Mein Array size according to Copy Array size
           
          // copy m_arr[] to c_arr[] array
          copyArr(m_arr, c_arr, curArr, i+6);
          
          // array to string converted
          speed=ArrToStr(c_arr,n2);
        }
        // check Array index find [<],[/],[t],[r],[k],[p],[t],[>] elements and record deta
        else if((m_arr[i]=='<'&&m_arr[i+1]=='/'&&m_arr[i+2]=='t'&&m_arr[i+3]=='r'&&m_arr[i+4]=='k'&&m_arr[i+5]=='p'&&m_arr[i+6]=='t'&&m_arr[i+7]=='>')||(m_arr[i]=='<' && m_arr[i+1]=='/' && m_arr[i+2]=='r' && m_arr[i+3]=='t' && m_arr[i+4]=='e' && m_arr[i+5]=='p' && m_arr[i+6]=='t' && m_arr[i+7]=='>')) {
        
        //Chack Same value are not recoded
        if(temlon==lon&&temlat==lat){
          id3+=1;
          continue;
        }
        // get points number
        id+=1; //increment id/Points +2
        
        // Insert the data to file
        fout << lon << ", "
             << lat << ", "
             << ele << ", "
             << id << ", "
             << speed
             << "\n";
         
         // copy lon and lat in temp variable
         temlon=lon;
         temlat=lat;
        }
      }
      // get gpx files all row number
      id2+=1;
    }
    
      // 14::Print insert data list and massages
      system("cls");
      massage();
      cout<<endl;
      cout<<"1.Inport total data in gpx files: "<<id2<<endl;
      cout<<"2.Export data in csv file: "<<id<<endl;
      cout<<"3.Same data present in gpx file: "<<id3<<endl;
      cout<<endl;
      cout<<"Your conversation is Successful......."<<endl;
      cout<<endl;
      cout<<"This software create by Sumit Das."<<endl;
      cout<<"Website: https://indicode4you.blogspot.com"<<endl;
  }else{
      // get error files can't opened
      cout<<"Opps!! files isn't opened :-/"<<endl
          <<"please try agen...."<<endl;
      cout<<"\nDo you want some help? Hits [Y]/[N]"<<endl;
      char ch=getch();
      if(ch=='y'||ch=='Y')
        helps();
      goto start;
  }
    
  //16::close the files
  fout.close();
  fin.close();
  
  getch();
  main();
}

void about(){
  system("cls");
  massage();
  cout<<endl;
  cout<<"Hi, I am Sumit Das. this my open source software."<<endl;
  cout<<"This software help to gpx file extension to csv file extension converted."<<endl;
  cout<<"copyright 2021 all right received by Sumit Das."<<endl<<endl;
  cout<<"gpx to csv converter"<<endl;
  cout<<"version: 2.0"<<endl;
  cout<<"https://indicode4you.blogspot.com"<<endl;
  getch();
  main();
}

void helps(){
  system("cls");
  massage();
  cout<<endl;
  cout<<"1. Copy your gpx file this application directory."<<endl;
  cout<<"2. Double check the exe file and run the application."<<endl;
  cout<<"3. Hit '1' or 'E' or 'e' key from your keyboard."<<endl;
  cout<<"4. Enter your gpx file name with extension. [Eg: example.gpx]."<<endl;
  cout<<"5. you get your cvs file name is [points.csv]."<<endl<<endl;
  getch();
  main();
}