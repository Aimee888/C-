// selfTrainingDll.cpp : Defines the exported functions for the DLL application.
//

#include "stdafx.h"
#include <WINDOWS.H>

#define DLL_TRAINING_API _declspec(dllexport)

#include <iostream>
#include "selfTrainingDll.h"

using namespace std;

double DLL_TRAINING_API arithmetic_operation::Add(double a, double b) {
	return a + b;
}

double DLL_TRAINING_API arithmetic_operation::Sub(double a, double b) {
	return a - b;
}

double DLL_TRAINING_API arithmetic_operation::Multi(double a, double b) {
	return a * b;
}

double DLL_TRAINING_API arithmetic_operation::Div(double a, double b) {
	return a / b;
}

int DLL_TRAINING_API export333() {
	return 333;
}


