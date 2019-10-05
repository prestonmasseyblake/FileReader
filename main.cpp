#include <iostream>
#include <fstream> //for File I/O
#include <string>

using namespace std;

int main()
{ 

        string fileName; 
        string line; 
        fstream fileStream; 
        int charCount= 0;
        char c;
        int lineCount=0;
        char another;
        do 
        {
                cout<<"What file do you want to open? ";
                getline(cin, fileName);


                fileStream.open(fileName.c_str(), ios::in);
                if(fileStream.is_open()  )
                { 
                        cout<<fileName<<" opened.\nFILE CONTENTS:\n";
                        do {
                                getline(fileStream,line);
                                cout<<line<<endl;
                                if(!line.empty()) { lineCount++; 
                                }
                                charCount = line.length() + charCount;
                        }
                        while (!(fileStream.eof()));

                        cout<<"METADATA"<<endl;
                        cout<<"File: "<<fileName<<endl;
                        cout<<"Lines: "<<lineCount<<endl;
                        cout<<"Characters: "<<charCount<<endl;
                        cout<<"Analyze another file (y/n)? ";
                        cin>>another;
                        cin.ignore();

                        fileStream.close();
                }
                else
                {
                        cout<<fileName<<" could not be opened.\n";
                }
        }
        while(another == 'y' || another == 'Y');



        return 0; } 

