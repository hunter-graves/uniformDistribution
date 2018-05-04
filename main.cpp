#include <iostream>
#include <vector>
#include <math.h>
#include <fstream>
using namespace std;


//g(x) = {x: x ∈ (0 < x < 1)}
//This will generate a number between 0 and 1
double uniformDistribution()
{

    double lowerRange = 0;
    double upperRange = 1;
    return ((double)rand() * (upperRange - lowerRange)) / (double)RAND_MAX + lowerRange;
}



//f(x) = x^3
double cubedFunction(double toBeCubed)
{
    return toBeCubed*toBeCubed*toBeCubed;
}



//generating 250 independent copies of g(x)
vector<double> sampleGeneration(int numberOfSamples)
{
    vector<double> vectorToHoldSamples;
    for(int x = 0; x < numberOfSamples; x++)
    vectorToHoldSamples.push_back(uniformDistribution());
    return vectorToHoldSamples;
}



//perform f(x) = x^3
//on each of the values in our 250 samples
vector<double> samplesCubed(vector<double> vectorToCube)
{
for(int x = 0; x < vectorToCube.size(); x++)
{
    vectorToCube[x] = cubedFunction(vectorToCube[x]);
}
    return vectorToCube;
}



//calculate the mean of our cubed sample values
double meanOfCubedSamples(vector<double> vectorOfCubedSamples)
{
    double sumTotalOfEachValue = 0;
    for(int x = 0; x < vectorOfCubedSamples.size(); x++)
        sumTotalOfEachValue += vectorOfCubedSamples[x];

    return ( sumTotalOfEachValue/vectorOfCubedSamples.size() );
}



//calculate the standard deviation of our cubed sample values
double standardDeviationOfCubedSamples(vector<double> vectorOfCubedSamples)
{
    double mean = meanOfCubedSamples(vectorOfCubedSamples);
    double runningTotal = 0;
    for(int x = 0; x < vectorOfCubedSamples.size(); x++)
    {
        runningTotal += ( pow( (vectorOfCubedSamples[x] - mean), 2.0) );
    }
    return sqrt( runningTotal/(vectorOfCubedSamples.size()-1) );
}



//calculate the sample average of f(g(x))
//for 25 samples
double sampleAverageTwentyFive(vector<double> vectorOfCubedSamples)
{
    double runningTotal = 0;
    for(int x = 0; x < vectorOfCubedSamples.size(); x++) {
        runningTotal += vectorOfCubedSamples[x];
   // cout<<"The running total is: " << runningTotal << endl;
    }
    return (runningTotal/25);
}

vector<double> generateAverages(int numberOfAveragesToGenerate)
{
   vector<double> vectorOfAverages;
    for(int x = 0; x < numberOfAveragesToGenerate; x++)
        vectorOfAverages.push_back(sampleAverageTwentyFive(samplesCubed(sampleGeneration(25))));
    return vectorOfAverages;
}


void printHistorgram(vector<double> vectorToWriteToFile)
{
    double intervalWidth = .05;

    for(int x = 0; x < vectorToWriteToFile.size(); x++)
    {
        cout << endl;
        cout << intervalWidth << "|| ";
        int frequency = 0;
        for (int i = 0; i < vectorToWriteToFile.size(); i++)
        {


            if (vectorToWriteToFile[i] < intervalWidth)
            {
                frequency++;
                vectorToWriteToFile.erase(vectorToWriteToFile.begin()+i);
            }


        }

        for (int a = 0; a < frequency; a++)
        cout << "*";
        intervalWidth = (intervalWidth +.05);
    }

}


int main()
{

srand(time(0));
//vector for 250 samples
vector<double> samples = sampleGeneration(250);
//vector to cube each sample
samples = samplesCubed(samples);
/*   for (int count = 0; count < samples.size(); count++)
 {
    cout << "samples["<<count<<"] "<< "contains: " << samples[count] << endl;
 }
*/
    cout <<"****Q1*********" << endl;
    cout <<"****Start******" << endl;
    cout << "The mean of the cubed samples is: " << meanOfCubedSamples(samples) << endl;
    cout << "The standard deviation of the cubed sample is: " << standardDeviationOfCubedSamples(samples) << endl;
    cout <<"***************" << endl;
    cout <<"****End********" << endl;
    cout <<"****************" << endl;
    cout <<"****Q2*********" << endl;
    cout <<"****Start******" << endl;
    vector<double> secondSamples = sampleGeneration(25);
    secondSamples = samplesCubed(secondSamples);
    /*
    cout << "The values of the sample are: " << endl;
    for (int count = 0; count < secondSamples.size(); count++)
    {
        cout << "samples["<<count<<"] "<< "contains: " << secondSamples[count] << endl;
    }
    cout << "The sample average is: " << sampleAverageTwentyFive(secondSamples) << endl;
     */


    //vector<double> final = generateAverages(250);
    /*printHistorgram(samplesCubed(sampleGeneration(250)));
    cout << endl;
    cout << "- - - - - - - - - - - - - - - - - " << endl;
         cout << endl;
    printHistorgram((generateAverages(250)));
cout << endl;
    //for(int x = 0; x < final.size(); x++)
     //   cout << "the average of index " << x << " is: " << final[x] << endl;
*/
    ofstream myFile("data.txt");

    for(int i = 0; i < samples.size(); i++) {
        myFile << samples[i] << ",";
    }
        return 0;
}



