// Include Header files 
#include <iostream> 
#include <fstream>
#include <string>
#include <vector>
#include <assert.h>
#include "Timer.h"




using namespace std;

extern "C" {
#include <cblas.h>
}

#ifdef USE_LIKWID
extern "C"{ 
#include <likwid.h>
}
#endif
 



//using namespace std;


// Main function passing argumentg
int main(int argc, char *argv[])

{
   
    std::vector<double> v_A;
    std::vector<double> v_B;
    std::vector<double> v_C;
    
    //Declaring the variables 
    double value_A;
    double value_B;
    
    // Declaring object of Fstream header file 
    std::ifstream file_A;
    std::ifstream file_B;

    // Opening The files 
    file_A.open(argv[1]);
    file_B.open(argv[2]);


    // Reading till untill end of file has reached 
    while(file_A>>value_A)
    {   
        //file>> arr[n]; // putting it in array 
        v_A.push_back(value_A);
        //++n;

    }
    // Reading the second file 
    while (file_B>> value_B)
    {
        //Reading the contents of the second file 

        v_B.push_back(value_B);
    }

    // Closing the files 
    file_A.close();
    file_B.close();
    
   
    // Getting the size of vector s
    int size_A;
    int size_B;
    size_A = v_A.size();
    size_B = v_B.size();
    
    // Printing the values stored in array
    
    /*
    for (int i =0; i < vsize ;++i)
        cout<<"The value of vectors are "<<v[i]<<endl;
    
    for (int j=0;j< vsize1;++j)
        cout<<"The values of second files are "<<v1[j]<<endl;

    */

    // Fetching the number of rows and columns 

    int numRow_A= v_A[0];
    int numCol_A = v_A[1];
    int numRow_B = v_B[0];
    int numCol_B = v_B[1];
    int numRow_C = numRow_A;
    int numCol_C = numCol_B ;  
    int size_C = numRow_C*numCol_C;

    v_C.push_back(numRow_C);
    v_C.push_back(numCol_C);

    assert(numCol_A == numRow_B);

    /*for(int i=0;i< size_A;++i)
    {
        cout<<"v_A["<< i <<"]: " << v_A[i] << ",  v_B["<< i <<"]: " << v_B[i] << endl;
    }*/

    //cout<<row<<"   "<<row2<<endl;
    //cout<<vsize<<"  "<<vsize1<<endl;
    //cout<<col<<"   "<<col2<<endl;
#ifdef USE_LIKWID
	likwid_markerInit();
	likwid_markerStartRegion("vector");
#endif

    //defining the timer
    siwir:: Timer timer;
    
    // Naive Matrix Matrix multiplication  O(n3)



    double timeTaken = 0.0;
    double temp = 0.0;
    int row = 0;
    int col = 0;
    
    for(int i=0; i< size_C ; ++i)
        {
            //cout<<"i is: "<<i <<endl;
            temp = 0.0;
            row = i/numCol_B;
            col = i % numCol_B; 

            //cout<<"\nrow is: "<<row<<endl;
            //cout<<"\ncol is:"<<col<<endl; 

            for(int j=0 ; j < numCol_A ; ++j)
            {
                //cout<<"j is: " << j << endl;

               // cout<<"\ntemp:   "<<temp<<endl;

                temp +=  v_A[2+ row*numCol_A + j] * v_B[2 + col+ j*numCol_B];
            }
            //cout<<"Now the temp is : " << temp << endl;
          
            v_C.push_back(temp);
            //cout<<"the temp is : " <<  temp<< endl;
        }

        timeTaken = timer.elapsed();
        
#ifdef USE_LIKWID
	likwid_markerInit();
	likwid_markerStartRegion("vector");
#endif

        cout<<"\nTime taken in matrix multiplication :" <<  timeTaken << " seconds \nDisplay of matrix C\n";
    
        for(int i=0 ; i < numRow_C; ++i)
          {   
            //cout<<"i is: "<<i<<endl;
          for(int j=0 ; j < numCol_C; ++j)
          {
            //cout<<"j is: " <<j<<endl;
          cout<< v_C[2+i*numCol_C + j]<<"\t";
          }
          cout<<endl;
        } 

    // Storing the result of computation in another matrix 


    return 0;

}

