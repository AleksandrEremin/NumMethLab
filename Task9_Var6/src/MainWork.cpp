#include "MainWork.h"
#include "mainwindow.h"
MainWork::MainWork(double L_, double R_, double E0_, double omega_, double right_border_, double initial_value_, double initial_step_, int max_steps_, bool ctrl_local_err_, double eps_)
{
    mult = 0;
    div = 0;
    this->ctrl_local_err = ctrl_local_err_;
    this->eps = eps_;
    this->max_steps = max_steps_;
    this->right_border = right_border_;
    mult2.push_back(mult);
    div2.push_back(div);
    grid.push_back(0);
    grid_step.push_back(initial_step_);
    true_values.push_back(initial_value_);
    num_values.push_back(initial_value_);
    d_num_values.push_back(initial_value_);
    final_num_values.push_back(initial_value_);

    L = L_;
	R = R_;
	E0 = E0_;
    omega = omega_;
}

double MainWork::Func(double x, double I)
{
	return ((E0*sin(omega*x)-R*I)/(L));
}

double MainWork::TrueFunc(double x)
{
    return (((R*E0*sin(omega*x))/((L*L)*(omega*omega)+(R*R))) -
    ((L*E0*omega*cos(omega*x))/((L*L)*(omega*omega)+(R*R))) +
    (((true_values.front() + (L * E0 * omega) / ((L * L) * (omega * omega) + (R * R))) * exp(-(R*x)/L))));
}

double MainWork::NumFunc(double x, double v, double h)
{
	const double k1 = Func(x, v);
	const double k2 = Func(x + h / 2.0, v + h / 2.0 * k1);
	const double k3 = Func(x + h / 2.0, v + h / 2.0 * k2);
	const double k4 = Func(x + h, v + h * k3);
    return (v + h / 6.0 * (k1 + 2.0 * k2 + 2.0 * k3 + k4));
}

double MainWork::DNumFunc(double x, double v, double h)
{
	const double v_tmp = NumFunc(x, v, h / 2);
	return NumFunc(x + h / 2, v_tmp, h / 2);
}
void MainWork::MethodStep(int P)
{
	double h = grid_step.back();
	const double v = NumFunc(grid.back(), final_num_values.back(), h);
	const double v2 = DNumFunc(grid.back(), final_num_values.back(), h);
	const double s = abs(v2 - v) / 15;

    if (s > eps && ctrl_local_err && P!=1) //P только для последнего шага (If в ран)
	{
		grid_step.back() /= 2;
		div++;
        n--;
	}
	else
    {
		const double x = grid.back() + h;
        const double u = TrueFunc(x);
        if (s < eps / 32 && ctrl_local_err && P!=1)
		{
			h *= 2;
			mult++;
		}

		mult2.push_back(mult);
		div2.push_back(div);
		grid_step.push_back(h);
		grid.push_back(x);
        true_values.push_back(u);
		num_values.push_back(v);
		d_num_values.push_back(v2);
		final_num_values.push_back(v + 16 * s);

	}
}

void MainWork::Run()
{
     n = 0;
    while (grid.back() + grid_step.back() <= right_border && n < max_steps)
    {
        n++;
        MethodStep(0);
    }

   // qDebug() << "n:" << n <<"grid.size(): "<<grid.size()<<" grid.back() + grid_step.back():"<<grid.back() + grid_step.back();
           // qDebug()<<" grid.back(): "<< grid.back()<< " grid_step.back(): "<< grid_step.back();
  // qDebug()<<"eps: "<< eps;
    if (right_border - grid.back() > eps && grid.back() + grid_step.back() > right_border )
    {
        //qDebug()<<"Зашел;";
        //qDebug()<<"right_border - grid.back() "<<right_border - grid.back();
        grid_step.back() = right_border - grid.back();
        MethodStep(1);
        //qDebug() << "n:" << n;
    }
   // qDebug() << "right_border: "<< right_border<<" grid.back(): " << grid.back();
    //qDebug() << "right_border - grid.back():" << right_border - grid.back();
}



/*void MainWork::Run2()
{
    int i = 0;
    while (grid.back() + grid_step.back() <= right_border && n < max_steps)
    {
        n++;
        i++;
        MethodStep();
    }
    qDebug()<<"n: "<<n;
    qDebug() <<"grid.back(): "<<grid.back()<< " grid_step.back(): "<<  grid_step.back()<< " right_border: "<<right_border<<"max_steps: "<<max_steps;
     std::vector<double> gridTMP(grid);
    while(ctrl_local_err && gridTMP.back() + grid_step.back() > right_border && right_border - gridTMP.back()> eps)
    {
       // qDebug() <<"grid.back(): "<<grid.back()<< " grid_step.back(): "<<  grid_step.back()<< " right_border: ";
        grid_step.back()/=2;
        div++;
        qDebug()<<" grid.back() + grid_step.back(): "<<grid.back() + grid_step.back()<<"right_border:"<<right_border;

        if((gridTMP.back() + grid_step.back())<right_border||(gridTMP.back() + grid_step.back())-right_border<=eps)
        {
            qDebug()<<"Зашел;";
            gridTMP.push_back(grid.back() + grid_step.back());
        }
    }
    if(ctrl_local_err  &&  right_border - grid.back()>= eps && grid.back() + grid_step.back() <= right_border && n < max_steps)
    {
        MethodStep();
    }

   qDebug() << "right_border: "<< right_border<<" grid.back(): " << grid.back();
   qDebug() << "right_border - grid.back():" << right_border - grid.back();
}

void MainWork::Run1()
{
    int i = 0;
    while (grid.back() + grid_step.back() <= right_border && n < max_steps)
    {
        n++;
        i++;
        MethodStep();
        //qDebug()<<"n: "<<n;
        //qDebug() <<"grid.back(): "<<grid.back()<< " grid_step.back(): "<<  grid_step.back()<< " right_border: "<<right_border<<"max_steps: "<<max_steps;
    }
    qDebug()<<"n: "<<n;
    qDebug() <<"grid.back(): "<<grid.back()<< " grid_step.back(): "<<  grid_step.back()<< " right_border: "<<right_border<<"max_steps: "<<max_steps;
    while(ctrl_local_err && grid.back() + grid_step.back() > right_border && right_border - grid.back()> eps)
    {
        grid_step.back()/=2;
        div++;
    }
    if(ctrl_local_err  &&  right_border - grid.back()>= eps && grid.back() + grid_step.back() <= right_border && n < max_steps)
    {
        MethodStep();
    }
   qDebug() << "right_border: "<< right_border<<" grid.back(): " << grid.back();
   qDebug() << "right_border - grid.back():" << right_border - grid.back();
}*/

void MainWork::Print()
{
	unsigned long long N = grid.size();
    for (unsigned int i = 0; i < N; i++)
	{
		std::cout << "Num: (" << grid[i] << ", " << num_values[i] << ")"
			<< "\th = " << grid_step[i] << "\tv = " << num_values[i] << "\tv2 = " << d_num_values[i]
			<< "\nmult2 = " << mult2[i] << ", div = " << div2[i]
			<< std::endl;
	}
}
