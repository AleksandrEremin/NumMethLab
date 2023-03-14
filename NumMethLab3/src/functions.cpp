#include "functions.h"

double TestFunc(double x) {
    if (x >= -1.0 && x <= 0.0)
        return x * x * x + 3.0 * x * x;
    else if (x >= 0.0 && x <= 1.0)
        return -x * x * x + 3.0 * x * x;
    return 0.0;
}

double MainFunc4(double x) {
    return log1p(x) / (x + 1.0);
}

double MainFunc3(double x) {
    return sin(x + 1.0) / (x + 1.0);
}

double MainFunc2(double x) {
    return pow(1.0 + x * x, 1.0 / 3.0);
}

double MainFunc1(double x) {
    return sqrt(x * x - 1.0) / x;
}

double dTF(double x)
{
    if (x >= -1.0 && x <= 0.0)
        return 3.0*x*x + 3.0 * 2.0 * x;
    else if (x >= 0.0 && x <= 1.0)
        return -3.0*x*x + 3.0 * 2.0 * x;
    return 0.0;
}

double d2TF(double x)
{
    if (x >= -1.0 && x <= 0.0)
        return 6.0 * x + 6.0;
    else if (x >= 0.0 && x <= 1.0)
        return - 6.0 * x + 6.0;
    return 0.0;
}

double dF4(double x)
{
    return (1 - log1p(x)) / ((x + 1.0)*(x + 1.0));
}

double d2F4(double x)
{
    return (2*log1p(x) - 3) / ((x + 1.0)*(x + 1.0)*(x + 1.0));
}

double dF1(double x)
{
    return 1/(x*x*sqrt(x*x-1));
}

double d2F1(double x)
{
    return (2-3*x*x)/(x*x*x*pow(x*x-1,3.0/2.0));
}

double dF2(double x)
{
    return (2*x)/(3*pow(1+x*x,2.0/3.0));
}

double d2F2(double x)
{
    return ((0-2)*(x*x-3))/(9*pow(1+x*x,5.0/3.0));
}

double dF3(double x)
{
    return ((x+1)*cos(x+1)-sin(x+1))/pow(x+1,2);
}

double d2F3(double x)
{
    return ((0-1)*(sin(x+1))/(x+1))+((2*sin(x+1))/pow(x+1,3.0))+(((0-2)*cos(x+1))/pow(x+1,2));
}


//--------------------------------
double MainFunc1CosX(double x)
{
    return ((sqrt(x * x - 1.0) / x) + cos(x));
}

double dF1CosX(double x)
{
    return ((1/(x*x*sqrt(x*x-1))) - sin(x));
}

double d2F1CosX(double x)
{
    return (((2-3*x*x)/(x*x*x*pow(x*x-1,3.0/2.0))) - cos(x));
}

double MainFunc1Cos10X(double x)
{
    return ((sqrt(x * x - 1.0) / x) + cos(10*x));
}

double dF1Cos10X(double x)
{
    return ((1/(x*x*sqrt(x*x-1))) - 10*sin(10*x));
}

double d2F1Cos10X(double x)
{
    return (((2-3*x*x)/(x*x*x*pow(x*x-1,3.0/2.0))) - 100*cos(10*x));
}

double MainFunc1Cos100X(double x)
{
    return ((sqrt(x * x - 1.0) / x) + cos(100*x));
}

double dF1Cos100X(double x)
{
    return ((1/(x*x*sqrt(x*x-1))) - 100*sin(100*x));
}

double d2F1Cos100X(double x)
{
    return (((2-3*x*x)/(x*x*x*pow(x*x-1,3.0/2.0))) - 10000*cos(100*x));
}
//--------------------------------
double MainFunc2CosX(double x)
{
    return pow(1.0 + x * x, 1.0 / 3.0) + cos(x);
}

double dF2CosX(double x)
{
    return (2*x)/(3*pow(1+x*x,2.0/3.0)) - sin(x);
}

double d2F2CosX(double x)
{
    return ((0-2)*(x*x-3))/(9*pow(1+x*x,5.0/3.0)) - cos(x);
}

double MainFunc2Cos10X(double x)
{
    return pow(1.0 + x * x, 1.0 / 3.0) + cos(10*x);
}

double dF2Cos10X(double x)
{
    return (2*x)/(3*pow(1+x*x,2.0/3.0)) - 10*sin(10*x);
}

double d2F2Cos10X(double x)
{
    return ((0-2)*(x*x-3))/(9*pow(1+x*x,5.0/3.0)) - 100*cos(10*x);
}

double MainFunc2Cos100X(double x)
{
    return pow(1.0 + x * x, 1.0 / 3.0) + cos(100*x);
}

double dF2Cos100X(double x)
{
    return (2*x)/(3*pow(1+x*x,2.0/3.0)) - 100*sin(100*x);
}

double d2F2Cos100X(double x)
{
    return ((0-2)*(x*x-3))/(9*pow(1+x*x,5.0/3.0)) - 10000*cos(100*x);
}
//--------------------------------

double MainFunc3CosX(double x)
{
    return (sin(x + 1.0) / (x + 1.0)) + cos(x);
}

double dF3CosX(double x)
{
    return (((x+1)*cos(x+1)-sin(x+1))/pow(x+1,2)) - sin(x);
}

double d2F3CosX(double x)
{
    return ((0-1)*(sin(x+1))/(x+1))+((2*sin(x+1))/pow(x+1,3.0))+(((0-2)*cos(x+1))/pow(x+1,2)) - cos(x);
}

double MainFunc3Cos10X(double x)
{
    return (sin(x + 1.0) / (x + 1.0)) + cos(10*x);
}

double dF3Cos10X(double x)
{
    return (((x+1)*cos(x+1)-sin(x+1))/pow(x+1,2)) - 10*sin(10*x);
}

double d2F3Cos10X(double x)
{
    return ((0-1)*(sin(x+1))/(x+1))+((2*sin(x+1))/pow(x+1,3.0))+(((0-2)*cos(x+1))/pow(x+1,2)) - 100*cos(10*x);
}

double MainFunc3Cos100X(double x)
{
    return (sin(x + 1.0) / (x + 1.0)) + cos(100*x);
}

double dF3Cos100X(double x)
{
    return (((x+1)*cos(x+1)-sin(x+1))/pow(x+1,2)) - 100*sin(100*x);
}

double d2F3Cos100X(double x)
{
    return ((0-1)*(sin(x+1))/(x+1))+((2*sin(x+1))/pow(x+1,3.0))+(((0-2)*cos(x+1))/pow(x+1,2)) - 10000*cos(100*x);
}
//--------------------------------

double MainFunc4CosX(double x)
{
    return log1p(x) / (x + 1.0) + cos(x);
}

double dF4CosX(double x)
{
    return (1 - log1p(x)) / ((x + 1.0)*(x + 1.0)) - sin(x);
}

double d2F4CosX(double x)
{
    return (2*log1p(x) - 3) / ((x + 1.0)*(x + 1.0)*(x + 1.0)) - cos(x);
}

double MainFunc4Cos10X(double x)
{
    return log1p(x) / (x + 1.0) + cos(10*x);
}

double dF4Cos10X(double x)
{
    return (1 - log1p(x)) / ((x + 1.0)*(x + 1.0)) - 10*sin(10*x);
}

double d2F4Cos10X(double x)
{
    return (2*log1p(x) - 3) / ((x + 1.0)*(x + 1.0)*(x + 1.0)) - 100*cos(10*x);
}

double MainFunc4Cos100X(double x)
{
    return log1p(x) / (x + 1.0) + cos(100*x);
}

double dF4Cos100X(double x)
{
    return (1 - log1p(x)) / ((x + 1.0)*(x + 1.0)) - 100*sin(100*x);
}

double d2F4Cos100X(double x)
{
    return (2*log1p(x) - 3) / ((x + 1.0)*(x + 1.0)*(x + 1.0)) - 10000*cos(100*x);
}
//---------------------------------

double TestFuncCosX(double x) {
    if (x >= -1.0 && x <= 0.0)
        return x * x * x + 3.0 * x * x + cos(x);
    else if (x >= 0.0 && x <= 1.0)
        return -x * x * x + 3.0 * x * x + cos(x);
    return 0.0;
}

double dTFCosX(double x)
{
    if (x >= -1.0 && x <= 0.0)
        return 3.0*x*x + 3.0 * 2.0 * x - sin(x);
    else if (x >= 0.0 && x <= 1.0)
        return -3.0*x*x + 3.0 * 2.0 * x - sin(x);
    return 0.0;
}

double d2TFCosX(double x)
{
    if (x >= -1.0 && x <= 0.0)
        return 6.0 * x + 6.0 - cos(x);
    else if (x >= 0.0 && x <= 1.0)
        return - 6.0 * x + 6.0 - cos(x);
    return 0.0;
}

double TestFuncCos10X(double x) {
    if (x >= -1.0 && x <= 0.0)
        return x * x * x + 3.0 * x * x + cos(10*x);
    else if (x >= 0.0 && x <= 1.0)
        return -x * x * x + 3.0 * x * x + cos(10*x);
    return 0.0;
}

double dTFCos10X(double x)
{
    if (x >= -1.0 && x <= 0.0)
        return 3.0*x*x + 3.0 * 2.0 * x - 10*sin(10*x);
    else if (x >= 0.0 && x <= 1.0)
        return -3.0*x*x + 3.0 * 2.0 * x -10* sin(10*x);
    return 0.0;
}

double d2TFCos10X(double x)
{
    if (x >= -1.0 && x <= 0.0)
        return 6.0 * x + 6.0 - 100*cos(10*x);
    else if (x >= 0.0 && x <= 1.0)
        return - 6.0 * x + 6.0 - 100*cos(10*x);
    return 0.0;
}

double TestFuncCos100X(double x) {
    if (x >= -1.0 && x <= 0.0)
        return x * x * x + 3.0 * x * x + cos(100*x);
    else if (x >= 0.0 && x <= 1.0)
        return -x * x * x + 3.0 * x * x + cos(100*x);
    return 0.0;
}

double dTFCos100X(double x)
{
    if (x >= -1.0 && x <= 0.0)
        return 3.0*x*x + 3.0 * 2.0 * x - 100*sin(100*x);
    else if (x >= 0.0 && x <= 1.0)
        return -3.0*x*x + 3.0 * 2.0 * x -100* sin(100*x);
    return 0.0;
}

double d2TFCos100X(double x)
{
    if (x >= -1.0 && x <= 0.0)
        return 6.0 * x + 6.0 - 10000*cos(100*x);
    else if (x >= 0.0 && x <= 1.0)
        return - 6.0 * x + 6.0 - 10000*cos(100*x);
    return 0.0;
}



