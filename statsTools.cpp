#include <iostream>
#include <cstdio>
#include <cmath>
#include <math.h>
#include <iomanip>
#include <vector>
#include <map>
#include <string>
#include <algorithm>
using namespace std;

int factorial(int num)
{
    if (num == 0) return 1;
    else return num * factorial(num - 1);
}

double nChooseK(int n, int k)
{
    return (double)(factorial(n)/(factorial(n-k) * factorial(k)));
}

double mean(vector<double> v, int len)
{
    double mean = 0;
    for (int i = 0; i < v.size(); i++)
    {
        mean += v[i];
    }
    return mean/len;
}

double weightedMean(vector<double> v, int len)
{
    double numerator = 0, denominator = 0;
    for (int i = 0; i < v.size(); i++)
    {
        numerator += v[i] * v[i+len];
        denominator += v[i+len];
    }
    return numerator/denominator;
}

double mode(vector<double> v, int len)
{
    sort(v.begin(), v.end());
    int counter = 1, largest = 0;
    double mode, tmp = v[len-1];
    for (int i = len-2; i >= 0; i--)
    {
        if (v[i] == tmp) counter++;
        else tmp = v[i];

        if (largest <= counter)
        {
            largest = counter;
            mode = v[i];
            counter = 1;
        }
    }
    return mode;
}

double median(vector<double> v)
{
    int len = v.size();
    double median, m1, m2;
    sort(v.begin(), v.end());
    if (len % 2 == 0) {
        m1 = v[len/2 - 1];
        m2 = v[len/2];
        median = (m1 + m2) / 2;
    } else {
        median = v[len/2];
    }
    return median;
}

double standardDev(vector<double> v, int len)
{
    double numerator = 0, u = mean(v, len);
    for (int i = 0; i < len; i++)
    {
        numerator += pow((v[i] - u), 2);
    }
    return sqrt(numerator/len);
}

void quartiles(vector<double> v, int len)
{
    double med;
    sort(v.begin(), v.end());
    vector<double> lower, upper;
    if (len % 2 != 0) // odd length
    {
        med = v[len/2];
        for (int i = 0; i < len/2; i++) lower.push_back(v[i]);
        for (int i = (len/2)+1; i < len; i++) upper.push_back(v[i]);
    }
    else // even length
    {
        med = (v[len/2 - 1] + v[len/2]) / 2;
        for (int i = 0; i < len/2; i++) lower.push_back(v[i]);
        for (int i = (len/2); i < len; i++) upper.push_back(v[i]);
    }

    cout << "Lower Quartile: " << median(lower) << endl;
    cout << "Middle Quartile: " << med << endl;
    cout << "Upper Quartile: " << median(upper) << endl << endl;
}

double binomial(int n, int k, double prob)
{
    return nChooseK(n, k) * pow(prob, k) * pow(1-prob, n-k);
}

double poisson(int k, double lambda)
{
    return (double)((pow(lambda, k) * exp((-1)*lambda))/(factorial(k)));
}

int main()
{
    int choice;
    do {
        cout << "Select computation to perform:" << endl <<

                "0. Exit\n" <<
                "1. Mean\n" <<
                "2. Weighted Mean\n" <<
                "3. Mode\n" <<
                "4. Median\n" <<
                "5. Standard Deviation\n" <<
                "6. Factorial\n" <<
                "7. Quartiles (Lower, Middle, Upper)\n" <<
                "8. Binomial Probability Distribution\n" <<
                "9. Poisson Probability Distribution\n" <<
                "10. Geometric Probability Distribution (nth trial success)\n" <<
                "11. Geometric Probability Distribution (n failures before success)\n" <<
                "12. Normal Probability Distribution\n" <<
                "13. Pearson Correlation Coefficient\n" <<
                "14. Spearman's Rank Correlation Coefficient\n\n" <<

                "Your choice --> ";

        cin >> choice;
        cout << endl;
        
        vector<double> v, v2, v3, v4;
        map<double, int> map3, map4;
        int len, iter, n, k, valX = 1, valY = 1;
        double tmp, prob, answer = 0, m, stdev, lower, upper;
        double x_mean, y_mean, x_stdev, y_stdev, numerator, denominator;
        bool unique = true;
        string pick;
        
        switch(choice)
        {
            case 0:
                cout << "Have a nice day!" << endl << endl;
                break;
            //==========================================================================================================
            case 1:
                cout << "Enter the number of elements in the data set --> "; cin >> len;
                iter = 0;
                cout << "Enter the " << len << " elements (separated by spaces) --> ";
                while (iter < len)
                {
                    cin >> tmp;
                    v.push_back(tmp);
                    iter++;
                }
                cout << fixed << setprecision(3) << "\nMean = " << mean(v, len) << endl << endl;
                v.clear();
                cout << "==============================" << endl;
                break;
            //==========================================================================================================
            case 2:
                cout << "Enter the number of elements in the data set --> "; cin >> len;
                iter = 0;
                cout << "Enter the " << len << " elements (separated by spaces) --> ";
                while (iter < len)
                {
                    cin >> tmp;
                    v.push_back(tmp);
                    iter++;
                }
                cout << "Now enter their respective weights (separated by spaces) --> ";
                iter = 0;
                while (iter < len)
                {
                    cin >> tmp;
                    v.push_back(tmp);
                    iter++;
                }
                cout << fixed << setprecision(3) << "\nWeighted Mean = " << weightedMean(v, len) << endl << endl;
                v.clear();
                cout << "==============================" << endl;
                break;
            //==========================================================================================================
            case 3:
                cout << "Enter the number of elements in the data set --> "; cin >> len;
                iter = 0;
                cout << "Enter the " << len << " elements (separated by spaces) --> ";
                while (iter < len)
                {
                    cin >> tmp;
                    v.push_back(tmp);
                    iter++;
                }
                cout << fixed << setprecision(3) << "\nMode = " << mode(v, len) << endl << endl;
                v.clear();
                cout << "==============================" << endl;
                break;
            //==========================================================================================================
            case 4:
                cout << "Enter the number of elements in the data set --> "; cin >> len;
                iter = 0;
                cout << "Enter the " << len << " elements (separated by spaces) --> ";
                while (iter < len)
                {
                    cin >> tmp;
                    v.push_back(tmp);
                    iter++;
                }
                cout << fixed << setprecision(3) << "\nMedian = " << median(v) << endl << endl;
                v.clear();
                cout << "==============================" << endl;
                break;
            //==========================================================================================================
            case 5:
                cout << "Enter the number of elements in the data set --> "; cin >> len;
                iter = 0;
                cout << "Enter the " << len << " elements (separated by spaces) --> ";
                while (iter < len)
                {
                    cin >> tmp;
                    v.push_back(tmp);
                    iter++;
                }
                cout << fixed << setprecision(3) << "\nStandard Deviation = " << standardDev(v, len) << endl << endl;
                v.clear();
                cout << "==============================" << endl;
                break;
            //==========================================================================================================
            case 6:
                cout << "Enter the number whose factorial you wish to compute --> ";
                cin >> len;
                cout << endl << len << "! = " << factorial(len) << endl << endl;
                cout << "==============================" << endl;
                break;
            //==========================================================================================================
            case 7:
                cout << "Enter the number of elements in the data set --> "; cin >> len;
                iter = 0;
                cout << "Enter the " << len << " elements (separated by spaces) --> ";
                while (iter < len)
                {
                    cin >> tmp;
                    v.push_back(tmp);
                    iter++;
                }
                cout << endl;
                quartiles(v, len);
                v.clear();
                cout << endl << "==============================" << endl;
                break;
            //==========================================================================================================
            case 8:
                cout << "Enter the number of trials --> "; cin >> n;
                cout << "Enter the number of successes --> "; cin >> k;
                cout << "Enter the probability --> "; cin >> prob;
                
                answer = binomial(n, k, prob);
                cout << endl << fixed << setprecision(3) << "P(X = " << k << ") = " << answer << endl;

                answer = 0;
                for (int i = 0; i <= k; i++) answer += binomial(n, i, prob);
                cout << fixed << setprecision(3) << "P(X <= " << k << ") = " << answer << endl;
                answer = 1 - answer;
                cout << fixed << setprecision(3) << "P(X > " << k << ") = " << answer << endl;
                
                answer = 0;
                for (int i = 0; i < k; i++) answer += binomial(n, i, prob);
                cout << fixed << setprecision(3) << "P(X < " << k << ") = " << answer << endl;
                answer = 1 - answer;
                cout << fixed << setprecision(3) << "P(X >= " << k << ") = " << answer << endl << endl;
                
                cout << "E[X] = " << n*prob << endl;
                cout << "Var[X] = " << n*prob*(1-prob) << endl << endl;

                cout << "Standard Deviation = " << sqrt(n*prob*(1-prob)) << endl << endl;
                cout << "==============================" << endl;
                answer = 0;
                break;
            //==========================================================================================================
            case 9:
                cout << "Enter the Poisson random variable --> "; cin >> k;
                cout << "Enter the average rate of success (lambda) --> "; cin >> prob;
                
                answer = poisson(k, prob);
                cout << endl << fixed << setprecision(3) << "P(X = " << k << ") = " << answer << endl;

                answer = 0;
                for (int i = 0; i <= k; i++) answer += poisson(i, prob);
                cout << fixed << setprecision(3) << "P(X <= " << k << ") = " << answer << endl;
                answer = 1 - answer;
                cout << fixed << setprecision(3) << "P(X > " << k << ") = " << answer << endl;
                
                answer = 0;
                for (int i = 0; i < k; i++) answer += poisson(i, prob);
                cout << fixed << setprecision(3) << "P(X < " << k << ") = " << answer << endl;
                answer = 1 - answer;
                cout << fixed << setprecision(3) << "P(X >= " << k << ") = " << answer << endl << endl;
                
                cout << "E[X] = " << prob << endl;
                cout << "Var[X] = " << prob << endl << endl;

                cout << "Standard Deviation = " << sqrt(prob) << endl << endl;
                cout << "==============================" << endl;
                answer = 0;
                break;
            //==========================================================================================================
            case 10:
                cout << "Enter the nth trial of success --> "; cin >> n;
                cout << "Enter the probability of success --> "; cin >> prob;
                
                answer = (double)(prob * pow(1-prob, n-1));
                cout << "Probability that success is on trial " << n << ":" << endl;
                cout << fixed << setprecision(3) << "P(X = " << n << ") = " << answer << endl << endl;

                cout << "E[X] = " << 1/prob << endl;
                cout << "Var[X] = " << (1-prob)/(prob*prob) << endl << endl;
                
                cout << "Standard Deviation = " << sqrt((1-prob)/(prob*prob)) << endl << endl;
                cout << "==============================" << endl;
                answer = 0;
                break;
            //==========================================================================================================
            case 11:
                cout << "Enter the number of trials before success --> "; cin >> n;
                cout << "Enter the probability of success --> "; cin >> prob;
                
                answer = (double)(prob * pow(1-prob, n));
                cout << fixed << setprecision(3) << "P(X = " << n << ") = " << answer << endl;

                answer = (double)(1 - pow(1-prob, n+1));
                cout << fixed << setprecision(3) << "P(X <= " << n << ") = " << answer << endl;
                
                answer = (double)(pow(1-prob, n));
                cout << fixed << setprecision(3) << "P(X >= " << n << ") = " << answer << endl << endl;
                
                cout << "E[X] = " << (1-prob)/prob << endl;
                cout << "Var[X] = " << (1-prob)/(prob*prob) << endl << endl;

                cout << "Standard Deviation = " << sqrt((1-prob)/(prob*prob)) << endl << endl;
                cout << "==============================" << endl;
                answer = 0;
                break;
            //==========================================================================================================
            case 12:
                cout << "Enter the mean --> "; cin >> m;
                cout << "Enter the standard deviation --> "; cin >> stdev;
                cout << "Enter the lower limit --> "; cin >> lower;
                cout << "Enter the upper limit --> "; cin >> upper;

                answer = (erf((upper-m)/(sqrt(2)*stdev)) - erf((lower-m)/(sqrt(2)*stdev))) / 2.0;
                cout << "\nP(" << lower << " <= X <= " << upper << ") = " << fixed << setprecision(3) << answer << endl;
                cout << fixed << setprecision(3) << "Complement = " << 1-answer << endl << endl;
                cout << "==============================" << endl;
                break;
            //==========================================================================================================
            case 13:
                x_mean = 0; y_mean = 0; x_stdev = 0; y_stdev = 0; numerator = 0;
                cout << "Enter the number of elements present in both data sets --> "; cin >> len;
                iter = 0;
                cout << "Enter the " << len << " elements (separated by spaces) of the first data set --> ";
                while (iter < len)
                {
                    cin >> tmp;
                    x_mean += tmp;
                    v.push_back(tmp);
                    iter++;
                }
                cout << "Now enter the " << len << " elements (separated by spaces) of the second data set --> ";
                iter = 0;
                while (iter < len)
                {
                    cin >> tmp;
                    y_mean += tmp;
                    v2.push_back(tmp);
                    iter++;
                }

                x_mean /= len; y_mean /= len;
                for (int i = 0; i < len; i++)
                {
                    x_stdev += pow(v[i]-x_mean, 2);
                    y_stdev += pow(v2[i]-y_mean, 2);
                    numerator += (v[i]-x_mean) * (v2[i]-y_mean);
                }
                x_stdev /= len; y_stdev /= len;
                x_stdev = sqrt(x_stdev); y_stdev = sqrt(y_stdev);

                cout << fixed << setprecision(3) <<
                                "\nPearson Correlation Coefficient = " << numerator/(len*x_stdev*y_stdev) << "\n\n";
                v.clear(); v2.clear();
                cout << "==============================" << endl;
                break;
            //==========================================================================================================
            case 14:
                x_mean = 0; y_mean = 0; x_stdev = 0; y_stdev = 0; numerator = 0;
                cout << "Enter the number of elements present in both data sets --> "; cin >> len;
                iter = 0;
                cout << "Enter the " << len << " elements (separated by spaces) of the first data set --> ";
                while (iter < len)
                {
                    cin >> tmp;
                    x_mean += tmp;
                    v.push_back(tmp);
                    v3.push_back(tmp);
                    iter++;
                }
                cout << "Now enter the " << len << " elements (separated by spaces) of the second data set --> ";
                iter = 0;
                while (iter < len)
                {
                    cin >> tmp;
                    y_mean += tmp;
                    v2.push_back(tmp);
                    v4.push_back(tmp);
                    iter++;
                }
                sort(v3.begin(), v3.end());
                sort(v4.begin(), v4.end());

                for (int i = 0; i < len; i++)
                {
                    map3[v3[i]] = valX;
                    map4[v4[i]] = valY;

                    if (i == len-1) break;
                    if (v3[i] != v3[i+1]) valX++;
                    if (v4[i] != v4[i+1]) valY++;
                }
                for (int i = 0; i < len-1; i++)
                {
                    if (v3[i] == v3[i+1] || v4[i] == v4[i+1]) unique = false;
                }
                for (int i = 0; i < len; i++)
                {
                    v[i] = map3[v[i]];
                    v2[i] = map4[v2[i]];
                }

                if (!unique)
                {
                    for (int i = 0; i < len; i++)
                    {
                        x_mean += v[i];
                        y_mean += v2[i];
                    }
                    for (int i = 0; i < len; i++)
                    {
                        x_stdev += pow(v[i] - x_mean, 2);
                        y_stdev += pow(v2[i] - y_mean, 2);
                        numerator += (v[i] - x_mean) * (v2[i] - y_mean);
                    }
                    x_stdev /= len; y_stdev /= len;
                    x_stdev = sqrt(x_stdev); y_stdev = sqrt(y_stdev);
                    denominator = len * x_stdev * y_stdev;
                    answer = numerator/denominator;
                }
                else
                {
                    double d = 0, den = len * (pow(len, 2) - 1), num = 0;
                    for (int i = 0; i < len; i++)
                    {
                        d += pow((v[i] - v2[i]), 2);
                    }
                    num = 6.0 * d;
                    answer = 1 - (num/den);
                }
            
                cout << fixed << setprecision(3) <<
                                "\nSpearman's Rank Correlation Coefficient = " << answer << "\n\n";
                v.clear(); v2.clear(); v3.clear(); v4.clear(); map3.clear(); map4.clear(); answer = 0;
                cout << "==============================" << endl;
                break;
            //==========================================================================================================
            default:
                cout << "Invalid input. Try again!" << endl;
                cout << "==============================" << endl;
                break;
        }
    } while(choice != 0);
    return 0;
}
