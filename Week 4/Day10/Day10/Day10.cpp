// Day10.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>



/*
    ╔══════════╗
    ║ File I/O ║
    ╚══════════╝

    3 things are required for File I/O:
    1) Open the file
    2) read/write to the file
    3) close the file



*/
int main()
{
    std::cout << "Hello PG2!\n";

    /*

        ╔════════════════╗
        ║ write csv data ║
        ╚════════════════╝

        [  Open the file  ]
        [  Write to the file  ]
        [  Close the file  ]

        you need the path to the file
            use full path ( drive + directories + filename )
            or use relative path ( directories + filename )
            or current directory ( filename )

        Make sure to separate the data in the file with a delimiter.
        The delimiter is important because it is used
            to separate the data when reading the file back in.


        Lecture code: set a filePath variable, open an output file, write some csv data to it
    */
    std::string directory = "C:\\temp\\2310\\";
    std::string fileName = "bat.csv";
    std::string fullPath = directory + fileName;

    char delimiter = '%';
    {
        std::ofstream outFile(fullPath);//step 1: open the file

        //step 2: write to the file
        outFile << "Bruce Wayne" << delimiter << "Batman" << delimiter;
        outFile << "The Greatest Detective" << delimiter << "NOT Aquaman" << "\n";
        outFile << 5123451 << delimiter << true << delimiter << 420.13;
        
        //outFile.close();//step 3: close the file
    }//closes automatically  //step 3: close the file

    /*

        ╔═══════════════╗
        ║ read csv data ║
        ╚═══════════════╝

        [  Open the file  ]
        [  read the file  ]
        [  Close the file  ]

        Lecture code: using the filePath variable, open an input file, use getline to read a line, print the line
    */
    std::ifstream inFile(fullPath);//step 1: open the file

    //step 2: read the data
    std::string line;
    int lineNum = 1;
    while (std::getline(inFile, line))//(input stream, string)
    {
        std::cout << lineNum++ << " ";
        std::cout << line << "\n";
        //1) turn the string into a string stream
        std::stringstream batStream(line);
        std::string batString;
        int itemNum = 1;
        if (lineNum == 2)
        {
            while (std::getline(batStream, batString, delimiter))//parsing the csv string
            {
                std::cout << "\t" << itemNum++ << " ";
                std::cout << batString << "\n";
            }
        }
        else
        {
            while (std::getline(batStream, batString, delimiter))//parsing the csv string
            {
                std::cout << "\t" << itemNum << " ";
                if (itemNum == 1)
                {
                    //int
                    int num = std::stoi(batString);//converts a string to an int
                    std::cout << num << "\n";
                }
                else if (itemNum == 2)
                {
                    //bool
                    bool isTrue = batString == "1";
                    std::cout << isTrue << "\n";
                }
                else
                {
                    //double
                    double dNum = std::stod(batString);//converts a string to a double
                    std::cout << dNum << "\n";
                }
                ++itemNum;
                //std::cout << batString << "\n";
            }
        }
    }

    inFile.close();//step 3: close the file


    /*

        ╔═════════════════════╗
        ║ parsing csv strings ║
        ╚═════════════════════╝
        
        use getline on a string stream instead of a file stream

        Lecture code: 
            using the line read in above, use a stringstream to split the line using getline.
            store the separate items in a vector
            parse each item in the vector to an appropriate variable.
        

    */





    /*

        CHALLENGE:

        Parse the multi csv string (below) to get the data.
        NOTE: the data is a collection of object data.
        There are multiple delimiters.
        Separate on the first delimiter (collectionSeparator) to get the csv data for each object.
        Then, separate the object csv data on objectSeparator to get the details of the object.

        EX: hero#hero#hero   each hero is separated by a #
            name^secret^age  the details of each hero is separated by a ^

    */
    std::string multi = "Batman^Bruce Wayne^35#Superman^Clark Kent^25#Wonder Woman^Diana Prince^25#Aquaman^Arthur Curry^12";
    char collectionSeparator = '#';
    char objectSeparator = '^';
}