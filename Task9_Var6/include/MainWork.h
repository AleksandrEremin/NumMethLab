#pragma once

#include <vector>
#include <iostream>
#include <cmath>

class MainWork
{
public:
    std::vector<double> grid;
    std::vector<double> grid_step;
    std::vector<double> true_values;
    std::vector<double> num_values;
    std::vector<double> d_num_values;
    std::vector<double> final_num_values;
    std::vector<int> mult2;
    std::vector<int> div2;
    double right_border;
    double eps;
    bool ctrl_local_err;
    int max_steps;
    int mult;
    int div;
	double L;
	double R;
	double E0;
	double omega;
    int n=0;

	MainWork(double L_, double R_, double E0_, double omega_, double right_border_, double initial_value_, double initial_step_, int max_steps_, bool ctrl_local_err_ = false, double eps_ = 1e-8);
	double Func(double x, double u);
	double NumFunc(double x, double v, double h);
	double DNumFunc(double x, double v, double h);
    double TrueFunc(double x);
    void MethodStep(int P);
	void Run();
    //void Run1();
     //void Run2();
	void Print();

};




