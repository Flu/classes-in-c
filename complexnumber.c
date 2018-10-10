#include "complexnumber.h"

struct _ComplexNumber {
	// Class attributes
	double real, imag;

	// Class methods
	void (*__init__)(ComplexNumber*);
	void (*setReal)(ComplexNumber*, const double);
	void (*setImag)(ComplexNumber*, const double);
	float (*magnitude)(const ComplexNumber*);
	int (*equalTo)(ComplexNumber*, const ComplexNumber*);
};

// Private methods

static void setReal_P(ComplexNumber* this, const double real) {
	this->real = real;
}

static void setImag_P(ComplexNumber* this, const double imag) {
	this->imag = imag;
}

static float magnitude_P(const ComplexNumber* this) {
	return sqrt(this->real*this->real + this->imag*this->imag);
}

static int equalTo_P(ComplexNumber* this, const ComplexNumber* comp) {
	return (this->real == comp->real && this->imag == comp->imag) ? 1 : 0;
}

// Public

void __init__(ComplexNumber* this) {
	this->real = 0.0;
	this->imag = 0.0;
	this->setReal = setReal_P;
	this->setImag = setImag_P;
	this->magnitude = magnitude_P;
	this->equalTo = equalTo_P;
}