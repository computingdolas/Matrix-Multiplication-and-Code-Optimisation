// Include Header files 
#include<iostream> 
#include<fstream>
#include<string>

// Using namespace std
using namespace std;

// Main function passing argument
int main(int argc, char *argv[])

{/*
    std::string line_;
    ifstream file_("mytext.txt");
    int i=0;
    int arr[100];
    int j=0;
    if (file_.is_open())
    { while (getline(file_,line_))
    	{
    		std::cout<<line_<<'\n';
            file_>>arr[i];
            ++i;
    	}
        file_.close();
    }
    else
      std::cout<<"the file is not open";
    j=i;
    for (j=0;j<<i;++j)
        cout<<arr[j];
*/
    //Declaring array to store number . Here we have to use vector since we dont input size always 
    
    int arr[100];
    int n=0;
    // Declaring object of Fstream header file 
    ifstream file;

    // Opening The files 
    file.open(argv[1]);

    // Reading till untill end of file has reached 
    while(!file.eof())
    {   
        file>> arr[n]; // putting it in array 
        ++n;

    }

    // Closing the files 
    file.close();
    
    // Checking number of entries in array to crosscheck with intial input 
    cout<<n;

    // Printing the values stored in array 
    while(n>=0)
    {
        cout<<" Numbers stored are "<<arr[n]<<endl;
        n=n-1;
    }
    return 0;


}

