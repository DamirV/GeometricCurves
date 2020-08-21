#pragma once
#include <iostream>

using namespace std;
class CurveHelixe : public CentralPoint {
private:
	float radius;
	float step;

public:
	CurveHelixe() : CentralPoint() {
		radius = 1;
		step = 2 * PI;
	}

	CurveHelixe(vector<float> _center, float _radius, float _step) : CentralPoint(_center) {
		radius = 1;
		step = 2 * PI;
		try {
			if (_radius < 0 || _step < 0) {
				throw 1;
			}
			radius = _radius;
			step = _step;
		}
		catch (int exeptionID) {
			cout << "Error " << exeptionID << " radius < 0 or step < 0" << endl;
		}
	}


	friend ostream& operator<< (ostream& out, const CurveHelixe& cHelixe) {

		return out << "Helixe { \n"
			<< "    Center: (" << cHelixe.center[0] << ", " << cHelixe.center[1] << ", " << cHelixe.center[2] << ") \n"
			<< "    Radius: " << cHelixe.radius << "\n"
			<< "    Step: " << cHelixe.step << "\n"
			<< "}" << endl;
	}

	void Print() {
		cout << "Helixe { \n"
			<< "    Center: (" << center[0] << ", " << center[1] << ", " << center[2] << ") \n"
			<< "    Radius: " << radius << "\n"
			<< "    Step: " << step << "\n"
			<< "}" << endl;
	}

	vector<float> GetPoint(float t) {
		float pi = PI;

		float x = radius * cos(t) + center[0];
		float y = radius * sin(t) + center[1];
		float z = step /(2 * pi) * t + center[2];

		return { x, y, z };
	}

	vector<float> GetPointDerivative(float t) {
		float pi = PI;

		float x = -radius * sin(t);
		float y = radius * cos(t);
		float z = step / (2 * pi);

		return { x, y, z };
	}

	void PrintPoint(float t) {
		float pi = PI;

		float x = radius * cos(t) + center[0];
		float y = radius * sin(t) + center[1];
		float z = step / (2 * pi) * t + center[2];

		cout << "Point: (" << x << ", " << y << ", " << z << " )" << endl;
	}

	void PrintPointDerivative(float t) {
		float pi = PI;

		float x = -radius * sin(t);
		float y = radius * cos(t);
		float z = step / (2 * pi);

		cout << "Derivative: (" << x << ", " << y << ", " << z << " )" << endl;
	}

	virtual bool IsCircle() {
		return false;
	}
	virtual bool IsEllipse() {
		return false;
	}
	virtual bool IsHelixe() {
		return true;
	}

	float GetRadius() {
		return radius;
	}

	float GetStep() {
		return step;
	}
};