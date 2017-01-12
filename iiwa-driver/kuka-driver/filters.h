#ifndef FILTERS_
#define FILTERS_

#include <cmath>
#include <cstring>
#include "filters.h"
#include <cstdio>

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
