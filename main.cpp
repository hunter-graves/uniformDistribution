#include <iostream>
#include <vector>
#include <math.h>
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
vector<double> sampleGeneration()
{
    vector<double> vectorToHoldSamples;
    for(int x = 0; x < 250; x++)
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
        runningTotal += ( pow( (vectorOfCubedSamples[x] - mean), 2) );
    }
    return sqrt(runningTotal/(vectorOfCubedSamples.size()-1));
}


int main()
{
    srand(time(0));
//vector for 250 samples
vector<double> samples = sampleGeneration();
//vector to cube each sample
samples = samplesCubed(samples);
    for (int count = 0; count < samples.size(); count++)
 {
    cout << "samples["<<count<<"] "<< "contains: " << samples[count] << endl;
 }

    cout <<"********" << endl;
    cout <<"********" << endl;
    cout << "The mean of the cubed samples is: " << meanOfCubedSamples(samples) << endl;
    cout <<"********" << endl;
    cout <<"********" << endl;
    cout << "The standard deviation of the cubed sample is: " << standardDeviationOfCubedSamples(samples) << endl;
    return 0;
}



