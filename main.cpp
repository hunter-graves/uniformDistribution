/* Hunter Graves
 * Math 324
 * May 3rd, 2018
 * Homework
 */

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



int main()
{
//initialize random generator
srand(time(0));


//vector for 250 samples for question 2
vector<double> samples = sampleGeneration(250);
//vector to cube each sample for question 2
samples = samplesCubed(samples);

    //Begin output screen for Q2 and provide mean and standard deviation
    //then begin output screen for Q3
    cout <<"****Q2c*********" << endl;
    cout <<"****Start******" << endl;
    cout << "The mean of the cubed samples is: " << meanOfCubedSamples(samples) << endl;
    cout << "The standard deviation of the cubed sample is: " << standardDeviationOfCubedSamples(samples) << endl;
    cout <<"***************" << endl;
    cout <<"****End********" << endl;
    cout <<"****************" << endl;
    cout <<"****Q3c*********" << endl;
    cout <<"****Start******" << endl;


    //Put question 3 data into text file
    //and output mean and standard deviation
    ofstream myNextFile("stepThreeData.txt");
    vector<double> partThree = generateAverages(250);
    for(int i = 0; i < partThree.size(); i++ )
        myNextFile << partThree[i] << endl;
    myNextFile.close();
    cout << "The mean of the samples is: " << meanOfCubedSamples(partThree) << endl;
    cout << "The standard deviation of the cubed sample is: " << standardDeviationOfCubedSamples(partThree) << endl;
    cout <<"***************" << endl;
    cout <<"****End********" << endl;


    //Put question 2 data into text file
    ofstream myFile("stepTwodata.txt");

    for(int i = 0; i < samples.size(); i++) {
        myFile << samples[i] << endl;
    }
    myFile.close();


        return 0;
}



