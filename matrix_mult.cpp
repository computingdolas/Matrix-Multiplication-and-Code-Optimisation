// Include Header files 
#include <iostream> 
#include <fstream>
#include <string>
#include <vector>
// Using namespace std
using namespace std;


// Main function passing argument
int main(int argc, char *argv[])

{

    
    int n=0;
    
    //Declaring the vector 

    std::vector<double> v;
    std::vector<double> v1;
    
    //Declaring the variables 

    
    double value;
    double value2;
    
    // Declaring object of Fstream header file 
    
    ifstream file;
    ifstream file2;

    // Opening The files 
    
    file.open(argv[1]);
    file2.open(argv[2]);


    // Reading till untill end of file has reached 
    
    while(file>>value)
    {   
        
        
        //file>> arr[n]; // putting it in array 
        v.push_back(value);
        ++n;

    }
    // Reading the second file 
    
    while (file2>> value2)
    {
        //Reading the contents of the second file 

        v1.push_back(value2);
    }

    // Closing the files 
    
    file.close();
    file2.close();
    
   
    // Getting the size of vector 
    
    int vsize;
    int vsize1;
    vsize = v.size();
    vsize1= v1.size();
    
    // Printing the values stored in array
    
    /*
    for (int i =0; i < vsize ;++i)
        cout<<"The value of vectors are "<<v[i]<<endl;
    
    for (int j=0;j< vsize1;++j)
        cout<<"The values of second files are "<<v1[j]<<endl;

    */

    // Fetching the number of rows and columns 

    int row1= v[0];
    int col1 = v[1];
    int row2= v1[0];
    int col2= v1[1];

    cout<<row1<<"   "<<row2<<endl;
    //cout<<vsize<<"  "<<vsize1<<endl;
    cout<<col1<<"   "<<col2<<endl;


    // Naive matrix Matrix multiplication 

    




    // Storing the result of computation in another matrix 


    return 0;

}

