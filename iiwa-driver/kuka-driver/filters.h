#ifndef FILTERS_
#define FILTERS_

#include <math.h>
#include <string.h>
#include <stdio.h>

class filter
{
public:
	filter(void);
	~filter(void);
	virtual void input(double input_value) = 0;
	virtual double output(void) = 0;
	virtual void clear(void) = 0;
};

filter::filter(void)
{
}

filter::~filter(void)
{
}

class butterworth_filter : public filter
{
public:
	butterworth_filter(int num_sample, double dt, double cutoff_frequency);
	~butterworth_filter(void);
	virtual void input(double input_value);
	virtual double output(void);
	virtual void clear(void);
private:
	double *mpBuffer;
	int mCurIdx;
	int mNumSample;
	double mDt;
	double mCutoffFreq;
	double mValue;
};

butterworth_filter::butterworth_filter(int num_sample, double dt, double cutoff_frequency)
{
	mNumSample	= num_sample;
	mDt			= dt;
	mCutoffFreq	= cutoff_frequency;

	mpBuffer	= new double[num_sample];
	memset((void *)mpBuffer, 0, sizeof(double)*num_sample);

	mCurIdx		= 0;
}

butterworth_filter::~butterworth_filter(void)
{
	delete[] mpBuffer;
}

void butterworth_filter::input(double input_value)
{

	int j;
	double sqrt_2 = sqrt(2);
	double value = 0;
	for ( j = mNumSample-2 ; j >= 0 ; j-- )
	  {
		mpBuffer[j+1] = mpBuffer[j];
	  }

	mpBuffer[0] = input_value;
	for ( j = 0 ; j < mNumSample ; j++ )
	{
		double t = (double)j*mDt;
		value += sqrt_2 / mCutoffFreq * mpBuffer[j] * exp(-1./sqrt_2*t) * sin(mCutoffFreq/sqrt_2*t ) * mDt;
//		value += sqrt_2 * exp(-1./sqrt_2*t) * sin(1./sqrt_2*t ) * mDt;
	}
	
	mValue = value;
}

double butterworth_filter::output(void)
{
	return mValue;
}

void butterworth_filter::clear(void)
{
}

class digital_lp_filter : public filter
{
public:
	digital_lp_filter(float w_c, float t_s);
	~digital_lp_filter(void);
	virtual void input(double input_value);
	virtual double output(void);
	virtual void clear(void);
private:
	float Lpf_in_prev[2];
	float Lpf_out_prev[2];
	float Lpf_in1, Lpf_in2, Lpf_in3, Lpf_out1, Lpf_out2;
	float lpf_out;
};

digital_lp_filter::digital_lp_filter(float w_c, float t_s)
{
	Lpf_in_prev[0] = Lpf_in_prev[1] = 0;
	Lpf_out_prev[0] = Lpf_out_prev[1] = 0;
	Lpf_in1=0, Lpf_in2=0, Lpf_in3=0, Lpf_out1=0, Lpf_out2=0;
	float den = 2500*t_s*t_s*w_c*w_c  + 7071*t_s*w_c + 10000;

	Lpf_in1 = 2500*t_s*t_s*w_c*w_c / den;
	Lpf_in2 = 5000*t_s*t_s*w_c*w_c / den;
	Lpf_in3 = 2500*t_s*t_s*w_c*w_c / den;
	Lpf_out1 = -(5000*t_s*t_s*w_c*w_c  - 20000) / den;
	Lpf_out2 = -(2500*t_s*t_s*w_c*w_c  - 7071*t_s*w_c + 10000) / den;

}

digital_lp_filter::~digital_lp_filter(void)
{
}

void digital_lp_filter::input(double lpf_in)
{
	lpf_out = Lpf_in1*lpf_in + Lpf_in2*Lpf_in_prev[0] + Lpf_in3*Lpf_in_prev[1] + //input component
	Lpf_out1*Lpf_out_prev[0] + Lpf_out2*Lpf_out_prev[1]; //output component
	Lpf_in_prev[1] = Lpf_in_prev[0];
	Lpf_in_prev[0] = lpf_in;
	Lpf_out_prev[1] = Lpf_out_prev[0];
	Lpf_out_prev[0] = lpf_out;
}

double digital_lp_filter::output(void)
{
	return lpf_out;
}

void digital_lp_filter::clear(void)
{
	Lpf_in_prev[1] = 0;
	Lpf_in_prev[0] = 0;
	Lpf_out_prev[1] = 0;
	Lpf_out_prev[0] = 0;
}

class moving_average_filter : public filter
{
public:
    moving_average_filter(int num_data);
    ~moving_average_filter();
    virtual void input(double input_value);
    virtual double output(void);
    virtual void clear(void);
private:
    double * buffer_;
    int num_data_;
    int idx_;
    double sum_;
};
moving_average_filter::moving_average_filter(int num_data): num_data_(num_data),
                                                            idx_(0),
                                                            sum_(0.0){
    buffer_ = new double [num_data_];
    memset((void *)buffer_, 0.0, sizeof(double)*num_data_);
}

void moving_average_filter::input(double input_value){
    sum_ -= buffer_[idx_];
    sum_ += input_value;
    buffer_[idx_] = input_value;
    ++idx_;
    idx_%=num_data_;
}

double moving_average_filter::output(){
    return sum_/num_data_;
}

void moving_average_filter::clear(void){
    sum_ = 0.0;
    memset((void *)buffer_, 0.0, sizeof(double)*num_data_);
}

moving_average_filter::~moving_average_filter(){
    delete [] buffer_;
}

class deriv_lp_filter : public filter
{
public:
	deriv_lp_filter(float w_c, float t_s);
	~deriv_lp_filter(void);
	virtual void input(double input_value);
	virtual double output(void);
	virtual void clear(void);
private:
	double Lpf_in_prev[2];
	double Lpf_out_prev[2];
	double Lpf_in1, Lpf_in2, Lpf_in3, Lpf_out1, Lpf_out2;
	double lpf_out;
};

deriv_lp_filter::deriv_lp_filter(float w_c, float t_s)
{
    Lpf_in_prev[0] = Lpf_in_prev[1] = 0;
    Lpf_out_prev[0] = Lpf_out_prev[1] = 0;
    Lpf_in1=0, Lpf_in2=0, Lpf_in3=0, Lpf_out1=0, Lpf_out2=0;
    double a = 1.4142;
    double den = 4 + 2*a*w_c*t_s + t_s*t_s*w_c*w_c;

    Lpf_in1 = 2*t_s*w_c*w_c / den;
    Lpf_in2 = 0;
    Lpf_in3 = -2.*t_s*w_c*w_c / den;
    Lpf_out1 = -1. *(-8 + t_s*t_s*w_c*w_c*2) / den; 
    Lpf_out2 = -1. *(4 - 2*a * w_c*t_s + t_s*t_s*w_c*w_c) / den;

    clear();
}

deriv_lp_filter::~deriv_lp_filter(void)
{
}

void deriv_lp_filter::input(double lpf_in)
{
	lpf_out = Lpf_in1*lpf_in + Lpf_in2*Lpf_in_prev[0] + Lpf_in3*Lpf_in_prev[1] + //input component
		Lpf_out1*Lpf_out_prev[0] + Lpf_out2*Lpf_out_prev[1]; //output component
	Lpf_in_prev[1] = Lpf_in_prev[0];
	Lpf_in_prev[0] = lpf_in;
	Lpf_out_prev[1] = Lpf_out_prev[0];
	Lpf_out_prev[0] = lpf_out;
}

double deriv_lp_filter::output(void)
{
	return lpf_out;
}

void deriv_lp_filter::clear(void)
{
	Lpf_in_prev[1] = 0;
	Lpf_in_prev[0] = 0;
	Lpf_out_prev[1] = 0;
	Lpf_out_prev[0] = 0;
}

class ff01_filter : filter
{
public:
	ff01_filter(float t_s, float w_c);
	~ff01_filter(void);
	virtual void input(double input_value);
	virtual double output(void);
	virtual void clear(void);
private:
	double Lpf_in_prev[2];
	double Lpf_out_prev[2];
	double Lpf_in1, Lpf_in2, Lpf_in3, Lpf_out1, Lpf_out2;
	double lpf_out;
};

ff01_filter::ff01_filter(float t_s, float w_c)
{
	Lpf_in_prev[0] = Lpf_in_prev[1] = 0;
	Lpf_out_prev[0] = Lpf_out_prev[1] = 0;
	Lpf_in1=0, Lpf_in2=0, Lpf_in3=0, Lpf_out1=0, Lpf_out2=0;
    double a = 1.4142;
	double den = 4 + 2*a*w_c*t_s + t_s*t_s*w_c*w_c;
    double J = 0.00008;
    double B = 0.0002;

	Lpf_in1 = B*t_s*t_s*w_c*w_c + 2*J*t_s*w_c*w_c;
	Lpf_in2 = 2*B*t_s*t_s*w_c*w_c;
	Lpf_in3 = B*t_s*t_s*w_c*w_c - 2 * J * t_s * w_c * w_c;
	Lpf_out1 = -1. *(-8 + t_s*t_s*w_c*w_c*2) / den; 
	Lpf_out2 = -1. *(4 - 2*a * w_c*t_s + t_s*t_s*w_c*w_c) / den;
}

ff01_filter::~ff01_filter(void)
{
}

void ff01_filter::input(double lpf_in)
{
	lpf_out = Lpf_in1*lpf_in + Lpf_in2*Lpf_in_prev[0] + Lpf_in3*Lpf_in_prev[1] + //input component
		Lpf_out1*Lpf_out_prev[0] + Lpf_out2*Lpf_out_prev[1]; //output component
	Lpf_in_prev[1] = Lpf_in_prev[0];
	Lpf_in_prev[0] = lpf_in;
	Lpf_out_prev[1] = Lpf_out_prev[0];
	Lpf_out_prev[0] = lpf_out;
}

double ff01_filter::output(void)
{
	return lpf_out;
}

void ff01_filter::clear(void)
{
	Lpf_in_prev[1] = 0;
	Lpf_in_prev[0] = 0;
	Lpf_out_prev[1] = 0;
	Lpf_out_prev[0] = 0;
}

class ff02_filter : filter
{
public:
	ff02_filter(float t_s, float w_c);
	~ff02_filter(void);
	virtual void input(double input_value);
	virtual double output(void);
	virtual void clear(void);
private:
	double Lpf_in_prev[2];
	double Lpf_out_prev[2];
	double Lpf_in1, Lpf_in2, Lpf_in3, Lpf_out1, Lpf_out2;
	double lpf_out;
};

ff02_filter::ff02_filter(float t_s, float w_c)
{
    double J = 0.003216;

	Lpf_in_prev[0] = Lpf_in_prev[1] = 0;
	Lpf_out_prev[0] = Lpf_out_prev[1] = 0;
	Lpf_in1=0, Lpf_in2=0, Lpf_in3=0, Lpf_out1=0, Lpf_out2=0;

    double a = 1.4142;
	double den = 4 + 2*a*w_c*t_s + t_s*t_s*w_c*w_c;

	Lpf_in1 = J*2*t_s*w_c*w_c / den;
	Lpf_in2 = 0;
	Lpf_in3 = -2.*J*t_s*w_c*w_c / den;
	Lpf_out1 = -1. *(-8 + t_s*t_s*w_c*w_c*2) / den; 
	Lpf_out2 = -1. *(4 - 2*a * w_c*t_s + t_s*t_s*w_c*w_c) / den;

    clear();

}

ff02_filter::~ff02_filter(void)
{
}

void ff02_filter::input(double lpf_in)
{
	lpf_out = Lpf_in1*lpf_in + Lpf_in2*Lpf_in_prev[0] + Lpf_in3*Lpf_in_prev[1] + //input component
		Lpf_out1*Lpf_out_prev[0] + Lpf_out2*Lpf_out_prev[1]; //output component
	Lpf_in_prev[0] = lpf_in;
	Lpf_in_prev[1] = Lpf_in_prev[0];
	Lpf_out_prev[0] = lpf_out;
	Lpf_out_prev[1] = Lpf_out_prev[0];
}

double ff02_filter::output(void)
{
	return lpf_out;
}

void ff02_filter::clear(void)
{
	Lpf_in_prev[1] = 0;
	Lpf_in_prev[0] = 0;
	Lpf_out_prev[1] = 0;
	Lpf_out_prev[0] = 0;
}

#endif