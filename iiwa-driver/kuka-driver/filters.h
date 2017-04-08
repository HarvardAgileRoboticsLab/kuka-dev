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

#endif