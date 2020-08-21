#pragma once
#include <iostream>
#include "CentralPoint.h"

using namespace std;
class CurveCircle : public CentralPoint {
private:
	 float radius;

public:
	CurveCircle() : CentralPoint(){
		radius = 1;
	}

	CurveCircle(vector<float> _center, float _radius) : CentralPoint(_center) {
		radius = 1;
		try {
			if (_radius < 0) {
				throw 1;
			}
			radius = _radius;
		}
		catch (int exeptionID) {
			cout << "Error " << exeptionID << " radius < 0" << endl;
		}
	}
	
	CurveCircle(const CurveCircle& otherCircle) : CentralPoint(otherCircle.center), radius(otherCircle.radius) { }

	friend ostream& operator<< (ostream& out, const CurveCircle& cCircle) {

		return out << "Circle { \n"
			<< "    Center: (" << cCircle.center[0] << ", " << cCircle.center[1] << ", " << cCircle.center[2] << ") \n"
			<< "    Radius: " << cCircle.radius << "\n"
			<< "}" << endl;
	}

	void operator= (const CurveCircle otherCicle) {
		radius = otherCicle.radius;
		center = otherCicle.center;
	}

	bool operator> (CurveCircle otherCicle) {
		if (radius > otherCicle.radius) {
			return true;
		}

		return false;
	}

	bool operator< (CurveCircle otherCicle) {
		if (radius < otherCicle.radius) {
			return true;
		}

		return false;
	}

	bool operator== (CurveCircle otherCicle) {
		if (radius == otherCicle.radius) {
			return true;
		}

		return false;
	}

	 vector<float> GetPoint(float t) {
		 float x = radius * cos(t) + center[0];
		 float y = radius * sin(t) + center[1];
		 float z = center[2];

		 return {x, y, z};
	 }
	 
	 vector<float> GetPointDerivative(float t) {
		 float x = -radius * sin(t);
		 float y = radius * cos(t);
		 float z = 0;

		 return { x, y, z };
	 }

	 void PrintPoint(float t) {
		 float x = radius * cos(t) + center[0];
		 float y = radius * sin(t) + center[1];
		 float z = center[2];

		 cout << "Point: (" << x << ", " << y << ", " << z << " )" << endl;
	 }

	 void PrintPointDerivative(float t) {
		 float x = -radius * sin(t);
		 float y = radius * cos(t);
		 float z = 0;

		 cout << "Derivative: (" << x << ", " << y << ", " << z << " )" << endl;
	 }

	 virtual bool IsCircle() {
		 return true;
	 }
	 virtual bool IsEllipse() {
		 return false;
	 }
	 virtual bool IsHelixe() {
		 return false;
	 }

	 float GetRadius() {
		 return radius;
	 }

	 void Print() {
		 cout << "Circle { \n"
			 << "    Center: (" << center[0] << ", " << center[1] << ", " << center[2] << ") \n"
			 << "    Radius: " << radius << "\n"
			 << "}" << endl;
	 }

};